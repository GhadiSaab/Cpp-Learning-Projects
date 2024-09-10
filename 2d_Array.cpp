#include <iostream>
using namespace std;

void Original(int *ptr, int size_row, int size_columns) {
    for (int i = 0; i < size_row; ++i) {
        for (int z = 0; z < size_columns; ++z) {
            cout << *(ptr + i * size_columns + z) << " ";
        }
        cout << endl;
    }
}
void Reverse(int *ptr, int size_row, int size_columns) {
    for (int i = size_row - 1; i >= 0 ; i--){
        for (int z = size_columns - 1 ; z >= 0 ; z--) {
            cout << *(ptr + i * size_columns + z) << " ";
        }
    cout << endl;    
    }
}

int main() {
    int x, y;
    cout << "Enter the number of rows and columns: ";
    cin >> x >> y;
    
    int arr[x][y];
    int *pr = &arr[0][0];
    
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < x; ++i) {
        for (int z = 0; z < y; ++z) {
            cout << "Enter element [" << i << "][" << z << "]: ";
            cin >> arr[i][z];
        }
    }

    Original(pr, x, y);

    Reverse(pr,x,y);

    return 0;
}
