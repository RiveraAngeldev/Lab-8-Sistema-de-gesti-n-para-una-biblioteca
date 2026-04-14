#include <iostream>
#include <algorithm>
#include <cctype>
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
     books*  newBook = new books(title,author,nullptr, tail);

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

    if(head == tail)
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

    if(tail == head)
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
void DLList::sortInsert(books* newBook)
{
    if (newBook == nullptr) return; 

    
    newBook->setNext(nullptr);
    newBook->setPrev(nullptr);

    if (isEmpty())
    {
        head = tail = newBook;
        size++;
        return;
    }

   
    books* current = head;
    while (current != nullptr && current->getTitle() < newBook->getTitle())
        current = current->getNext();

    if (current == nullptr)
    {
        
        newBook->setPrev(tail);
        tail->setNext(newBook);
        tail = newBook;
    }
    else if (current == head)
    {
        
        newBook->setNext(head);
        head->setPrev(newBook);
        head = newBook;
    }
    else
    {
        // Middle insertion: splice between current->prev and current.
        books* prevNode = current->getPrev();
        newBook->setNext(current);      // newBook points forward to current.
        newBook->setPrev(prevNode);     // newBook points back to prevNode.
        prevNode->setNext(newBook);     // prevNode now points forward to newBook.
        current->setPrev(newBook);      // current now points back to newBook.
    }

    size++;

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

void DLList:: deleteBookByTitle(string searchTitle)
{
     toLowerCase(searchTitle);

    books* current = head;
    while (current != nullptr)
    {
        string currentTitle = current->getTitle();
        toLowerCase(currentTitle);

        if (currentTitle == searchTitle)
        {
            if (current == head && current == tail)
            {
                // Only node in the list.
                head = tail = nullptr;
            }
            else if (current == head)
            {
                head = current->getNext();
                head->setPrev(nullptr);
            }
            else if (current == tail)
            {
                tail = current->getPrev();
                tail->setNext(nullptr);
            }
            else
            {
                // Middle node: bypass it by linking its neighbors to each other.
                current->getPrev()->setNext(current->getNext());
                current->getNext()->setPrev(current->getPrev());
            }

            delete current;
            size--;
            return; // Done, exit after deleting the first match.
        }

        current = current->getNext();
    }

    cout << "Book not found.\n";
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

void DLList::printBooksByAuthor(string searchAuthor)
{
     toLowerCase(searchAuthor);
    bool found = false;

    books* current = head;
    while (current != nullptr)
    {
        string currentAuthor = current->getAuthor();
        toLowerCase(currentAuthor);

        if (currentAuthor == searchAuthor)
        {
            cout << "Title: " << current->getTitle()
                 << " | Author: " << current->getAuthor() << "\n";
            found = true; // Mark that at least one match was found.
        }

        current = current->getNext();
    }

    if (!found)
        cout << "No books found for that author.\n";
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

void DLList::toLowerCase(string& s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = (char)tolower((unsigned char)s[i]);
    }
}