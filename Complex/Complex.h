#ifndef COMPLEX_H
#define COMPLEX_H

#include <string>

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
    void operator+=(Complex<type> );
    
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