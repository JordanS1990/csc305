/* 
 * File:   Point3D->cpp
 * Author: jssmythe
 * 
 * Created on January 27, 2014, 5:40 PM
 */

#include "Point3D.h"
#include "Matrix.h"
#include <math.h>
#include <iostream>

using namespace std;

Point3D::Point3D() {
}

Point3D::Point3D(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Point3D::rotation(double xRot, double yRot, double zRot) {
    double matVals[] = {this->x, this->y, this->z};
    Matrix* vector = new Matrix(3,1,matVals);
    if(xRot > 0) {
        double xVals[] = {1,0,0,0,cos(xRot),-sin(xRot),0,sin(xRot),cos(xRot)};
        Matrix* xMatrix = new Matrix(3,3,xVals);
        vector = xMatrix->multiplication(vector);
    }
    if(yRot > 0) {
        double yVals[] = {cos(yRot),0,sin(yRot),0,1,0,-sin(yRot),0,cos(yRot)};
        Matrix* yMatrix = new Matrix(3,3,yVals);
        vector = yMatrix->multiplication(vector);
    }
    if(zRot > 0) {
        double zVals[] = {cos(zRot),-sin(zRot),0,sin(zRot),cos(zRot),0,0,0,1};
        Matrix* zMatrix = new Matrix(3,3,zVals);
        vector = zMatrix->multiplication(vector);
    }

    this->x = (int)vector->matrix[0][0];
    this->y = (int)vector->matrix[1][0];
    this->z = (int)vector->matrix[2][0];
}

void Point3D::translation(int xMov, int yMov, int zMov) {
    this->x = this->x+xMov;
    this->y = this->y+yMov;
    this->z = this->z+zMov;
}

void Point3D::scale(int xFac, int yFac, int zFac) {
    this->x = this->x*xFac;
    this->y = this->y*yFac;
    this->z = this->z*zFac;
}

void Point3D::showPoint() {
   cout << this->x << " " << this->y << " " << this->z << endl;
}

Point3D::~Point3D() {
}

