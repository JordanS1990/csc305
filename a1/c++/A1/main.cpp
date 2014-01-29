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
#include <string>

using namespace std;

Point3D* p1;
Point3D* p2;
Matrix* m1;
Matrix* m2;

void enterMatrix();
void enterPoint();
void matrixFunc(string func);
void pointFunc(string func);
void tests();

int main(int argc, char** argv) {
    
    string command;
    int number = 0;

    while(true) {
        command = "";
        cout << "Please enter a command: ";
        getline(cin, command);
        
        if(command == "Matrix") {
            enterMatrix();
        }
        else if(command == "Point") {
            enterPoint ();
        }
        else if(command == "Multiply") {
            matrixFunc ("Multiply");
        }
        else if(command == "Transpose") {
            matrixFunc ("Transpose");
        }
        else if(command == "Equality") {
            matrixFunc ("Equality");
        }
        else if(command == "Cross") {
            matrixFunc ("Cross");
        }
        else if(command == "Dot") {
            matrixFunc ("Dot");
        }
        else if(command == "Inverse"){

        }
        else if(command == "Translate") {
            pointFunc ("Translate");
        }
        else if(command == "Scale") {
            pointFunc ("Scale");
        }
        else if(command == "Rotate") {
            pointFunc ("Rotate");
        }
        else if(command == "Show Matrix") {
            cout << "Please enter a number: ";
            getline(cin, command);

            number = atoi(command.c_str());

            if(number == 1){
                m1->showMatrix();
            }
            else {
                m2->showMatrix();
            }
        }
        else if(command == "Show Point") {
            cout << "Please enter a number: ";
            getline(cin, command);

            number = atoi(command.c_str());

            if(number == 1){
                p1->showPoint();
            }
            else {
                p2->showPoint();
            }  
        }
        else if(command == "Run Tests") {
            tests ();
        }
        else if(command == "Finish") {
            break;
        }
    }

    return 0;
}

void enterPoint() {

    cout << "type 'Done' if you wish to return without setting the Point" << endl;
    
    string command;

    int pointNum;

    while(true) {
        cout << "Please enter which point you want to use(1 or 2): ";
        getline(cin, command);

        if(command == "Done") {
            return;
        }

        int number = atoi(command.c_str());
        if(number == 1 || number == 2) {
            pointNum = number;
        }
        else {
            continue;
        }

        break;
    }

    while(true) {
        int x, y, z;
        
        cout << "Please enter the row values one at a time - x: ";
        getline(cin, command);
        x = atoi(command.c_str());
        cout << "y: ";
        getline(cin, command);
        y = atoi(command.c_str());
        cout << "z: ";
        getline(cin, command);
        z = atoi(command.c_str());


        if(pointNum == 1) {
            p1 = new Point3D(x, y, z);
        }
        else {
            p2 = new Point3D(x, y, z);
        }
        break;
    }
}

void enterMatrix() {

    cout << "type 'Done' if you wish to return without setting the matrix" << endl;

    string command;
    char temp[1];

    int matrixNum;

    int rows;
    int cols;

    cout << "Please enter which matrix you want to use(1 or 2): ";
    getline(cin,command);

    if(command == "Done") {
        cout << "Returns?" << endl;
        return;
    }

    matrixNum = atoi(command.c_str());


    cout << "Please enter number of rows: ";
    getline(cin, command);
    rows = atoi(command.c_str());

    cout << "Please enter number of columns: ";
    getline(cin, command);
    cols = atoi(command.c_str());

    double matrixVals[rows*cols];
    int z = 0;
    for(int i=0;i<rows*cols;i++) {
        cout << "Please enter the the next value: ";
        getline(cin, command);
        
        matrixVals[i] = atof(command.c_str());
    }

    if(matrixNum == 1) {
        m1 = new Matrix(rows, cols, matrixVals);
    }
    else {
        m2 = new Matrix(rows, cols, matrixVals);
    }

}

