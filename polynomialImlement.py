#!/usr/bin/python3
from math import *


# ln definition
def ln(x):
    return log(x, e)

# function equation implementation copyRight Baraa Al-Masri.
# LOL :)
y = 0  # some initial value for y before the big change :)
def func(x, polynomial):  # pol = polynomial
    updateY = "global y; " + polynomial
    exec(updateY)
    return y

# derivative formulas
def diff(point, approachingPoint, fx):
    # reminder
    # f'(a) = (f(a+h) - f(a))/(h)
    return (func(point + approachingPoint, fx) - func(point, fx)) / approachingPoint

def secondDiffrentiate(point, approachingPoint, fx):
    # reminder
    # f''(a) = (f(a-h) - 2f(a) + f(a+h))/(h^2)
    return (func(point - approachingPoint, fx) - 2 * func(point, fx) + func(point + approachingPoint, fx)) / (
                approachingPoint ** 2)

################################################################
################################################################

equation = "y = "  # polynomial assignment statement
equation += str(input("Enter function's formula: \nNote that x^n ==> x**n \nf(x) = "))
x0 = float(input("Enter x: "))  # point to find the second derivative at


print("f(", x0, ") = ", end="")
print(func(x0, equation))

print("f'(", x0, ") = ", end="")
print(diff(x0, 0.00001, equation))

print("f''(", x0, ") = ", end="")
print(secondDiffrentiate(x0, 0.00001, equation))
