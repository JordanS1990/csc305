/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package a1;

import java.io.BufferedReader;
import java.io.Console;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author jssmythe
 */
public class A1 {

    /**
     * @param args the command line arguments
     */
    
    public static Matrix m1;
    public static Matrix m2;
    
    public static Point3D p1;
    public static Point3D p2;
    
    public static void main(String[] args) {
        
        new A1().objectHelp();
        System.out.println("Type 'Help' at any time for instructions and 'Finish' to exit");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String command = null;
        int number = 0;
        
        while(true) {
            System.out.print("Please enter a command: ");
            try {
                command = br.readLine();
            } catch(IOException e) {
                continue;
            }
            
            if(command.equals("Help")) {
                new A1().objectHelp();
            }
            else if(command.equals("Matrix Help")) {
                new A1().matrixHelp();
            }
            else if(command.equals("Point Help")) {
                new A1().pointHelp();
            }
            else if(command.equals("Matrix")) {
                new A1().enterMatrix();
            }
            else if(command.equals("Point")) {
                new A1().enterPoint();
            }
            else if(command.equals("Multiply")) {
                new A1().matrixFunc("Multiply");
            }
            else if(command.equals("Transpose")) {
                new A1().matrixFunc("Transpose");
            }
            else if(command.equals("Equality")) {
                new A1().matrixFunc("Equality");
            }
            else if(command.equals("Cross")) {
                new A1().matrixFunc("Cross");
            }
            else if(command.equals("Dot")) {
                new A1().matrixFunc("Dot");
            }
            else if(command.equals("Inverse")){
                
            }
            else if(command.equals("Translate")) {
                new A1().pointFunc("Translate");
            }
            else if(command.equals("Scale")) {
                new A1().pointFunc("Scale");
            }
            else if(command.equals("Rotate")) {
                new A1().pointFunc("Rotate");
            }
            else if(command.equals("Show Matrix")) {
                System.out.print("Please enter a number: ");
                try {
                    command = br.readLine();
                } catch(IOException e) {
                    continue;
                }
                
                try {
                    number = Integer.parseInt(command);
                } catch(NumberFormatException e) {
                    System.out.println("Improper Input");
                }

                if(number == 1){
                    m1.showMatrix();
                }
                else {
                    m2.showMatrix();
                }
                
                
            }
            else if(command.equals("Show Point")) {
                System.out.print("Please enter a number: ");
                try {
                    command = br.readLine();
                } catch(IOException e) {
                    continue;
                }
                
                try {
                    number = Integer.parseInt(command);
                } catch(NumberFormatException e) {
                    System.out.println("Improper Input");
                }
                
                if(number == 1){
                    p1.showPoint();
                }
                else {
                    p2.showPoint();
                }  
            }
            else if(command.equals("Finish")) {
                break;
            }
        }
        /*
        Matrix m1 = new Matrix();
        Matrix m2 = new Matrix(4,4,new double[][] {{1,2,3,4},{4,3,2,1},{9,8,7,6},{6,7,8,9}});
        Matrix m2same = new Matrix(4,4,new double[][] {{1,2,3,4},{4,3,2,1},{9,8,7,6},{6,7,8,9}});
        
        Matrix mult1 = new Matrix(3,3,new double[][] {{1,2,3},{4,5,6},{7,8,9}});
        Matrix mult2 = new Matrix(3,3,new double[][] {{9,8,7},{6,5,4},{3,2,1}});
        
        Matrix vector1 = new Matrix(3,1,new double[][] {{1},{2},{3}});
        Matrix vector2 = new Matrix(3,1,new double[][] {{4},{5},{6}});
        
        
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
        */
    }
    
    public void objectHelp() {
        System.out.println("Object Commands Help: Command - Definition");
        System.out.println("Enter 'Matrix Help' or 'Point Help' for info on functions");
        System.out.println("Only two Matrices and two 3D Points are available at any one time\n");
        System.out.println("Matrix - enter a new Matrix");
        System.out.println("\tMatrix Rows - enter number of rows");
        System.out.println("\tMatrix Columns - enter number of columns");
        System.out.println("\tMatrix Values - enter row values(eg. 1 4 5)");
        System.out.println("Point - enter a new 3D Point");
        System.out.println("\tPoint Values - enter Values(eg. 1 2 3)");
    }
    
    public void matrixHelp() {
        System.out.println("Multiply - prompts for multiplication parameters");
        System.out.println("Transpose - prompts for matrix to transpose");
        System.out.println("Equality - checks equality of Matrix 1 and 2");
        System.out.println("Dot - computes the dot product of Matrix 1 and 2");
        System.out.println("Cross - computers cross product of Matrix 1 and 2");
        System.out.println("Inverse - this doesn't do anything right now");
        
    }
    
