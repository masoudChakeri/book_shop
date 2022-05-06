#include "DataBase.h"

DataBase *DataBase::_instance = nullptr;

DataBase::DataBase(char *server, char *username, char *password, char *db) {
    if (!mysql_real_connect(_connection, server, username, password, db, 0, nullptr, 0)) {
        printf("Connection error : %s\n", mysql_error(_connection));
        exit(1);
    };

    mysql_free_result(query(strdup("CREATE TABLE IF NOT EXISTS Books ("
                                   "id int NOT NULL AUTO_INCREMENT, "
                                   "name varchar(255) NOT NULL, "
                                   "author varchar(255) NOT NULL, "
                                   "price int, "
                                   "quantity int, "
                                   "PRIMARY KEY (id));")));

}

DataBase *DataBase::GetInstance() {
    if (_instance == nullptr) {
        _instance = new DataBase(strdup("127.0.0.1"), strdup("masoud"), strdup("Ali 123roshan"), strdup("BookShop"));
    }
    return _instance;
}

MYSQL_RES *DataBase::query(char *query) {
    std::cout << query << std::endl;
    if (mysql_query(_connection, query)) {
        printf("MySQL query error : %s\n", mysql_error(_connection));
        exit(1);
    }
    return mysql_store_result(_connection);
}

void DataBase::showResult(MYSQL_RES *result) {
    if (result != nullptr) {
        unsigned int numFields = mysql_num_fields(result);
        my_ulonglong numRows{mysql_num_rows(result)};
        MYSQL_ROW row;

        while ((row = mysql_fetch_row(result))) {
            if (numRows == 1) {
                for (int i = 0; i < numFields; ++i) {
                    (i == 0) ? std::cout << row[i] << "- " : std::cout << row[i] << "   ";
                }
            } else {
                for (int i = 0; i < numFields; i++) {
                    (i % numRows == 0) ? std::cout << "\n" << row[i] << "- " : std::cout << row[i] << "\t";
                }
            }
        }

        mysql_free_result(result);

    } else {
        std::cout << "sry but there is no result!";
    }
}

DataBase::~DataBase() {
    mysql_close(_connection);
    std::cout << "database connection closed" << std::endl;
}