void matrixFunc(string func) {
    cout << "type 'Done' if you wish to return without completing a function" << endl;

    string command;
    Matrix* result;

    if(func == "Multiply") {
        cout << "Select which matrix to use first(ie. 1 means 1x2): ";
        getline(cin, command);

        if(command == "Done") {
            return;
        }

        int first = atoi(command.c_str());

        if(first == 1) {
            result = m1->multiplication(m2);
        }
        else {
            result = m2->multiplication(m1);
        }

        result->showMatrix();
    }
    else if(func == "Transpose") {
        cout << "Select a Matrix to transpose: ";
        getline(cin, command);

        if(command == "Done") {
            return;
        }

        int first = atoi(command.c_str());

        if(first == 1) {
            result = m1->transpose();
        }
        else {
            result = m2->transpose();
        }

        result->showMatrix();

    }
    else if(func == "Cross") {
        cout << "Select which matrix to use first(ie. 1 means 1x2): ";
        getline(cin, command);

        if(command == "Done") {
            return;
        }

        int first = atoi(command.c_str());

        if(first == 1) {
            result = m1->crossProduct(m2);
        }
        else {
            result = m2->crossProduct(m1);
        }

        if(result == NULL) {
            return;
        }
        result->showMatrix();

    }
    else if(func == "Dot") {
        int product;

        cout << "Select which matrix to use first(ie. 1 means 1x2): ";
        getline(cin, command);

        if(command == "Done") {
            return;
        }

        int first = atoi(command.c_str());

        if(first == 1) {
            product = m1->dotProduct(m2);
        }
        else {
            product = m2->dotProduct(m1);
        }

        if(product != INT_MAX) {
            cout << product << endl;  
        }
    }
    else if(func == "Equality") {
        bool truth = m1->equality(m2);
        cout << truth << endl;
    }
}

void pointFunc(string func) {

     cout << "type 'Done' if you wish to return without completing a function" << endl;

     string command;
     
     int x,y,z;

     if(func == "Translate") {
         cout << "Select which Point you want to translate: ";
         getline(cin, command);

         if(command == "Done") {
             return;
         }

         int first = atoi(command.c_str());

         cout << "Enter the translation for each coordinate separately - x:";
         getline(cin, command);
         x = atoi(command.c_str());
         cout << "y: ";
         getline(cin, command);
         y = atoi(command.c_str());
         cout << "z: ";
         getline(cin, command);
         z = atoi(command.c_str());
         if(first == 1) {
             p1->translation(x, y, z);
         }
         else {
             p2->translation(x, y, z);
         }
     }
     else if(func == "Scale") {
         cout << "Select which Point you want to scale: ";
         getline(cin, command);

         if(command == "Done") {
             return;
         }

         int first = atoi(command.c_str());

         cout << "Enter the scaling factor for each coordinate separately - x:";
         getline(cin, command);
         x = atoi(command.c_str());
         cout << "y: ";
         getline(cin, command);
         y = atoi(command.c_str());
         cout << "z: ";
         getline(cin, command);
         z = atoi(command.c_str());

         if(first == 1) {
             p1->scale(x, y, z);
         }
         else {
             p2->scale(x, y, z);
         }
     }
     else if(func == "Rotate") {
         cout << "Select which Point you want to Rotate: ";
         getline(cin, command);

         if(command == "Done") {
             return;
         }

         int first = atoi(command.c_str());

         cout << "Enter the rotation angle for each coordinate separately - x:";
         getline(cin, command);
         x = atoi(command.c_str());
         cout << "y: ";
         getline(cin, command);
         y = atoi(command.c_str());
         cout << "z: ";
         getline(cin, command);
         z = atoi(command.c_str());

         if(first == 1) {
             p1->rotation(x, y, z);
         }
         else {
             p2->rotation(x, y, z);
         }
     }
 }

void tests() {
    double temp[] = {1,2,3,4,5,6,7,8,9};
    double temp2[] = {9,8,7,6,5,4,3,2,1};
    
    Matrix* uM1 = new Matrix(3, 3, temp);
    Matrix* uM2 = new Matrix(3, 3, temp2);
    
    Matrix* result = uM1->multiplication(uM2);
    
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

    Matrix* mTransp = uM1->transpose();
    
    Point3D* testP1 = new Point3D(1, 2, 3);

    cout << "Matrix Multiplication: " << endl;
    cout << "Matrix One: " << endl;
    uM1->showMatrix();
    cout << "Matrix Two: " << endl;
    uM2->showMatrix();
    cout << "Matrix Result: " << endl;
    result->showMatrix();
    cout << "" << endl;
    cout << "Matrix Transpose: " << endl;
    cout << "Original Matrix: " << endl;
    uM1->showMatrix();
    cout << "Transposed Matrix: " << endl;
    mTransp->showMatrix();
    cout << "" << endl;
    cout << "Matrix Equality" << endl;
    cout << "Comparing Matrix Two with itself: " << endl;
    cout << uM2->equality(uM2) << endl;
    cout << "Comparing Matrix Two with Matrix One: " << endl;
    cout << uM2->equality(uM1) << endl;
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
    
    cout << endl << endl;
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
    
    cout << endl << endl;
    cout << "Error Tests: " << endl;
    cout << "Incompatible Matrix Sizes:" << endl;
    Matrix* err1 = breaker->multiplication(uM2);
    cout << "Nx1 Vectors not used in dot product:" << endl;
    int err2 = uM1->dotProduct(uM2);
    cout << "3x1 Vectors not used in Cross Product:" << endl;
    Matrix* err3 = uM1->crossProduct(uM2);

    cout << "\nEnd of Tests" << endl;
}