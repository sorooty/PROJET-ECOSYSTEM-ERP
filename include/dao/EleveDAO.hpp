#ifndef ELEVEDAO_HPP
#define ELEVEDAO_HPP

#include "../models/Eleve.hpp"
#include "../databaseConnection.hpp"
#include <vector>

class EleveDAO {
private:
    DatabaseConnection* db;

public:
    EleveDAO();
    bool ajouter(Eleve& eleve);
    std::vector<Eleve> getAll();
    Eleve* getById(int id);
    bool modifier(const Eleve& eleve);
    bool supprimer(int id);

    // Méthodes spécifiques
    std::vector<Eleve> getByClasse(int classeId);
    std::vector<Eleve> getByParent(int parentId);
    bool changerClasse(int eleveId, int nouvelleClasseId);
};

#endif
