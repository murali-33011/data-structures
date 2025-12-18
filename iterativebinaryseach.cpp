#include<iostream>
using namespace std;
bool BinarySearch(int list[],int last,int target,int &locn)
{
int mid=0,low=0,high=last-1;
while(low<=high)
{
mid=(low+high)/2;
if(list[mid]==target)
{
locn=mid;
return true;
}
else if(target>list[mid])
low=mid+1;
else high=mid-1;

}
return false;
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
bool found=BinarySearch(list,last,target,locn);
if(found)
{
cout<<"Element "<<target<<" found at location: "<<locn+1<<endl;
}
else
cout<<"Element "<<target<<" not found"<<endl;
return 0;
}
