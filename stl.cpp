#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vct;
    int num;

    cout << "how many elem: " ;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int value;
        cout << "enter the elem num "<< i;
        cin >> value;
        vct.push_back(value);
    }


    return 0;
}
