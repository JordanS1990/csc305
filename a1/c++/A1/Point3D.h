/* 
 * File:   Point3D.h
 * Author: jssmythe
 *
 * Created on January 27, 2014, 5:40 PM
 */

#ifndef POINT3D_H
#define	POINT3D_H

class Point3D {
public:
    int x;
    int y;
    int z;
    Point3D();
    Point3D(int x, int y, int z);
    void rotation(double xRot, double yRot, double zRot);
    void translation(int xMov, int yMov, int zMov);
    void scale(int xFac, int yFac, int zFac);
    void showPoint();
    virtual ~Point3D();
private:

};

#endif	/* POINT3D_H */

