#include "String.hh"
#include <iostream>
#include <wrl.h>

using namespace std;

String::String():len(0), s(nullptr){}

String::String(const char str[]):len(strlen(str)), s(new char[len]) {
	for (int i = 0; i < len; i++) {
		s[i] = str[i];
	}
}
	
String::String(const char str[], uint32_t mult): len(strlen(str)*mult), s(new char[len]) {
	uint32_t strsize = len / mult;
	int c = 0;
	for (int j = 0; j < mult; j++) {
		for (int i = 0; i < strsize; i++, c++){
			s[c] = str[i];
		}
	}
}

String::~String() {
	delete [] s;
}

	//copy constructor
String::String(const String& orig):len(orig.len), s(new char[len]) {
    uint64_t *src = (uint64_t *) orig.s;
    uint64_t *des = (uint64_t *) s;
    uint32_t count;
    for (count = len; count >= 8; count -= 8) {
        *des++ = *src++;
    }
    char* pdes = (char*)des;
    char* psrc = (char*)src;
    for (count = len; count > 0; count--) {
        *pdes++ = *psrc++;
    }
}

String& String::operator =(const String& orig) {
    String copy(orig);
    len = orig.len;
    swap(s, copy.s);
    return *this;
}

char String::operator [](const uint32_t pos)const {
    return s[pos];
}
char& String::operator [](uint32_t pos) {
    return s[pos];
}

ostream& operator<<(ostream& s, const String& str) {
    for (uint32_t i = 0; i < str.len; i++){
        s << str[i];
    }
    return s;
}

String& String::operator+=(const char *str) {
    String ans;
    ans.len = len + strlen(str);
    ans.s = new char[ans.len];
    for (int i = 0; i < len; i++)
        ans.s[i] = s[i];
    int j = len;
    for (int i = 0; i < strlen(str); i++)
        ans.s[j+i] = str[i];
    return ans;
}

void String::replace(char str1, char str2) {
    str1 = str2;
}

String String::substring(uint32_t a, uint32_t b) {
    String ans;
    ans.len = b;
    ans.s = new char[ans.len];
    for(int i=0; i<ans.len; i++)
        ans.s[i] = s[i+a-1];
    return ans;
}

String String::operator+(const String &r) const {
    String ans;
    ans.len = len + r.len;
    ans.s = new char[ans.len];
    for (int i = 0; i < len; i++)
        ans.s[i] = s[i];
    int j = len;
    for (int i = 0; i < r.len; i++)
        ans.s[j+i] = r.s[i];
    return ans;
}

int String::length() const{
    return len;
}

String String::insert(uint32_t a, const String& b) {
    String ans;
    ans.len = len + b.len;
    ans.s = new char[ans.len];
    for(int i=0; i<a; i++)
        ans.s[i] = s[i];
    for(int i=0; i<b.len; i++)
        ans.s[i+a] = b.s[i];
    for(int i=0; i<ans.len-a-b.len; i++)
        ans.s[i+a+b.len] = s[i+a];
    return ans;
}

String::String(String &&orig) :len(orig.len), s(orig.s){
    orig.s = nullptr;
}

	
