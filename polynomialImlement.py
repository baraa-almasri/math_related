#!/usr/bin/python3
from math import *


# ln definition
def ln(x):
    return log(x, e)

# function equation implementation copyRight Baraa Al-Masri.
# LOL :)
y = None  # some initial value for y before the big change :)

def func(x, polynomial) -> float:
    updateY = "global y; " + polynomial  # calling the global y then applying change to the string "updateY"
    exec(updateY)  # executing the string to find f(a)
    return y

# derivative formulas
def diff(point, approachingPoint, fx) -> float:
    # reminder
    # f'(a) = (f(a+h) - f(a))/(h)
    # just applying first derivative's formula
    return (func(point + approachingPoint, fx) - func(point, fx)) / approachingPoint

def secondDiffrentiate(point, approachingPoint, fx) -> float:
    # reminder
    # f''(a) = (f(a-h) - 2f(a) + f(a+h))/(h^2)
    # just applying second derivative's formula
    return (func(point - approachingPoint, fx) - 2 * func(point, fx) + func(point + approachingPoint, fx)) / (
                approachingPoint ** 2)

################################################################
################################################################

equation = "y = "  # polynomial assignment statement
equation += str(input("Enter function's formula: \nNote that x^n ==> x**n \nf(x) = "))


while True:
    x0 = float(input("Enter x: "))  # point to find the second derivative at


    print("f(%f) = " % x0, end="")
    print(func(x0, equation))

    print("f'(%f) = " % x0, end="")
    print(diff(x0, 0.0000001, equation))

    print("f''(%f) = " % x0, end="")
    print(secondDiffrentiate(x0, 0.0000001, equation))

    print()
#:    print("1. Continue, 2. Exit")
 #   exit = int(input())
  #  if exit == 2:
   #     break

