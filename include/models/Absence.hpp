#ifndef ABSENCE_HPP
#define ABSENCE_HPP

#include <string>

class Absence {
private:
    int id;
    int eleveId;
    std::string dateDebut;
    std::string dateFin;
    bool justifie;
    std::string motif;

public:
    Absence(int eleveId, const std::string& dateDebut, const std::string& dateFin);

    // Getters
    int getId() const { return id; }
    int getEleveId() const { return eleveId; }
    std::string getDateDebut() const { return dateDebut; }
    std::string getDateFin() const { return dateFin; }
    bool estJustifie() const { return justifie; }
    std::string getMotif() const { return motif; }

    // Setters
    void setId(int id) { this->id = id; }
    void setJustifie(bool justifie) { this->justifie = justifie; }
    void setMotif(const std::string& motif) { this->motif = motif; }

    // Validation
    bool estValide() const;
};

#endif 