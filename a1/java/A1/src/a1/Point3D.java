/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package a1;
import java.lang.Math.*;
/**
 *
 * @author jssmythe
 */
public class Point3D {
    
    int x;
    int y;
    int z;
    
    public Point3D(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
    
    public void rotation(double xRot, double yRot, double zRot) {
        Matrix vector = new Matrix(3,1,new double[][] {{this.x},{this.y},{this.z}});
        if(xRot > 0) {
            Matrix xMatrix = new Matrix(3,3,new double[][] {{1,0,0},{0,Math.cos(xRot),-Math.sin(xRot)},{0,Math.sin(xRot),Math.cos(xRot)}});
            vector = xMatrix.multiplication(vector);
        }
        if(yRot > 0) {
            Matrix yMatrix = new Matrix(3,3,new double[][] {{Math.cos(yRot),0,Math.sin(yRot)},{0,1,0},{-Math.sin(yRot),0,Math.cos(yRot)}});
            vector = yMatrix.multiplication(vector);
        }
        if(zRot > 0) {
            Matrix zMatrix = new Matrix(3,3,new double[][] {{Math.cos(zRot),-Math.sin(zRot),0},{Math.sin(zRot),Math.cos(zRot),0},{0,0,1}});
            vector = zMatrix.multiplication(vector);
        }
        
        this.x = (int)vector.matrix[0][0];
        this.y = (int)vector.matrix[1][0];
        this.z = (int)vector.matrix[2][0];
    }
    
    public void translation(int xMov, int yMov, int zMov) {
        this.x = this.x+xMov;
        this.y = this.y+yMov;
        this.z = this.z+zMov;
    }
    
    public void scale(int xFac, int yFac, int zFac) {
        this.x = this.x*xFac;
        this.y = this.y*yFac;
        this.z = this.z*zFac;
    }
    
    public void showPoint() {
        System.out.println(String.format("%s %s %s", this.x, this.y, this.z));
    }
    
}
