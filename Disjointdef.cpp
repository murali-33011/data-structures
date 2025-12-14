#include <iostream>
using namespace std;


struct node
{ 
  int data;
  int rank;
  node* parent;
};

class Disjointset
{
  private:
    node* element[50];
    int ne;
  public:
    Disjointset();
    void Makeset(int x);
    node* Findset(int x);
    node* Findset(node* x);
    void Union(int x, int y);
    void Link(node* u, node* v);
    void Display();
};


