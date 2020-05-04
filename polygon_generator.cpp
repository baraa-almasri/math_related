#include <iostream>
#include <cstdio>
#include <cmath>
#include <utility>
#include <vector>
#define pi 3.1415902991527593
//reminder    x = r*cos(theta), y = r*sin(theta)
//hence    theta = arccos(x/r) or arcsin(y/r)
double genXcartesian(double radius,double angle){
    return radius*cos(angle);
}
double genYcartesian(double radius,double angle){
    return radius*sin(angle);
}
int main(){

    double radius;
    printf("Enter the radius of the circumferting circle: ");
    scanf("%lf", &radius);
    printf("Enter the cartesian coordinates of polygon's center (x,y): ");
    
    double x,y;
    scanf("%lf %lf",&x ,&y);

    int noOfSides;
    printf("Enter number of sides of the polygon: ");
    scanf("%d",&noOfSides);

    //from r = S/2sin(pi/n)    |  S is the side length
    //we got S = r*2sin(pi/n)  |    for future confusion
    double side;
    side = radius*2*sin(pi/noOfSides);

    //the angle between two neighbouring diameters of the polygon in radians
    double angle;
    angle = (pi*2)/noOfSides;
    double theta = angle; //we'll need them later, just wait....

    printf("\n------------------------");
    printf("\nSide length = %lf\n",side);

    printf("------------------------\n");
    std::vector< std::pair<double,double> > points(noOfSides+1);

    //calculating points' polar coordinates (compared to the center of the polygon),
    //then converting them into catesian coordinates(compared to the center of the polygon),
    //and adding the coordinates of the center.
    //then voila we got the coordinates of the vertices(heads) 🎉🎉
    
    for(int point = 1 ; point <= noOfSides ; point++){
        points.at(point) = std::make_pair(x + genXcartesian(radius, theta), y + genYcartesian(radius, theta));
        printf("Point %d (%lf , %lf)\n", point, points.at(point).first, points.at(point).second);
        theta += angle;
    } //also I started indexes with one so the first is the origin (0,0)


    //Points with index-1
    //to calculate the slopes duh.😐
    std::vector< std::pair<double,double> > prevPoints(noOfSides+1);
    std::vector< std::pair<double,double> > differences(noOfSides+1);

    for(int point = 1 ; point <= noOfSides ; point++){
        prevPoints.at(point) = points.at(point-1);
        differences.at(point).first = points.at(point).first - prevPoints.at(point).first;
        differences.at(point).second = points.at(point).second - prevPoints.at(point).second;
    }
    //difference between the first and the last point so it's useful for their line
    differences.at(1).first = points.at(1).first - points.back().first;
    differences.at(1).second = points.at(1).second - points.back().second;

    printf("\n------------------------\n");

    //finally the slopes and lines equation generation
    double slope;
    for(int point = 1 ; point <= noOfSides ; point++){

        //for vertical slopes since you can't devide by zero 🙃
		if(differences.at(point).first == 0){
            printf("\nSide %d Equation: ",point);
            printf("y%d = %lf",point, points.at(point).first);
        }
        //for normal slopes that doesn't involve deviding by zero 🎉
		else{
            slope = differences.at(point).second / differences.at(point).first;
            printf("\nSide %d Equation: ",point);
            printf("y%d = %lf * (x - %lf) + %lf",point, slope,  points.at(point).first , points.at(point).second);
        }

    }

    //last but not least, I liked to add it, so that every juicable thing is here 👽👽
    printf("\n\n------------------------\n\n");
    printf("Circumferting circle's equation:\n");
    printf("(x - %lf)^2 + (y - %lf)^2 = %lf \n",x ,y, pow(radius,2));

    //Mafs LOL 🤓🤓
    
    return 0;
}
