#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

 struct tree_node {

    int key;
    char value;
    struct tree_node *left_child, *right_child, *up;
 } *root;
 
void add_node(struct tree_node **root, int key, char value) {
  
  if(*root==NULL) {
    *root = (struct tree_node *)malloc(sizeof(struct tree_node));
    if(*root) {
      (*root)->key = key;
      (*root)->value = value;
      (*root)->left_child = (*root)->right_child = NULL;
    }
  } else {
    if((*root)->key >= key)
      add_node(&(*root)->left_child,key,value);
    else
      add_node(&(*root)->right_child,key,value);
    }
}

void display_tree(struct tree_node **root) {
  
  if (*root == NULL)
    return;

    display_tree(&(*root)->left_child);
    cout<<"Key: "<<(*root)->key<<", Value: "<<(*root)->value<<endl;
    display_tree(&(*root)->right_child);
}

struct tree_node* find_min(struct tree_node **root) {
  
  struct tree_node *temp = *root;
  while (temp->left_child != NULL) {
        temp = temp->left_child;
  }
  return temp;
}

struct tree_node* find_max(struct tree_node **root) {
  
  struct tree_node *temp = *root;
  while (temp->right_child != NULL) {
        temp = temp->right_child;
  }
  return temp;
}

struct tree_node* del_node(struct tree_node **root, int key) {

  if (*root == NULL)
    return NULL;
  else if((*root)->key > key)
    (*root)->left_child = del_node(&(*root)->left_child,key);
  else if((*root)->key < key)
    (*root)->right_child = del_node(&(*root)->right_child,key);
  else {
    if ((*root)->left_child == NULL && (*root)->right_child == NULL) {
      delete *root;
      *root = NULL;
    } else if ((*root)->left_child == NULL) {
      struct tree_node *temp = *root;
      *root = (*root)->right_child;
      delete temp;
    } else if ((*root)->right_child == NULL) {
      struct tree_node *temp = *root;
      *root = (*root)->left_child;
      delete temp;
    } else {
      struct tree_node *temp = find_min(&(*root)->right_child);
      (*root)->key = temp->key;
      (*root)->right_child = del_node(&(*root)->right_child, temp->key);
    }
  }
  return *root;
}

int main() {
  
    struct tree_node *root = NULL;

    display_tree(&root);

    add_node(&root, 1, 'A');
    add_node(&root, 7, 'G');
    add_node(&root, 3, 'Z');
    add_node(&root, 5, 'K');
    add_node(&root, 2, 'Q');
    add_node(&root, 8, 'C');
  
    display_tree(&root);
    cout<<"-----------"<<endl;
  
    del_node(&root, 7);

    display_tree(&root);
    cout<<"-----------"<<endl;
    
    del_node(&root, 1);

    display_tree(&root);
    
    return 0;
}