#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string cr, cl, cp;      // łańcuchy do znaków ramek

class BSTNode
{
    public:
        BSTNode * up, * left, * right;
        int key;
};

void printBT(std::string sp, std::string sn, BSTNode * v)// Procedura wypisuje drzewo
{
    std::string s;
    if(v)
    {
        s = sp;
        if(sn == cr) s [s.length() - 2] = ' ';
        printBT(s + cp, cr, v -> right);

        s = s.substr(0, sp.length()-2);
        std::cout << s << sn << v -> key << std::endl;

        s = sp;
        if(sn == cl) s [s.length() - 2] = ' ';
        printBT(s + cp, cl, v -> left);
    }
}

void DFSRelease(BSTNode* v)// Procedura DFS:postorder usuwająca drzewo
{
    if(v)
    {
        DFSRelease(v -> left);  // usuwamy lewe poddrzewo
        DFSRelease(v -> right); // usuwamy prawe poddrzewo
        delete v;                // usuwamy sam węzeł
    }
}

void insertBST(BSTNode* & root, int k)// Procedura wstawia do drzewa BST węzeł o kluczu k
{
    BSTNode * w, * p;
    w = new BSTNode;           // Tworzymy dynamicznie nowy węzeł
    w -> left = w -> right = NULL; // Zerujemy wskazania synów
    p = root;                  // Wyszukujemy miejsce dla w, rozpoczynając od korzenia

    if(!p)                   // Drzewo puste?
        root = w;                // Jeśli tak, to w staje się korzeniem
    else
        while(true)            // Pętla nieskończona
            if(k < p -> key)       // W zależności od klucza idziemy do lewego lub
            {                      // prawego syna, o ile takowy istnieje
                if(!p -> left)       // Jeśli lewego syna nie ma, 
                {
                    p -> left = w;       // to węzeł w staje się lewym synem
                    break;             // Przerywamy pętlę while
                }
                else p = p -> left;
            }
            else
            {
                if(!p->right)      // Jeśli prawego syna nie ma, 
                {
                    p -> right = w;      // to węzeł w staje się prawym synem
                    break;             // Przerywamy pętlę while
                }
                else p = p -> right;
            }
    w -> up  = p;                // Ojcem węzła w jest zawsze węzeł wskazywany przez p
    w -> key = k;                // Wstawiamy klucz. Operacja jest zakończona.

}

void rot_L(BSTNode*& root, BSTNode* A)// Rotacja w lewo
{
    BSTNode * B = A -> right, * p = A -> up;

    if(B)
    {
        A -> right = B -> left;
        if(A -> right) A -> right -> up = A;

        B -> left = A;
        B -> up = p;
        A -> up = B;

        if(p)
        {
            if(p -> left == A)
                p -> left = B;
            else p -> right = B;
        }
        else root = B;
    }
}

void rot_R(BSTNode * & root, BSTNode * A)// Rotacja w prawo
{
    BSTNode * B = A -> left, * p = A -> up;

    if(B)
    {
        A -> left = B -> right;
        if(A -> left) A -> left -> up = A;

        B -> right = A;
        B -> up = p;
        A -> up = B;

        if( p )
        {
            if(p->left == A)
                p->left = B; 
            else p->right = B;
        }
    else root = B;
    }
}


// Funkcja oblicza szybko 2^log2 ( x )
// Wartością tej funkcji jest liczba x, 
// w której pozostawiono najstarszy bit 1.
unsigned log2(unsigned x)
{
  unsigned y = 1;
  while((x >>= 1) > 0) y <<= 1;
  return y;
}

// Procedura równoważy drzewo BST
// root - referencja zmiennej zawierającej adres korzenia
void rebalanceDSW(BSTNode * & root)
{
    unsigned n, i, s;
    BSTNode * p;

    n = 0;                          // W n zliczamy węzły
    p = root;                       // Rozpoczynamy tworzenie listy liniowej
    while(p)                      // Dopóki jesteśmy w drzewie
        if(p -> left)                 // Jeśli przetwarzany węzeł ma lewego syna, 
        {
            rot_R(root, p);         // to obracamy wokół niego drzewo w prawo
            p = p -> up;
        }
        else
        {
            n++;                        // Inaczej zwiększamy licznik węzłów
            p = p -> right;               // i przesuwamy się do prawego syna
        }
                                  // Teraz z listy tworzymy drzewo BST
    s = n + 1 - log2(n + 1);     // Wyznaczamy początkową liczbę obrotów

    p = root;                       // Rozpoczynamy od początku drzewa
    for(i = 0; i < s; i++)        // Zadaną liczbę razy
    {
        rot_L(root, p);            // co drugi węzeł obracamy w lewo
        p = p -> up -> right;
    }

    n -= s;                         // Wyznaczamy kolejne liczby obrotów

    while(n > 1)                  // Powtarzamy procedurę obrotów węzłów
    {
        n >>= 1;                      // Jednakże wyznaczając za każdym razem
        p = root;                     // odpowiednio mniejszą liczbę obrotów, która
        for(i = 0; i < n; i++)      // maleje z potęgami 2.
        {
            rot_L(root, p);
            p = p -> up -> right;
        }
    }
}

int main()
{
    int i;
    BSTNode * root = NULL;

// ustawiamy łańcuchy znakowe, ponieważ nie wszystkie edytory pozwalają
// wstawiać znaki konsoli do tworzenia ramek.
// cr = +--
//      |

// cl = |
//      +--

// cp = |
//      |

    cr = cl = cp = "  ";
    cr [0] = 218; cr [1] = 196;
    cl [0] = 192; cl [1] = 196;
    cp [0] = 179;

    srand(time(NULL));    // inicjujemy generator pseudolosowy

    for(i = 0; i < 15; i++)   // Drzewo wypełniamy węzłami
        insertBST(root, 1 + rand() % 50);
        
     printBT("", "", root);   // wyświetlamy drzewo
    std::cout << std::endl << std::endl;
    rebalanceDSW(root);      // Równoważymy drzewo
    printBT("", "", root);   // wyświetlamy drzewo
    std::cout << std::endl << std::endl;
    DFSRelease(root);        // Usuwamy drzewo BST z pamięci
    return 0;
}