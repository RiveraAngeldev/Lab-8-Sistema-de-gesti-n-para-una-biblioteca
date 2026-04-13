#include <iostream>
#include "DLList.h"
using namespace std;


//Constructor
DLList::DLList() : head(nullptr), tail(nullptr), size(0)
{

}

//Desctructor
DLList::~DLList()
{
    deleteAllTheBooks();
}

//Basic Functions
void DLList::addToHead(string title, string author)
{
    books*  newBook = new books(title,author, head, nullptr);

    if (isEmpty())
    {
        head = tail = newBook;
    }
    else
    {
        head -> setPrev(newBook);

        head = newBook; 
    }

    size++;
}

void DLList::addToTail(string title, string author)
{
     books*  newBook = new books(title,author, head, nullptr);

    if (isEmpty())
    {
        head = tail = newBook;
    }
    else
    {
        tail -> setNext(newBook);

        tail = newBook; 
    }

    size++;
}

void DLList::deleteFromHead()
{   
    if(isEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }
    
    books* temp = head;

    if(head = tail)
    {
        head = tail = nullptr;
    }
    else
    {
        head = head->getNext();
        head->setPrev(nullptr);
    }

    delete temp;
    size--;
}

void DLList::deleteFromTail()
{
    if(isEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }
    
    books* temp = tail;

    if(tail = head)
    {
        head = tail = nullptr;
    }
    else
    {
        tail = tail->getPrev();
        tail->setNext(nullptr);
    }

    delete temp;
    size--;
}

bool DLList::isEmpty()
{
    return size == 0;
}

//Required Functions for the Lab
void DLList::sortInsert(books*)
{

}

void DLList:: deleteAllButTail()
{
    if( isEmpty() || head == tail) return;
    while(head != tail){
        deleteFromHead();
    }
}

void DLList::deleteAllButHead() 
{
    if(isEmpty() || head == tail) return;
    while(head != tail) {
        deleteFromTail();
    }
}

string DLList:: findBookByTitle(string title)
{
    books *temp = head;
    while(temp != nullptr) {
        if(temp->getTitle() == title) {
            return "Title found: " + temp->getTitle() + " by " + temp->getAuthor();
        }
        temp = temp->getNext();
    }
    return "Book not found with title: " + title;
}
void DLList:: deleteBookByTitle(string)
{

}

void DLList:: setBook(string oldTitle, string newTitle, string newAuthor)
{
    books *temp = head;
    while(temp != nullptr) {
        if(temp->getTitle() == oldTitle) {
            temp->setTitle(newTitle);
            temp->setAuthor(newAuthor);
            return;
        }
        temp = temp->getNext();
    }
    cout << "The book you're looking for cannot be found."<< endl;
}

void DLList::printBooksByAuthor(string)
{

}

void DLList:: showBooks()
{
    if(isEmpty()) {
        cout << "The list is empty." << endl;
        return;
    }
    books* temp = head;
    while(temp != nullptr) {
        cout << temp->getTitle() << " by " << temp->getAuthor() << endl;
        temp = temp->getNext();
    }
}

void DLList:: deleteAllTheBooks()
{
    while(!isEmpty())
    {
        deleteFromHead();
    }
}

int DLList:: obtainSize() const
{
    return size;
}