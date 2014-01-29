/* 
 * File:   Matrix.cpp
 * Author: jssmythe
 * 
 * Created on January 27, 2014, 5:40 PM
 */

#include "Matrix.h"
#include <iostream>
#include <iomanip>

using namespace std;

Matrix::Matrix() {
}

Matrix::Matrix(int rows, int cols, double array[]) {
    
    this->rows = rows;
    this->cols = cols;
    
    this->matrix = new double*[rows];
    for(int i=0;i<rows;i++) {
        this->matrix[i] = new double[cols];
    }
    
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            this->matrix[i][j] = array[j + (cols*i)];
        }
    }
}

Matrix* Matrix::transpose() {
    
    double transp[this->cols*this->rows];
        
    for(int i=0;i<this->rows;i++) {
        for(int j=0;j<this->cols;j++) {
            transp[j + (cols*i)] = this->matrix[j][i];
        }
    }

    return new Matrix(this->cols,this->rows,transp); 
}

bool Matrix::equality(Matrix* neo) {
    
    if((this->cols == neo->cols) && (this->rows == neo->rows)) {
        for(int i=0;i<this->rows;i++) {
            for(int j=0;j<this->cols;j++) {
                if(this->matrix[i][j] != neo->matrix[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
        
    return false;
    
}

Matrix* Matrix::multiplication(Matrix* neo) {
    
    int nCols = neo->cols;
    int nRows = neo->rows;
    double **nMatrix = neo->matrix;
    
    if(this->cols != nRows) {
        cout << "Matrix Size Mismatch" << endl;
        return NULL;
    }
        
    double multi[this->rows * this->cols];

    for(int i=0;i<this->rows;i++) {
        for(int j=0;j<nCols;j++) {
            int sum = 0;
            for(int k=0;k<this->cols;k++) {
                sum += this->matrix[i][k] * nMatrix[k][j];
            }
            multi[j + (nCols*i)] = (int)sum;
        }
    }

    return new Matrix(this->rows, nCols, multi);
    
}

Matrix* Matrix::inverse() {
    
}

int Matrix::dotProduct(Matrix* neo) {
    
    if(this->cols != 1 || neo->cols != 1 || this->rows != neo->rows) {
        cout << "Matrices are not Vectors Matrices, Dot Product requires two Nx1 matrices" << endl;
        return INT_MAX;
    }

    int result = 0;

    for(int i=0;i<this->rows;i++) {
        result += this->matrix[i][0] * neo->matrix[i][0];
    }

    return (int)result;
    
}

Matrix* Matrix::crossProduct(Matrix* neo) {
    
    int nRows = neo->rows;
    int nCols = neo->cols;
    
    if(this->cols != 1 || nCols != 1 || this->rows != 3 || nRows != 3) {
        cout << "Matrices are not Vectors Matrices, Cross Product requires two 3x1 matrices" << endl;
        return NULL;
    }

    double x = this->matrix[0][0];
    double y = this->matrix[1][0];
    double z = this->matrix[2][0];
    
    double temp[] = {0,-z,y,z,0,-x,-y,x,0};

    Matrix* dual = new Matrix(this->rows, this->rows, temp);
    
    double thing[3];

    return dual->multiplication(neo); 
}

void Matrix::showMatrix() {
    
    for(int i=0;i<this->rows;i++) {
        for(int j=0;j<this->cols;j++) {
            cout << setw(6) << setprecision(3) << this->matrix[i][j];
            
        }
        cout << endl;
    }
    cout << endl;
}

Matrix::~Matrix() {
}

