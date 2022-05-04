#ifndef BOOKSHOP_BOOK_H
#define BOOKSHOP_BOOK_H

#include <iostream>
#include <string>
#include <cstring>

#include "DataBase.h"

class Book {

private:
    int _id;
    std::string _name;
    std::string _author;
    int _price;
    int _quantity;

    DataBase* _db;
public:
    Book();

    bool add();

    bool remove();

    bool update();

    void display();
};


#endif //BOOKSHOP_BOOK_H
