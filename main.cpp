//All you require to do is build an application that will let its customers add and display books.
// Furthermore, it will help the customers to change their books by implementing modifications
// to them or adding or deleting pages. Create an application that will be user-friendly
// and effortless to access and use. It also lets users check and buy their favorite
// books anytime, anywhere with one click. But you have to be very mindful of your
// graphics as it is the major part of your bookshop management system application.

#include <cstring>

#include "DataBase.h"
#include "Book.h"

int main() {

    DataBase::GetInstance();
    Book book;
    book.add();

    return 0;
}
