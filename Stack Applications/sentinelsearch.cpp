#include<iostream>
using namespace std;
bool SentinelSearch(int list[],int last,int target,int &locn)
{
int i=0;
list[last+1]=target;
cout<<"Array after adding sentinel element: ";
for(int i=0;i<last;i++)
{
cout<<list[i]<<" ";
}
cout<<target<<endl;;
while(target != list[i])
{
i++;
}
if(i<=last)
{
locn=i;
return true;
}
else 
return false;
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
bool found=SentinelSearch(list,last,target,locn);
if(locn)
{
cout<<"Element "<<target<<" found at location: "<<locn+1<<endl;
}
else
cout<<"Element "<<target<<" not found"<<endl;
return 0;
}
