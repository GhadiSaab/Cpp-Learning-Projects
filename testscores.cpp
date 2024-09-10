#include <iostream>
#include <fstream>
#include <string>
#include <climits>
using namespace std;

int main() {
    ifstream fin;
    fin.open("TestScores.txt");

    if (!fin.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string name;
    int grade;
    string highestScorer;
    int highestGrade = INT_MIN; // Initialize with the smallest possible integer value

    while (fin >> name >> grade) {
        cout << "Name: " << name << " Grade: " << grade << endl;
        if (grade > highestGrade) {
            highestGrade = grade;
            highestScorer = name;
        }
    }

    if (highestGrade != INT_MIN) {
        cout << "Highest Grade: " << highestGrade << " scored by " << highestScorer << endl;
    } else {
        cout << "No grades found in the file." << endl;
    }

    fin.close();
    return 0;
}
