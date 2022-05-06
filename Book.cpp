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

void Book::display() {
    int id;
    std::cout << "pls enter book id: ";
    std::cin >> id;

    std::string str = "select * from Books where id = " + std::to_string(id) + ";";
    char *query = const_cast<char *>(str.c_str());

    DataBase::showResult(_db->query(query));
}

bool Book::remove() {
    int id;
    std::cout << "pls enter book id: ";
    std::cin >> id;

    std::string str = "delete from Books where id = " + std::to_string(id) + ";";
    char *query = const_cast<char *>(str.c_str());

    _db->query(query);
}

bool Book::update() {
    int id;
    std::cout << std::endl << "pls enter book id: ";
    std::cin >> id;

    std::cout << "edit name: ";
    std::cin >> _name;
    std::cout << std::endl << "edit author: ";
    std::cin >> _author;
    std::cout << std::endl << "edit price: ";
    std::cin >> _price;
    std::cout << std::endl << "edit quantity: ";
    std::cin >> _quantity;

    std::string str = "update Books "
                      "set name = '" + _name + "', "
                                               "author = '" + _author + "', "
                                                                        "price = '" + std::to_string(_price) + "', "
                                                                                                               "quantity =  " +
                      std::to_string(_quantity) +
                      " where id = " + std::to_string(id) + ";";
    char *query = const_cast<char *> (str.c_str());

    _db->query(query);
}


