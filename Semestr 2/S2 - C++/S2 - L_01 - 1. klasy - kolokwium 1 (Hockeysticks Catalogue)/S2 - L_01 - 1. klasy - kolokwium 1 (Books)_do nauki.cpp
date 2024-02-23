//Mateusz Pieda

#include <cstdlib>
#include <iostream>

class Book {

    public:

    Book() = default;

    Book(int id, std::string title, std::string author, int year)
    :id(id),title(title),author(author),yearOfRelease(year) {
    }

    void showBook() const {

        std::cout<<"ID number: "<<id<<", Title: "<<title<<", Author: "<<author<<", Year of release: "<<yearOfRelease<<std::endl;

    }

    int getID() {
        return id;
    }

    int getYear() {
        return yearOfRelease;
    }

    private:
        int id;
        std::string title;
        std::string author;
        int yearOfRelease;
};

class BookCatalogue {

    public:
    static constexpr unsigned int maxNoOfBooks{100};
    Book books[maxNoOfBooks];

    BookCatalogue() = default;

    void addBook(int id, std::string title, std::string author, int year) {

        Book book = Book(id, title, author, year);\

        if (!checkBooks(book)) {
            if (counter < maxNoOfBooks) {
                books[counter] = book;
                sortCatalogue();
                counter++;
            } else {
                std::cout<<"Catalogue is full. Cannot add another book."<<std::endl;
            }
        }
    }

    void delBook(int id) {

        for (int i = 0; i < counter; i++) {
            if (books[i].getID() == id) {
                for (int j = i; j < counter; j++) {
                    books[j] = books[j+1];
                }
                counter--;
                return;
            }
        }
        std::cout<<"Book with that ID is not in the catalogue"<<std::endl;

    }

    void checkBooks() const {

        for (int i = 0; i < counter; i++) {
            books[i].showBook();
        }

    }

    private:
    unsigned int counter = 0;

    bool checkBooks(Book book) {

        for (int i = 0; i < counter; i++) {
            if (books[i].getID() == book.getID()) {
                books[i] = book;
                sortCatalogue();
                return true;
            }
        }
        return false;
    }

    void sortCatalogue() {

        for (int i = 0; i < counter; i++) {
            for (int j = 0; j < counter-i; j++) {
                if (books[j].getYear() > books[j+1].getYear()) {
                    Book tempBook = books[j];
                    books[j] = books[j+1];
                    books[j+1] = tempBook;
                }
            }
        }
    }
    

};

int main() {

    BookCatalogue bCatalogue;

    bCatalogue.addBook(1,"Tytul1","Autor1",2003);
    bCatalogue.addBook(2,"Tytul2","Autor2",2006);
    bCatalogue.addBook(3,"Tytul3","Autor3",2021);
    bCatalogue.addBook(50,"Tytul4","Autor4",2021);
    bCatalogue.addBook(43,"Tytul5","Autor5",2023);
    bCatalogue.addBook(22,"Tytul6","Autor6",1994);
    bCatalogue.addBook(5,"Tytul7","Autor7",2001);
    bCatalogue.addBook(19,"Tytul8","Autor8",2020);
    bCatalogue.addBook(6,"Tytul9","Autor3",2005);
    bCatalogue.addBook(10,"Tytul10","Auto10",2021);
    bCatalogue.addBook(11,"Tytul11","Autor11",2022);

    bCatalogue.checkBooks();

    bCatalogue.addBook(19,"Zmieniony","Nowy",1995);
    std::cout<<"---"<<std::endl;

    bCatalogue.checkBooks();

    bCatalogue.delBook(50);
    bCatalogue.delBook(6);
    bCatalogue.delBook(11);
    bCatalogue.delBook(3);
    bCatalogue.delBook(22);
    std::cout<<"---"<<std::endl;
    bCatalogue.checkBooks();

}