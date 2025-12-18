#include<iostream>
using namespace std;
bool RBinarySearch(int list[],int first,int last,int target,int &locn)
{
if(first>last)
{
locn=-1;
return false;
}
else
{
int mid=(first+last)/2;
if(target<list[mid])
return RBinarySearch(list,first,mid-1,target,locn);
else if (target>list[mid])
return RBinarySearch(list,mid+1,last,target,locn);
else 
{
locn=mid;
return true;
}
}
}

int main()
{
int list[50],last,target,locn;
cout<<"Enter the length of the array: ";
cin>>last;
cout<<"Enter "<<last<<" numbers in ascending order: ";
for(int i=0;i<last;i++)
{
cin>>list[i];
}
cout<<"Enter the Element to be searched: ";
cin>>target;
bool found=RBinarySearch(list,0,last,target,locn);
if(found)
{
cout<<"Element "<<target<<" found at location: "<<locn+1<<endl;
}
else
cout<<"Element "<<target<<" not found"<<endl;
return 0;
}
