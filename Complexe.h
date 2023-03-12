//
// Created by clement on 03/03/2023.
//

#ifndef NOMBRESCOMPLEXES_COMPLEXE_H
#define NOMBRESCOMPLEXES_COMPLEXE_H

#include <string>

class Complexe {
public:
    Complexe(double, double);
    Complexe(std::string);

    std::string toString();

    Complexe operator +(Complexe&) const;
    Complexe operator -(Complexe&) const;
    Complexe operator /(Complexe&) const;
    Complexe operator *(Complexe&) const;

    Complexe& operator +=(Complexe&);
    Complexe& operator -=(Complexe&);
    Complexe& operator /=(Complexe&);
    Complexe& operator *=(Complexe&);

private:
    double reel;
    double imaginaire;
};


#endif //NOMBRESCOMPLEXES_COMPLEXE_H
