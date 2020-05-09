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

# 2nd derivative formula
def secondDiffrentiate(point, approachingPoint, fx) -> float:
    # reminder
    # f''(a) = (f(a-h) - 2f(a) + f(a+h))/(h^2)
    # just applying second derivative's formula
    return (func(point - approachingPoint, fx) - 2 * func(point, fx) + func(point + approachingPoint, fx)) / (
                approachingPoint ** 2)


################################################################
################################################################

print("------------------------------")
print("-= Second Derivative Finder =-")
print("------------------------------\n")


while True:
    equation = "y = "  # polynomial assignment statement
    equation += str(input("Enter function's formula: \nNote that x^n ==> x**n \nf(x) = "))
    x0 = float(input("Enter x0: "))  # point to find the second derivative at
    approachingPoint = float(input("\nEnter approaching point \nh = "))

    print("f''(%f) = " % x0, end="")
    print(secondDiffrentiate(x0, approachingPoint, equation))

    print("1.Another one 2.Exit")
    choice = int(input())
    if choice == 2: break
