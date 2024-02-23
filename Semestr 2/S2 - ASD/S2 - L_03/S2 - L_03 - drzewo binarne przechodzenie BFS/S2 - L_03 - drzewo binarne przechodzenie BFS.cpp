#include <iostream>

class BTNode
{
    public:
        BTNode * left;
        BTNode * right;
        char data;
};

//Definicja typu obiektowego queue
class queue
{
    public:
        queue (int x)
        : n(x)
        {
            n = x;
            Q = new BTNode * [x]; // tworzymy tablicę x wskazań węzłów
            qptr = qcnt = 0;
        }
        ~queue()
        {
            delete[]Q;
        }

        bool empty(void);//Sprawdza, czy kolejka jest pusta
        BTNode* front(void);//Zwraca początek kolejki.
        void push (BTNode* v);//dodaje do kolejki
        void pop(void);//Usuwa z kolejki

    private:
        int n;           // rozmiar tablicy
        int qptr;        // wskaźnik początku kolejki
        int qcnt;        // licznik elementów
        BTNode * * Q; // tablica dynamiczna wskazań węzłów
};

bool queue::empty(void)
{
  return !qcnt;
}

BTNode * queue::front(void)
{
  if(qcnt) return Q [qptr];
  return NULL;
}

void queue::push(BTNode * v)
{
  int i;
  if(qcnt < n)
  {
    i = qptr + qcnt++;
    if(i >= n) i -= n;
    Q [i] = v;
  }
}

void queue::pop(void)
{
  if(qcnt)
  {
    qcnt--;
    qptr++;
    if(qptr == n) qptr = 0;
  }
}

// Tworzenie struktury drzewa rozpoczynamy od liści

BTNode G = {NULL, NULL, 'G'};
BTNode H = {NULL, NULL, 'H'};
BTNode I = {NULL, NULL, 'I'};
BTNode J = {NULL, NULL, 'J'};
BTNode K = {NULL, NULL, 'K'};

// Tworzymy kolejnych ojców

BTNode D = { &H,  &I, 'D'};
BTNode E = { &J, NULL, 'E'};
BTNode F = { &K, NULL, 'F'};
BTNode B = { &D,  &E, 'B'};
BTNode C = { &F,  &G, 'C'};

// Tworzymy korzeń drzewa

BTNode A = { &B,  &C, 'A'};

int main( )
{
    queue Q(8);       //rozmiar kolejki równy 2^3, gdzie 3 jest wysokością drzewa
    BTNode* v;    //wskazanie węzła
    Q.push(&A);       //w kolejce umieszczamy wskazanie węzła A

    while(!Q.empty())
    {
        v = Q.front();  //pobieramy element z kolejki
        Q.pop();        //pobrany element usuwamy z kolejki
        std::cout << v -> data << " "; //odwiedzamy węzeł

// w kolejce umieszczamy synów węzła wskazywanego przez v
        if(v -> left) Q.push(v -> left);  //lewy syn
        if(v -> right) Q.push(v -> right); //prawy syn
  }
    std::cout << std::endl;
    return 0;
}