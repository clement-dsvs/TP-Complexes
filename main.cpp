#include <iostream>
#include "Complexe.h"
#include <string>
#include "printf.h"

int main() {
    Complexe c1(1,1);
    Complexe c2 = c1.getConjugue();
    std::cout << c1.toString() << std::endl;
}
