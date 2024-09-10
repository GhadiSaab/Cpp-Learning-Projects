#include <iostream>
using namespace std;
void Originale(int *ptr, int size) {
    for (int i = 0; i < size ; i++) {
        cout << *(ptr+i) << " ";
    }
    cout << endl;
}

void Reverse(int *ptr, int size , int arr[]) {
    for (int i = size-1 , z = 0 ; i >= 0 ; i--, z++) {
        cout << *(ptr + i) << " ";
        arr[z] = *(ptr + i) ;

    }
}
int main() {
    cout << "Choose the size of your array" <<endl;
    int x;
    cin >> x;
    int arr1[x];
    for( int i=0; i < x ; i++ ) {
        cout << "Put in your elements" << " ";
        cin >> arr1[i]; 
    }
    int *p = &arr1[0];
    int reverseAR[x];
    Originale(p,x);
    Reverse(p , x , reverseAR);
    int *p1 = &reverseAR[0];
    bool isPalindrome = true;
    for (int i = 0 ; i < x ; i ++) {
        if (arr1[i] != reverseAR[i] ) {
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome) {
        cout << "it is a Palindrome" << endl;
    } else {
        cout << "its not a Palindrome" << endl;
    }


    
    return 0;
}