/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package a1;

/**
 *
 * @author jssmythe
 */
public class Matrix {
    
    public int cols;
    public int rows;
    
    public double[][] matrix;
    
    public Matrix() {
        this.cols = 4;
        this.rows = 4;
        
        this.matrix = new double[][] {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
        
    }
    
    public Matrix(int rows, int cols, double[][] array) {
        this.cols = cols;
        this.rows = rows;
        
        this.matrix = array;
    }
    
    public Matrix transpose() {
        
        double[][] transp = new double[cols][rows];
        
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                transp[i][j] = this.matrix[j][i];
            }
        }
        
        Matrix result = new Matrix(cols,rows,transp);
        
        return result;
    }
    
    public boolean equality(Matrix neo) {
        
        if((this.cols == neo.cols) && (this.rows == neo.rows)) {
            for(int i=0;i<rows;i++) {
                for(int j=0;j<cols;j++) {
                    if(this.matrix[i][j] != neo.matrix[i][j]) {
                        return false;
                    }
                }
            }
            return true;
        }
        
        return false;
    }
    
    public Matrix multiplication(Matrix neo) {
        
        if(this.cols != neo.rows) {
            return null;
        }
        
        double[][] multi = new double[this.rows][neo.cols];
        
        for(int i=0;i<this.rows;i++) {
            for(int j=0;j<neo.cols;j++) {
                int sum = 0;
                for(int k=0;k<this.cols;k++) {
                    sum += this.matrix[i][k] * neo.matrix[k][j];
                }
                multi[i][j] = (int)sum;
            }
        }
        
        Matrix result = new Matrix(this.rows, neo.cols, multi);
        
        return result;
    }
    
    public Matrix inverse() {
        
        return this;
    }
    
    public int dotProduct(Matrix neo) {
        
        if(this.cols != 1 || neo.cols != 1 || this.rows != neo.rows) {
            System.out.println("Matrices are not Vectors Matrices, Dot Product requires two Nx1 matrices");
            return Integer.MAX_VALUE;
        }
        
        int result = 0;
        
        for(int i=0;i<this.rows;i++) {
            result += this.matrix[i][0] * neo.matrix[i][0];
        }
        
        return (int)result;
    }
    
    public Matrix crossProduct(Matrix neo) {
        
        if(this.cols != 1 || neo.cols != 1 || this.rows != 3 || neo.rows != 3) {
            System.out.println("Matrices are not Vectors Matrices, Cross Product requires two 3x1 matrices");
            return null;
        }
        
        double x = this.matrix[0][0];
        double y = this.matrix[1][0];
        double z = this.matrix[2][0];
        
        
        Matrix dual = new Matrix(this.rows, this.rows, new double[][] {{0,-z,y},{z,0,-x},{-y,x,0}});
        
        Matrix result = dual.multiplication(neo);
        
        return result;
    }
    
    public void showMatrix() {
        
        for(int i=0;i<this.rows;i++) {
            for(int j=0;j<this.cols;j++) {
                System.out.print(this.matrix[i][j]);
                System.out.print(" ");
            }
            System.out.print("\n");
        }
    }
    
}
