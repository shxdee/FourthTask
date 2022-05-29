#include "LinkedHashTable.h"
#include "iostream"
using namespace std;

Element::Element(int value,int key, Element * next)
{
	this->value = value;
	this->key = key;
	this->next = next;
}

LinkedHashTable::LinkedHashTable()
{
	countElem = 0;
	size = 5;
	hashTable = new Element*[size];
	list = new HashList();
	for (int i = 0; i < size; i++) {
		hashTable[i] = nullptr;
	}
}

LinkedHashTable::LinkedHashTable(int size)
{
	countElem = 0;
	this->size = size;
	hashTable = new Element*[size];
	list = new HashList();
	for (int i = 0; i < size; i++) {
		hashTable[i] = nullptr;
	}
}

int LinkedHashTable::hash(int key) {
	return key % size;
}

void LinkedHashTable::addElem(int key, int elem)
{
	int position = hash(key);
	if (!hashTable[position]) {
		hashTable[position] = new Element(elem, key);
	}
	else {
		Element* temp = hashTable[position];
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = new Element(elem, key);
	}
	list->addElem(elem, key);
	countElem++;
}

void LinkedHashTable::removeElem(int key)
{
	int position = hash(key);
	Element* temp = hashTable[position];
	Element *buf = temp;
	while (temp) {
		if (key == temp->key) {
			if (buf == temp) {
				hashTable[position] = temp->next;
			}
			else {
				buf->next = temp->next;
			}
			list->delElem(temp->value);
			delete temp;
			countElem--;
			return;
		}
		buf = temp;
		temp = temp->next;
	}
}

int LinkedHashTable::findElem(int key)
{
	int position = hash(key);
	Element* temp = hashTable[position];
	while (temp) {
		if (key == temp->key) {
			return temp->value;
		}
		temp = temp->next;
	}
	throw NoElemException();
}

void LinkedHashTable::makeEmpty()
{
	for (int i = 0; i < size; i++) {
		Element *temp = hashTable[i];
		Element *buf;
		while (temp) {
			buf = temp->next;
			delete temp;
			temp = buf;
		}
		hashTable[i] = nullptr;
	}
	countElem = 0;
	list->makeEmpty();
}

bool LinkedHashTable::isEmpty()
{
	if (countElem > 0) { return false; }
	return true;
}

void LinkedHashTable::printTable()
{
	for (int i = 0; i < size; i++) {
		cout << i << ": ";
		Element* temp = hashTable[i];		
		if (temp) {
			cout<<" " << temp->value<<" ";
			//temp = temp->next;
		}
		cout << endl;
	}
}


LinkedHashTable::~LinkedHashTable()
{
	makeEmpty();
	delete[] hashTable;
	delete list;
}

HashList::HashList()
{
	head = nullptr;
	tail = nullptr;
}

HashList::~HashList()
{
	Element* temp = head;
	while (temp != tail) {
		temp = temp->next;
		delete head;
		head = temp;
	}
	delete head;
}

void HashList::addElem(int elem, int key)
{
	if (!tail) {
		tail = new Element(elem, key);
		head = tail;
	}
	else {
		tail->next = new Element(elem, key);
		tail = tail->next;
	}
}

void HashList::delElem(int elem)
{
	Element* temp = head->next;
	Element* buf = head;
	if (head->value == elem) {
		delete head;
		head = temp;
		return;
	}
	while (temp->value != elem) {
		buf = temp;
		temp = temp->next;
	}
		buf->next = temp->next;
		delete temp;
}

void HashList::makeEmpty()
{
	Element* temp = head;
	while (temp != tail) {
		temp = temp->next;
		delete head;
		head = temp;
	}
	delete head;
}

Iterator::Iterator(LinkedHashTable* & hashTable)
{
	hashList = hashTable;
	cur = hashList->list->head;
}

Iterator::~Iterator()
{
}

bool Iterator::hasNext()
{
	if (cur != hashList->list->tail) { return true; }
	return false;
}

void Iterator::start()
{
	cur = hashList->list->head;
}

void Iterator::next()
{
	cur = cur->next;
}

int Iterator::seeElem()
{
	return cur->value;
}

