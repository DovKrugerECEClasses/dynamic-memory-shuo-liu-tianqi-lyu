#include <iostream>
#include "Color.hh"
using namespace std;

Class Bitmap{
private:
    uint32_t* rgb;
    uint32_t width, height;
public:
    Bitmap(unit32_t width, unit32_t height, uint32_t defa = 0x000000):rgb(new char[width * height]), width(width), height(height){
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                rgb[i * height + j] = defa;
            }
        }
    }
    ~Bitmap(){
        delete [] rgb;
    }

    void line(uint32_t x1, uint32_t x2, uint32_t y1, uint32_t y2, Color& c){
        double deltax = x2 - x1;
        double deltay = y2 - y1;
        double deltaerr = 0;
        if(deltay / deltax < 0){
            deltaerr = -(deltay / deltax);
        } else{
            deltaerr = deltay / deltax;
        }
        double error = 0;
        int a = y1;
        for (int i = x1; i <= x2; i++){
            rgb[i * height + a] = c.getColor();
            error = error + deltaerr;
            if(error >= 0.5){
                if(deltay > 0){
                    a = a + 1;
                } else if(deltay = 0){
                    a = a;
                } else{
                    a = a - 1;
                }
                error = error - 1;
            }
        }
    }

    void horizLine(uint32_t x1, uint32_t x2, uint32_t y, Color& c){
        for (int i = x1; i <= x2; i++) {
            rgb[y * height + i] = c.getColor();
        }
    }

    void vertLine(uint32_t x, uint32_t y1, uint32_t y2, Color& c){
        for (int i = y1; i <= y2 ; i++) {
            rgb[i * height + x] = c.getColor();
        }
    }

    void fillRect(uint32_t x1, uint32_t y1, uint32_t Width, uint32_t Height, Color& c){
        for (int i = x1; i <= x1 + Width; i++) {
            for (int j = y1; j <= y1 + Height; j++){
                rgb[j * height + i] = c.getColor();
            }
        }
    }

    void drawRect(uint32_t x1, uint32_t y1, uint32_t Width, uint32_t Height, Color& c){
        for (int i = x1; i <= x1 + Width; i++) {
            for (int j = y1; j <= y1 + Height; j++){
                if (j == y1 || j == y1 + Height - 1){
                    rgb[j * height + i] = c.getColor();
                } else{
                    if(i == x1 || i == x1 + Width - 1){
                        rgb[j * height + i] = c.getColor();
                    }
                }
            }
        }
    }

    void ellipse(uint32_t xCenter, uint32_t yCenter, uint32_t Width, uint32_t Height, Color& c){
        for(int i = xCenter - (Width / 4) + 1; i <= xCenter + (Width / 4); i++){
            rgb[i]
        }
    }

    friend ostream& operator <<(ostream& s, Bitmap x){
        for(int i = 0; i < x.height; i++){
            for(int j = 0; j < x.width; j++){
                s << x.rgb[x.width * i + j] << " ";
            }
            s << '\n';
        }
        return s;
    }
};


int main() {
	Bitmap b(30,20); // 30 pixels across, 20 pixels high, each pixel RGBA
	// top left pixel = (0,0)
	Color RED(255,0,0); // all red, no green, no blue (fully opaque)
	Color GREEN(0,255,0);
	Color BLUE(0,0,255);
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



	
