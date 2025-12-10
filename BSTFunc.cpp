#include <iostream>
#include "BSTDef.cpp"
using namespace std;

node* create(int d)
{
  node* n = new node();
  n->data = d;
  n->left = n->right = NULL;
  return n;
}

node* insert(node* root, int d)
{
  if(root==NULL)
  {
    return create(d);
  }
  else
  {
    if(root->data>d)
    {
      root->left = insert(root->left,d);
    }
    else
    { 
      root->right = insert(root->right,d);
    }
    return root;
  }
}

bool search(node* root, int d)
{
  if(root==NULL)
  {return false;}
  else if(root->data == d)
  {
    return true;
  }
  else if(root->data > d)
  {
    return search(root->left,d);
  }
  else
  {
    return search(root->right,d);
  }
}

node* inordersucc(node* root)
{
  node* temp = root->right;
  while(temp->left != NULL)
  {
    temp = temp->left;
  }
  return temp;
}

node* deletenode(node* root, int d)
{
  if (root == NULL)
  {
    return root;
  }
  if (root->data>d)
  {
    root->left = deletenode(root->left,d);
  }
  else if(root->data < d)
  {
    root->right = deletenode(root->right,d);
  }
  else
  {
    if(root->left == NULL)
    { 
      node* temp = root->right;
      delete root;
      return temp;
    }
    else if(root->right == NULL)
    {
      node* temp = root->left;
      delete root;
      return temp;
    }
    else
    {
      node* temp = inordersucc(root);
      root->data= temp->data;
      root->right = deletenode(root->right,temp->data);
    }
  }
  return root;
}

void preorder(node* root)
{ 
  if(root!=NULL)
  {
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(node* root)
{ 
  if(root != NULL)
  {
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
  }
}

void postorder(node* root)
{
  if(root != NULL)
  {
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
  }
}

