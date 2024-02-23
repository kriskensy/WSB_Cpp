#include<iostream> 

class Number
{
    public:
        Number()
        {
            std::cout << "Creating Number" << std::endl;
        }

        virtual ~Number()
        {
            std::cout << "Destroying Number" << std::endl;
        }

        virtual std::string getType() const = 0; //czysto wirtualna, nie ma implementacji
        virtual void dispNumber() const = 0;
};

class Complex : public Number
{
    public:
        Complex(float re = 0, float im = 0)
        : mRe(re), mIm(im)
        {
            std::cout << "Creating Complex" << std::endl;
        }

        ~Complex()
        {
            std::cout << "Destroying Complex" << std::endl;
        }

        std::string getType() const override;
        void dispNumber() const override;

    private:
        float mRe;
        float mIm;
};

std::string Complex::getType() const
{
    return "Complex";
}

void Complex::dispNumber() const
{
    if(mIm == 0)
        std::cout << mRe << std::endl;
    else if(mIm < 0)
        std::cout << mRe << mIm << "i" << std::endl;
    else
        std::cout << mRe << " + " << mIm << "i" << std::endl;
}

class Rational : public Number
{
    public:
        Rational(int numerator = 0, int denominator = 0)
        : mNumerator(numerator), mDenominator(denominator)
        {
            std::cout << "Creating Rational" << std::endl;
        }

        ~Rational()
        {
            std::cout << "Destroying Rational" << std::endl;
        }

        std::string getType() const override;
        void dispNumber() const override;

    private:
        int mNumerator;
        int mDenominator;
};

std::string Rational::getType() const
{
    return "Rational";
}

void Rational::dispNumber() const
{
    if(mDenominator == 0)
        std::cout << "NaN";
    else
        std::cout << mNumerator << "/" << mDenominator;
}

int main()
{
//     float re{0}, im{0};
//     std::cin >> re >> im;
//     Complex* pComplex = new Complex(re, im);
//     std::cout << pComplex -> getType() << " ";
//     pComplex -> dispNumber();
//     std::cout << std::endl;
// //    pComplex = new Complex(1, 1); //tak nie wolno robić bo tracę dostęp do obiektu/zmiennej i może dojśc do wycieku pamięci
//     delete pComplex;

// //ze wskaźnikiem na klasę bazową
//     int numerator{0}, denominator{0};
//     std::cin >> numerator >> denominator;
//     Number* pNumber = new Rational(numerator, denominator);
//     std::cout << pNumber -> getType() << " ";
//     pNumber -> dispNumber();
//     std::cout << std::endl;
//     delete pNumber;


//dynamiczna tablica obiektów
    size_t size{0};
    std::cin >> size;
    Complex* array = new Complex[size];
    for(int i = 0; i < size; i++)
    {
        std::cout << array[i].getType() << " ";
        array[i].dispNumber();
    }

    delete[] array;

//dynamiczna tablica wskaźników
    Number** arrayPointers = new Number * [size]; //dwie gwiazdki bo wskaźnik na tablicę wskaźników
    for(int i = 0; i < size; i++)
    {
        if(i % 2) arrayPointers[i] = new Complex(i+1, i+1);
        else arrayPointers[i] = new Rational(i+1, i+1);
    }
//wyswietlanie
    for(int i = 0; i < size; i++)
    {
        std::cout << arrayPointers[i] -> getType() << " ";
        arrayPointers[i] -> dispNumber();
        std::cout << std::endl;
    }
//sprzatanie -> iteracja po tablicy i usuniecie wskaznikow z tablicy, które wskazuja na obiekty
    for(int i = 0; i < size; i++)
    {
        delete arrayPointers[i];
    }
    delete[] arrayPointers; //usuniecie wskaznika na tablice

//=================wskaźniki przypomnienie======================
    // std::cout << "=============wskazniki przypomnienie=============" << std::endl;
    // std::cout << std::endl;
    // int x{6};
    // int* pX = &x;
    // int* pX2 = &x;
    // *pX2 = 8;

    // std::cout << "x = " << x << ", &x = " << &x << ", pX = " << pX << ", pX2 = " << pX2 << ", &pX = " << &pX <<  ", &pX2 = " << &pX2 << std::endl;
    // std::cout << *pX << std::endl;
    // std::cout << "================================================" <<std::endl;

    return 0;
}

// Napisz klasę reprezentującą liczbę. Klasa zawiera dwie czyste wirtualne metody wyświetlające typ liczby oraz wartość liczby.
// Następnie napisz klasę reprezentującą liczbę zespoloną oraz klasę reprezentującą liczbę wymierną, które dziedziczą z klasy reprezentującej liczbę.
// Klasa reprezentująca liczbę zespoloną zawiera:
// - prywatne atrybuty typu float reprezentujące część rzeczywistą i urojoną domyślnie przyjmujące wartość 0,
// - metodę wyświetlającą liczbę w formacie "Re +/- Im i", gdzie Re to część rzeczywista natomiast Im to część urojona,
// - przeciążoną metodę z klasy reprezentującej liczbę, wyświetlającą typ liczby.
// Klasa reprezentująca liczbę wymierną zawiera:
// - prywatne atrybuty typu float reprezentujące licznik i mianownik liczby,
// - metodę wyświetlającą liczbę w formacie "a/b", gdzie a to licznik natomiast b to mianownik,
// - przeciążoną metodę z klasy reprezentującej liczbę, wyświetlającą typ liczby.
//  W funkcji main():
// 1. stwórz wskaźnik do obiektu klasy reprezentującej liczbę zespoloną oraz stwórz obiekt tego typu pobierając od użytkownika wartości części rzeczywistej i urojonej,
// 2. wyświetl typ oraz liczbę dla stworzonego obiektu,
// 3. stwórz wskaźnik do obiektu klasy reprezentującej liczbę oraz stwórz obiekt reprezentujący liczbę wymierną pobierając od użytkownika wartość licznika i mianownika,
// 4. wyświetl typ oraz liczbę dla stworzonego obiektu,
// 5. stwórz dynamiczną tablicę obiektów reprezentujących liczby zespolone o rozmiarze podanym przez użytkownika,
// 6. wyświetl liczby znajdujące się w stworzonej tablicy,
// 7. *stwórz dynamiczną tablicę wskaźników do obiektów klasy reprezentującej liczbę o rozmiarze podanym przez użytkownika. Dla nieparzystych indeksów stwórz obiekty reprezentujące liczby zespolone, dla parzystych obiekty reprezentujące liczby wymierne,
// 8. *wyświetl typy i liczby dla stworzonej tablicy.
// Wszystkie elementy wyświetlane w funkcji main mają być oddzielone od siebie spacją.
// Przykładowo dla poniższych danych wejściowych
// 2 3 2.1 4.2 2
// program powinien wyświetlić
// Complex 2 +/- 3 i Rational 2.1/4.2 0 +/- 0 i 0 +/- 0 i