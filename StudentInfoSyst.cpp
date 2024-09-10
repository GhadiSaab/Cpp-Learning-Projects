#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    double gpa;
    string major;
    int id;
public:
    // Setters
    void setName(string n) {
        name = n;
    }
    void setId(int i) {
        id = i;
    }
    void setGpa(double g) {
        gpa = g;
    }
    void setMajor(string m) {
        major = m;
    }

    // Getters
    string getName() {
        return name;
    }
    int getId() {
        return id;
    }
    double getGpa() {
        return gpa;
    }
    string getMajor() {
        return major;
    }
};

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    // Create a vector to store Student objects
    vector<Student> students(numStudents);

    // Input student information
    for (int i = 0; i < numStudents; ++i) {
        string name;
        int id;
        double gpa;
        string major;

        cout << "Enter student " << i+1 << " information (name id gpa major): ";
        cin >> name >> id >> gpa >> major;

        // Validate GPA
        while (gpa < 0 or gpa > 4) {
            cout << "Invalid GPA. Enter a valid GPA: ";
            cin >> gpa;
        }

        // Set student information
        students[i].setName(name);
        students[i].setId(id);
        students[i].setGpa(gpa);
        students[i].setMajor(major);
    }

    // Display student information
    cout << "\nStudent Information:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student " << i+1 << ":\n";
        cout << "Name: " << students[i].getName() << endl;
        cout << "ID: " << students[i].getId() << endl;
        cout << "GPA: " << students[i].getGpa() << endl;
        cout << "Major: " << students[i].getMajor() << endl << endl;
    }

    return 0;
}
