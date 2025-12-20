#include <iostream>
using namespace std;

enum vcolor {WHITE,GRAY,BLACK};

struct node
{
  int ver;
  node* next;
};

struct vnode
{
  string name;
  int d;
  int pi;
  int f;
  vcolor color;
  node* adj;
};

template<class T> struct datanode
{
  T data;
  datanode<T> *next;
};

template <class T> struct headnode
{
  int count;
  datanode<T> *front, *rear;
};

template<class T> class Queue
{
  private:
    headnode<T>* Qhead;
  public:
    Queue();
    ~Queue();
    bool enqueue(T x);
    bool dequeue(T &x);
    bool emptyQueue();
};

class Graph
{
  private:
    vnode** V;
    int n;
    int time;
  public:
    void createGraph();
    void printGraph();
    void BFS(int v);
    void DFS();
    void DFS_visit(int u);
    void printPath(int s,int v);
};
  

