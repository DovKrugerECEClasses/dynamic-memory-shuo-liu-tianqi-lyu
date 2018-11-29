/*
	Cube
	Cylinder
	Sphere (optional)
https://en.wikipedia.org/wiki/STL_(file_format)

 */

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

class Vector{
private:
    double x,y,z;
public:
    Vector(double x=0, double y=0, double z=0) : x(x), y(y), z(z){}
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
    Vector minus(const Vector& a) const {
        return Vector(this->x-a.x, this->y-a.y, this->z-a.z);
    }
    Vector devide(double i){
        return Vector(this->x/i, this->y/i, this->z/i);
    }
    Vector MultiplyVec(const Vector& b) const{
        return Vector(this->y*b.z-this->z*b.y, this->z*b.x-this->x*b.z, this->x*b.y-this->y*b.x);
    }
    double length() const {
        return sqrt(x*x+y*y+z*z);
    }
};

class face{
private:
    Vector v1, v2, v3;
public:
    face(Vector v1, Vector v2, Vector v3) : v1(v1), v2(v2), v3(3){}
    Vector getV1(){ return v1; }
    Vector getV2(){ return v2; }
    Vector getV3(){ return v3; }
    Vector getUnit() const {
        Vector v12 = v2.minus(v1);
        Vector v13 = v3.minus(v1);
        Vector n = v12.MultiplyVec(v13);
        Vector u = n.devide(n.length());
        return u;
    }
};

class shape3D{
private:
    double x,y,z;
public:
    shape3D(double x, double y, double z) : x(x), y(y), z(z){}
    void translate(double dx=0, double dy=0, double dz=0){
        x=x+dx;
        y=y+dy;
        z=z+dz;
    }
    double getX(){ return x; }
    double getY(){ return y; }
    double getZ(){ return z; }
    virtual double volume() = 0;
    virtual vector<face> getFaces() = 0;
    void writeIn(ostream &file){
        vector<face> faces = this->getFaces();
        for(int i=0;i<faces.size();i++){
            file<<"face unit "<<faces[i].getUnit().getX()<<" "<<faces[i].getUnit().getY()
                <<" "<<faces[i].getUnit().getZ()<<endl;
            file<<endl;
            file<<"vertex "<<faces[i].getV1().getX()<<" "<<faces[i].getV1().getY()
                <<" "<<faces[i].getV1().getZ()<<endl;
            file<<"vertex "<<faces[i].getV2().getX()<<" "<<faces[i].getV2().getY()
                <<" "<<faces[i].getV2().getZ()<<endl;
            file<<"vertex "<<faces[i].getV3().getX()<<" "<<faces[i].getV3().getY()
                <<" "<<faces[i].getV3().getZ()<<endl;
            file<<"endLoop\n";
            file<<"endFace\n";
        }
    }
    void write(const string &filename){
        ofstream file;
        file.open(filename);
        file<<"solid "<<filename<<'\n';
        writeIn(file);
        file<<"endSolid "<<filename<<'\n';
        file.close();
    }
};

class Cube : public shape3D{
private:
    double sideLength;
public:
    Cube(double s):shape3D(0, 0, 0), sideLength(s){}
    double volume(){
        return sideLength*sideLength*sideLength;
    }
    vector<face> getFaces(){
        double x=this->getX();
        double y=this->getY();
        double z=this->getZ();
        //8 points
        Vector v1(x, y, z);
        Vector v2(x, y+sideLength, z);
        Vector v3(x+sideLength,y+sideLength,z);
        Vector v4(x+sideLength,y,z);
        Vector v5(x,y,z+sideLength);
        Vector v6(x+sideLength,y,z+sideLength);
        Vector v7(x+sideLength,y+sideLength,z+sideLength);
        Vector v8(x,y+sideLength,z+sideLength);

        vector<face> faces;
        faces.emplace_back(face(v1,v2,v3));
        faces.emplace_back(face(v1,v3,v4));
        faces.emplace_back(face(v8,v5,v6));
        faces.emplace_back(face(v8,v6,v7));
        faces.emplace_back(face(v2,v8,v7));
        faces.emplace_back(face(v2,v7,v3));
        faces.emplace_back(face(v4,v6,v5));
        faces.emplace_back(face(v4,v5,v1));
        faces.emplace_back(face(v1,v5,v8));
        faces.emplace_back(face(v1,v8,v2));
        faces.emplace_back(face(v1,v5,v8));
        faces.emplace_back(face(v3,v6,v4));
        faces.emplace_back(face(v3,v7,v6));
        return faces;
    }
};

class Cylinder : public shape3D{
private:
    double r,h;
public:
    Cylinder(double r, double h):shape3D(0, 0, 0), r(r), h(h){}
    double volume(){
        return M_PI*r*r*h;
    }
    vector<face> getFaces(){
        Vector botCenter(this->getX(), this->getY(), this->getZ());
        Vector topCenter(this->getX(), this->getY(), this->getZ() + h);
        vector<Vector> topVec;
        vector<Vector> botVec;
        //let precision be 20
        double step = 2*M_PI/20;
        for (int i=0; i<20; i++){
            double a = step*i;
            topVec.emplace_back(r*cos(a), r*sin(a), h);
            botVec.emplace_back(Vector(r*cos(a), r*sin(a), 0));
        }
        vector<face> faces;
        for(int i=0;i<19;i++){
            faces.emplace_back(botCenter,botVec[i+1],botVec[i]);
            faces.emplace_back(topCenter,topVec[i],topVec[i+1]);
            faces.emplace_back(botVec[i],botVec[i+1],topVec[i]);
            faces.emplace_back(botVec[i+1],topVec[i+1],topVec[i]);
        }
        faces.emplace_back(face(botCenter, botVec[0], botVec[19]));
        faces.emplace_back(face(topCenter, topVec[19], topVec[0]));
        faces.emplace_back(face(botVec[19], botVec[0], topVec[19]));
        faces.emplace_back(face(botVec[0], topVec[0], topVec[19]));
        return faces;
    }
};

/* to be done
class Sphere : public shape3D{
private:
    double r;
public:
    Sphere(double r) : shape3D(0, 0, 0 ), r(r){}
};
*/

class Design{
private:
    vector<shape3D*> shp;
public:
    void add(shape3D* s){
        shp.push_back(s);
    }
    void write(const string &filename){
        ofstream file;
        file.open(filename);
        file<<"solid "<<filename<<'\n';
        for(int i=0;i<shp.size();i++){
            shp[i]->writeIn(file);
        }
        file<<"endSolid "<<filename<<'\n';
        file.close();
    }
};

int main() {
    Design d;
    double s = 10;
    Cube c(&s);
    c.translate(x,y,z);
    // rotate??
    cout << c.volume() << '\n';
    c.write("out.stl"); // how to get all my shapes into the same file
    d.add(c);
    double r = 10, height  = 20;
    Cylinder cyl(r, height);
    d.add(&cyl);
    d.write("test.stl");
}