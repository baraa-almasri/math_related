#!/bin/python3
import math
# reminder    x = radius*cos(theta), y = radius*sin(theta)
# hence    theta = arccos(x/radius) or arcsin(y/radius)


def genXcartesian(radius, angle):
    return radius*math.cos(angle)


def genYcartesian(radius, angle):
    return radius*math.sin(angle)


radius = float(input("Enter the radius of the Circumferting circle: "))

print("Enter the cartesian coordinates of polygon's center (x,y): ")
x, y = float(input()), float(input())

noOfSides = int(input("Enter number of sides of the polygon: "))

# radius = S/2sin(pi/n)
# S = radius*2sin(pi/n)
side = radius*2*math.sin(math.pi/noOfSides)

# the angle between two neighbouring diameters of the polygon
angle = (math.pi*2)/noOfSides
theta = angle
for i in range(1, noOfSides+1):
    print("for point ", i)
    print("x:", x + genXcartesian(radius, theta))
    print("y:", y + genYcartesian(radius, theta))

    theta += angle

print("Side length =", side)
## Mafs LOL
