#include <iostream>
using namespace std;


int main() {
    int size = 5;
    int arr[5];
    int *p = arr;
    for (int i=0; i < 5 ; i++) {
        cout << "enter 5 integers one by one: ";
        cin >> *(p+i);
    }
    int sumval = 0;
    for (int i = 0; i < 5 ; i ++) {
        sumval += *(p+i);
    }
    cout << "heres the average" << sumval / 5;

    return 0;
}