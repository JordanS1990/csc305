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
    
    public int[][] matrix;
    
    public Matrix() {
        this.cols = 4;
        this.rows = 4;
        
        this.matrix = new int[][] {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
        
    }
    
    public Matrix(int rows, int cols, int[][] array) {
        this.cols = cols;
        this.rows = rows;
        
        this.matrix = array;
    }
    
    public Matrix transpose() {
        
        int[][] transp = new int[cols][rows];
        
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
        
        int[][] multi = new int[this.rows][neo.cols];
        
        for(int i=0;i<this.rows;i++) {
            for(int j=0;j<neo.cols;j++) {
                int sum = 0;
                for(int k=0;k<this.cols;k++) {
                    sum += this.matrix[i][k] * neo.matrix[k][j];
                }
                multi[i][j] = sum;
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
            return Integer.MAX_VALUE;
        }
        
        int result = 0;
        
        for(int i=0;i<this.rows;i++) {
            result += this.matrix[i][0] * neo.matrix[i][0];
        }
        
        return result;
    }
    
    public Matrix crossProduct(Matrix neo) {
        
        int x = this.matrix[0][0];
        int y = this.matrix[1][0];
        int z = this.matrix[2][0];
        
        
        Matrix dual = new Matrix(this.rows, this.rows, new int[][] {{0,-z,y},{z,0,-x},{-y,x,0}});
        
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
