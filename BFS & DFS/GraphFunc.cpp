#include <iostream>
#include "GraphDef.cpp"
#include <limits.h>
using namespace std;

template<class T> Queue<T> :: Queue()
{
  Qhead = new headnode<T>();
  Qhead->count = 0;
  Qhead->front = Qhead->rear = NULL;
}

template<class T> Queue<T> :: ~Queue()
{
  while(Qhead->front != NULL)
  {
    datanode<T>* t = Qhead->front;
    Qhead->front = t->next;
    delete t;
  }
  delete Qhead;
}

template<class T> 
bool Queue<T> :: enqueue(T x)
{
  datanode<T>* t = new datanode<T>();
  t->data = x;
  t->next = NULL;
  
  if ( Qhead->rear == NULL) //IF ENTERING THE FIRST ELEMENT
  {
    Qhead->front = Qhead->rear = t;
  }
  else // CONSECUTIVE ELEMENTS
  {
    Qhead->rear->next = t;
    Qhead->rear = t;
  }
  Qhead->count++;
  return true;
}

template<class T> 
bool Queue<T> :: dequeue(T &x)
{
  if(Qhead->count == 0) //CAN NOT DEQUEUE EMPTY QUEUE
  {
    return false;
  }
  datanode<T>* t = Qhead->front; //Assigning "t" to the 'front' element [to pop next]
  x = t->data;
  Qhead->front = t->next; // re assigning queue's next front
  delete t;
  
  if(Qhead->front == NULL)
  {
    Qhead->rear = NULL;
  }
  Qhead->count--;
  return true;
}

template<class T> bool Queue<T> :: emptyQueue()
{
  return (Qhead->count == 0);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graph :: createGraph()
{
  cout<<"Enter no. of vertices";
  cin>>n;
  
  int m; 
  V = new vnode*[n]; //initializing n vertices of type vnode - [NOTE * = 'V' already defined in GraphDef.cpp]
  for( int i = 0 ; i < n ; i++)
  {
    V[i] = new vnode();
    cout<<"Enter node name : ";
    cin>>V[i]->name;
       
    cout<<"Enter no. of Adjacent nodes : ";
    cin>>m;

    V[i]->adj = NULL; //initially declaring adj as NULL for given vertex
    
    for ( int j=0; j<m;j++) //later if adj exists - traverse and assign index for each adj respectively.
    {
      node* t = new node();
      cout<<"Enter adj vertex index for "<<(j+1)<<" : ";
      cin>>t->ver;
      t->next = V[i]->adj;
      V[i]->adj = t;
    }
  }
}

void Graph :: BFS(int s)
{
  for ( int i = 0; i<n ; i++)
  {
    V[i]->d = INT_MAX;
    V[i]->color = WHITE;
    V[i]->pi = -1;
  }
  
  V[s]->color = GRAY;
  V[s]-> d = 0;
  V[s]->pi = -1;
  
  Queue<int> Q;
  Q.enqueue(s);
  
  while(!Q.emptyQueue())
  {
    int u;
    Q.dequeue(u);
    cout<<V[u]->name<<" ";
  
    node* temp = V[u]->adj;
    while(temp != NULL)
    {
      int v = temp->ver;
      if(V[v]->color == WHITE)
      {
        V[v]->color = GRAY;
        V[v]->d = V[u]->d  + 1;
        V[v]->pi = u;
        Q.enqueue(v);
      }
      temp = temp->next;
    } 
    V[u]->color = BLACK;
  }
  cout<<endl;

}

void Graph :: printPath(int s, int v)
{
  if (s == v)
  {
    cout<<V[s]->name<<" ";
  }
  else if (V[v]->pi == -1)
  {
    cout<<"NO PATH FROM "<<V[s]->name<<" TO "<<V[v]->name<<endl;
  }
  else
  {
    printPath(s, V[v]->pi);
    cout<< V[v]->name << " ";
  }
}

void Graph :: DFS()
{
  time = 0;
  for (int i = 0; i<n ; i++)
  {
    V[i]->color = WHITE;
    V[i]->pi = -1;

    for (int j = 0 ; j < n ; j++)
    {
      if(V[j]->color == WHITE)
      {
        DFS_visit(j);
      }
    }
  }
}
  
void Graph :: DFS_visit(int u)
{
  time = time + 1;
  V[u]->color = GRAY;
  V[u]->d = time;
  
  node* temp = V[u]->adj;
  while(temp != NULL)
  {
    int k = temp->ver;
    if (V[k]->color == WHITE)
    {
      V[k]->pi = u;
      DFS_visit(k);
    }
    
    temp = temp ->next;
  }
  
  V[u]->color = BLACK;
  time++;
  V[u]->f = time;
}




void Graph::printGraph()
{
    for(int i=0;i<n;i++)
    {
        cout<<V[i]->name<<" "<<V[i]->d<<" "<<V[i]->color<<" "<<V[i]->pi<<" "<<V[i]->f<<" ADJ: ";
        for(node* n = V[i]->adj;n!= NULL;n = n->next)
        {
            cout<<n->ver<<" "; 
        }
        cout<<endl;
    }
}




