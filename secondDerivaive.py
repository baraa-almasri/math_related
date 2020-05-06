#!/usr/bin/python3
from math import *


# logs definition
def ln(x):
    return log(x, e)

def log(x):
    return log10(x)


# function equation implementation copyRight Baraa Al-Masri. LOL :)
y = 0  # some initial value for y before the big change :)
def func(x, polynomial):  # pol = polynomial
    updateY = "global y; " + polynomial
    exec(updateY)
    return y


# 2nd derivative formula
def secondDiffrentiate(point, approachingPoint, fx):
    # reminder
    # f''(a) = (f(a-h) - 2f(a) + f(a+h))/(h^2)
    return (func(point - approachingPoint, fx) - 2 * func(point, fx) + func(point + approachingPoint, fx)) / (
                approachingPoint ** 2)


################################################################

print("------------------------------")
print("-= Second Derivative Finder =-")
print("------------------------------\n")

equation = "y = "  # polynomial assignment statement
equation += str(input("Enter function's formula: \nNote that x^n ==> x**n \nf(x) = "))
x0 = float(input("Enter x0: "))  # point to find the second derivative at
approachingPoint = float(input("Enter approachingPoint \nh = "))

print("f''(", x0, ") = ", end="")
print(secondDiffrentiate(x0, approachingPoint, equation))

