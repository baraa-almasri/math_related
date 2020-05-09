#!/usr/bin/python3
from math import *


# ln definition
def ln(x):
    return log(x, e)

# function equation implementation copyRight Baraa Al-Masri.
# LOL :)
y = None  # some initial value for y before the big change :)

def func(x, polynomial):
    updateY = "global y; " + polynomial  # calling the global y then applying change to the string "updateY"
    exec(updateY)  # executing the string to find f(a)
    return y

# five-point formula
def fivePoint(point, approachingPoint, fx) -> float:
    # reminder
    # f'(a) = (f(a-2h) - 8f(a-h) + 8f(a+h) - f(a+2h))/(12h)
    # just applying second derivative's formula
    return (func(point - 2*approachingPoint, fx) - 8*func(point - approachingPoint, fx)
            + 8 * func(point + approachingPoint, fx) - func(point + 2*approachingPoint, fx)) / (
                approachingPoint * 12)


################################################################
################################################################

print("------------------------")
print("-= Five-Point Formula =-")
print("------------------------\n")


while True:
    equation = "y = "  # polynomial assignment statement
    equation += str(input("Enter function's formula: \nNote that x^n ==> x**n \nf(x) = "))
    x0 = float(input("Enter x0: "))  # point to find the derivative at
    approachingPoint = float(input("\nEnter approaching point \nh = "))

    print("f'(%f) = " % x0, end="")
    print(fivePoint(x0, approachingPoint, equation))

    print("1.Another one 2.Exit")
    choice = int(input())
    if choice == 2: break
