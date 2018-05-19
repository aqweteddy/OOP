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

    Matrix operator+=(const Matrix& b) {
        if (!checkError(b)) return b;
        return (*this) = (*this) + b;
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

    Matrix operator-=(const Matrix& b) {
        if (!checkError(b)) return b;
        return (*this) = (*this) - b;
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
        return b;
    }

    double operator()(const int& i, const int& j) {
        if (i - 1 > n || j - 1 >= mat[i - 1].size()) {
            cout << "Out of range" << endl;
            return -1;
        }
        return mat[i - 1][j - 1];
    }

    vector<double>& operator[](const int& i) { return mat.at(i); }

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

    void setSize(bool stat, int n) {
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

    double dot(vector<double> a, vector<double> b) {
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
    for (auto v : M.mat) {
        for (auto k : v) out << k << '\t';
        out << endl;
    }
    return out;
}