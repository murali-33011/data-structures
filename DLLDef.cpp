#include <iostream>
using namespace std;

template<class T>
struct datanode
{
  datanode<T>* pred;
  T data;
  datanode<T>* succ;
};

template<class T>
struct headnode
{
  int count;
  datanode<T>* first;
  datanode<T>* last;
};

template<class T>
class DLL
{
  private:
    headnode<T>* dllhead;
  public:
    DLL();
    ~DLL();
    
    bool ODLL_INSERT(T x);
    bool ODLL_DELETION(T x);
    bool ODLL_SEARCH(T x,int &c); //return position(c) for given data element (x)
    bool RETRIEVE_ODLL_FROMBEG(int position,T &x); //return element present(x) in DLL for given position
    bool DESTROY_ODLL();
};


    
