#ifndef DATABASECONNECTION_HPP
#define DATABASECONNECTION_HPP

#include <mysql.h>
#include <iostream>
#include <string>

class DatabaseConnection {
private:
    MYSQL* connection;
    static DatabaseConnection* instance;

    // Constructeur privé (pattern Singleton)
    DatabaseConnection();

public:
    static DatabaseConnection* getInstance();
    bool executeQuery(const std::string& query);
    MYSQL_RES* getResult();
    std::string getLastError();
    ~DatabaseConnection();
};

#endif
