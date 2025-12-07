#include "LQueuedef.cpp"
#include <iostream>
using namespace std;

LQueue :: LQueue()
{
  Queuehead = new headnode();
  Queuehead->count = 0;
  Queuehead->front = Queuehead->rear = NULL;
}

bool LQueue :: enqueue( int x)
{
  datanode* t = new datanode();
  t->data = x;
  t->link = NULL;
  
  if(emptyQueue())
  {
    Queuehead->front = t;
    Queuehead->rear = t;
  }
  else
  {
    Queuehead->rear->link = t;
    Queuehead->rear = t;
  }
  Queuehead->count++;
  return true;
}

bool LQueue :: dequeue(int &x)
{
  if(emptyQueue())
  {
    return false;
  }
  else
  {
    datanode* t= Queuehead->front;
    x = t->data;
    Queuehead->front = t->link;
    
    if(Queuehead->front == NULL)
    {
      Queuehead->rear = NULL;
    }
    delete t;
    Queuehead->count--;
    return true;
  }
}

bool LQueue :: queueFront(int &x)
{
  if(emptyQueue())
  {
    return false;
  }
  else
  {
    x = Queuehead->front->data;
    return (Queuehead->front->data);
  }
}

bool LQueue::emptyQueue(){
	if (Queuehead->count == 0)
	    return true;
	else
		return false;
}

int LQueue::queueCount(){
	return Queuehead->count;
}
