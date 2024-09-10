#include <iostream>
#include <cstdlib> // for rand() and srand()

using namespace std;

class sum {
public:
    int rows, cols;
    int *rowSum;
    int *colSum;

    sum(int rows_, int cols_) : rows(rows_), cols(cols_) {
        rowSum = new int[rows];
        colSum = new int[cols];
    }

    ~sum() {
        delete[] rowSum;
        delete[] colSum;
    }
};

void fillArray(int**& arr, int rows, int cols) { // Pass arr by reference
    arr = new int*[rows];
    for(int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100;
        }
    }
}

void calculateSums(int **arr, int rows, int cols, sum& sum1) { // Pass sum1 by reference
    for (int i = 0; i < rows; i++) { // rows
        sum1.rowSum[i] = 0;
        for (int j = 0; j < cols; j++) {
            sum1.rowSum[i] += arr[i][j];
        }
    }
    for (int j = 0; j < cols; j++) { // cols
        sum1.colSum[j] = 0;
        for (int i = 0; i < rows; i++) {
            sum1.colSum[j] += arr[i][j];
        }
    }
}

void printArray(int **arr, int rows, int cols) {
    cout << "Here's your array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void printSums(sum sum1) {
    cout << "Row sums:" << endl;
    for (int i = 0; i < sum1.rows; i++) {
        cout << sum1.rowSum[i] << " ";
    }
    cout << endl;

    cout << "Column sums:" << endl;
    for (int j = 0; j < sum1.cols; j++) {
        cout << sum1.colSum[j] << " ";
    }
    cout << endl;
}

int main() {
    int x, y;
    cout << "Enter the dimensions for the array: ";
    cin >> x >> y;
    int** arr = nullptr; // Initialize arr to nullptr

    sum sum1(x, y);
    fillArray(arr, x, y);
    calculateSums(arr, x, y, sum1);
    printArray(arr, x, y);
    printSums(sum1);

    // Deallocate memory for arr
    if (arr != nullptr) {
        for (int i = 0; i < x; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    return 0;
}
