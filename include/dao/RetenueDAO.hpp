#ifndef RETENUEDAO_HPP
#define RETENUEDAO_HPP

#include "../models/Retenue.hpp"
#include "../DatabaseConnection.hpp"
#include <vector>

class RetenueDAO {
private:
    DatabaseConnection* db;

public:
    RetenueDAO();
