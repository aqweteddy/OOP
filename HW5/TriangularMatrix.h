#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Matrix {
   public:
    friend std::ostream& operator<<(std::ostream& out, const Matrix);
    friend Matrix operator*(double s, const Matrix& rt);

    Matrix() { return; }

    ~Matrix() { mat.clear(); }

    Matrix(const Matrix& b) {
        stat = b.stat;
        n = b.n;
        mat = b.mat;
    }

    Matrix operator+(const Matrix& b) {
        Matrix c;

        if (!checkError(b)) return (*this);

        c.setSize(stat, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < mat[i].size(); ++j) {
                c.mat[i][j] = mat[i][j] + b.mat[i][j];
            }
        }
        return c;
    }

    void operator+=(const Matrix& b) {
        if (!checkError(b)) return;
        (*this) = (*this) + b;
    }

    Matrix operator-(const Matrix& b) {
        Matrix c;

        if (!checkError(b)) return (*this);

        c.setSize(stat, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (int)mat[i].size(); ++j) {
                c.mat[i][j] = mat[i][j] - b.mat[i][j];
            }
        }
        return c;
    }

    void operator-=(const Matrix& b) {
        if (!checkError(b)) return;
        (*this) = (*this) - b;
    }

    Matrix operator*=(double k) {
        return (*this) = k * (*this);
    }

    Matrix operator*(const double& k) {
        Matrix b;

        b.setSize(stat, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < mat[i].size(); ++j) b.mat[i][j] = mat[i][j] * k;
        }
        return b;
    }

    Matrix operator*(const Matrix& b) {
        if (!checkError(b)) return b;
        Matrix c;
        c.setSize(stat, n);

        if(stat == 1){
            for(int i=0; i<n; ++i){
                for(int j=0; j<=i; ++j){
                    vector<double> p, q;
                    p = mat[i];
                    while(p.size() != n) p.push_back(0);
                    while(q.size() != j) q.push_back(0);
                    for(int k=j; k<n; ++k){
                        q.push_back(b.mat[k][j]);
                    }
                    c[i][j] = dot(p, q);
                }
            }
        } else {
            for(auto &v : c.mat)
                for(auto &k : v) k = 0;
            for(int i=0; i<n; ++i){
                vector<double> p;        
                for(int k=0; k<i; ++k) p.push_back(0);
                for(int k=0; k<n-i; ++k) p.push_back(mat[i][k]);
                int cnt = 0;
                for(int j=1; j<=n; ++j){
                    vector<double> q;

                    for(int k=0, m=j-1; k<j; --m, ++k) {
                        q.push_back(b.mat[k][m]);
                    }
                    while(q.size() != n) q.push_back(0);
                    if(dot(p, q) == 0) continue;
                    c.mat[i][cnt++] = dot(p, q);
                }
            }
        }
        return c;
    }

    void operator*=(const Matrix& b){
       if (!checkError(b)) return;
        (*this)  = (*this) * b;
    }

    double operator()(const int& i, const int& j) const {
        if (i - 1 > n || j - 1 >= mat[i - 1].size()) {
            cout << "Out of range" << endl;
            return -1;
        }
        return mat[i - 1][j - 1];
    }

    vector<double>& operator[](const int& i) { 
         if (i >= n) {
            cout << "Out of range" << endl;
            return mat.at(0);
        }
        return mat.at(i); 
    }

    Matrix get_uni_matrix(double k){
        Matrix c;
        c.setSize(stat, size());
        for(auto &i : c.mat)
            for(auto &j : i) j = k; 
        return c;
    }

    void readMatrix() {
        cout << "upper or lower ? (0 is upper, 1 or others is lower)" << endl;
        cout << "> ";
        cin >> stat;
        cout << "number of row ?" << endl;
        cout << "> ";
        cin >> n;
        mat.resize(n);

        cout << "input data: \n> ";
        if (stat == 1) {  // lower
            for (int i = 0; i < n; ++i) {
                mat[i].resize(i + 1);
                for (int j = 0; j < i + 1; ++j) cin >> mat[i][j];
            }
        } else {  // upper
            for (int i = 0, j = n; i < n; ++i, --j) {
                mat[i].resize(j);
                for (int k = 0; k < j; ++k) cin >> mat[i][k];
            }
        }
        cout << "end of input" << endl;
    }

    int size() const { return n; }

   private:
    int n;      // n*n
    bool stat;  // 0 is upper,1 1 is lower
    vector<vector<double> > mat;

    void setSize(const bool &stat, const int& n) {
        this->n = n;
        this->stat = stat;
        mat.resize(n);

        if (stat == 1) {  // lower
            for (int i = 0; i < n; ++i) mat[i].resize(i + 1);
        } else {
            for (int i = 0, j = n; i < n; ++i, --j) mat[i].resize(j);
        }
    }

    bool checkError(const Matrix& b) {
        bool fl = 1;

        try {
            if(b.n != n) throw 1;
        } catch (int k){
            cout << "Can't compute with different dimension" << endl;
            fl = 0;
        }

        try {
            if (stat != b.stat) throw 1;
        } catch(int k){
            cout << "Can't compute Upper with Lower" << endl;
            fl = 0;
        }
        return fl;
    }

    double dot(const vector<double> &a, const vector<double> b) {
        double sum = 0;

        for (int i = 0; i < a.size(); ++i) sum += (a[i] * b[i]);
        return sum;
    }
};

Matrix operator*(double k, const Matrix& rt) {
    Matrix b;

    b.setSize(rt.stat, rt.n);
    for (int i = 0; i < rt.n; ++i) {
        for (int j = 0; j < rt.mat[i].size(); ++j)
            b.mat[i][j] = rt.mat[i][j] * k;
    }
    return b;
}

std::ostream& operator<<(std::ostream& out, const Matrix M) {
    if(M.stat == 0){
        for (auto v : M.mat) {
            for(int i=v.size(); i<M.size(); ++i) out << '0' << '\t';
            for (auto k : v) out << k << '\t';
            out << endl;
        }
        return out;
    }
    for (auto v : M.mat) {
        for (auto k : v) out << k << '\t';
        for (int i = v.size(); i<M.size(); ++i) out << "0\t";
        out << endl;
    }
    return out;
}