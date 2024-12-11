#include "../../include/dao/ClasseDAO.hpp"
#include <sstream>

// Constructeur
ClasseDAO::ClasseDAO() {
    try {
        db = DatabaseConnection::getInstance();
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de l'initialisation de ClasseDAO : " << e.what() << std::endl;
        db = nullptr;
    }
}

ClasseDAO::~ClasseDAO() {
    // Le destructeur de DatabaseConnection sera appelé automatiquement
    // car c'est un singleton
}

bool ClasseDAO::ajouter(const Classe& classe) {
    std::stringstream ss;
    ss << "INSERT INTO classes (nom_classe, niveau, annee_scolaire, "
       << "professeur_principal_id, capacite_max, salle_principale) VALUES ('"
       << classe.getNom() << "', '"
       << classe.getNiveau() << "', '"
       << classe.getAnneeScolaire() << "', "
       << classe.getProfesseurPrincipalId() << ", "
       << classe.getCapaciteMax() << ", '"
       << classe.getSallePrincipale() << "')";

    return db->executeQuery(ss.str());
}

std::vector<Classe> ClasseDAO::getAll() {
    std::vector<Classe> classes;

    if (db->executeQuery("SELECT * FROM classes")) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Classe classe(row[1], row[2], row[3]);
                classe.setId(std::stoi(row[0]));
                if (row[4]) classe.setProfesseurPrincipalId(std::stoi(row[4]));
                if (row[5]) classe.setCapaciteMax(std::stoi(row[5]));
                if (row[6]) classe.setSallePrincipale(row[6]);
                classes.push_back(classe);
            }
            mysql_free_result(result);
        }
    }
    return classes;
}

Classe* ClasseDAO::getById(int id) {
    std::stringstream ss;
    ss << "SELECT * FROM classes WHERE id_classe = " << id;

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row = mysql_fetch_row(result);
            if (row) {
                Classe* classe = new Classe(row[1], row[2], row[3]);
                classe->setId(std::stoi(row[0]));
                if (row[4]) classe->setProfesseurPrincipalId(std::stoi(row[4]));
                if (row[5]) classe->setCapaciteMax(std::stoi(row[5]));
                if (row[6]) classe->setSallePrincipale(row[6]);

                mysql_free_result(result);
                return classe;
            }
            mysql_free_result(result);
        }
    }
    return nullptr;
}

bool ClasseDAO::inscrireEleve(int classeId, int eleveId) {
    std::stringstream ss;
    ss << "INSERT INTO inscriptions_classe (id_classe, id_eleve) VALUES ("
       << classeId << ", " << eleveId << ")";
    return db->executeQuery(ss.str());
}

std::vector<Utilisateur> ClasseDAO::getElevesClasse(int classeId) {
    std::vector<Utilisateur> eleves;
    std::stringstream ss;

    ss << "SELECT u.* FROM utilisateurs u "
       << "JOIN inscriptions_classe ic ON u.id_utilisateur = ic.id_eleve "
       << "WHERE ic.id_classe = " << classeId
       << " AND ic.statut = 'actif'";

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Utilisateur eleve(row[1], row[2], row[3], "eleve");
                eleve.setId(std::stoi(row[0]));
                eleve.setActif(row[5] != nullptr && std::string(row[5]) == "1");
                if (row[6]) eleve.setDateCreation(row[6]);
                eleves.push_back(eleve);
            }
            mysql_free_result(result);
        }
    }
    return eleves;
}

bool ClasseDAO::modifier(const Classe& classe) {
    try {
        if (!db) return false;

        std::stringstream ss;
        ss << "UPDATE classes SET "
           << "nom = '" << classe.getNom() << "', "
           << "niveau = '" << classe.getNiveau() << "', "
           << "annee_scolaire = '" << classe.getAnneeScolaire() << "', "
           << "professeur_principal_id = " << classe.getProfesseurPrincipalId() << ", "
           << "capacite_max = " << classe.getCapaciteMax() << ", "
           << "salle_principale = '" << classe.getSallePrincipale() << "' "
           << "WHERE id = " << classe.getId();

        return db->executeQuery(ss.str());
    } catch (const std::exception& e) {
        std::cerr << "Erreur dans ClasseDAO::modifier : " << e.what() << std::endl;
        return false;
    }
}

bool ClasseDAO::desinscrireEleve(int classeId, int eleveId) {
    try {
        if (!db) return false;

        std::stringstream ss;
        ss << "DELETE FROM inscriptions "
           << "WHERE classe_id = " << classeId
           << " AND eleve_id = " << eleveId;

        return db->executeQuery(ss.str());
    } catch (const std::exception& e) {
        std::cerr << "Erreur dans ClasseDAO::desinscrireEleve : " << e.what() << std::endl;
        return false;
    }
}

// ... autres méthodes ...
