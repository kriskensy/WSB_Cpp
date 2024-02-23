#include <iostream>

class BinaryTree
{
public:
    BinaryTree() //konstruktor
    {
        root = NULL;
        std::cout << "BT creating" << std::endl;
    }

    ~BinaryTree() // destruktor
    {
        std::cout << "BT destroying" << std::endl;
    }

    void addToTree(int Value) //dodawanie węzła
    {
        root = addToTree(Value, root);
    }

    void remove(int Value) //usuwanie węzła
    {
        root = remove(Value, root);
    }

    void display() // wyświetlanie
    {
        display(root); //wywołanie funkcji ze struktury
        std::cout << std::endl;
    }

private:
    struct Node //tutaj struktura
    {
        int data;
        Node* leftChild;
        Node* rightChild;
    };
    Node* root;

    Node* addToTree(int Value, Node* ptr)
    {
        if(ptr == NULL)
        {
            ptr = new Node;
            ptr -> data = Value;
            ptr -> leftChild = ptr -> rightChild = NULL;
        }
        else if(Value < ptr -> data)
            ptr -> leftChild = addToTree(Value, ptr -> leftChild);
        else if(Value > ptr -> data)
            ptr -> rightChild = addToTree(Value, ptr -> rightChild);
        return ptr;
    }

    Node* findMin(Node* ptr)
    {
        if(ptr == NULL)
            return NULL;
        else if(ptr -> leftChild == NULL)
            return ptr;
        else
            return findMin(ptr -> leftChild);
    }

    Node* remove(int Value, Node* ptr)
    {
        Node* temp;
        if(ptr == NULL)
            return NULL;
        else if(Value < ptr -> data)
            ptr -> leftChild = remove(Value, ptr -> leftChild);
        else if(Value > ptr -> data)
            ptr -> rightChild = remove(Value, ptr -> rightChild);
        else if(ptr -> leftChild && ptr -> rightChild)
        {
            temp = findMin(ptr -> rightChild);
            ptr -> data = temp -> data;
            ptr -> rightChild = remove(ptr -> data, ptr -> rightChild);
        }
        else
        {
            temp = ptr;
            if(ptr -> leftChild == NULL)
                ptr = ptr -> rightChild;
            else if(ptr -> rightChild == NULL)
                ptr = ptr -> leftChild;
            delete temp;
        }
        return ptr;
    }

    void display(Node* ptr)
    {
        if(ptr != NULL)
        {
        display(ptr -> leftChild);
        std::cout << ptr -> data << " ";
        display(ptr -> rightChild);
        }
        else
        return;
    }
};

int main()
{
    BinaryTree BT;

    BT.addToTree(20);
    BT.addToTree(25);
    BT.addToTree(15);
    BT.addToTree(10);
    BT.addToTree(30);
    BT.addToTree(67);
    BT.addToTree(6);
    BT.addToTree(99);
    BT.display();

    BT.remove(20);
    BT.display();

    BT.remove(25);
    BT.display();

    BT.remove(30);
    BT.display();
}