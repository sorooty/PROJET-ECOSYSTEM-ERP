#include "../../include/dao/UtilisateurDAO.hpp"
#include <sstream>

UtilisateurDAO::UtilisateurDAO() {
    db = DatabaseConnection::getInstance();
}

bool UtilisateurDAO::ajouter(const Utilisateur& user) {
    std::stringstream ss;
    ss << "INSERT INTO utilisateurs (nom, prenom, login, type_utilisateur, actif) VALUES ('"
       << user.getNom() << "', '"
       << user.getPrenom() << "', '"
       << user.getLogin() << "', '"
       << user.getType() << "', "
       << (user.estActif() ? "1" : "0") << ")";

    return db->executeQuery(ss.str());
}

std::vector<Utilisateur> UtilisateurDAO::getAll() {
    std::vector<Utilisateur> utilisateurs;

    if (db->executeQuery("SELECT * FROM utilisateurs")) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Utilisateur user(row[1], row[2], row[3], row[4]);
                user.setId(std::stoi(row[0]));
                user.setActif(row[5] != nullptr && std::string(row[5]) == "1");
                if (row[6]) user.setDateCreation(row[6]);
                utilisateurs.push_back(user);
            }
            mysql_free_result(result);
        }
    }
    return utilisateurs;
}

Utilisateur* UtilisateurDAO::getById(int id) {
    std::stringstream ss;
    ss << "SELECT * FROM utilisateurs WHERE id_utilisateur = " << id;

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row = mysql_fetch_row(result);
            if (row) {
                Utilisateur* user = new Utilisateur(
                    row[1],  // nom
                    row[2],  // prenom
                    row[3],  // login
                    row[4]   // type
                );

                user->setId(std::stoi(row[0]));
                user->setActif(row[5] != nullptr && std::string(row[5]) == "1");
                if (row[6]) user->setDateCreation(row[6]);

                mysql_free_result(result);
                return user;
            }
            mysql_free_result(result);
        }
    }
    return nullptr;
}

bool UtilisateurDAO::modifier(const Utilisateur& user) {
    std::stringstream ss;
    ss << "UPDATE utilisateurs SET "
       << "nom = '" << user.getNom() << "', "
       << "prenom = '" << user.getPrenom() << "', "
       << "login = '" << user.getLogin() << "', "
       << "type_utilisateur = '" << user.getType() << "', "
       << "actif = " << (user.estActif() ? "1" : "0")
       << " WHERE id_utilisateur = " << user.getId();

    return db->executeQuery(ss.str());
}

bool UtilisateurDAO::supprimer(int id) {
    std::stringstream ss;
    ss << "DELETE FROM utilisateurs WHERE id_utilisateur = " << id;
    return db->executeQuery(ss.str());
}

std::vector<Utilisateur> UtilisateurDAO::rechercherParType(const std::string& type) {
    std::vector<Utilisateur> utilisateurs;
    std::stringstream ss;
    ss << "SELECT * FROM utilisateurs WHERE type_utilisateur = '" << type << "'";

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Utilisateur user(row[1], row[2], row[3], row[4]);
                user.setId(std::stoi(row[0]));
                user.setActif(row[5] != nullptr && std::string(row[5]) == "1");
                if (row[6]) user.setDateCreation(row[6]);
                utilisateurs.push_back(user);
            }
            mysql_free_result(result);
        }
    }
    return utilisateurs;
}

std::vector<Utilisateur> UtilisateurDAO::rechercherParNom(const std::string& nom) {
    std::vector<Utilisateur> utilisateurs;
    std::stringstream ss;
    ss << "SELECT * FROM utilisateurs WHERE nom LIKE '%" << nom << "%' OR prenom LIKE '%" << nom << "%'";

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Utilisateur user(row[1], row[2], row[3], row[4]);
                user.setId(std::stoi(row[0]));
                user.setActif(row[5] != nullptr && std::string(row[5]) == "1");
                if (row[6]) user.setDateCreation(row[6]);
                utilisateurs.push_back(user);
            }
            mysql_free_result(result);
        }
    }
    return utilisateurs;
}

bool UtilisateurDAO::activerUtilisateur(int id) {
    std::stringstream ss;
    ss << "UPDATE utilisateurs SET actif = 1 WHERE id_utilisateur = " << id;
    return db->executeQuery(ss.str());
}

bool UtilisateurDAO::desactiverUtilisateur(int id) {
    std::stringstream ss;
    ss << "UPDATE utilisateurs SET actif = 0 WHERE id_utilisateur = " << id;
    return db->executeQuery(ss.str());
}

int UtilisateurDAO::compterParType(const std::string& type) {
    std::stringstream ss;
    ss << "SELECT COUNT(*) FROM utilisateurs WHERE type_utilisateur = '" << type << "'";

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row = mysql_fetch_row(result);
            if (row) {
                int count = std::stoi(row[0]);
                mysql_free_result(result);
                return count;
            }
            mysql_free_result(result);
        }
    }
    return 0;
}

bool UtilisateurDAO::assignerMatiereAProfesseur(int profId, int matiereId) {
    // Vérifier d'abord que l'utilisateur est un professeur
    Utilisateur* prof = getById(profId);
    if (!prof || prof->getType() != "professeur") {
        delete prof;
        return false;
    }
    delete prof;

    std::stringstream ss;
    ss << "INSERT INTO professeur_matiere (id_professeur, id_matiere) VALUES ("
       << profId << ", " << matiereId << ")";

    return db->executeQuery(ss.str());
}

bool UtilisateurDAO::retirerMatiereAProfesseur(int profId, int matiereId) {
    std::stringstream ss;
    ss << "DELETE FROM professeur_matiere WHERE id_professeur = "
       << profId << " AND id_matiere = " << matiereId;

    return db->executeQuery(ss.str());
}

std::vector<Matiere> UtilisateurDAO::getMatieresEnseignees(int profId) {
    std::vector<Matiere> matieres;
    std::stringstream ss;

    ss << "SELECT m.* FROM matieres m "
       << "JOIN professeur_matiere pm ON m.id_matiere = pm.id_matiere "
       << "WHERE pm.id_professeur = " << profId;

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Matiere matiere(row[1], row[2], std::stoi(row[3]));
                matiere.setId(std::stoi(row[0]));
                matieres.push_back(matiere);
            }
            mysql_free_result(result);
        }
    }
    return matieres;
}

std::vector<Utilisateur> UtilisateurDAO::getProfesseursParMatiere(int matiereId) {
    std::vector<Utilisateur> professeurs;
    std::stringstream ss;

    ss << "SELECT u.* FROM utilisateurs u "
       << "JOIN professeur_matiere pm ON u.id_utilisateur = pm.id_professeur "
       << "WHERE pm.id_matiere = " << matiereId;

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Utilisateur prof(row[1], row[2], row[3], "professeur");
                prof.setId(std::stoi(row[0]));
                professeurs.push_back(prof);
            }
            mysql_free_result(result);
        }
    }
    return professeurs;
}
