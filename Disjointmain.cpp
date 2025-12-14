#include <iostream>
#include "Disjointfunc.cpp"
using namespace std;

int main()
{
  Disjointset ds;
  int choice,x,y;
  
  cout << "===== DISJOINT SET OPERATIONS =====\n";
    
    do {
        cout << "\n1. MAKE_SET (Create new set)\n";
        cout << "2. UNION (Merge two sets)\n"; 
        cout << "3. FIND_SET (Find representative)\n";
        cout << "4. DISPLAY (Show all sets)\n";
        cout << "5. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter element to create set: ";
                cin >> x;
                ds.Makeset(x);
                break;
                
            case 2:
                cout << "Enter two elements to union: ";
                cin >> x >> y;
                ds.Union(x, y);
                break;
                
            case 3:
                cout << "Enter element to find: ";
                cin >> x;
                {
                    node* result = ds.Findset(x);
                    if(result != nullptr)
                        cout << "Representative: " << result->data << endl;
                    else
                        cout << "Element not found!\n";
                }
                break;
                
            case 4:
                ds.Display();
                break;
                
            case 5:
                cout << "Exiting...\n";
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 5);

    return 0;
}
