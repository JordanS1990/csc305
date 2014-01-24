/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package a1;

/**
 *
 * @author jssmythe
 */
public class A1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Matrix m1 = new Matrix();
        Matrix m2 = new Matrix(4,4,new int[][] {{1,2,3,4},{4,3,2,1},{9,8,7,6},{6,7,8,9}});
        Matrix m2same = new Matrix(4,4,new int[][] {{1,2,3,4},{4,3,2,1},{9,8,7,6},{6,7,8,9}});
        
        Matrix mult1 = new Matrix(3,3,new int[][] {{1,2,3},{4,5,6},{7,8,9}});
        Matrix mult2 = new Matrix(3,3,new int[][] {{9,8,7},{6,5,4},{3,2,1}});
        
        Matrix vector1 = new Matrix(3,1,new int[][] {{1},{2},{3}});
        Matrix vector2 = new Matrix(3,1,new int[][] {{4},{5},{6}});
        
        
        Matrix result = mult1.multiplication(mult2);
        
        int dot = vector1.dotProduct(vector2);
        
        Matrix cross = vector1.crossProduct(vector2);
        
        Matrix mTransp = m2.transpose();
        
        m1.showMatrix();
        System.out.print("\n");
        m2.showMatrix();
        System.out.print("\n");
        mTransp.showMatrix();
        System.out.print("\n");
        System.out.println(m2.equality(m2same));
        System.out.print("\n");
        result.showMatrix();
        System.out.print("\n");
        System.out.println(dot);
        System.out.print("\n");
        cross.showMatrix();
        System.out.print("\n");
        
        System.out.print("\n");
        
        System.out.print("\n");
        
    }
}
