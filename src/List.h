#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

template<class T>
class List{
	int size = 0;
	T* list = new T[0];

public:
	~List(){
		delete[] list;
	}

	// inserts a new value into the list
	void Add(const T &value){
		T* temp = list;
		size++;

		// create a new array with the new size, assigning it the old values
		list = new T[size];
		list = temp;

		// then assign the new value. -1 because of 0-based indexing
		list[size - 1] = value;
	}

	// removes a value from the list by index
	void Remove(const int &index){
		T* temp = list;
		size--;

		// declare new array with the new size
		list = new T[size];

		// use counting individual to the loop's iterator because we'll be skipping one value
		int count = 0;
		for (int i = 0; i < size + 1; i++){
			if (i == index){
				continue;
			}
			// assign our new array the relevant old values
			list[count] = temp[i];
			count++;
		}
	}

	// sets the value at the specified index
	void Set(const int &index, const T &value){
		if (index < size && index > -1){
			list[index] = value;
		}
	}

	// inserts a value at the specified index, pushing all other values back
	void Insert(const T &value, const int &index){
		if (index < size && index > -1){
			Add(value);

			int temp[2]; // 0 = old, 1 = new
			temp[0] = list[index];
			for (int i = index; i < size; i++){
				temp[1] = list[i];
				Set(i, temp[0]);
				temp[0] = temp[1];
			}

			Set(index, value);
		}
	}

	// adds all values from an array to the end of the list
	void AddFrom(T arr[], const int &arrsize){
		int count = 0;
		for (int i = 0; i < arrsize; i++){
			Add(arr[i]);
			count++;
		}
	}

	// inserts all the values of an array at the specified index
	void InsertArray(T arr[], const int &arrsize, const int &index){
		int count = 0;
		for (int i = 0; i < arrsize; i++){
			Insert(arr[i], index + count);
			count++;
		}
	}

	// clears all elements from the list
	void Clear(){
		delete[] list;

		size = 0;
		T* list = new T[size];
	}

	// returns a value from the specified index
	T Get(const int &index){
		if (index < size){
			return list[index];
		}
	}

	// checks if the list contains a certain element
	bool Contains(const T &value){
		for (int i = 0; i < size; i++){
			if (list[i] == value){
				return true;
			}
		}
		return false;
	}

	// checks if the list contains all values in an array
	bool ContainsAll(T arr[], const int &arrsize){
		int matches = 0;
		for (int i = 0; i < size; i++){
			for (int i2 = 0; i < arrsize; i++){
				if (arr[i2] == list[i])
					matches++;
			}
		}
		return (matches == arrsize);
	}

	// copies the list to a new array
	T* ToArray(){
		T* arr = new T[size];
		for (int i = 0; i < size; i++){
			arr[i] = list[i];
		}
		return arr;
	}

	// copies the list to a specified array
	void CopyTo(T arr[]){
		for (int i = 0; i < size; i++){
			arr[i] = list[i];
		}
	}

	// copies the list to a specified array from the specified index
	void CopyTo(T arr[], const int &from){
		// infinite loop prevention
		if ((size - from) < from){ return; };

		int count = 0;
		for (int i = from; i < (size - from); i++){
			arr[count] = list[i];
			count++;
		}
	}

	// copies the list to a specified array in the specified range
	void CopyTo(T arr[], const int &from, const int &end){
		// infinite loop prevention
		if (end < from){ return; };

		int count = 0;
		for (int i = from; i < end; i++){
			arr[count] = list[i];
			count++;
		}
	}

	// returns the first value of the list
	T GetFirst(){
		return list[0];
	}

	// returns the last value of the list
	T GetLast(){
		return list[size - 1];
	}

	// returns the list size
	int Size(){
		return size;
	}

	// prints the list contents via the standard output
	void PrintList(){
		for (int i = 0; i < size; i++){
			cout << i << ": " << list[i] << endl;
		}
	}
};

#endif