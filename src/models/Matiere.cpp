#include "../../include/models/Matiere.hpp"

Matiere::Matiere(const std::string& nom, const std::string& description,
                 int coefficient, int volumeHoraire)
    : nom(nom),
      description(description),
      coefficient(coefficient),
      volumeHoraire(volumeHoraire)
{
    id = 0;
}

// Getters
int Matiere::getId() const { return id; }
std::string Matiere::getNom() const { return nom; }
std::string Matiere::getDescription() const { return description; }
int Matiere::getCoefficient() const { return coefficient; }
int Matiere::getVolumeHoraire() const { return volumeHoraire; }

// Setters
void Matiere::setId(int id) { this->id = id; }
void Matiere::setNom(const std::string& nom) { this->nom = nom; }
void Matiere::setDescription(const std::string& description) { this->description = description; }
void Matiere::setCoefficient(int coefficient) { this->coefficient = coefficient; }
void Matiere::setVolumeHoraire(int volume) { this->volumeHoraire = volume; }

bool Matiere::estValide() const {
    return !nom.empty() && coefficient > 0 && volumeHoraire >= 0;
}

std::string Matiere::toString() const {
    return nom + " (Coefficient: " + std::to_string(coefficient) + ")";
}
