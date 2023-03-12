//
// Created by clement on 03/03/2023.
//

#include "Complexe.h"
#include <string>

Complexe::Complexe(double reel, double imaginaire) : reel(reel), imaginaire(imaginaire) {}

Complexe::Complexe(std::string nombre) {
    // [signe]reel[signe_im]imaginaire[i]
    std::string part1, part2;
    char signe1 = ' ', signe2 = ' ';

    for(auto tempChar : nombre)
    {
        if (tempChar == '-' || tempChar == '+')
        {
            if(signe1 == ' ') {
                signe1 = tempChar;
            }
            else {
                signe2 = tempChar;
            }
        }
        else {
            if(signe2 != ' ') part2 += tempChar;
            else part1 += tempChar;
        }
    }



}

std::string Complexe::toString() {
    char signe_reel = reel > 0 ? '\0' : '-';
    char signe_ima = imaginaire > 0 ? '+' : '-';
    return signe_reel + std::to_string(reel) + signe_ima + std::to_string(imaginaire) + "i";
}

Complexe Complexe::operator+(Complexe &c) const {
    return Complexe(reel + c.reel, imaginaire + c.imaginaire);
}

Complexe Complexe::operator-(Complexe &c) const {
    return Complexe(reel - c.reel, imaginaire - c.imaginaire);
}

Complexe Complexe::operator*(Complexe &c) const {
    double NvReel = reel * c.reel - imaginaire * c.imaginaire;
    double NvImaginaire = reel * c.reel + imaginaire * c.imaginaire;
    return Complexe(NvReel, NvImaginaire);
}

Complexe Complexe::operator/(Complexe &c) const {
    return;
}

Complexe &Complexe::operator+=(Complexe &complexe) {
    reel += complexe.reel;
    imaginaire += complexe.imaginaire;
}

Complexe &Complexe::operator-=(Complexe &complexe) {
    return ;
}

Complexe &Complexe::operator/=(Complexe &complexe) {
    return ;
}

Complexe &Complexe::operator*=(Complexe &complexe) {
    return ;
}
