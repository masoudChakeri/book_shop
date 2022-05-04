#ifndef BOOKSHOP_DATABASE_H
#define BOOKSHOP_DATABASE_H

#include <iostream>
#include <mysql/mysql.h>
#include <cstring>

class DataBase {

private:

    DataBase(char *server, char *username, char *password, char *db);

    static DataBase *_instance;

    MYSQL *_connection{mysql_init(nullptr)};

public:
    static DataBase *GetInstance();

    MYSQL_RES *query(char *query);
};

#endif //BOOKSHOP_DATABASE_H
