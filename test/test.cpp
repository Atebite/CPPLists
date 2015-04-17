#include "List.h"

using namespace std;

int main(){
	List<int> foo;

	// adds to the end of the list
	foo.Add(1);
	foo.Add(2);
	foo.Add(3);

	cout << foo.Size();

	// remove value at index 1 (2)
	foo.Remove(1);

	// insert 4 at index 1
	foo.Insert(4, 1);

	List<int>* bar = &foo;

	bar->Add(5);

	// prints the list via standard output
	bar->PrintList();

	cout << foo.GetFirst();

	// copy list to (dynamic) array
	int baz[foo.Size()] = foo.ToArray();

	for(int i = 0; i < foo.Size(); i++){
		cout << baz[i]
	}

	delete[] baz;

	int* baz = new int[];

	// copy foo to baz in range 1-3 (4, 3, 5)
	foo.CopyTo(baz,1, 3)
}
