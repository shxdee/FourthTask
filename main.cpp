#include "LinkedHashTable.h"
#include "iostream"
using namespace std;

void main()
{
	LinkedHashTable* hashTable1 = new LinkedHashTable(6);

	hashTable1->addElem(1, 4);
	hashTable1->addElem(3, 2);
	hashTable1->addElem(4, 5);
	hashTable1->addElem(2, 3);
	hashTable1->addElem(5, 12);
	hashTable1->printTable();
	cout << endl;

	Iterator iterator1(hashTable1);
	while (iterator1.hasNext()) {
		cout << iterator1.seeElem() << endl;
		iterator1.next();
	}
	cout << iterator1.seeElem() << endl;
	cout << endl;

	cout << iterator1.seeElem() << endl;
	hashTable1->removeElem(3);

	cout << endl;
	iterator1.start();
	while (iterator1.hasNext()) {
		cout << iterator1.seeElem() << endl;
		iterator1.next();
	}
	cout << iterator1.seeElem() << endl;

	cout << endl;
	cout << hashTable1->findElem(4) << endl;
	cout << hashTable1->findElem(5) << endl;
	cout << "isEmpty: " << hashTable1->isEmpty() << endl;
	cout << "Made empty!" << endl;
	hashTable1->makeEmpty();
	cout << "isEmpty: " << hashTable1->isEmpty() << endl;
}

