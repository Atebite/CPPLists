#include "list.h"

template<typename T>

void List::Add(const T &value){
	T* temp = list;
	size++;

	// create a new array with the new size, assigning it the old values
	list = new T[size];
	list = temp;

	// then assign the new value. -1 because of 0-based indexing
	list[size - 1] = value;
}

void List::Remove(const int &index){
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

void List::Set(const int &index, const T &value){
	if (index < size && index > -1){
		list[index] = value;
	}
}

void List::Insert(const T &value, const int &index){
	if (index < size && index > -1){
		Add(value);

		int temp[2]; // 0 = old, 1 = new
		temp[0] = list[index];
		for (int i = index; i < size; i++){
			// set the new value (the one to store) to the one we're going to replace
			temp[1] = list[i];
			// replace the value with the one that's just been replaced, pushing it back
			Set(i, temp[0]);
			// set our old value to the one that's just been overwritten
			temp[0] = temp[1];
		}

		// set the value at the specified index
		Set(index, value);
	}
}

void List::AddFrom(T arr[], const int &arrsize){
	int count = 0;
	for (int i = 0; i < arrsize; i++){
		Add(arr[i]);
		count++;
	}
}

void List::InsertArray(T arr[], const int &arrsize, const int &index){
	int count = 0;
	for (int i = 0; i < arrsize; i++){
		Insert(arr[i], index + count);
		count++;
	}
}

void List::RemoveFrom(T arr[], const int &arrsize){
	for (int i = 0; i < arrsize; i++){
		if(Contains(arr[i]))
			Remove(*GetIndexByValue(arr[i]));
	}
}

void List::Clear(){
	delete[] list;

	size = 0;
	T* list = new T[size];
}

T List::Get(const int &index){
	if (index < size){
		return list[index];
	}
}

int* List::GetIndexByValue(const T &value){
	for (int i = 0; i < size; i++){
		if (list[i] == value){
			int index = i;
			return &index;
		}
	}
	return nullptr;
}

bool List::Contains(const T &value){
	for (int i = 0; i < size; i++){
		if (list[i] == value){
			return true;
		}
	}
	return false;
}

bool List::ContainsAll(T arr[], const int &arrsize){
	int matches = 0;
	for (int i = 0; i < size; i++){
		for (int i2 = 0; i < arrsize; i++){
			if (arr[i2] == list[i])
				matches++;
		}
	}
	return (matches == arrsize);
}

T* List::ToArray(){
	T* arr = new T[size];
	for (int i = 0; i < size; i++){
		arr[i] = list[i];
	}
	return arr;
}

void List::CopyTo(T arr[]){
	for (int i = 0; i < size; i++){
		arr[i] = list[i];
	}
}

void List::CopyTo(T arr[], const int &from){
	int count = 0;
	for (int i = from; i < size - 1; i++){
		arr[count] = list[i];
		count++;
	}
}

void List::CopyTo(T arr[], const int &from, const int &end){
	int count = 0;
	for (int i = from; i < end; i++){
		arr[count] = list[i];
		count++;
	}
}

T List::GetFirst(){
	return list[0];
}

T List::GetLast(){
	return list[size - 1];
}

int List::Size(){
	return size;
}

void List::PrintList(){
	for (int i = 0; i < size; i++){
		cout << i << ": " << list[i] << endl;
	}
}