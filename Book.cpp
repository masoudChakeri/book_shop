#include "Book.h"

Book::Book() {
    _db = DataBase::GetInstance();
}

bool Book::add() {
    std::cout << "pls enter name: " << std::endl;
    std::cin >> _name;
    std::cout << "pls enter author: " << std::endl;
    std::cin >> _author;
    std::cout << "pls enter price: " << std::endl;
    std::cin >> _price;
    std::cout << "pls enter quantity: " << std::endl;
    std::cin >> _quantity;

    std::string str = " insert into Books (name, author, price, quantity) "
                      "values ('" + _name + "', '" + _author + "', '" + std::to_string(_price) + "', '" +
                      std::to_string(_quantity) + "')";

    char *query = const_cast <char *>(str.c_str());

    _db->query(strdup(query));
    return true;
}

void Book::displayAll() {
    std::string str = "select id, name from Books;";
    char *query = const_cast<char *>(str.c_str());

    DataBase::showResult(_db->query(query));
}


