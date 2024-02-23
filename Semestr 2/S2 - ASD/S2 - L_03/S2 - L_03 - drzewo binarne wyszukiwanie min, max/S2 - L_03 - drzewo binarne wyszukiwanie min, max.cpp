#include <iostream>

class Node
{
    public:
        int data;
        Node *left, *right;

        Node(int data)
        {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

int findMaxNode(Node* root)
{
    if (root == NULL)
        return -100;

    int maxVal = root -> data;
    int leftMaxVal = findMaxNode(root -> left);
    int rightMaxVal = findMaxNode(root -> right);
    if (leftMaxVal > maxVal)
        maxVal = leftMaxVal;
    if (rightMaxVal > maxVal)
        maxVal = rightMaxVal;
    return maxVal;
}

int findMinNode(Node* root)
{
    if (root == NULL)
        return 100;

    int minVal = root -> data;
    int leftMinVal = findMinNode(root -> left);
    int rightMinVal = findMinNode(root -> right);
    if (leftMinVal < minVal)
        minVal = leftMinVal;
    if (rightMinVal < minVal)
        minVal = rightMinVal;
    return minVal;
}

int main()
{
   Node* NewRoot = NULL;
   Node* root = new Node(5);
   root -> left = new Node(3);
   root -> right = new Node(2);
   root -> left -> left = new Node(1);
   root -> left -> right = new Node(8);
   root -> right -> left = new Node(11);
   root -> right -> right = new Node(9);
   std::cout << "The Maximum element of Binary Tree is " << findMaxNode(root) << std::endl;
   std::cout << "The Minimum element of Binary Tree is " << findMinNode(root) << std::endl;
   return 0;
}