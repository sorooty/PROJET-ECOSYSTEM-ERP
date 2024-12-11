#include "../../include/dao/NoteDAO.hpp"
#include <sstream>

NoteDAO::NoteDAO() {
    db = DatabaseConnection::getInstance();
}

bool NoteDAO::ajouter(const Note& note) {
    if (!note.estValide()) {
        if (note.getEleveId() <= 0) {
            std::cout << "Erreur : L'identifiant de l'élève est invalide." << std::endl;
            return false;
        }
        if (note.getMatiereId() <= 0) {
            std::cout << "Erreur : L'identifiant de la matière est invalide." << std::endl;
            return false;
        }
        if (note.getProfesseurId() <= 0) {
            std::cout << "Erreur : L'identifiant du professeur est invalide." << std::endl;
            return false;
        }
        if (note.getValeur() < 0 || note.getValeur() > 20) {
            std::cout << "Erreur : La note doit être comprise entre 0 et 20." << std::endl;
            return false;
        }
        if (note.getCoefficient() <= 0) {
            std::cout << "Erreur : Le coefficient doit être supérieur à 0." << std::endl;
            return false;
        }
        return false;
    }

    std::stringstream checkEleve;
    checkEleve << "SELECT COUNT(*) FROM utilisateurs WHERE id_utilisateur = " << note.getEleveId();
    if (db->executeQuery(checkEleve.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row = mysql_fetch_row(result);
            if (row && std::stoi(row[0]) == 0) {
                std::cout << "Erreur : L'élève spécifié n'existe pas." << std::endl;
                mysql_free_result(result);
                return false;
            }
            mysql_free_result(result);
        }
    }

    std::stringstream ss;
    ss << "INSERT INTO notes ("
       << "id_eleve, "
       << "id_matiere, "
       << "id_professeur, "
       << "note, "
       << "coefficient, "
       << "type_evaluation, "
       << "date_evaluation, "
       << "commentaire) VALUES ("
       << note.getEleveId() << ", "
       << note.getMatiereId() << ", "
       << note.getProfesseurId() << ", "
       << note.getValeur() << ", "
       << note.getCoefficient() << ", '"
       << note.getTypeEvaluation() << "', '"
       << note.getDateEvaluation() << "', "
       << (note.getCommentaire().empty() ? "NULL" : "'" + note.getCommentaire() + "'")
       << ")";

    bool success = db->executeQuery(ss.str());
    if (!success) {
        std::string erreur = db->getLastError();
        if (erreur.find("foreign key constraint") != std::string::npos) {
            if (erreur.find("id_matiere") != std::string::npos) {
                std::cout << "Erreur : La matière spécifiée n'existe pas." << std::endl;
            } else if (erreur.find("id_professeur") != std::string::npos) {
                std::cout << "Erreur : Le professeur spécifié n'existe pas." << std::endl;
            } else {
                std::cout << "Erreur : Une des références n'existe pas dans la base de données." << std::endl;
            }
        } else {
            std::cout << "Erreur : Impossible d'ajouter la note. Veuillez vérifier les informations saisies." << std::endl;
        }
        return false;
    }

    std::cout << "Note ajoutée avec succès!" << std::endl;
    return true;
}

bool NoteDAO::modifier(const Note& note) {
    if (!note.estValide()) return false;

    std::stringstream ss;
    ss << "UPDATE notes SET "
       << "note = " << note.getValeur() << ", "
       << "coefficient = " << note.getCoefficient() << ", "
       << "type_evaluation = '" << note.getTypeEvaluation() << "', "
       << "commentaire = " << (note.getCommentaire().empty() ? "NULL" : "'" + note.getCommentaire() + "'")
       << " WHERE id_note = " << note.getId();

    return db->executeQuery(ss.str());
}

std::vector<Note> NoteDAO::getNotesEleve(int eleveId) {
    std::vector<Note> notes;
    std::stringstream ss;

    ss << "SELECT * FROM notes WHERE id_eleve = " << eleveId
       << " ORDER BY date_evaluation DESC";

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Note note(
                    std::stoi(row[1]),  // eleveId
                    std::stoi(row[2]),  // matiereId
                    std::stoi(row[3]),  // professeurId
                    std::stod(row[4]),  // valeur
                    std::stoi(row[5])   // coefficient
                );
                note.setId(std::stoi(row[0]));
                note.setTypeEvaluation(row[6]);
                note.setDateEvaluation(row[7]);
                if (row[8]) note.setCommentaire(row[8]);

                notes.push_back(note);
            }
            mysql_free_result(result);
        }
    }
    return notes;
}

double NoteDAO::getMoyenneEleve(int eleveId, int matiereId) {
    std::stringstream ss;
    ss << "SELECT SUM(note * coefficient) / SUM(coefficient) as moyenne "
       << "FROM notes WHERE id_eleve = " << eleveId;

    if (matiereId > 0) {
        ss << " AND id_matiere = " << matiereId;
    }

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row = mysql_fetch_row(result);
            if (row && row[0]) {
                double moyenne = std::stod(row[0]);
                mysql_free_result(result);
                return moyenne;
            }
            mysql_free_result(result);
        }
    }
    return 0.0;
}

double NoteDAO::getMoyenneClasse(int classeId, int matiereId) {
    std::stringstream ss;
    ss << "SELECT AVG(moyenne_eleve) FROM ("
       << "SELECT id_eleve, SUM(note * coefficient) / SUM(coefficient) as moyenne_eleve "
       << "FROM notes n "
       << "INNER JOIN inscriptions i ON n.id_eleve = i.id_eleve "
       << "WHERE i.id_classe = " << classeId;

    if (matiereId > 0) {
        ss << " AND n.id_matiere = " << matiereId;
    }

    ss << " GROUP BY id_eleve) as moyennes_individuelles";

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row = mysql_fetch_row(result);
            if (row && row[0]) {
                double moyenne = std::stod(row[0]);
                mysql_free_result(result);
                return moyenne;
            }
            mysql_free_result(result);
        }
    }
    return 0.0;
}
