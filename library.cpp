#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    string Title;
    string Author;
    int ISBN;
    bool Availability;

public:
    void setTitle(string t) {
        Title = t;
    }
    void setAuthor(string a) {
        Author = a;
    }
    void setISBN(int i) {
        ISBN = i;
    }
    void setAvailable(bool a = true) {
        Availability = a;
    }
    string getTitle() {
        return Title;
    }
    string getAuthor() {
        return Author;
    }
    int getISBN() {
        return ISBN;
    }
    string getAvailability() {
        if (Availability == true) {
            return "Available";
        } else {
            return "Checked out";
        }
    }
    void borrowBook() {
        if (Availability == true) {
            Availability = false;
            cout << "Thank you for borrowing a book!" << endl;
        } else {
            cout << "This book is checked out" << endl;
        }
    }
    void returnBook() {
        if (Availability == false) {
            Availability = true;
            cout << "Thank you for returning the book" << endl;
        } else {
            cout << "This book is already available" << endl;
        }
    }
};

int main() {
    vector<Book> library;
    int choice;
    bool found;

    cout << "Menu" << endl;
    cout << "1. Add a book" << endl;
    cout << "2. Remove a book" << endl;
    cout << "3. Search for a book" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        if (library.size() < 100) {
            string title, author;
            int ISBN;
            cout << "Enter the Title, Author, and ISBN of your book: ";
            cin >> title >> author >> ISBN;
            bool availability = true;

            Book newBook;
            newBook.setTitle(title);
            newBook.setAuthor(author);
            newBook.setISBN(ISBN);
            newBook.setAvailable(availability);
            library.push_back(newBook);
        } else {
            cout << "The library is full" << endl;
        }
        break;

    case 2:
        if (library.size() == 0) {
            cout << "The library is empty" << endl;
        } else {
            int removeISBN;
            found = false;
            cout << "Enter the ISBN of the book you want to remove: ";
            cin >> removeISBN;
            for (auto it = library.begin(); it != library.end(); it++) {
                if (it->getISBN() == removeISBN) {
                    library.erase(it);
                    found = true;
                    cout << "Book successfully removed" << endl;
                    break;
                }
            }
            if (!found) {
                cout << "Book with ISBN " << removeISBN << " not found in the library." << endl;
            }
        }
        break;

    case 3:
        int searchISBN;
        found = false;
        cout << "Enter the ISBN of the book you are searching for: ";
        cin >> searchISBN;
        for (auto it = library.begin(); it != library.end(); it++) {
            if (it->getISBN() == searchISBN) {
                cout << "Book title: " << it->getTitle() << endl;
                cout << "Book author: " << it->getAuthor() << endl;
                cout << "Book ISBN: " << it->getISBN() << endl;
                cout << "Book availability: " << it->getAvailability() << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book with ISBN " << searchISBN << " not found in the library." << endl;
        }
        break;

    case 4:
        break;

    default:
        cout << "Invalid choice" << endl;
        break;
    }

    return 0;
}
