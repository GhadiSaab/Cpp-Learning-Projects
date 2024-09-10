#include <iostream>
using namespace std;

template <typename T>
class Calculator {
public:
    T add(T a , T b){
        return a + b;
    }

    T subtract(T a, T b){
        return a - b;
    }

    T divide(T a, T b) {
        if (b == 0){
            throw "Division by zero is not possible";
        } else {
            return a / b;
        }
    }

    T multiply(T a, T b) {
        return a * b;
    }
};

int main() {
    Calculator<double> cal; // Specify the type for the template class

    cout << "Addition: " << cal.add(15.3, 21) << endl;
    try {
        cout << "Division: " << cal.divide(15, 0) << endl;
    } catch (const char* error) {
        cerr << "Error: " << error << endl;
    }

    return 0;
}
