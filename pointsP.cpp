#include <iostream>
#include <cmath> 
#include <cstdlib>
#include <ctime>
using namespace std;
#include "pointsP.h" //including the header file of the class 

Points::Points(){
    x = 0;
    y = 0;
}

Points::Points(float i, float j){
    x = i;
    y = j;
}

void Points::setX(float i){
    x = i;
}

void Points::setY(float j){
    y = j;
}

float Points::getX(){
    return x;
}

float Points::getY(){
    return y;
}

void Points::displayXY(){
    cout << "(" << x << ", " << y << ")" <<endl;
}

float Points::calcDistance(Points p){
    return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
}

Points Center(Points* C, int n){
    //precondition: this function receives a Points array C and n, the no. of points in C 
    //postcondition: this function loops through C to get its center point by calculating the average X and Y values then returning that point 
    float sumX = 0.0,sumY = 0.0, avgX, avgY;
    for(int i=0; i<n; i++){
        sumX += (*(C+i)).getX();
        sumY += (*(C+i)).getY();
    }

    avgX = sumX/n;
    avgY = sumY/n;

    Points Center;
    Center.setX(avgX);
    Center.setY(avgY);
    return Center;
}

void minDistance(Points* A, int nOfA, Points* B,int nOfB, Points p){
    //precondition: this function receives two clusters (arrays) A and B of type Points, their number of points nOfA and nOfB, and a variable of type Points
    //postcondition: this function compares the distance between point p and cluster A and the distance between point p and cluster B then outputs which cluster p is closer to 
    if(p.calcDistance(Center(A, nOfA)) < p.calcDistance(Center(B, nOfB)))
        cout << "The point is closer to the first cluster given." <<endl;
    else if(p.calcDistance(Center(A, nOfA)) > p.calcDistance(Center(B, nOfB)))
        cout << "The point is closer to the second cluster given." <<endl;
    else 
        cout << "The point is at equal distance from either clusters." <<endl;
}



int main(){

    srand(time(0)); //this makes the rand() function generate different random numbers every run 

    int n = 200, m=20;
    Points *A = new Points [n]; //declaring and initializing cluster A 
    Points *B = new Points [n]; //declaring and initializing cluster B 
    Points *P = new Points [m]; //declaring and initializing an array of points 

    for(int i=0; i<n; i++){ //filling cluster A with random points 
        (*(A+i)).setX(rand()% (91 - 70) + 70);
        (*(A+i)).setY(rand()% (91 - 70) + 70);
    }

    for(int i=0; i<n; i++){ //filling cluster B with random points 
        (*(B+i)).setX(rand()% (41 - 20) + 20);
        (*(B+i)).setY(rand()% (41 - 20) + 20);
    }

    for(int i=0; i<m; i++){ //filling the array with random points 
        (*(P+i)).setX(rand()% (101 - 5) + 5);
        (*(P+i)).setY(rand()% (101 - 5) + 5);

        minDistance(A, n, B, n, (*(P+i))); //checking which cluster each point is closer to 
    }


    return 0;
}