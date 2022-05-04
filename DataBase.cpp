#include "DataBase.h"

DataBase *DataBase::_instance = nullptr;

DataBase::DataBase(char *server, char *username, char *password, char *db) {
    if (!mysql_real_connect(_connection, server, username, password, db, 0, nullptr, 0)) {
        printf("Connection error : %s\n", mysql_error(_connection));
        exit(1);
    };

    query(strdup("CREATE TABLE IF NOT EXISTS Books ("
                 "id int NOT NULL AUTO_INCREMENT, "
                 "name varchar(255) NOT NULL, "
                 "author varchar(255) NOT NULL, "
                 "price int, "
                 "quantity int, "
                 "PRIMARY KEY (id));"));
}

DataBase *DataBase::GetInstance() {
    if (_instance == nullptr) {
        _instance = new DataBase(strdup("127.0.0.1"), strdup("masoud"), strdup("Ali 123roshan"), strdup("BookShop"));
    }
    return _instance;
}

MYSQL_RES *DataBase::query(char *query) {
    if (mysql_query(_connection, query)) {
        printf("MySQL query error : %s\n", mysql_error(_connection));
        exit(1);
    }
    printf("MySQL query error : %s\n", mysql_error(_connection));
}


