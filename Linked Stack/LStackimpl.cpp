#include "LStackdef.cpp"
#include <iostream>
using namespace std;

LStack :: LStack()
{
	Stackhead->count = 0;
	Stackhead->top = NULL;
}

bool LStack :: pushStack(int x)
{
	datanode* t = new datanode();
	t->data = x;
	t->link = Stackhead->top;
	Stackhead->top = t;
	Stackhead->count++;
	return true;
}

bool LStack :: popStack(int x)
{
	if(emptyStack())
	{
		return false;
	}
	else
	{
		datanode* t = Stackhead->top;
		x = t->data;
		Stackhead->top = t->link;
		delete t;
		Stackhead->count--;
		return true;
	}
}

bool LStack :: stackTop(T &x)
{
	if(emptyStack())
	{
		return false;
	}
	else
	{
		x = Stackhead->top->data;
		return true;
	}
}

bool LStack :: emptyStack()
{
	if(Stackhead->count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool LStack :: stackCount()
{
	return Stackhead->count;
}
	
	
