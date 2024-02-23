// Program ma na celu przetestowanie efektywności haszowania z porcjowaniem. Tworzy on 10-cio elementową tablicę haszowaną list łańcuchów. Następnie generuje 35 losowych łańcuchów 4-ro znakowych z liter od A do Z, po czym umieszcza je na listach w tablicy haszowanej.
// Po wypełnieniu tablicy jej zawartość jest wyświetlana w oknie konsoli – wartość haszu jest zawsze równa indeksowi komórki, która zawiera listę z danym łańcuchem.
// W drugiej części program generuje wszystkie łańcuchy 4-znakowe z liter od A do Z, a następnie wyszukuje je w tablicy haszowanej, wyświetlając kolejno: łańcuch, wartość haszu hf( ), liczbę obiegów pętli wyszukującej c. Zwróć uwagę na pozycje, dla których liczba obiegów c  jest równa zero – te łańcuchy znaleziono od razu za pierwszym podejściem. Liczba obiegów c  wskazuje pozycję danego łańcucha na liście.
// Zwiększając rozmiar tablicy, zmniejszamy wielkość porcji, a zatem zmniejszamy czas potrzebny na odszukanie danych.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Definicja elementu listy
class slistEl
{
    public:
        slistEl * next;
        std::string data;
};

// Funkcja haszująca
unsigned int hf(std::string s)
{
    unsigned int h, i;
    h = 0;
    for(i = 0; i < s.length(); i++)
        h = 31 * h + s[i] - 65;
    return h % 10;
}

int main()
{
    slistEl * T[10], * p, * r;
    unsigned int i, j, h, c;
    std::string s;
    bool t;
    srand(time(NULL));

// Zerujemy tablicę haszowaną
    for(i = 0; i < 10; i++) T[i] = NULL;

// Tablicę wypełniamy łańcuchami
    for(i = 0; i < 35; i++)
    {
// Generujemy losowy łańcuch z 4 znaków A-Z
        s = "";
        for(j = 0; j < 4; j++)
            s += 65 + (rand() % 26);

// Łańcuch umieszczamy na odpowiedniej liście
        h = hf(s);
        p = T[h];
        t = true;

        if(p)
        while(true)
        {
            if(p -> data == s)
            {
                t = false;
                break;
            }
            if(!p -> next) break;
            p = p -> next;
        }

        if(t)
        {
            r = new slistEl;
            r -> data = s;
            r -> next = NULL;
            if(!p) T[h] = r;
            else p -> next = r;
        }
    }

// Wypisujemy tablicę
    for(i = 0; i < 10; i++)
    {
        std::cout << "T [ " << i << " ] = ";
        p = T[i];
        while(p)
        {
            std::cout << p -> data << " ";
            p = p -> next;
        }
    std::cout << std::endl;
    }
    std::cout << std::endl;

// Generujemy wszystkie łańcuchy 4-ro znakowe i szukamy ich w tablicy

    s = "AAAA";
    do
    {
        h = hf(s);
        c = 0;
        p = T[h];
        while(p && (p -> data != s))
        {
            c++;
            p = p -> next;
        }

        if(p) std::cout << s << " hf = " << h << " c = " << c << std::endl;

        for(i = 4; i > 0; i--)
        {
            s[i - 1] = s[i - 1] + 1;
            if(s[i - 1] <= 'Z' ) break;
            s [i - 1] = 'A';
        }
    } while(s != "AAAA");

// Usuwamy listy z pamięci
    for(i = 0; i < 10; i++)
        while((p = T[i]))
        {
            T[i] = p -> next;
            p -> data = "";
            delete p;
        }
    std::cout << std::endl;
    return 0;
}