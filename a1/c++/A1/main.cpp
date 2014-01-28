/* 
 * File:   main->cpp
 * Author: jssmythe
 *
 * Created on January 27, 2014, 5:34 PM
 */

#include <cstdlib>
#include <iostream>
#include "Matrix.h"
#include "Point3D.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    double temp[] = {1,2,3,4,5,6,7,8,9};
    double temp2[] = {9,8,7,6,5,4,3,2,1};
    
    Matrix* m1 = new Matrix(3, 3, temp);
    Matrix* m2 = new Matrix(3, 3, temp2);
    
    Matrix* result = m1->multiplication(m2);
    
    result->showMatrix();
    
    double vec1[] = {1,2,3,1};
    double vec2[] = {4,5,6,1};
    Matrix* vector1 = new Matrix(4,1,vec1);
    Matrix* vector2 = new Matrix(4,1,vec2);

    double crs1[] = {1,2,3};
    double crs2[] = {4,5,6};
    Matrix* cross1 = new Matrix(3,1,crs1);
    Matrix* cross2 = new Matrix(3,1,crs2);

    double brk1[] = {1,1,2,2};
    Matrix* breaker = new Matrix(2,2,brk1);

    int dot = vector1->dotProduct(vector2);

    Matrix* cross = cross1->crossProduct(cross2);

    Matrix* mTransp = m2->transpose();
    
    Point3D* testP1 = new Point3D(1, 2, 3);

    cout << "Matrix Multiplication: " << endl;
    cout << "Matrix One: " << endl;
    m1->showMatrix();
    cout << "Matrix Two: " << endl;
    m2->showMatrix();
    cout << "Matrix Result: " << endl;
    result->showMatrix();
    cout << "" << endl;
    cout << "Matrix Transpose: " << endl;
    cout << "Original Matrix: " << endl;
    m2->showMatrix();
    cout << "Transposed Matrix: " << endl;
    mTransp->showMatrix();
    cout << "" << endl;
    cout << "Matrix Equality" << endl;
    cout << "Comparing Matrix Two with itself: " << endl;
    cout << m2->equality(m2) << endl;
    cout << "Comparing Matrix Two with Matrix One: " << endl;
    cout << m2->equality(m1) << endl;
    cout << "" << endl;
    cout << "Matrix Dot Product: " << endl;
    cout << "Vector One: " << endl;
    vector1->showMatrix();
    cout << "Vector Two: " << endl;
    vector2->showMatrix();
    cout << "Dot Product Result: " << endl;
    cout << dot << endl;
    cout << "" << endl;
    cout << "Matrix Cross Product " << endl;
    cout << "Cross Vector One: " << endl;
    cross1->showMatrix();
    cout << "Cross Vector Two: " << endl;
    cross2->showMatrix();
    cout << "Cross Product Result: " << endl;
    cross->showMatrix();
    
    cout << "\n" << endl;
    cout << "3D Point functions:" << endl;
    cout << "Original Point" << endl;
    testP1->showPoint();
    cout << "3D Point Translation:" << endl;
    testP1->translation(3, 1, 1);
    testP1->showPoint();
    cout << "3D Point Scaling:" << endl;
    testP1->scale(2,3,2);
    testP1->showPoint();
    cout << "3D Point X Rotation:" << endl;
    testP1->rotation(45, 0, 0);
    testP1->showPoint();
    cout << "3D Point Y Rotation:" << endl;
    testP1->rotation(0, 45, 0);
    testP1->showPoint();
    cout << "3d Point Z Rotation:" << endl;
    testP1->rotation(0, 0, 45);
    testP1->showPoint();

    cout << "\nEnd of Tests" << endl;

    return 0;
}

