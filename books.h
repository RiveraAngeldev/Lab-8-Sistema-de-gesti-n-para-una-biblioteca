#pragma once
#include <string>
using namespace std;

class books
{
private: // Private attributes relating to the book and the Node traversal
	string title;
	string author;
	books* next;
	books* prev;
public:
	// Constructors
	books();
	books(const string &t, const string &a, books* n, books* p);
	// Getters
	string getTitle() const;
	string getAuthor() const;
	books* getNext() const;
	books* getPrev() const;
	// Setters
	void setTitle(string const& t);
	void setAuthor(string const& a);
	void setNext(books* n);
	void setPrev(books* p);
};

// Given that this is not a template, the implementation is in the books.cpp file