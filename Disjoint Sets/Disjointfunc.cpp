#include <iostream>
#include "Disjointdef.cpp"
using namespace std;

Disjointset :: Disjointset()
{
  ne = 0;
  for(int i = 0 ; i < 50 ; i++)
  {
    element[i] = nullptr;
  }
}

void Disjointset :: Makeset(int x)
{
  for(int i = 0 ; i < ne ;i++)
  {
    if(x == element[i]->data)
    {
      cout<<"element "<<x<<" is duplicate";
      return;
    }
  }

  node* n = new node();
  n->data = x;
  n->parent = n;
  n->rank = 0;
  element[ne] = n;
  ne++;
}

node* Disjointset :: Findset(int x)
{
  for(int i = 0 ; i<ne ;i++)
  {
    if(element[i]->data == x)
    {
      return Findset(element[i]);
    }
  }
  cout<<"element not found"<<endl;
  return nullptr;
}

node* Disjointset :: Findset(node* x)
{
  if ( x != x->parent)
  {x->parent = Findset(x->parent);}
  return x->parent;
}

void Disjointset :: Link(node* u, node* v)
{
  if(u->rank > v->rank)
  {
    v->parent = u;
  }
  else
  {
    u->parent = v;
    if(u->rank == v->rank)
    {
      v->rank++;
    }
  }
}

void Disjointset :: Union(int x, int y)
{
  node* u = Findset(x);
  node* v = Findset(y);
  
  if(u == nullptr || v == nullptr)
  {
    cout<<"Both are not found";
    return;
  }
  if( u==v)
  {
    cout<<"both are in same set";
    return;
  }
  Link(u,v);
  cout<<"union done.";
}

void Disjointset :: Display()
{
  for(int i = 0 ; i<ne ; i++)
  {
    cout<<"data : "<<element[i]->data<<"\t"<<"parent : "<<element[i]->parent->data<<endl;
  }
}
    
  
