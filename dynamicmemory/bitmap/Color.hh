#pragma once

class Color {
private:
    uint32_t rgba;
public:
	Color(uint8_t r, uint8_t g, uint8_t b) {
        rgba = (r << 16) + (g << 8) + b;
	}
	//TODO:	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha) {}
	
};