    public void pointHelp() {
        System.out.println("Translate - prompts for translation values");
        System.out.println("Scale - prompts for scaling values");
        System.out.println("Rotate - prompts for rotation values");
    }
    
    public void enterMatrix() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("type 'Done' if you wish to return without setting the matrix");
        
        String delims = "[ ]+";
        String command;
        
        int matrixNum;
        
        int rows;
        int cols;
        
        while(true) {
            System.out.print("Please enter which matrix you want to use(1 or 2): ");
            try {
                command = br.readLine();
            } catch(IOException e) {
                continue;
            }
            
            if(command.equals("Done")) {
                return;
            }
  
            int number = Integer.parseInt(command);
            if(number == 1 || number == 2) {
                matrixNum = number;
            }
            else {
                continue;
            }
            
            break;
        }
        
        while(true) {
            System.out.print("Please enter number of rows and columns(eg. 3 3): ");
            try {
                command = br.readLine();
            } catch(IOException e) {
                continue;
            }
            
            if(command.equals("Done")) {
                return;
            }
            String[] params = command.split(delims);
            if(params.length != 2){
                System.out.println("Improper Input, Try again");
                continue;
            }
            rows = Integer.parseInt(params[0]);
            cols = Integer.parseInt(params[1]);
            
            break;
        }
        
        double[][] matrixVals = new double[rows][cols];
        int z = 0;
        while(true) {
            System.out.print(String.format("Please enter the row %s values(eg. 1 2 3): ", z));
            try {
                command = br.readLine();
            } catch(IOException e) {
                continue;
            }
            
            if(command.equals("Done")) {
                return;
            }
            
            String[] params = command.split(delims);
            if(params.length != cols) {
                System.out.println("Amount of values provided inconsistant with column count provided");
                continue;
            }
            
            double[] temp = new double[params.length];
            for(int i=0;i<params.length;i++) {
                temp[i] = Double.parseDouble(params[i]);
            }
            
            matrixVals[z] = temp;
            z++;
            
            if(z == rows) {
                break;
            }
        }
        
