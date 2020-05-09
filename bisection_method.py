#!/usr/bin/python3
from math import *

# ln definition
def ln(x):
    return log(x, e)

# function equation implementation copyRight Baraa Al-Masri.
# LOL :)
y = 0  # some initial value for y before the big change :)

def func(x, polynomial) -> float:
    updateY = "global y; " + polynomial  # calling the global y then applying change to the string "updateY"
    exec(updateY)  # executing the string to find f(a)
    return y

# note that the method finds the root on an interval I = [a,b]
def biSection(a, b, error, polynomial):
    steps = 0  # number of steps taken to find the root
    midPoint = (a+b)/2  # mid point between a & b
    oldMid = None
    while error <= abs(func(midPoint, polynomial)) and oldMid != midPoint:
        oldMid = midPoint
        fa = func(a, polynomial)
        fb = func(b, polynomial)
        fc = func(midPoint, polynomial)
        if fa * fc < 0:
            b = midPoint
        else:
            a = midPoint
        midPoint = (a + b) / 2  # update mid point
        steps += 1

    print("\nnumber of steps ", steps)
    print("root =", midPoint)

################################################################
################################################################


print("----------------------")
print("-= Bisection Method =-")
print("----------------------\n")

while True:
    equation = "y = "  # polynomial assignment statement
    equation += str(input("Enter function's formula: \nNote that x^n ==> x**n \nf(x) = "))
    print("Now we'll find root on the interval [a,b] using bisection method")
    firstPoint = float(input("enter a: "))
    secondPoint = float(input("enter b: "))
    errorTolerance = float(input("Enter error tolerance \nerror = "))

    biSection(firstPoint, secondPoint, errorTolerance, equation)

    print("1.Another one 2.Exit")
    choice = int(input())
    if choice == 2: break
