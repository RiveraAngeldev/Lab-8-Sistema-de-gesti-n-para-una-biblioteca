#pragma once
#include "books.h"

class DLList
{
private: // Private attributes relating to Node positioning and the size of the List
	books* head;
	books* tail;
	int size;
	void toLowerCase(string&);
public:
	// Constructors
	DLList();
	// Destructor
	~DLList();
	// Basic Functions
	void addToHead(string, string);
	void addToTail(string, string);
	void deleteFromHead();
	void deleteFromTail();
	bool isEmpty();
	// Required Functions for the Lab
	void sortInsert(books*);
	void deleteAllButTail();
	void deleteAllButHead();
	string findBookByTitle(string);
	void deleteBookByTitle(string);
	void setBook(string, string, string);
	void printBooksByAuthor(string);
	void showBooks();
	void deleteAllTheBooks();
	int obtainSize() const;
};

// Given that this is not a template, the implementation is in the DLList.cpp file