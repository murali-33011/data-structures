#include <iostream>
using namespace std;&
struct datanode
{
  int data;
  datanode* link;
};

struct headnode
{
  int count;
  datanode* top;
};

class LStack
{
  private:
    headnode* Stackhead;
  public:
    LStack();
    bool pushStack(int x);
    bool popStack(int &x);
    bool stackTop(int &x);
    bool emptyStack();
    int stackCount();
 };
 
