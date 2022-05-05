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

    DataBase *_db;
public:
    Book();

    bool add();

    void displayAll();

    void display();

    bool remove(int id);

    bool update();
};


#endif //BOOKSHOP_BOOK_H
