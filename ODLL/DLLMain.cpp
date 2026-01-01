#include <iostream>
#include "DLLfunc.cpp"
using namespace std;

int main()
{
   DLL<int> list;
    list.ODLL_INSERT(10);
    list.ODLL_INSERT(5);
    list.ODLL_INSERT(20);

    int val;
    list.RETRIEVE_ODLL_FROMBEG(1, val);
    cout << "Second element = " << val << endl;


    list.ODLL_DELETION(5);
    list.DESTROY_ODLL();
    
    return 0;
}
