#include <iostream>
#include <cstdio>
#include "TriangularMatrix.h"
// ****If you need to include more header files, add it here****

using std::cin;
using std::cout;
using std::endl;

int main() {
#ifdef DEBUG
    freopen("test_file", "r", stdin);
#endif
    Matrix M1, M2, M3;
    cout << "* Assign values for matrix M1 *" << endl;
    M1.readMatrix();
    // ---This should be implemented in Matrix::readMatrix()---
    // <prompt> specify number of rows:
    // <user input> 3
    // <prompt> is upper or lower triangular: (upper: 1, lower:0)
    // <user input> 0
    // <prompt> input elements of the matrix:
    // <prompt> for example, if you want to create a lower-triangular matrix
    // with following elements: <prompt> 4    0    0
    // <prompt> 3    2.5  0
    // <prompt> 1    2    2
    // <prompt> please type: 4 3 2.5 1 2 2

    cout << "* Assign values for matrix M2 *" << endl;
    M2.readMatrix();
    //cout << "M1 * M2 \n" << M1 * M2 << endl;
    cout << "M1 is: \n" << M1 << endl;
    cout << "M2 is: \n" << M2 << endl;

    cout << "Copy Constractor M3 = M2" << endl;
    M3 = M2;
    cout << "M3 is: \n"<< M3 << endl;
    // Note that the size(row count) of M1, M2 may vary,
    // also M1, M2 can be upper or lower triangular matrices.
    // Therefore, please make sure that you check their types first before doing
    // the calculation.

    cout << "M3 = M1 + M2" << endl;
    M3 = M1 + M2;
    cout << "Now M3 is: \n" << M3 << endl;

    cout << "M3 = M3 - M2" << endl;
    M3 = M3 - M2;
    cout << "Now M3 is: \n" << M3 << endl;

    cout << "M3 += M2" << endl;
    M3 += M2;
    cout << "Now M3 is: \n" << M3 << endl;

    cout << "M3 -= M1" << endl;
    M3 -= M1;
    cout << "Now M3 is: \n" << M3 << endl;

    cout << "M3 = M2 * 5" << endl;
    M3 = M2 * 5;
    cout << "Now M3 is: \n" << M3 << endl;
    //cout << "M3 = M2 * 2 * M1" << endl;
   
   	cout << "M3 = M2 * 2 * M1" << endl;	
    M3 = M2 * 2 * M1;
    cout << "Now M3 is: \n" << M3 << endl;
	
	cout << "M3 *= M2" << '\n';
	M3 *= M2;	
    cout << "Now M3 is: \n" << M3 << endl;

    cout << "zero matrix:" << endl;
    cout << M1.get_uni_matrix(0) << endl;
    
	cout << "double d = M1(1,2)" << endl;
    double d = M1(1, 2);
    cout << "Now d is: " << d << endl << endl;

    cout << "M2(1,1) equals to: " << M2(1, 1) << endl << endl;//1~n
    cout << "M2[0][0] equals to: " << M2[1 - 1][1 - 1] << endl << endl;//0~n-1
    cout << "---------- END PROGRAM ----------" << endl << endl;

    return 0;
}
