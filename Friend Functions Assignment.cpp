#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int width;

public:
    Rectangle(int l, int w)
        : length(l), width(w) {}

    int area() {
        return width * length;
    }

    int perimeter() {
        return 2 * width + 2 * length;
    }

    friend bool equalArea(Rectangle rect1, Rectangle rect2) {
        return rect1.area() == rect2.area();
    }
};

int main() {
    Rectangle r1(2, 3);
    Rectangle r2(4, 5);
    
    bool areEqual = equalArea(r1, r2);
    if (areEqual) {
        cout << "The areas of the two rectangles are equal." << endl;
    } else {
        cout << "The areas of the two rectangles are not equal." << endl;
    }

    return 0;
}
