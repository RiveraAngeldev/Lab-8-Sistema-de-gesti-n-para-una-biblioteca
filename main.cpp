#include <iostream>
#include "DLList.h"
using namespace std;

int main()
{
    books b1("Cien anios de soledad", "Gabriel Garcia Marquez", 0, 0);
    books b2("El amor en los tiempos del colera", "Gabriel Garcia Marquez", 0, 0);
    books b3("The Hobbit", "J.R.R. Tolkien", 0, 0);
    books b4("El Principito", "Antoine de Saint-Exupery", 0, 0);

    DLList Library;

    // Insert 4 books in the Library and print the Library
    cout << "Books in the Library:\n";
    Library.sortInsert(&b2);
    Library.sortInsert(&b3);
    Library.sortInsert(&b4);
    Library.sortInsert(&b1);
    Library.showBooks();

    cout << "\n\n";

    // Update the title and author of one of the books (The Hobbit: An Unexpected Journey, J.R.R Tolkien)
    // Print the Library
    cout << "Updating 'The Hobbit' to 'The Hobbit: An Unexpected Journey'...\n"
         << "Books in the Library after the update:\n";
    Library.setBook(b3.getTitle(), "The Hobbit: An Unexpected Journey", b3.getAuthor());
    Library.showBooks();

    cout << "\n\n";

    // Eliminate a book based off its title (El Principito)
    // Print the Library
    cout << "Deleting 'El Principito'...\n"
         << "Books in the Library after the deletion:\n";
    Library.deleteBookByTitle(b4.getTitle());
    Library.showBooks();

    cout << "\n\n";

    // Invoke deleteAllButTail
    // Print the Library
    cout << "Deleting everything except the tail...\n"
         << "Books in the Library after deleting everything except the tail:\n";
    Library.deleteAllButTail();
    Library.showBooks();

    cout << "\n\n";

    // Delete all the books from the Library and print the size
    cout << "Cleaning Library...\n";
    Library.deleteFromTail();

    int size = Library.obtainSize();
    cout << "Number of books in the Library: " << size << endl;
}