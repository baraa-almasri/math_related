#!/bin/python3
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

# trapezoidal integration
def integrate1(firstBound, secondBound, polynomial):
    # reminder   b
    #           ∫ f(x)dx = (f(a) + f(b)) * (h/2)
    #          a
    #                       where h = b - a
    midPoint = secondBound - firstBound
    return (func(firstBound, polynomial) + func(secondBound, polynomial)) * (midPoint / 2)

# simpson's formula
def integrate2(firstBound, secondBound, polynomial):
    # reminder   b
    #           ∫ f(x)dx = (f(a) + f(b) + 4f(a+h)) * (h/3)
    #          a
    #                       where h = (b-a)/2
    midPoint = (secondBound - firstBound)/2
    return (func(firstBound, polynomial) + func(secondBound, polynomial)
            + 4 * func(firstBound + midPoint, polynomial)) * (midPoint/3)
################################################################
################################################################


print("---------------------------")
print("-= Numerical Integration =-")
print("---------------------------\n")

while True:
    equation = "y = "  # polynomial assignment statement
    equation2 = str(input("Enter function's formula: \nNote that x^n ==> x**n \nf(x) = "))
    equation += equation2
    a = float(input("Enter a: "))
    b = float(input("Enter b: "))

    print("Trapezoide area")
    print("    %f" % b)
    answer = integrate1(a, b, equation)
    print("  ∫ %s dx = %f " % (equation2, answer))
    print("%f" % a)

    print("\nSimpson's Method")
    print("    %f" % b)
    answer = integrate2(a, b, equation)
    print("  ∫ %s dx = %f " % (equation2, answer))
    print("%f" % a)

    print("\n1.Another one 2.Exit")
    choice = int(input())
    if choice == 2: break


print("∫")
