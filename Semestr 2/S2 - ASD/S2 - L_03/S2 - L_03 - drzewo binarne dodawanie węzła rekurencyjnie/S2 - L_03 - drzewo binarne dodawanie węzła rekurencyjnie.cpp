#include <stdio.h>
#include <stdlib.h> //malloc

class treeNode
{
    public:
        int key;
        char value;
        treeNode *leftChild, *rightChild, *parent;
 } *root;

void addNode(class treeNode **root, int key, char value)
{
    if(*root==NULL)
    {
        *root = (class treeNode *)
            malloc(sizeof(class treeNode));
        if(*root) 
        {
            (*root)->key = key;
            (*root)->value = value;
            (*root)->leftChild = (*root)->rightChild = NULL;
        }
    }
    else 
    {
        if((*root)->key >= key)
            addNode(&(*root)->leftChild,key,value);
        else
        addNode(&(*root)->rightChild,key,value);
    }
}

int main()
{
    return 0;
}