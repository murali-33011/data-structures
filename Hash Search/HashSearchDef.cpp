template<class T>
struct datanode
{
	T data;
	datanode<T>*link;
};

template<class T>
struct headnode
{
	int count;
	datanode<T>*first;
	datanode<T>*last;
};

template<class T>
class HashTbl
{
	private:
		headnode<T>** Hash;
		int size;
		datanode<T>* createNode(T key);
	public:
		HashTbl(int s);
		~HashTbl();
		bool insertToHashTbl(T key, int &x);
		bool searchInHashTbl(T key, int &x);
		void display();
};
		

