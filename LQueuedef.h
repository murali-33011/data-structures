// changed from .cpp into .h file
#include <iostream>
using namespace std;

struct datanode
{
  int data;
  datanode* link;
};

struct headnode
{
  int count;
  datanode* front;
  datanode* rear;
};

class LQueue
{
  private:
    headnode* Queuehead;
  public:
    LQueue();
		~LQueue();
		bool enqueue(int x);
		int dequeue(int &x);
		bool queueFront(int &x);
		bool emptyQueue();
		int queueCount();
};
