#pragma once

class Color {
private:
    uint32_t rgba;
public:
	Color(uint8_t r, uint8_t g, uint8_t b) {
        rgba = (r << 16) + (g << 8) + b;
	}

	char getColor(){
	    if(rgba == 0xFF0000){
            return 'R';
	    } else if(rgba == 0x0000FF){
            return 'B';
	    } else if(rgba == 0x00FF00){
            return 'G';
	    } else if(rgba == 0xFFFFFF){
            return 'W';
	    }
	}
	//TODO:	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha) {}
	
};
