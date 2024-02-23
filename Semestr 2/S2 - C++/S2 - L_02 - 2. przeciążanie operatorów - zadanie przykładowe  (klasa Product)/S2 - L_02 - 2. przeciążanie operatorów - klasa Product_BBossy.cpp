/*
Uzupełnij plik startowy (bazujący na przykładowym programie z poprzednich zajęć) przeładowując dwa operatory dla klasy Product.

1. Operator += powinien dodawać dwa produkty i aktualizować obiekt, na którym jest wykonywany. W przypadku różnych jednostek, w których liczone są dodawane produkty, operator powinien zwracać wartość false. W przeciwnym wypadku powinna zostać zwrócona wartość true. Nazwy dodawanych produktów zostają połączone znakiem '+', przy czym w wynikowym ciągu znaków "przed plusem" jest nazwa obiektu, na którym wywoływany jest operator, a "po plusie" jest nazwa obiektu będącego argumentem operatora. Dla wszystkich zmiennych typu double z klasy Product, operator += powinien wykonać ich dodawanie.

2. Operator << powinien wyświetlać nazwę produktu oraz cenę netto oddzielone od siebie spacją i ponadto wyświetlać znak nowej linii.

W funkcji main pobierz dane dla nowego produktu. Dodaj nowy produkt do obiektu tomato (operator += wykonany na obiekcie tomato) i wyświetl obiekt tomato za pomocą operatora <<.
*/

#include<iostream>
#include<string>

using namespace std;

enum unit {gram, piece};

class Product {
    public:
        string name_;
        double netPrice_;
        double weight_;
        unit unit_;
        
        Product(){
            cout << "Creating a product." << endl;
        }
        
        Product(string, double, double, unit, double);
        
        ~Product() {
            cout << "Destroying the product " << name_ << endl;
        }
        
        double getGrossPrice() const {
            return grossPrice_;
        }
        double calcTotalPrice();

    private:
        double grossPrice_;
    
};

Product::Product(string name, double netPrice, double weight, unit u, double grossPrice)
: name_(name), netPrice_(netPrice), weight_(weight), unit_(u), grossPrice_(grossPrice) {
    cout << "Creating a product with data." << endl;
}

double Product::calcTotalPrice() {
    if (unit_ == gram) {
        return weight_/1000*netPrice_;
    }
    else
        return weight_*netPrice_;
}

int main() {
    
    Product tomato("MyTomato", 1.99, 2, gram, 0.99);
    Product avocado("MyAvacado", 4.99, 2, piece, 2.5);
    cout << "------------------" << endl;

    return 0;
}
