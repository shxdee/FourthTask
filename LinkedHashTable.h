#pragma once

struct NoElemException{};


struct Element
{
	int value;
	int key;
	Element* next;
	Element(int value, int key, Element* next = nullptr);
};

class HashList {
private:
	Element* head;
	Element* tail;
public:
	friend class Iterator;
	HashList();
	~HashList();
	void addElem(int elem, int key);
	void delElem(int elem);
	void makeEmpty();
};

class LinkedHashTable
{
private:
	Element** hashTable;
	HashList* list;
	int size;
	int countElem;
public:
	friend class Iterator;
	LinkedHashTable();
	LinkedHashTable(int size);
	int hash(int key);
	void addElem(int key, int elem);
	void removeElem(int key);
	int findElem(int key);
	void makeEmpty();
	bool isEmpty();
	void printTable();
	~LinkedHashTable();
};


class Iterator {
private:
	Element* cur;
	LinkedHashTable* hashList;
	
public:
	Iterator(LinkedHashTable* &hashTable);
	~Iterator();
	bool hasNext();
	void start();
	void next();
	int seeElem();
};

