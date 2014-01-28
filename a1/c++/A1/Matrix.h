/* 
 * File:   Matrix.h
 * Author: jssmythe
 *
 * Created on January 27, 2014, 5:40 PM
 */

#ifndef MATRIX_H
#define	MATRIX_H

class Matrix {
public:
    int rows;
    int cols;
    double **matrix;
    Matrix();
    Matrix(int rows, int cols, double array[]);
    Matrix* transpose();
    Matrix* multiplication(Matrix* neo);
    bool equality(Matrix* neo);
    Matrix* crossProduct(Matrix* neo);
    int dotProduct(Matrix* neo);
    Matrix* inverse();
    void showMatrix();
    virtual ~Matrix();
private:

};

#endif	/* MATRIX_H */

