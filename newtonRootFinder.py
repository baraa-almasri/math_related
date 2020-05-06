#!/usr/bin/python3
# math functions and more LOL :)
from math import *

# ln(x) definition
def ln(x):
    return log(x, e)

# function's formula
y = 0 # some initial value for y
def f(x, pol): # pol = polynomya
    updateY = "global y; " + pol
    exec(updateY)
    return y

# derivative formula
def diff(a, h, fx):
    return (f(a+h, fx) - f(a, fx)) / h

def findRootnewton(x0, fx, err):
    difference = 9e12  # assigned to a very high value
    xi = x0
    xi1 = 0  # assigned to a random value
    steps = 0
    while err <= difference or difference != 0:
        # reminder: newton's method formula
        # x0 = constant
        # Xi+1 = Xi - (f(Xi)/f'(Xi))
        xi1 = xi - (f(xi, fx) / diff(xi, 0.0000001, fx))
        difference = abs(xi1 - xi)
        steps += 1
        xi = xi1

    print("\nnumber of steps ", steps)
    print("root =", xi1)


################################################################

print("---------------------------")
print("-= Newton-Raphson Method =-")
print("---------------------------\n")

eq = "y = "  # polynomial assignment statement
eq += str(input("Enter function's formula: \nf(x) = "))
x0 = float(input("Enter x0: "))
errorTolerance = float(input("Enter error tolerance \nerr = "))

findRootnewton(x0, eq, errorTolerance)
