// Program ma na celu przetestowanie efektywności haszowania z próbkowaniem liniowych. Tworzy on 10-cio elementową tablicę haszowaną łańcuchów. Następnie generuje 10 losowych łańcuchów 4-ro znakowych z liter A i B, po czym umieszcza je w tablicy haszowanej. Ponieważ łańcuchy są tworzone losowo, to będą się pojawiały duplikaty, których program nie umieści w tablicy, zatem część jej komórek pozostanie niezajęta. Również pojawią się łańcuchy o tej samej wartości funkcji haszującej. W takim przypadku próbkowanie liniowe umieści je w innych komórkach, niż wychodzi to z ich haszu.
// Po wypełnieniu tablicy jej zawartość jest wyświetlana w oknie konsoli wraz z wartościami haszu. Jeśli wartość haszu różni się od indeksu tablicy, to dany łańcuch został zapisany w innej komórce, ponieważ jego komórka była zajęta przez inny łańcuch.

// W drugiej części program generuje wszystkie łańcuchy 4-znakowe z liter A i B, a następnie wyszukuje je w tablicy haszowanej, wyświetlając kolejno: łańcuch, wartość haszu hf( ), liczbę obiegów pętli wyszukującej c  oraz informację o pozycji łańcucha w tablicy, jeśli się tam znajduje. Zwróć uwagę na pozycje, dla których liczba obiegów c jest równa zero – te łańcuchy znaleziono od razu za pierwszym podejściem.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int hf(std::string s)// Funkcja haszująca
{
    unsigned int h, i;
    h = 0;
    for(i = 0; i < s.length(); i++)
        h = 2 * h + 1 - (s [i] & 1);
    return h % 10;
}

// Funkcja tworzy łańcuch 4 znakowy z A i B na podstawie wartości bitów x
std::string s4(int x)
{
    std::string s = "";
    int m = 8;  // Maska bitowa
    while(m)
    {
        s += (x & m)? 'B' : 'A';
        m >>= 1;
    }
    return s;
}

int main()
{
    std::string T [10], s;
    int i, j, h, c, p;
    srand (time(NULL));

// Zerujemy tablicę haszowaną
    for(i = 0; i < 10; i++) T [i] = "";

// Tablicę wypełniamy łańcuchami
    for(i = 0; i < 10; i++)
    {
// Generujemy losowy łańcuch z 4 znaków A, B
        s = s4(rand() % 16);

// Łańcuch umieszczamy w tablicy haszowanej
        h = hf(s);
        j = h;
        while(true)
        {
            if(T[j] == "")
            {
                T[j] = s;
                break;
            }
            if(T[j] == s) break;
                j = (j + 1) % 10;
            if(j == h) break;
        }
    }

// Wyświetlamy zawartość tablicy wraz z wartością funkcji haszującej
    for(i = 0; i < 10; i++)
    {
        std::cout << "T [ " << i << " ] = ";
        if(T[i] != "")
            std::cout << T[i] << " hf( ) = " << hf(T[i]);
        else
            std::cout << "-";
        std::cout << std::endl;
    }
    std::cout << std::endl;

// Sprawdzamy obecność łańcuchów w tablicy haszowanej
    for(i = 0; i < 16; i++)
    {
        s = s4(i);  // Łańcuch
        h = hf(s);  // Hasz łańcucha
        c = 0;      // Licznik obiegów
        j = h;
        p = -1;
        while(true)
        {
            if(T[j] == "") break;
            if(T[j] == s)
            {
                p = j; break;
            };
            j = (j + 1) % 10;
            if(j == h) break;
            c++;
        }

// Wyświetlamy wyniki
        std::cout << s << " hf( ) = " << h << " c = " << c << " ";
        if(p > -1)
            std::cout << "is in T [ " << p << " ] ";
        else
            std::cout << "-";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}