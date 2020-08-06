#!/usr/bin/python3
from math import *


# ln definition
def ln(x):
    return log(x, e)


# function equation implementation copyRight Baraa Al-Masri.
# LOL :)
y = None


def func(x, polynomial) -> float:
    updateY = "global y; " + polynomial  # calling the global y then applying change to the string "updateY"
    exec(updateY)  # executing the string to find f(a)
    return y


# note that the method finds the root on an interval I = [a,b]
def solveRegulaFalsi(a, b, error, polynomial):
    steps = 0  # number of steps taken to find the root
    rootToBe = b - (func(b, polynomial)*(b - a)) /(func(b, polynomial) - func(a, polynomial)) # root to be
    oldRoot = None
    while error <= abs(func(rootToBe, polynomial)) and oldRoot != rootToBe:
        oldRoot = rootToBe
        fa = func(a, polynomial)
        fb = func(b, polynomial)
        fc = func(rootToBe, polynomial)

        if fa * fc < 0:
            b = rootToBe
        else:
            a = rootToBe

        rootToBe = b - (func(b, polynomial) * (b - a)) / (func(b, polynomial) - func(a, polynomial))  # update root
        steps += 1

    print("\nnumber of steps ", steps)
    print("root =", rootToBe)

################################################################
################################################################


print("---------------------------")
print("-= False Position Method =-")
print("---------------------------\n")

while True:
    equation = "y = "  # polynomial assignment statement
    equation += str(input("Enter function's formula: \nNote that x^n ==> x**n \nf(x) = "))
    print("Now we'll find root on the interval [a,b] using false position method")
    firstPoint = float(input("enter a: "))
    secondPoint = float(input("enter b: "))
    errorTolerance = float(input("Enter error tolerance \nerror = "))

    solveRegulaFalsi(firstPoint, secondPoint, errorTolerance, equation)

    print("1.Another one 2.Exit")
    choice = int(input())
    if choice == 2: break
