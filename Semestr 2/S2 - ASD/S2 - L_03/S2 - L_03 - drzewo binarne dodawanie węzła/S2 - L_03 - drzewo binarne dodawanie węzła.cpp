#include <iostream>
#include <stdlib.h>

class treeNode
{
    public:
        int key;
        char value;
        treeNode *leftChild, *rightChild, *parent;
} *root;

void add_node(int val)
{
//tworzymy wskazniki wskazujace na aktualnie rozpatrywany wezel i nowy wezel
    class treeNode * now = root;
    class treeNode * addedNode = new treeNode;

//Przypisujemy wartosci do wezla
    addedNode -> key = val;
    addedNode -> leftChild = NULL;
    addedNode -> rightChild = NULL;

//Jesli korzen ma wartosc null, nowy wezel staje sie korzeniem
    if(root == NULL)
    {
    addedNode -> parent = NULL;
    root = addedNode;
    return;
    }
    else
    {
        while(now != NULL)
        {
//wartosc nowego wezla jest wieksza badz rowna od wskazywanego
            if(now -> key <= addedNode -> key)
            {
//jesli po prawej jest wolne miejsce dodajemy w nie wezel
                if(now -> rightChild == NULL)
                {
                    addedNode -> parent = now;
                    now -> rightChild = addedNode;
                    return;
                }
//w innym przypadku przechodzimy w glab drzewa
                else
                {
                    now = now -> rightChild;
                }
            }
//wartosc nowego wezla jest mniejsza od wskazywanego
            if (now -> key > addedNode -> key)
            {
//jesli po lewej jest wolne miejsce dodajemy w nie wezel
                if (now -> leftChild == NULL)
                {
                    addedNode -> parent = now;
                    now -> leftChild = addedNode;
                    return;
                }
//w innym przypadku przechodzimy w glab drzewa
                else
                {
                    now = now -> leftChild;
                }
            }
        }
    }
}

//metoda rekurencyjna
// void add_node(class treeNode **root, int key, char value)
// {
//     if(*root==NULL)
//     {
//         *root = (class treeNode *)
//             malloc(sizeof(class treeNode));
//         if(*root) 
//         {
//             (*root)->key = key;
//             (*root)->value = value;
//             (*root)->leftChild = (*root)->rightChild = NULL;
//         }
//     }   
//     else 
//     {
//         if((*root)->key >= key)
//             add_node(&(*root)->leftChild,key,value);
//         else
//         add_node(&(*root)->rightChild,key,value);
//     }
// }

int main()
{
    treeNode T1();
    add_node(5);
}