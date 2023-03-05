#include <iostream>
using namespace std;

class Points{
    private: 
    float x;
    float y;

    public:
    Points(); //Default constructor, sets X and Y to 0
    Points(float i, float j); //Constructor, initializes X and Y
    void setX(float i); //setter for X 
    void setY(float j); //setter for Y
    float getX(); //getter for X
    float getY(); //getter for Y
    void displayXY(); //displays x and y as a point (x, y)
    float calcDistance(Points p); //calculates the distance between the current (object) point and the given point 
};