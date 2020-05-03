#include <iostream>
#include <cstdio>
#include <cmath>
#include <utility>
#include <vector>
#define pi 3.1415902991527593
double genXcartesian(double radius,double angle){
    return radius*cos(angle);
}
double genYcartesian(double radius,double angle){
    return radius*sin(angle);
}
int main(){
    // reminder    x = radius*cos(theta), y = radius*sin(theta)
    // hence    theta = arccos(x/radius) or arcsin(y/radius)
    double radius;
    printf("Enter the radius of the circumference circle: ");
    scanf("%lf", &radius);
    printf("Enter the cartesian coordinates of polygon's center (x,y): ");
    
    double x,y;
    scanf("%lf %lf",&x ,&y);

    int noOfSides;
    printf("Enter number of sides of the polygon: ");
    scanf("%d",&noOfSides);

    //from radius = S/2sin(pi/n)
    //we got S = radius*2sin(pi/n)
    double side;
    side = radius*2*sin(pi/noOfSides);

    //the angle between two neighbouring diameters of the polygon in radians
    double angle;
    angle = (pi*2)/noOfSides;
    double theta = angle;

    printf("\n------------------------");
    printf("\nSide length = %lf\n",side);

    printf("------------------------\n");
    std::vector< std::pair<double,double> > points(noOfSides+1);
    
    for(int point = 1 ; point <= noOfSides ; point++){
        points.at(point) = std::make_pair(x + genXcartesian(radius, theta), y + genYcartesian(radius, theta));
        printf("Point %d (%lf , %lf)\n", point, points.at(point).first, points.at(point).second);
        theta += angle;
    }
 
    //Points with index-1
    std::vector< std::pair<double,double> > prevPoints(noOfSides+1);
    std::vector< std::pair<double,double> > differences(noOfSides+1);

    for(int point = 1 ; point <= noOfSides ; point++){
        prevPoints.at(point) = points.at(point-1);
        differences.at(point).first = points.at(point).first - prevPoints.at(point).first;
        differences.at(point).second = points.at(point).second - prevPoints.at(point).second;
    }
    differences.at(1).first = points.at(1).first - points.back().first;
    differences.at(1).second = points.at(1).second - points.back().second;

    printf("\n------------------------\n");

    double slope;
    for(int point = 1 ; point <= noOfSides ; point++){
        //printf("diff X %d = %lf \n",point ,differences.at(point).first );
        //printf("diff Y %d = %lf \n",point ,differences.at(point).second );

		if(differences.at(point).first == 0){
            printf("\nSide %d Equation: ",point);
            printf("y = %lf", points.at(point).first);
        }
		else{
            slope = differences.at(point).second / differences.at(point).first;
            printf("\nSide %d Equation: ",point);
            printf("y = %lf * (x - %lf) + %lf", slope,  points.at(point).first , points.at(point).second);
        }

    }

    printf("\n\n------------------------\n\n");
    printf("Circumferting circle's equation:\n");
    printf("(x - %lf)^2 + (y - %lf)^2 = %lf \n",x ,y, pow(radius,2));

    //Mafs LOL
    
    return 0;
}
