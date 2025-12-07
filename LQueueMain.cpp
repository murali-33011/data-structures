#include <iostream>
using namespace std;
#include "LQueueImpl.cpp"

int main(){
	LQueue lq;
	int op;
	int x;
	int count;
	bool flag;
	do
	{
		cout << "1-Enqueue 2-Dequeue 3-Queue Front 4-Empty Queue 5-Queue Count 6-Exit" << endl;
		cin >> op;
		switch (op){
			case 1: cout << "Enter element to insert: ";
					cin >> x;
					flag = lq.enqueue(x);
					if (flag)
						cout << "Element inserted successfully.." << endl;
					break;
			case 2: flag = lq.dequeue(x);
					if (flag)
						cout << "Element dequeued is: " << x << endl;
					else
						cout << "Queue is empty" << endl;
					break;
			case 3: flag = lq.queueFront(x);
					if (flag)
						cout << "Element at front is: " << x << endl;
					else
						cout << "Queue is empty" << endl;
					break;
			case 4: flag = lq.emptyQueue();
					if (flag)
						cout << "Queue is empty"<< endl;
					else
						cout << "Queue is not empty" << endl;
					break;
			case 5: count = lq.queueCount();
					cout << "No. of elements: " << count << endl;
					break;
		}
	}while (op < 6);
	return 0;	
}
