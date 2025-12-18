#include <iostream>
#include "HashSearchDef.cpp"
using namespace std;

template<class T> HashTbl<T>::HashTbl(int s)
{
	size = s;
	Hash = new headnode<T>*[size];
	for(int i=0;i<size;i++)
	{
		Hash[i] = new headnode<T>();
		Hash[i]->count=0;
		Hash[i]->first = NULL;
		Hash[i]->last = NULL;
	}
}

template<class T> HashTbl<T>::~HashTbl()
{
	int i=0;
	if(Hash[i] == NULL)
		delete Hash[i];
	else
	{	
		while(Hash[i]!=NULL)
		{
			datanode<T>*t = Hash[i]->first;
			Hash[i]->first = t->link;
			delete t;
			i++;
		}
		delete Hash[i];
	}
	cout<<"Deleted Hash Table!\n";
	delete Hash;
}

template <class T> datanode<T>* HashTbl<T>::createNode(T key)
{
	datanode<T>* t = new datanode<T>();
	t->data = key;
	t->link = NULL;
	return t;
}

template<class T>bool HashTbl<T>::insertToHashTbl(T key, int &x)
{
	int hashIndex = key%size;
	datanode<T>* t = createNode(key);
	if(Hash[hashIndex]->first == NULL)//empty
	{
		t->link = Hash[hashIndex]->first;
		Hash[hashIndex]->first = t;
		Hash[hashIndex]->last = t;
	}
	else// not empty, so insert at end
	{
		Hash[hashIndex]->last->link = t;
		Hash[hashIndex]->last = t;
		t->link = NULL;
	}
	x = hashIndex+1;
	Hash[hashIndex]->count++;
	return true;
}

template<class T> bool HashTbl<T>::searchInHashTbl(T key, int &x)
{
	int hashIndex = key%size;
	datanode<T>*cur = Hash[hashIndex]->first;
	while(cur != NULL && cur->data != key)
	{
		cur=cur->link;
	}
	if(cur == NULL)
		return false;
	else
	{
		x = hashIndex;
		return true;
	}
}

template<class T> void HashTbl<T>::display()
{
	for(int i=0;i<size;i++)
	{
		cout<<"Elements at Index "<<(i+1)<<": ";
		datanode<T>*cur = Hash[i]->first;
		if(cur == NULL)
			cout<<"No data\n";
		else
		{
			while(cur!=NULL)
			{
				cout<<cur->data;
				cur = cur->link;
				if(cur!=NULL)
					cout<<" -> ";
				else
					cout<<" ";
 			}
 			cout<<endl;
		}
	}
}	
		
