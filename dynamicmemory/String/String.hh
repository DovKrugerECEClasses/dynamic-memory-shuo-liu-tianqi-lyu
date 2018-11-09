#include <iostream>
using namespace std;

class String {
private:
	uint32_t capacity;
	uint32_t len;
	char* s;
	uint32_t stringlen(const char* str) {
		uint32_t count = 0;
		while (*str++ != '\0')
			count++;
		return count;
	}
public:
    String();
    ~String();

	String(const char str[]);

	String(String&& orig);

	String(const char str[], uint32_t mult);

	//copy constructor
	String(const String& orig);

	String& operator =(const String& orig);

	char operator [](const uint32_t pos)const;

	char& operator [](uint32_t pos);

    friend ostream& operator<<(ostream& s, const String& str);

    String& operator +=(const char str[]);

    String substring(uint32_t a, uint32_t b);

    void replace(char str1, char str2);

    int length()const;

    String insert(uint32_t a, const String& b);

    String operator +(const String& r) const;
};