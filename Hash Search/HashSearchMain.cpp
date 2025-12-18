#include <iostream>
#include "HashSearchFun.cpp"
using namespace std;

int main()
{
	int n;
	cout<<"Enter size of hash Table: ";
	cin>>n;
	HashTbl<int> H(n);
	int c,x,loc;
	do
	{
	
		cout<<"Operations: 1. Insert 2. Search 3. Display 4. Exit\n";
		cin>>c;
		switch(c)
		{
			case 1:
				cout<<"Enter element to insert: ";
				cin>>x;
				if(H.insertToHashTbl(x,loc))
					cout<<"Element inserted at "<<loc<<endl;
				break;
			
			case 2:
				cout<<"Enter element to search: ";
				cin>>x;
				if(H.searchInHashTbl(x,loc))
					cout<<"Element found at "<<loc<<endl;
				else
					cout<<"Element not found!\n";
				break;
				
			case 3:
				H.display();
				break;
			
			case 4:
				cout<<"Exiting....\n";
				break;
			
			default:
				cout<<"Invlid Choice! Re-Enter choice.\n";
		}
	}while(c!=4);
	return 0;
}	
