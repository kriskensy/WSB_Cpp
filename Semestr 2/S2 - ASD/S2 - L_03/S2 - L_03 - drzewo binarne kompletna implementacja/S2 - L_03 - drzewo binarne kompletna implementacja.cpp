#include <iostream>

class BinaryTree
{
public:
    BinaryTree()
    {
        root = NULL;
    }

    ~BinaryTree()
    {
        root = makeEmpty(root);
    }

    void insert(int x)
    {
        root = insert(x, root);
    }

    void remove(int x)
    {
        root = remove(x, root);
    }

    void display()
    {
        inorder(root);
        std::cout << std::endl;
    }

    void search(int x)
    {
        root = find(root, x);
    }

private:
    struct Node
    {
        int data;
        Node* leftChild;
        Node* rightChild;
    };
    Node* root;

    Node* makeEmpty(Node* t)
    {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t -> leftChild);
            makeEmpty(t -> rightChild);
            delete t;
        }
        return NULL;
    }

    Node* insert(int x, Node* t)
    {
        if(t == NULL)
        {
            t = new Node;
            t -> data = x;
            t -> leftChild = t -> rightChild = NULL;
        }
        else if(x < t -> data)
            t -> leftChild = insert(x, t -> leftChild);
        else if(x > t -> data)
            t -> rightChild = insert(x, t -> rightChild);
        return t;
    }

    Node* findMin(Node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t -> leftChild == NULL)
            return t;
        else
            return findMin(t -> leftChild);
    }

    Node* findMax(Node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t -> rightChild == NULL)
            return t;
        else
            return findMax(t -> rightChild);
    }

    Node* remove(int x, Node* t)
    {
        Node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t -> data)
            t -> leftChild = remove(x, t -> leftChild);
        else if(x > t -> data)
            t -> rightChild = remove(x, t -> rightChild);
        else if(t -> leftChild && t -> rightChild)
        {
            temp = findMin(t -> rightChild);
            t -> data = temp -> data;
            t -> rightChild = remove(t -> data, t -> rightChild);
        }
        else
        {
            temp = t;
            if(t -> leftChild == NULL)
                t = t -> rightChild;
            else if(t -> rightChild == NULL)
                t = t -> leftChild;
            delete temp;
        }
        return t;
    }

    void inorder(Node* t)
    {
        if(t == NULL)
            return;
        inorder(t -> leftChild);
        std::cout << t -> data << " ";
        inorder(t -> rightChild);
    }

    Node* find(Node* t, int x)
    {
        if(t == NULL)
            return NULL;
        else if(x < t -> data)
            return find(t -> leftChild, x);
        else if(x > t -> data)
            return find(t -> rightChild, x);
        else
            return t;
    }
};

int main(int argc, char* argv[])
{
    BinaryTree BT;
    BT.insert(20);
    BT.insert(25);
    BT.insert(15);
    BT.insert(10);
    BT.insert(30);
    BT.display();
    BT.remove(20);
    BT.display();
    BT.remove(25);
    BT.display();
    BT.remove(30);
    BT.display();
}