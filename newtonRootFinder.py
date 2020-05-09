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


# derivative formula
def diff(point, approachingPoint, fx) -> float:
    # reminder
    # f'(a) = (f(a+h) - f(a))/(h)
    return (func(point + approachingPoint, fx) - func(point, fx)) / approachingPoint

def findRootnewton(initialPoint, fx, error):
    difference = 9e12  # assigned to a very high value to make the loop's condition true
    xi = initialPoint  # first point
    xi1 = 0  # i-th point
    steps = 0  # number of steps taken to find the root
    while error <= difference:
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
################################################################

print("---------------------------")
print("-= Newton-Raphson Method =-")
print("---------------------------\n")

while True:
    equation = "y = "  # polynomial assignment statement
    equation += str(input("Enter function's formula: \nNote that x^n ==> x**n \nf(x) = "))
    x0 = float(input("Enter x0: "))  # initial point in the newton sequence
    errorTolerance = float(input("Enter error tolerance \nerror = "))

    findRootnewton(x0, equation, errorTolerance)

    print("1.Another one 2.Exit")
    choice = int(input())
    if choice == 2: break
