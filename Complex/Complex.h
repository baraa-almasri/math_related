#ifndef COMPLEX_H
#define COMPLEX_H

#include <string> // for represintations
#include <ostream>

#define TEMP template<typename type>

TEMP
// type must be numerical
class Complex {
public:
    // dont use a not numeric type!
    Complex<type>(type, type);
    
    // setters & getters
    type getReal();
    Complex<type> setReal(type);
    type getImaginary();
    Complex<type> setImaginary(type);
    
    // operations
    void operator+=(Complex<type>);
    void operator-=(Complex<type>);
    void operator*=(Complex<type>);
    void operator/=(Complex<type>);
    //void operator=(Complex<type>);
    
    
    // get algebraic representaion of the complex number
    std::string getAlgebraic();

private:
    type real;
    type imaginary;

    // complex number as a string
    std::string algebraicRepresntation;
    // update algebraic representation
    void updateAlgebraicString();

};


TEMP
// coonstructor
Complex<type>::Complex(type real, type imaginary) {
    this->real = real;
    this->imaginary = imaginary;
    // update representitive strings
    this->updateAlgebraicString();
}

// setters & getters
TEMP
type Complex<type>::getReal() {
    return this->real;
}

TEMP
Complex<type> Complex<type>::setReal(type real) {
    this->real = real;

    // update representitive strings
    updateAlgebraicString();

    // return object of the same type
    return *this;
}

TEMP
type Complex<type>::getImaginary() {
    return this->imaginary;
}

TEMP
Complex<type> Complex<type>::setImaginary(type imaginary) {
    this->imaginary = imaginary;

    // update representitive strings
    updateAlgebraicString();

    // return object of the same type
    return *this;
}

// operators

TEMP
// add a complex number to the current complex number
void Complex<type>::operator+=(Complex<type> anotherComplex) {
    this->real += anotherComplex.getReal();
    this->imaginary += anotherComplex.getImaginary();

    // update representitive strings
    updateAlgebraicString();

    // return object of the same type
    //return *this;
}

TEMP
// subtract a complex number from the current complex number
void Complex<type>::operator-=(Complex<type> anotherComplex) {
    // subtracting a complex number from an another complex number is same as
    // adding the number to -1*number
    
    Complex<type> tmp = anotherComplex;

    tmp.setReal(-1 * tmp.getReal());
    tmp.setImaginary(-1 * tmp.getImaginary());
    *this += tmp;

    // update representitive strings
    updateAlgebraicString();

}

TEMP
// add a complex number to the current complex number
void Complex<type>::operator*=(Complex<type> anotherComplex) {
    // oh this will be messy 
    // res = (a + bi)(x + yi)
    // res = a*x + a*yi + bi*x + bi*yi
    // res = ax + (-1)by + (ay + xb)i 
    // i.e .... re = ax + (-1)by, im = ay + xb

    // resulting parts
    type re, im;
    re =  this->getReal() * anotherComplex.getReal() + (-1)*(this->getImaginary() * anotherComplex.getImaginary());
    im = this->getReal() * anotherComplex.getImaginary() + this->getImaginary() * anotherComplex.getReal();

    this->setReal(re);
    this->setImaginary(im);

    // update representitive strings
    updateAlgebraicString();

}

// other functions

TEMP
// update algebraic representation
void Complex<type>::updateAlgebraicString() {
    this->algebraicRepresntation = std::to_string(getReal()) + " + " + std::to_string(getImaginary()) + "i";
}

TEMP
// get algebraic representation of the complex number
std::string Complex<type>::getAlgebraic() {
    return this->algebraicRepresntation;
}

#endif // COMPLEX_H