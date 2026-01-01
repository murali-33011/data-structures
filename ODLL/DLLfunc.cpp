#include <iostream>
#include "DLLDef.cpp"
using namespace std;

template<class T>
DLL<T> :: DLL()
{
  dllhead = new headnode<T>();
  dllhead->count = 0;
  dllhead->first = dllhead->last = NULL;
}

template<class T>
DLL<T> :: ~DLL()
{
  DESTROY_ODLL();
}

template<class T>
bool DLL<T> :: ODLL_INSERT(T x)
{
  datanode<T>* t = new datanode<T>();
  t->data = x;
  t->pred = t->succ = NULL;
  
  if(dllhead->first == NULL)
  {
    dllhead->first = t;
    dllhead ->last = t;
  }
  else
  {
    datanode<T>* cur = dllhead->first;
    while (cur != NULL and cur->data<x)
    {
      cur = cur->succ;
    }
    if (cur == NULL) //at end
    {
      t->pred = dllhead->last;
      dllhead->last->succ = t;
      dllhead->last = t;
    }
    else if(cur->pred == NULL) //insert before first element
    {
      t->succ = cur;
      t->pred = cur->pred;
      dllhead->first = t;
      
    }
    else//insert in between
    {
      t->succ = cur;
      t->pred = cur->pred;
      cur->pred->succ = t;
      cur->pred = t;
    }
    
  }
  dllhead->count++;
  return true;
}

template<class T>
bool DLL<T> :: ODLL_DELETION(T x)
{
  if(dllhead->first = NULL)
  {
    return false;
  }
  datanode<T>* cur = dllhead->first;
  while (cur != NULL and cur->data<x)
  {
    cur = cur->succ;
  }
  if (cur == NULL || cur->data>x)
  {
    return false;
  }
  else
  {
    if (cur->pred==NULL) //first element
    {
      dllhead->first = cur->succ;
    }
    else if(cur->succ == NULL) //last element
    {
      dllhead->last = cur->pred;
    }
    else //inbetween
    {
      cur->pred->succ = cur->succ;
    }
  }
  dllhead->count--;
  delete cur;
  return true;
}

template<class T>
bool DLL<T> :: ODLL_SEARCH(T x, int & pos)
{
  if(dllhead->first == NULL)
  {
    return false;
  }
  datanode<T>* cur = dllhead->first;
  pos = 1;
  while (cur != NULL)
  {
    if(cur->data == x)
    {
      return true;
    }
    else
    {
	pos++;
	cur = cur->succ;
    }
  }
}

template<class T>
bool DLL<T> :: RETRIEVE_ODLL_FROMBEG(int pos,T &x)
{
  if (dllhead->count<pos)
  {
    return false;
  }
  int c = 1;
  datanode<T>* cur = dllhead->first;
  while( cur!= NULL and c<pos)
  {
    cur = cur->succ;
    c++;
  }
  if (cur == NULL)
  {
    return false;
  }
  else
  {
    x = cur->data;
    return true;
  }
}


template<class T>
bool DLL<T> :: DESTROY_ODLL()
{
  datanode<T>* cur = dllhead->first;
  while( cur != NULL )
  {
    datanode<T>* p = cur->succ;
    delete p;
    p = cur;
  }
  dllhead->first = dllhead->last = NULL;
  dllhead->count = 0;
  return true;
}
