#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string copy[100];
    int i = 0; 
    ifstream file("example.txt");
    if (file.is_open()) {
        while (getline(file, copy[i])) {
            i++;
        }
        file.close();

        ofstream outfile("examplecopy.txt");
        if (outfile.is_open()) {
            while (i > 0) { // Start from i-1 to 0
                outfile << copy[i - 1] << endl; // Write each string to the file
                i--;
            }
            outfile.close();
            cout << "Data written successfully!" << endl;
        } else {
            cout << "Unable to open output file" << endl;
        }
    } else {
        cout << "Unable to open input file" << endl;
    }
    return 0;
}
