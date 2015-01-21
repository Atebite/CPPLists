#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

template<typename T>
class List{
	int size = 0;
	T* list = new T[0];

public:
	~List(){
		delete[] list;
	}

	// inserts a new value into the list
	void Add(const T &value);

	// removes a value from the list by index
	void Remove(const int &index);

	// sets the value at the specified index
	void Set(const int &index, const T &value);

	// inserts a value at the specified index, pushing all other values back
	void Insert(const T &value, const int &index);

	// adds all values from an array to the end of the list
	void AddFrom(T arr[], const int &arrsize);

	// inserts all the values of an array at the specified index
	void InsertArray(T arr[], const int &arrsize, const int &index);

	// removes all elements from the list that exist in an array
	void RemoveFrom(T arr[], const int &arrsize);

	// clears all elements from the list
	void Clear();

	// returns a value from the specified index
	T Get(const int &index);

	// returns the index of a given value, and a nullpointer if it couldn't be found
	int* GetIndexByValue(const T &value);

	// checks if the list contains a certain element
	bool Contains(const T &value);

	// checks if the list contains all values in an array
	bool ContainsAll(T arr[], const int &arrsize);

	// copies the list to a new array
	T* ToArray();

	// copies the list to a specified array
	void CopyTo(T arr[]);

	// copies the list to a specified array from the specified index
	void CopyTo(T arr[], const int &from);

	// copies the list to a specified array in the specified range
	void CopyTo(T arr[], const int &from, const int &end);

	// returns the first value of the list
	T GetFirst();

	// returns the last value of the list
	T GetLast();

	// returns the list size
	int Size();

	// prints the list contents via the standard output
	void PrintList();
};

#endif