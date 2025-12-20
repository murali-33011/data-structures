#include <iostream>
#include "GraphFunc.cpp"
using namespace std;

int main()
{
  Graph G;
  cout<<"Creating graph : ";
  G.createGraph();
  cout<<"Printing Graph : ";
  G.printGraph();
  cout<<"BFS";
  int a;
  cout<<"bfs search element : ";
  cin>>a;
  G.BFS(a);
  
  G.DFS();
  G.printGraph();
}
