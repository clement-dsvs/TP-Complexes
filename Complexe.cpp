//
// Created by clement on 03/03/2023.
//

#include "Complexe.h"
#include <string>

Complexe::Complexe(double a_reel, double a_imaginaire) : m_dReel(a_reel), m_dImaginaire(a_imaginaire) {}

Complexe::Complexe(const std::string &nombre) {
    int position = 0;
    std::string tableau[2], temp;

    for (int i = 0; i < nombre.size(); i++) { // Lecture intégrale de la chaîne de caractères

        // Vérification pour stocker correctemment la partie réelle et m_dImaginaire dans le tableau
        if (i != 0 && (nombre[i] == '+' || nombre[i] == '-')) {
            tableau[position] = temp;
            temp = nombre[i];
            position = 1;
        } else if (nombre[i] == 'i' && position == 0) {
            position = 1;
            temp += nombre[i];
        } else {
            temp += nombre[i];
        }

    }
    tableau[position] = temp;

    // S'il n'y a pas de partie réelle
    if (tableau[0].empty()) {
        tableau[0] = "0";
    }

    // Vérification de la partie m_dImaginaire
    if (tableau[1].empty()) {
        tableau[1] = "0";
    } else if (tableau[1] == "i" || tableau[1] == "+i") {
        tableau[1] = "1";
    } else if (tableau[1] == "-i") {
        tableau[1] = "-1";
    } else {
        tableau[1].replace(tableau[1].find('i'), 1, ""); // Supprimer le i en le remplaçant par rien
    }

    // Suppression du signe devant un 0 pour la partie réelle
    if (tableau[0] == "+0" || tableau[0] == "-0") {
        tableau[0] = "0";
    }

    // Suppression du signe devant un 0 pour la partie m_dImaginaire
    if (tableau[1] == "+0" || tableau[1] == "-0") {
        tableau[1] = "0";
    }

    m_dReel = stod(tableau[0]);
    m_dImaginaire = stod(tableau[1]);
}

std::string Complexe::toString() const {
    char signe_ima = m_dImaginaire > 0 ? '+' : ' ';
    return std::to_string(m_dReel) + signe_ima + std::to_string(m_dImaginaire) + "i";
}

Complexe Complexe::getConjugue() const {
    return Complexe(m_dReel, m_dImaginaire * -1);
}

double Complexe::getModule() {
    return std::sqrt(m_dReel * m_dReel + m_dImaginaire * m_dImaginaire);
}

Complexe &Complexe::operator+=(Complexe &c) {
    m_dReel += c.m_dReel;
    m_dImaginaire += c.m_dImaginaire;
    return *this;
}

Complexe &Complexe::operator-=(Complexe &c) {
    m_dReel -= c.m_dReel;
    m_dImaginaire -= c.m_dImaginaire;
    return *this;
}

Complexe &Complexe::operator*=(const Complexe &c) {
    m_dReel = m_dReel * c.m_dReel - m_dImaginaire * c.m_dImaginaire;
    m_dImaginaire = m_dReel * c.m_dReel + m_dImaginaire * c.m_dImaginaire;
    //std::complex c3;
    return *this;
}

Complexe &Complexe::operator/=(const Complexe &c) {
    double _r = m_dReel * c.m_dReel + m_dImaginaire * c.m_dImaginaire;
    double _n = m_dReel * m_dReel + m_dImaginaire * m_dImaginaire;
    m_dImaginaire = (m_dImaginaire * c.m_dReel - m_dReel * c.m_dImaginaire) / _n;
    m_dReel = _r / _n;
    return *this;
}

Complexe Complexe::operator+(Complexe &c) const {
    return Complexe(m_dReel + c.m_dReel, m_dImaginaire + c.m_dImaginaire);
}

Complexe Complexe::operator-(Complexe &c) const {
    return Complexe(m_dReel - c.m_dReel, m_dImaginaire - c.m_dImaginaire);
}

Complexe Complexe::operator*(Complexe &c) const {
    Complexe c1 = c;
    c1 *= *this;
    return c1;
}

Complexe Complexe::operator/(Complexe &c) const {
    Complexe c1 = c;
    c1 /= *this;
    return c1;
}

double Complexe::getReel() const {
    return m_dReel;
}

void Complexe::setReel(const double &r) {
    m_dReel = r;
}

double Complexe::getImaginaire() const {
    return m_dImaginaire;
}

void Complexe::setImaginaire(const double &ima) {
    m_dImaginaire = ima;
}