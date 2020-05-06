#!/usr/bin/python3
from math import *

# ln(x) definition
def ln(x):
    return log(x, e)


# function equation implementation copyRight Baraa Al-Masri. LOL :)
y = 0 # some initial value for y before the big change :)
def func(x, polynomial): # pol = polynomial
    updateY = "global y; " + polynomial
    exec(updateY)
    return y


# derivative formula
def diff(point, approachingPoint, fx):
    # reminder
    # f'(a) = (f(a+h) - f(a))/(h)
    return (func(point + approachingPoint, fx) - func(point, fx)) / approachingPoint


def findRootnewton(initialPoint, fx, error):
    difference = 9e12  # assigned to a very high value to make the loop's condition true
    xi = initialPoint  # first point
    xi1 = 0  # i-th point
    steps = 0
    while error <= difference or difference != 0:
        # reminder of newton's method formula:
        # x0 = constant //initial point
        # Xi+1 = Xi - (f(Xi)/f'(Xi)) //i-th point
        xi1 = xi - (func(xi, fx) / diff(xi, 0.0000001, fx))
        difference = abs(xi1 - xi)

        steps += 1
        xi = xi1

    print("\nnumber of steps ", steps)
    print("root =", xi1)


################################################################

print("---------------------------")
print("-= Newton-Raphson Method =-")
print("---------------------------\n")

equation = "y = "  # polynomial assignment statement
equation += str(input("Enter function's formula: \nf(x) = "))
x0 = float(input("Enter x0: "))  # initial point in the newton sequence
errorTolerance = float(input("Enter error tolerance \nerror = "))

findRootnewton(x0, equation, errorTolerance)
