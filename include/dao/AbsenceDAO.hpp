#ifndef ABSENCEDAO_HPP
#define ABSENCEDAO_HPP

#include "../models/Absence.hpp"
#include "../DatabaseConnection.hpp"
#include <vector>

class AbsenceDAO {
private:
    DatabaseConnection* db;

public:
    AbsenceDAO();

    // Méthodes CRUD adaptées
    bool ajouter(const Absence& absence);
    bool supprimer(int id);
    std::vector<Absence> getAll();
    
    // Méthodes spécifiques
    std::vector<Absence> getAbsencesEleve(int eleveId);
    std::vector<Absence> getAbsencesNonJustifiees();
    bool justifierAbsence(int absenceId, const std::string& motif);
    int compterAbsencesEleve(int eleveId, const std::string& dateDebut, const std::string& dateFin);
};

#endif 