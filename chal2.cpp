#include <iostream>
using namespace std;

void maxloc(int** p, int row, int col) {
    int maxVal = **p;
    int maxRow = 0;
    int maxCol = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (p[i][j] > maxVal) {
                maxVal = p[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
    cout << "heres the max value" << maxVal << endl << "the max row,col :" << maxRow << "," << maxCol;
}



int main () {
    cout << "dim 2d: ";
    int row,col;
    cin >> row >> col;
    int** arr = new int*[row];
    for (int i = 0; i < row ; i ++) {
        arr[i] = new int[col];
    }
    for (int i = 0;i < row;i++) {
        for (int j = 0 ; j < col ; j ++) {
            cout << "fil in your " <<  "array["<< i << "][" <<  j << "]" ;
            cin >> arr[i][j] ;
        }
    } 
    int **p = arr;
    maxloc(p,row,col);

    return 0;
}