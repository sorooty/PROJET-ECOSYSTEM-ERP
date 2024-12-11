#include "../../include/dao/EleveDAO.hpp"
#include <sstream>

EleveDAO::EleveDAO() {
    db = DatabaseConnection::getInstance();
}

bool EleveDAO::ajouter(Eleve& eleve) {
    // D'abord, on ajoute l'utilisateur
    std::stringstream ss;
    ss << "INSERT INTO utilisateurs (nom, prenom, login, mot_de_passe, email, "
       << "type_utilisateur) VALUES ('"
       << eleve.getNom() << "', '"
       << eleve.getPrenom() << "', '"
       << eleve.getLogin() << "', '"
       << eleve.getMotDePasse() << "', '"
       << eleve.getEmail() << "', 'eleve')";

    if (db->executeQuery(ss.str())) {
        // Récupérer l'ID de l'utilisateur créé
        int userId = mysql_insert_id(db->getConnection());
        eleve.setId(userId);

        // Ensuite, on ajoute l'élève
        ss.str("");
        ss << "INSERT INTO eleves (utilisateur_id, date_naissance) VALUES ("
           << userId << ", '"
           << eleve.getDateNaissance() << "')";

        if (db->executeQuery(ss.str())) {
            eleve.setIdEleve(mysql_insert_id(db->getConnection()));
            return true;
        }
    }
    return false;
}

std::vector<Eleve> EleveDAO::getByClasse(int classeId) {
    std::vector<Eleve> eleves;
    std::stringstream ss;
    ss << "SELECT u.*, e.* FROM utilisateurs u "
       << "INNER JOIN eleves e ON u.id_utilisateur = e.utilisateur_id "
       << "WHERE e.classe_id = " << classeId;

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Eleve eleve(row[1], row[2], row[3], row[4], row[5], row[11]);
                eleve.setId(std::stoi(row[0]));
                eleve.setIdEleve(std::stoi(row[10]));
                if (row[12]) eleve.setClasseId(std::stoi(row[12]));
                if (row[13]) eleve.setParentId(std::stoi(row[13]));
                eleves.push_back(eleve);
            }
            mysql_free_result(result);
        }
    }
    return eleves;
}
