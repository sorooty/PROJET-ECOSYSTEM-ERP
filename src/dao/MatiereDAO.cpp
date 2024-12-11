#include "../../include/dao/MatiereDAO.hpp"
#include <sstream>

MatiereDAO::MatiereDAO() {
    db = DatabaseConnection::getInstance();
}

bool MatiereDAO::ajouter(const Matiere& matiere) {
    std::stringstream ss;
    ss << "INSERT INTO matieres (nom, description, coefficient, volume_horaire) VALUES ('"
       << matiere.getNom() << "', '"
       << matiere.getDescription() << "', "
       << matiere.getCoefficient() << ", "
       << matiere.getVolumeHoraire() << ")";

    return db->executeQuery(ss.str());
}

std::vector<Matiere> MatiereDAO::getAll() {
    std::vector<Matiere> matieres;

    if (db->executeQuery("SELECT * FROM matieres")) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Matiere matiere(
                    row[1],  // nom
                    row[2],  // description
                    row[3] ? std::stoi(row[3]) : 1,  // coefficient
                    row[4] ? std::stoi(row[4]) : 0   // volume_horaire
                );
                matiere.setId(std::stoi(row[0]));
                matieres.push_back(matiere);
            }
            mysql_free_result(result);
        }
    }
    return matieres;
}

Matiere* MatiereDAO::getById(int id) {
    std::stringstream ss;
    ss << "SELECT * FROM matieres WHERE id_matiere = " << id;

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row = mysql_fetch_row(result);
            if (row) {
                Matiere* matiere = new Matiere(
                    row[1],  // nom
                    row[2],  // description
                    row[3] ? std::stoi(row[3]) : 1,  // coefficient
                    row[4] ? std::stoi(row[4]) : 0   // volume_horaire
                );
                matiere->setId(std::stoi(row[0]));

                mysql_free_result(result);
                return matiere;
            }
            mysql_free_result(result);
        }
    }
    return nullptr;
}

bool MatiereDAO::modifier(const Matiere& matiere) {
    std::stringstream ss;
    ss << "UPDATE matieres SET "
       << "nom = '" << matiere.getNom() << "', "
       << "description = '" << matiere.getDescription() << "', "
       << "coefficient = " << matiere.getCoefficient() << ", "
       << "volume_horaire = " << matiere.getVolumeHoraire()
       << " WHERE id_matiere = " << matiere.getId();

    return db->executeQuery(ss.str());
}

bool MatiereDAO::supprimer(int id) {
    std::stringstream ss;
    ss << "DELETE FROM matieres WHERE id_matiere = " << id;
    return db->executeQuery(ss.str());
}

bool MatiereDAO::assignerProfesseur(int matiereId, int profId, const std::string& anneeScolaire) {
    std::stringstream ss;
    ss << "INSERT INTO professeur_matiere (id_professeur, id_matiere, annee_scolaire) VALUES ("
       << profId << ", " << matiereId << ", '" << anneeScolaire << "')";

    return db->executeQuery(ss.str());
}

bool MatiereDAO::retirerProfesseur(int matiereId, int profId) {
    std::stringstream ss;
    ss << "DELETE FROM professeur_matiere WHERE id_matiere = " << matiereId
       << " AND id_professeur = " << profId;

    return db->executeQuery(ss.str());
}

std::vector<Matiere> MatiereDAO::getMatieresParClasse(int classeId) {
    std::vector<Matiere> matieres;
    std::stringstream ss;

    ss << "SELECT m.* FROM matieres m "
       << "JOIN classe_matiere cm ON m.id_matiere = cm.id_matiere "
       << "WHERE cm.id_classe = " << classeId;

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Matiere matiere(
                    row[1],  // nom
                    row[2],  // description
                    row[3] ? std::stoi(row[3]) : 1,  // coefficient
                    row[4] ? std::stoi(row[4]) : 0   // volume_horaire
                );
                matiere.setId(std::stoi(row[0]));
                matieres.push_back(matiere);
            }
            mysql_free_result(result);
        }
    }
    return matieres;
}

std::vector<Matiere> MatiereDAO::getMatieresParProfesseur(int profId) {
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
                Matiere matiere(
                    row[1],  // nom
                    row[2],  // description
                    row[3] ? std::stoi(row[3]) : 1,  // coefficient
                    row[4] ? std::stoi(row[4]) : 0   // volume_horaire
                );
                matiere.setId(std::stoi(row[0]));
                matieres.push_back(matiere);
            }
            mysql_free_result(result);
        }
    }
    return matieres;
}

bool MatiereDAO::ajouterMatiereClasse(int classeId, int matiereId, int profId, int volumeHoraire) {
    std::stringstream ss;
    ss << "INSERT INTO classe_matiere (id_classe, id_matiere, id_professeur, volume_horaire) VALUES ("
       << classeId << ", " << matiereId << ", " << profId << ", " << volumeHoraire << ")";

    return db->executeQuery(ss.str());
}

bool MatiereDAO::modifierVolumeHoraire(int classeId, int matiereId, int nouveauVolume) {
    std::stringstream ss;
    ss << "UPDATE classe_matiere SET volume_horaire = " << nouveauVolume
       << " WHERE id_classe = " << classeId
       << " AND id_matiere = " << matiereId;

    return db->executeQuery(ss.str());
}
