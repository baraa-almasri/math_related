#include "Complex.h"
#include <iostream>

int main() {
    Complex<double> *z = new Complex<double>(3, 2);
    
    std::cout << "z = " << z->getAlgebraic() << std::endl;
    
    *z += *(new Complex<double>(6,9));
    std::cout << "z = " << z->getAlgebraic() << std::endl;
    
    Complex<double> *c = new Complex<double>(1,1);
    *z += *c;
    std::cout << "z = " << z->getAlgebraic() << std::endl;
    
    *z -= *(new Complex<double>(10,30));
    std::cout << "z = " << z->getAlgebraic() << std::endl;

    *z *= *(new Complex<double>(3,2));
    std::cout << "z = " << z->getAlgebraic() << std::endl;

    *z *= *(z->getConjugate());
    
    std::cout << "z = " << z->getAlgebraic() << std::endl;
   
    std::cout << "z = " << z->getInverse()->getAlgebraic() << std::endl;

    *z /= *(new Complex<double>(2, 3));
    std::cout << "z = " << z->getAlgebraic() << std::endl;

    return 0;
}