/*
	Cube
	Cylinder
	Sphere (optional)
https://en.wikipedia.org/wiki/STL_(file_format)

 */
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

class Vector{
private:
    double x,y,z;
public:
    Vector(double x=0, double y=0, double z=0) : x(x), y(y), z(z){}

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
    void writeIn(ostream &file);
    void write(string filename){
        ofstream file;
        file.open(filename);
        file<<"solid "<<filename<<'\n';
        writeIn(file);
        file<<"endSolid "<<filename<<'\n';
        file.close();
    }
};

void shape3D::writeIn(ostream &file) {

}

class Cube : public shape3D{
private:
    double sideLength;
public:
    Cube(double s):shape3D(0, 0, 0), sideLength(s){}
    double volume(){
        return sideLength*sideLength*sideLength;
    }
};

class Cylinder : public shape3D{
private:
    double r,h;
public:
    Cylinder(double r, double h):shape3D(0, 0, 0), r(r), h(h){}
};

class Design{
private:
    vector<shape3D*> shp;
public:
    void add(shape3D* s1){
        shp.push_back(s1);
    }
    void write(string filename){
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
    Cube c(s);
    c.translate(x,y,z);
    // rotate??
    cout << c.volume() << '\n';
    c.write("out.stl"); // how to get all my shapes into the same file
    d.add(c);
    double r = 10, height  = 20;
    Cylinder cyl(r, height);
    d.add(c);
    d.write("test.stl");
}