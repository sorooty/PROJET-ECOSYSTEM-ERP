#include "../../include/dao/PaiementDAO.hpp"
#include <sstream>

PaiementDAO::PaiementDAO() {
    db = DatabaseConnection::getInstance();
}

bool PaiementDAO::ajouter(const Paiement& paiement) {
    if (!paiement.estValide()) return false;

    std::stringstream ss;
    ss << "INSERT INTO paiements (id_facture, montant, date_paiement, "
       << "methode_paiement) VALUES ("
       << paiement.getFactureId() << ", "
       << paiement.getMontant() << ", '"
       << paiement.getDatePaiement() << "', '"
       << paiement.getMethodePaiement() << "')";

    return db->executeQuery(ss.str());
}

bool PaiementDAO::modifier(const Paiement& paiement) {
    if (!paiement.estValide()) return false;

    std::stringstream ss;
    ss << "UPDATE paiements SET "
       << "montant = " << paiement.getMontant() << ", "
       << "methode_paiement = '" << paiement.getMethodePaiement() << "' "
       << "WHERE id_paiement = " << paiement.getId();

    return db->executeQuery(ss.str());
}

bool PaiementDAO::supprimer(int id) {
    std::stringstream ss;
    ss << "DELETE FROM paiements WHERE id_paiement = " << id;
    return db->executeQuery(ss.str());
}

Paiement* PaiementDAO::getById(int id) {
    std::stringstream ss;
    ss << "SELECT * FROM paiements WHERE id_paiement = " << id;

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row = mysql_fetch_row(result);
            if (row) {
                Paiement* paiement = new Paiement(
                    std::stoi(row[1]),     // factureId
                    std::stod(row[2]),     // montant
                    row[3],                // datePaiement
                    row[4]                 // methodePaiement
                );
                paiement->setId(std::stoi(row[0]));
                mysql_free_result(result);
                return paiement;
            }
            mysql_free_result(result);
        }
    }
    return nullptr;
}

std::vector<Paiement> PaiementDAO::getAll() {
    std::vector<Paiement> paiements;
    std::string query = "SELECT * FROM paiements ORDER BY date_paiement DESC";

    if (db->executeQuery(query)) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Paiement paiement(
                    std::stoi(row[1]),     // factureId
                    std::stod(row[2]),     // montant
                    row[3],                // datePaiement
                    row[4]                 // methodePaiement
                );
                paiement.setId(std::stoi(row[0]));
                paiements.push_back(paiement);
            }
            mysql_free_result(result);
        }
    }
    return paiements;
}

std::vector<Paiement> PaiementDAO::getPaiementsParFacture(int factureId) {
    std::vector<Paiement> paiements;
    std::stringstream ss;
    
    ss << "SELECT * FROM paiements WHERE id_facture = " << factureId
       << " ORDER BY date_paiement DESC";

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Paiement paiement(
                    std::stoi(row[1]),     // factureId
                    std::stod(row[2]),     // montant
                    row[3],                // datePaiement
                    row[4]                 // methodePaiement
                );
                paiement.setId(std::stoi(row[0]));
                paiements.push_back(paiement);
            }
            mysql_free_result(result);
        }
    }
    return paiements;
}

double PaiementDAO::getTotalPaiementsFacture(int factureId) {
    std::stringstream ss;
    ss << "SELECT SUM(montant) FROM paiements WHERE id_facture = " << factureId;

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row = mysql_fetch_row(result);
            if (row && row[0]) {
                double total = std::stod(row[0]);
                mysql_free_result(result);
                return total;
            }
            mysql_free_result(result);
        }
    }
    return 0.0;
} 