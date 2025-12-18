#include<iostream>
using namespace std;
bool SequentialSearch(int list[],int last,int target,int &locn)
{
int i=0;
while(i<last && target != list[i])
{
i++;
}
locn=i;
if(target==list[i])
return true;
else 
return false;
}

bool ProbabilitySearch(int list[],int last,int target,int &locn)
{
bool found=SequentialSearch(list,last,target,locn);
if(found)
{
  if(locn !=0)
  {
   int k=list[locn-1];
   list[locn-1]=list[locn];
   list[locn]=k;
  }
}
return found;
}


int main()
{
int list[50],last,target,locn;
cout<<"Enter the length of the array: ";
cin>>last;
cout<<"Enter "<<last<<" numbers: ";
for(int i=0;i<last;i++)
{
cin>>list[i];
}
cout<<"Enter the Element to be searched: ";
cin>>target;
bool found=ProbabilitySearch(list,last,target,locn);
if(found)
{
cout<<"Element "<<target<<" found at location: "<<locn+1<<endl;
cout<<"Array after moving the search element: ";
for(int i=0;i<last;i++)
{
cout<<list[i]<<" ";
}
cout<<endl;
}
else
cout<<"Element "<<target<<" not found"<<endl;
return 0;
}
