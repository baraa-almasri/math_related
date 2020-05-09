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


# derivative formulas
def diff(point, approachingPoint, fx) -> float:
    # reminder
    # f'(a) = (f(a+h) - f(a))/(h)
    # just applying first derivative's formula
    return (func(point + approachingPoint, fx) - func(point, fx)) / approachingPoint


################################################################
################################################################

print("--------------------------------")
print("-= Forward-difference Formula =-")
print("--------------------------------\n")


while True:
    equation = "y = "  # polynomial assignment statement
    equation += str(input("Enter function's formula: \nNote that x^n ==> x**n \nf(x) = "))
    x0 = float(input("Enter x0: "))  # point to find the second derivative at
    approachingPoint = float(input("\nEnter approaching point \nh = "))

    print("f'(%f) = " % x0, end="")
    print(diff(x0, approachingPoint, equation))
    error = abs(approachingPoint)/(x0**2)
    print("Error: %f" % error)

    print("1.Another one 2.Exit")
    choice = int(input())
    if choice == 2: break
