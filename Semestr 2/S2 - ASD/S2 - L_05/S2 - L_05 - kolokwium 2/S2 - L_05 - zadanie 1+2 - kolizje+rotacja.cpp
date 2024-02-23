/*
Rotacja drzewa to operacja na drzewie BST, która zmienia jego strukturę bez zmiany kolejności elementów, tzn. przejście in-order dla tego drzewa da takie same wyniki przed jak i po rotacji. Istnieją dwie symetryczne rotacje: prawa i lewa.
Dla przykładowego drzewa:

A – korzeń drzewa
B – lewy syn A, który zajmie miejsce A. Nazywamy go piwotem.
BL, BR – lewy i prawy syn B
AR – prawy syn A
Po wykonaniu rotacji w prawo B zajmuje miejsce A, a A staje się prawym synem B. Dodatkowo przemieszcza się również węzeł BR, czyli prawy syn B. Staje się on lewym synem A.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class BSTNode
{
    public:
    BSTNode * up, * left, * right;
    int key;
};

std::string cr, cl, cp;  // łańcuchy do znaków ramek

void printBT(std::string sp, std::string sn, BSTNode * v)
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
        if(sn == cl) s[s.length() - 2] = ' ';
        printBT(s + cp, cl, v -> left);
    }
}

void insertBST(BSTNode * & root, int k)
{
    BSTNode * w, * p;
    w = new BSTNode;
    w -> left = w -> right = NULL;
    w -> key = k;
    p = root;
    if(!p)
        root = w;
    else
        while(true)
            if(k < p -> key)
            {
                if(!p->left)
                {
                    p -> left = w;
                    break;
                }
                else p = p -> left;
            }
            else
            {
                if(!p->right)
                {
                    p -> right = w;
                    break;
                }
                else p = p -> right;
            }

    w -> up  = p;
}

// Rotacja w prawo
void rot_R(BSTNode * & root, BSTNode * A)
{
    BSTNode * B = A -> left, * p = A -> up;

    if(B)
    {
        A -> left = B -> right;
        if(A -> left) A -> left -> up = A;

        B -> right = A;
        B -> up = p;
        A -> up = B;

        if(p)
        {
            if(p -> left == A) p -> left = B;
            else p -> right = B;
        }
        else root = B;
    }
}

int main()
{
    int i;
    BSTNode * root = NULL;

    cr = cl = cp = "  ";
    cr [0] = 218; cr [1] = 196;
    cl [0] = 192; cl [1] = 196;
    cp [0] = 179;
    srand (time(NULL));

    for(i = 0; i < 15; i++)
        insertBST(root, 10 + rand() % 90);

    printBT("", "", root);
    std::cout << std::endl << std::endl;

    if(root->right)
        rot_R(root, root->right);

    printBT("", "", root);
    std::cout << std::endl << std::endl;
    return 0;
}