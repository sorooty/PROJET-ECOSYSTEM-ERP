#ifndef NOTE_HPP
#define NOTE_HPP

#include <string>

class Note {
private:
    int id;
    int eleveId;
    int matiereId;
    int professeurId;
    double valeur;
    int coefficient;
    std::string typeEvaluation;
    std::string dateEvaluation;
    std::string commentaire;

public:
    Note(int eleveId, int matiereId, int professeurId, double valeur, 
         int coefficient = 1, const std::string& type = "Contrôle continu");

    // Getters
    int getId() const { return id; }
    int getEleveId() const { return eleveId; }
    int getMatiereId() const { return matiereId; }
    int getProfesseurId() const { return professeurId; }
    double getValeur() const { return valeur; }
    int getCoefficient() const { return coefficient; }
    std::string getTypeEvaluation() const { return typeEvaluation; }
    std::string getDateEvaluation() const { return dateEvaluation; }
    std::string getCommentaire() const { return commentaire; }

    // Setters
    void setId(int id) { this->id = id; }
    void setValeur(double valeur) { this->valeur = valeur; }
    void setCoefficient(int coef) { this->coefficient = coef; }
    void setTypeEvaluation(const std::string& type) { this->typeEvaluation = type; }
    void setDateEvaluation(const std::string& date) { this->dateEvaluation = date; }
    void setCommentaire(const std::string& com) { this->commentaire = com; }

    // Méthodes de validation
    bool estValide() const;
};

#endif 