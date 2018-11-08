#include <iostream>
#include "Color.hh"
using namespace std;

Class Bitmap{
private:
    uint32_t* rgba;
    uint32_t width, height;
public:
    Bitmap(unit32_t width, unit32_t height, uint32_t color = 0x000000):rgba(new uint32_t[width * height]), width(width), height(height){
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                rgba[i * height + j] = color;
            }
        }
    }
    ~Bitmap(){
        delete [] rgba;
    }

    void line(uint32_t x1, uint32_t x2, uint32_t y1, uint32_t y2, Color c){
        for (int i = x1; i <= x2 ; i++) {
            for (int j = y1; j <= j2 ; j++) {
                rgba[j * height + i] = c;
            }
        }
    }

    void horizLine(uint32_t x1, uint32_t x2, uint32_t y, Color c){
        for (int i = x1; i <= x2; i++) {
            rgba[y * height + i] = uint32_t val;
        }
    }

    void vertLine(uint32_t x, uint32_t y1, uint32_t y2, Color c){
        for (int i = y1; i <= y2 ; i++) {
            rgba[i * height + x] = c;
        }
    }

    void vertLine(uint32_t x, uint32_t y1, uint32_t y2, Color c){
        for (int i = y1; i <= y2 ; i++) {
            rgba[i * height + x] = c;
        }
    }

    Bitmap& ellipse(uint32_t xCenter, uint32_t yCenter, uint32_t width, uint32_t height, Color c){

    }
};


int main() {
	Bitmap b(30,20); // 30 pixels across, 20 pixels high, each pixel RGBA
	// top left pixel = (0,0)
	Color RED(255,0,0); // all red, no green, no blue (fully opaque)
	Color BLUE(0,255,0);
	Color GREEN(0,0,255);
	Color WHITE(255,255,255);
	
	
	b.line(0,0,   19,19, RED);
	b.line(0,5,   29,10, BLUE); //Bresenham algorithm
	//https://en.wikipedia.org/wiki/Bresenham's_line_algorithm

	// https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
	//TODO: b.line(0,100, 100,50, BLUE); //Wu algorithm
	b.horizLine(0, 20, 19, GREEN); // from x=0 to x=20 at y=19
	b.vertLine(5, 0,19, GREEN); // from y = 0 to y=19 at x = 5
	b.fillRect(10,10, 4, 3,BLACK); // x = 10, y =10 w=4, h=3
	b.drawRect(10,10, 4, 3,WHITE); // x = 10, y =10 w=4, h=3
    b.ellipse(15,0, 8, 5, RED);    // ellipse centered at (15,0) w= 8, h=5
	cout << b;
	/*
R
 R
  R
   R
    R
BBB
   BBBBB
        BBBBBB


	 */
}



	
