// src/models/Enseignement.cpp
#include "../../include/models/Enseignement.hpp"
#include <sstream>

Enseignement::Enseignement(int professeurId, int matiereId, int classeId)
    : professeurId(professeurId), matiereId(matiereId), classeId(classeId) {
    id = 0;
}

int Enseignement::getId() const {
    return id;
}

int Enseignement::getProfesseurId() const {
    return professeurId;
}

int Enseignement::getMatiereId() const {
    return matiereId;
}

int Enseignement::getClasseId() const {
    return classeId;
}

void Enseignement::setId(int newId) {
    id = newId;
}

void Enseignement::setProfesseurId(int newProfesseurId) {
    professeurId = newProfesseurId;
}

void Enseignement::setMatiereId(int newMatiereId) {
    matiereId = newMatiereId;
}

void Enseignement::setClasseId(int newClasseId) {
    classeId = newClasseId;
}

bool Enseignement::estValide() const {
    return professeurId > 0 && matiereId > 0 && classeId > 0;
}

std::string Enseignement::toString() const {
    std::stringstream ss;
    ss << "Enseignement [ID: " << id
       << ", Professeur: " << professeurId
       << ", Matière: " << matiereId
       << ", Classe: " << classeId
       << "]";
    return ss.str();
}
