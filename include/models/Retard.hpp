#ifndef RETARD_HPP
#define RETARD_HPP

#include <string>

class Retard {
private:
    int id;
    int eleveId;
    std::string dateRetard;
    std::string heureArrivee;
    int dureeMinutes;
    bool justifie;
    std::string motif;
    int validateurId;

public:
    Retard(int eleveId, const std::string& dateRetard, 
           const std::string& heureArrivee, int dureeMinutes);

    // Getters
    int getId() const { return id; }
    int getEleveId() const { return eleveId; }
    std::string getDateRetard() const { return dateRetard; }
    std::string getHeureArrivee() const { return heureArrivee; }
    int getDureeMinutes() const { return dureeMinutes; }
    bool estJustifie() const { return justifie; }
    std::string getMotif() const { return motif; }
    int getValidateurId() const { return validateurId; }

    // Setters
    void setId(int id) { this->id = id; }
    void setJustifie(bool justifie) { this->justifie = justifie; }
    void setMotif(const std::string& motif) { this->motif = motif; }
    void setValidateurId(int id) { this->validateurId = id; }

    // Validation
    bool estValide() const;
};

#endif 