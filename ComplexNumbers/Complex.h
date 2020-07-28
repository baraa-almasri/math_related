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
    // inverse
    Complex<type> *getInverse();
    
    // check if the number is pure real or imaginary 
    bool isPureReal();
    bool isPureImaginary();

    // get conjugate of the complex number
    Complex<type> *getConjugate();

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
// multiply a complex number to the current complex number
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

TEMP
// devide the current complex number over the given complex number
void Complex<type>::operator/=(Complex<type> anotherComplex) {
    // temporary complex number 
    Complex<type> *tmp = new Complex<type>(this->getReal(), this->getImaginary());

    if(anotherComplex.isPureReal()) {
        // multiply and divide by other number's conjugate
        anotherComplex *= *anotherComplex.getConjugate();
        *tmp *= *anotherComplex.getConjugate();

        type denominatorValue;
        denominatorValue = anotherComplex.getReal();

        this->setReal( tmp->getReal() / denominatorValue );
        this->setImaginary( tmp->getImaginary() / denominatorValue );
    }

    *this *= *anotherComplex.getInverse();

    // update representitive strings
    updateAlgebraicString();

    // return object of the same type
    //return *this;
}

// other functions

TEMP
// update algebraic representation
void Complex<type>::updateAlgebraicString() {
    this->algebraicRepresntation = 
        (this->isPureImaginary()? "": std::to_string(getReal()) ) // add real part
        + ( this->getImaginary() > 0 && !this->isPureReal()? " + ": " ") // add a plus sign if there's no one
        + ( this->isPureReal() ? "": std::to_string(getImaginary()) ) // add imaginary part
        + ( this->isPureReal() ? "": "i"); // add imaginary unit
}

TEMP
Complex<type> *Complex<type>::getConjugate() {
    
    Complex<type> *tmp = new Complex<type>(this->getReal(), this->getImaginary());
    // multiply the imaginary part by -1
    tmp->setImaginary( -1*tmp->getImaginary() );
    
    return tmp;
}
TEMP
// get algebraic representation of the complex number
std::string Complex<type>::getAlgebraic() {
    return this->algebraicRepresntation;
}

TEMP
// check if complex number is pure real
bool Complex<type>::isPureReal() {
    return this->getImaginary() == 0; 
}

TEMP
// check if complex number is pure imaginary
bool Complex<type>::isPureImaginary() {
    return this->getReal() == 0; 
}

TEMP
// get inverse of the complex number
Complex<type> *Complex<type>::getInverse() {
    // Z = a + bi
    // Z' = 1/(a + bi)
    // Z' = ~Z / ~Z*Z
    // Z' = ~Z / (some x ∈ R)

    // temp copy complex number
    Complex<type> *tmp = new Complex<type>(this->getReal(), this->getImaginary());
    
    *tmp *= *(tmp->getConjugate() );
    type theXmentionedAbove = tmp->getReal();

    // temp parts
    type tmpReal;
    type tmpImg;

    // assign values
    tmpReal = this->getConjugate()->getReal() / theXmentionedAbove;
    tmpImg = this->getConjugate()->getImaginary() / theXmentionedAbove;

    // another temp
    Complex<type> *inverse = new Complex<type>(tmpReal, tmpImg);

    return inverse;
}

#endif // COMPLEX_H