        if(matrixNum == 1) {
            m1 = new Matrix(rows, cols, matrixVals);
        }
        else {
            m2 = new Matrix(rows, cols, matrixVals);
        }
        
    }
    
    public void enterPoint() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("type 'Done' if you wish to return without setting the matrix");
        
        String delims = "[ ]+";
        String command;
        
        int pointNum;
        
        while(true) {
            System.out.print("Please enter which point you want to use(1 or 2): ");
            try {
                command = br.readLine();
            } catch(IOException e) {
                continue;
            }
            
            if(command.equals("Done")) {
                return;
            }
  
            int number = Integer.parseInt(command);
            if(number == 1 || number == 2) {
                pointNum = number;
            }
            else {
                continue;
            }
            
            break;
        }
        
        while(true) {
            System.out.print("Please enter the row values(eg. 1 2 3): ");
            try {
                command = br.readLine();
            } catch(IOException e) {
                continue;
            }
            
            if(command.equals("Done")) {
                return;
            }
            
            String[] params = command.split(delims);
            if(params.length != 3) {
                System.out.println("Please provide exactly 3 values");
                continue;
            }
            
            if(pointNum == 1) {
                p1 = new Point3D(Integer.parseInt(params[0]), Integer.parseInt(params[1]), Integer.parseInt(params[2]));
            }
            else {
                p2 = new Point3D(Integer.parseInt(params[0]), Integer.parseInt(params[1]), Integer.parseInt(params[2]));
            }
            break;
        }
    }
    
    public void matrixFunc(String func) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("type 'Done' if you wish to return without completing a function");
        
        String command;
        Matrix result;
        
        if(func.equals("Multipy")) {
            System.out.print("Select which matrix to use first(ie. 1 means 1x2): ");
            try {
                command = br.readLine();
            } catch(IOException e) {
                return;
            }
            if(command.equals("Done")) {
                return;
            }
            
            int first = Integer.parseInt(command);
            
            if(first == 1) {
                result = m1.multiplication(m2);
            }
            else {
                result = m2.multiplication(m1);
            }
            
            result.showMatrix();
        }
        else if(func.equals("Transpose")) {
            System.out.print("Select a Matrix to transpose: ");
            try {
                command = br.readLine();
            } catch(IOException e) {
                return;
            }
            if(command.equals("Done")) {
                return;
            }
            
            int first = Integer.parseInt(command);
            
            if(first == 1) {
                result = m1.transpose();
            }
            else {
                result = m2.transpose();
            }
            
            result.showMatrix();
            
        }
        else if(func.equals("Cross")) {
            System.out.print("Select which matrix to use first(ie. 1 means 1x2): ");
            try {
                command = br.readLine();
            } catch(IOException e) {
                return;
            }
            if(command.equals("Done")) {
                return;
            }
            
            int first = Integer.parseInt(command);
            
            if(first == 1) {
                result = m1.crossProduct(m2);
            }
            else {
                result = m2.crossProduct(m1);
            }
            
            if(result == null) {
                return;
            }
            result.showMatrix();
            
        }
        else if(func.equals("Dot")) {
            int product;
            
            System.out.print("Select which matrix to use first(ie. 1 means 1x2): ");
            try {
                command = br.readLine();
            } catch(IOException e) {
                return;
            }
            if(command.equals("Done")) {
                return;
            }
            
            int first = Integer.parseInt(command);
            
            if(first == 1) {
                product = m1.dotProduct(m2);
            }
            else {
                product = m2.dotProduct(m1);
            }
            
            if(product != Integer.MAX_VALUE) {
                System.out.println(product);  
            }
        }
        else if(func.equals("Equality")) {
            boolean bool = m1.equality(m2);
            System.out.println(bool);
        }
    }
    
    public void pointFunc(String func) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("type 'Done' if you wish to return without completing a function");
        
        String delims = "[ ]+";
        String command;
        
        if(func.equals("Translate")) {
            System.out.print("Select which Point you want to translate: ");
            try {
                command = br.readLine();
            } catch(IOException e) {
                return;
            }
            if(command.equals("Done")) {
                return;
            }
            
            int first = Integer.parseInt(command);
            
            String[] params;
            while(true) {
                System.out.print("Enter the 3 translation values x y z(eg. 1 0 5): ");
                try {
                    command = br.readLine();
                } catch(IOException e) {
                    return;
                }
                if(command.equals("Done")) {
                    return;
                }

                params = command.split(delims);
                if(params.length != 3) {
                    System.out.println("Three values are required");
                    continue;
                }
                
                break;
            }
            
            if(first == 1) {
                p1.translation(Integer.parseInt(params[0]), Integer.parseInt(params[1]), Integer.parseInt(params[2]));
            }
            else {
                p2.translation(Integer.parseInt(params[0]), Integer.parseInt(params[1]), Integer.parseInt(params[2]));
            }
        }
        else if(func.equals("Scale")) {
            System.out.print("Select which Point you want to scale: ");
            try {
                command = br.readLine();
            } catch(IOException e) {
                return;
            }
            if(command.equals("Done")) {
                return;
            }
            
            int first = Integer.parseInt(command);
            
            String[] params;
            while(true) {
                System.out.print("Enter the 3 scaling values x y z(eg. 1 4 5): ");
                try {
                    command = br.readLine();
                } catch(IOException e) {
                    return;
                }
                if(command.equals("Done")) {
                    return;
                }

                params = command.split(delims);
                if(params.length != 3) {
                    System.out.println("Three values are required");
                    continue;
                }
                
                break;
            }
            
            if(first == 1) {
                p1.scale(Integer.parseInt(params[0]), Integer.parseInt(params[1]), Integer.parseInt(params[2]));
            }
            else {
                p2.scale(Integer.parseInt(params[0]), Integer.parseInt(params[1]), Integer.parseInt(params[2]));
            }
        }
        else if(func.equals("Rotate")) {
            System.out.print("Select which Point you want to Rotate: ");
            try {
                command = br.readLine();
            } catch(IOException e) {
                return;
            }
            if(command.equals("Done")) {
                return;
            }
            
            int first = Integer.parseInt(command);
            
            String[] params;
            while(true) {
                System.out.print("Enter the 3 scaling values x y z(eg. 20 45 0): ");
                try {
                    command = br.readLine();
                } catch(IOException e) {
                    return;
                }
                if(command.equals("Done")) {
                    return;
                }

                params = command.split(delims);
                if(params.length != 3) {
                    System.out.println("Three values are required");
                    continue;
                }
                
                break;
            }
            
            if(first == 1) {
                p1.rotation(Integer.parseInt(params[0]), Integer.parseInt(params[1]), Integer.parseInt(params[2]));
            }
            else {
                p2.rotation(Integer.parseInt(params[0]), Integer.parseInt(params[1]), Integer.parseInt(params[2]));
            }
        }
    }
}
