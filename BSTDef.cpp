#include <iostream>
using namespace std;

struct node
{
  node* left;
  int data;
  node* right;
};


node* create(int d);
node* insert(node* root, int d);
bool search(node* root, int d);
node* inordersucc(node* root);
node* deletenode(node* root, int d);
void preorder(node* root);
void inorder(node* root);
void postorder(node* root);

