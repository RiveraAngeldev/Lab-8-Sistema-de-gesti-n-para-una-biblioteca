#include "books.h"

//Constructors
books::books() {

}

books::books(const string &t, const string &a, books* n, books* p) {
    books::title = t;
    books::author = a;
    books::next = n;
    books::prev = p;
}
 
//Getters
string books::getTitle() const {
    return books::title;
}

string books::getAuthor() const {
    return books::author;
}

books* books::getNext() const {
    return books::next;
}

books* books::getPrev() const {
    return books::prev;
}

//Setters
void books::setTitle(string const& t) {
    books::title = t;
}

void books::setAuthor(string const& a) {
    books::author = a;
}

void books::setNext(books* n) {
    books::next = n;
}

void books::setPrev(books* p) {
    books::prev = p;
}