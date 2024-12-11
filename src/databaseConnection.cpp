#include "../include/databaseConnection.hpp"

DatabaseConnection* DatabaseConnection::instance = nullptr;

DatabaseConnection::DatabaseConnection() {
    connection = mysql_init(NULL);
    if (connection == NULL) {
        std::cout << "Échec de l'initialisation MySQL" << std::endl;
        return;
    }

    // Modifiez ces paramètres selon votre configuration
    const char* host = "localhost";
    const char* user = "root";         // Votre nom d'utilisateur MySQL
    const char* password = "110705";         // Votre mot de passe MySQL
    const char* database = "test_ecolsystem"; // Nom de votre base de données
    const int port = 3306;

    if (!mysql_real_connect(connection, host, user, password,
                          database, port, NULL, 0)) {
        std::cout << "Erreur de connexion: " << mysql_error(connection) << std::endl;
        return;
    }
    std::cout << "Connexion réussie à MySQL!" << std::endl;
}

DatabaseConnection* DatabaseConnection::getInstance() {
    if (instance == nullptr) {
        instance = new DatabaseConnection();
    }
    return instance;
}

bool DatabaseConnection::executeQuery(const std::string& query) {
    return (mysql_query(connection, query.c_str()) == 0);
}

MYSQL_RES* DatabaseConnection::getResult() {
    return mysql_store_result(connection);
}

std::string DatabaseConnection::getLastError() {
    return mysql_error(connection);
}

DatabaseConnection::~DatabaseConnection() {
    if (connection != NULL) {
        mysql_close(connection);
    }
}
