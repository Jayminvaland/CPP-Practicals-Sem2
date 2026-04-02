#include <iostream>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    int copies;

public:
    void addBook() {
        cout << "Enter Book ID: ";
        cin >> id;
        cout << "Enter Title: ";
        cin >> title;
        cout << "Enter Author: ";
        cin >> author;
        cout << "Enter Copies: ";
        cin >> copies;
    }

    int getId() {
        return id;
    }

    void issueBook() {
        if (copies > 0) {
            copies--;
            cout << "Book issued.\n";
        } else {
            cout << "No copies available.\n";
        }
    }

    void returnBook() {
        copies++;
        cout << "Book returned.\n";
    }
};

class Library {
private:
    Book b[100];
    int count;

public:
    Library() {
        count = 0;
    }

    void addBook() {
        b[count].addBook();
        count++;
        cout << "Book added successfully.\n";
    }

    void issueBook(int id) {
        for (int i = 0; i < count; i++) {
            if (b[i].getId() == id) {
                b[i].issueBook();
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook(int id) {
        for (int i = 0; i < count; i++) {
            if (b[i].getId() == id) {
                b[i].returnBook();
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void displayTotal() {
        cout << "Total books: " << count << endl;
    }
};

int main() {
    Library lib;
    int choice, id;

    do {
        cout << "\n1.Add Book\n2.Issue Book\n3.Return Book\n4.Total Books\n5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2:
                cout << "Enter Book ID: ";
                cin >> id;
                lib.issueBook(id);
                break;
            case 3:
                cout << "Enter Book ID: ";
                cin >> id;
                lib.returnBook(id);
                break;
            case 4: lib.displayTotal(); break;
        }
    } while (choice != 5);

    return 0;
}