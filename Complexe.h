//
// Created by clement on 03/03/2023.
//

#ifndef NOMBRESCOMPLEXES_COMPLEXE_H
#define NOMBRESCOMPLEXES_COMPLEXE_H

#include <string>

class Complexe {
public:
    Complexe(double, double);
    explicit Complexe(const std::string&);

    std::string toString() const;

    Complexe getConjugue() const;
    double getModule();

    Complexe& operator +=(Complexe&);
    Complexe& operator -=(Complexe&);
    Complexe& operator /=(const Complexe&);
    Complexe& operator *=(const Complexe&);

    Complexe operator +(Complexe&) const;
    Complexe operator -(Complexe&) const;
    Complexe operator /(Complexe&) const;
    Complexe operator *(Complexe&) const;

    double getReel() const;
    void setReel(const double&);
    double getImaginaire() const;
    void setImaginaire(const double&);

private:
    double m_dReel;
    double m_dImaginaire;
};


#endif //NOMBRESCOMPLEXES_COMPLEXE_H
