#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Book {
public:
    Book(string title, string author, string isbn)
        : title(title), author(author), isbn(isbn), available(true) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    string getISBN() const {
        return isbn;
    }

    bool isAvailable() const {
        return available;
    }

    void setAvailable(bool available) {
        this->available = available;
    }

private:
    string title;
    string author;
    string isbn;
    bool available;
};

class Borrower {
public:
    Borrower(string name, string address)
        : name(name), address(address) {}

    string getName() const {
        return name;
    }

    string getAddress() const {
        return address;
    }

private:
    string name;
    string address;
};

class LibrarySystem {
public:
    LibrarySystem() {
        loadBooksFromFile("books.txt"); // Load books from file
    }

    ~LibrarySystem() {
        saveBooksToFile("books.txt"); // Save books to file
    }

    void addBook(const Book& book) {
        books.push_back(book);
    }

    

    void searchBook(const string& query) const {
        cout << "Search results for \"" << query << "\":\n";
        for (const auto& book : books) {
            if (book.getTitle().find(query) != string::npos ||
                book.getAuthor().find(query) != string::npos ||
                book.getISBN().find(query) != string::npos) {
                cout << "Title: " << book.getTitle() << "\n"
                     << "Author: " << book.getAuthor() << "\n"
                     << "ISBN: " << book.getISBN() << "\n"
                     << "Available: " << (book.isAvailable() ? "Yes" : "No") << "\n\n";
            }
        }
    }

    void checkoutBook(const string& isbn, const Borrower& borrower) {
        auto it = find_if(books.begin(), books.end(), [&](const Book& book) {
            return book.getISBN() == isbn && book.isAvailable();
        });

        if (it != books.end()) {
            it->setAvailable(false);
            cout << "Book checked out to " << borrower.getName() << ".\n";
        } else {
            cout << "Book not found or already checked out.\n";
        }
    }

    void returnBook(const string& isbn) {
        auto it = find_if(books.begin(), books.end(), [&](const Book& book) {
            return book.getISBN() == isbn;
        });

        if (it != books.end()) {
            it->setAvailable(true);
            cout << "Book returned.\n";
        } else {
            cout << "Book not found.\n";
        }
    }

private:
    vector<Book> books;

    void loadBooksFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                stringstream ss(line);
                string title, author, isbn;
                getline(ss, title, ',');
                getline(ss, author, ',');
                getline(ss, isbn);
                addBook(Book(title, author, isbn));
            }
            file.close();
        }
    }

    void saveBooksToFile(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& book : books) {
                file << book.getTitle() << ',' << book.getAuthor() << ',' << book.getISBN() << '\n';
            }
            file.close();
        }
    }
};

int main() {
    LibrarySystem library;

    int choice;
    string query, isbn, name, address;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Search for a book\n";
        cout << "2. List all books\n";
        cout << "3. Checkout a book\n";
        cout << "4. Return a book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter search query: ";
                cin.ignore();
                getline(cin, query);
                library.searchBook(query);
                break;
            case 2:
                library.listBooks();
                break;
            case 3:
                cout << "Enter ISBN of the book to checkout: ";
                cin >> isbn;
                cout << "Enter borrower's name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter borrower's address: ";
                getline(cin, address);
                library.checkoutBook(isbn, Borrower(name, address));
                break;
            case 4:
                cout << "Enter ISBN of the book to return: ";
                cin >> isbn;
                library.returnBook(isbn);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}