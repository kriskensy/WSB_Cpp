#include <iostream>

class BTNode
{
    public:
        BTNode * left;
        BTNode * right;
        char data;
};

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

// Rekurencyjna funkcja preorder

void preorder(BTNode * v)
{
    if(v)
    {
        std::cout << v -> data << " "; // odwiedzamy węzeł
        preorder(v -> left);      // przechodzimy lewe poddrzewo
        preorder(v -> right);     // przechodzimy prawe poddrzewo
    }
}

int main( )
{
    preorder(&A);  // przejście rozpoczynamy od korzenia
    std::cout << std::endl;
    return 0;
}