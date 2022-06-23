#include <iostream>
#include <cstring>

using namespace std;

char charCipherN(char& c, unsigned short n) {
	size_t alphaLen = 'z' - 'a' + 1;
	
	return c + n;	
}

char charDecipherN(char& c, unsigned short n) {
	size_t alphaLen = 'z' - 'a' + 1;
	
	return c - n;	
}

void cipherN(string& str, size_t len, unsigned short n) {
	for (size_t i = 0; i < len; ++i) {
		str[i] = charCipherN(str[i], n);
	}
}

void decipherN(string& str, size_t len, unsigned short n) {
	size_t alphaLen = 'z' - 'a' + 1;
	for (size_t i = 0; i < len; ++i) {
		str[i] = charDecipherN(str[i], n);
	}
}

size_t keyToNum(string& key) {
	size_t n = 0;
	size_t len = key.size();
	for (size_t i = 0; i < len; i++)
		n += key[i];
	return n;
}

void CBC(string& str, string& key, std::string& vect) {
    	size_t strLen = str.size();
	size_t vectLen = vect.size();
	
	for (size_t i = 0; i < strLen; ++i) {
		str[i] = str[i] ^ vect[i % vectLen];
	}
	
	cipherN(str, strLen, keyToNum(key));
	
	vect = str;
}


void DeCBC(string& str, string& key, string& vect, size_t vectLen) {
    size_t strLen = str.size();
	string tempVect = str;
	
	decipherN(str, strLen, keyToNum(key));
	cout << str << endl << key << endl << vect << endl << vectLen << endl;
	for (size_t i = 0; i < strLen; ++i) {
		str[i] = str[i] ^ vect[i % vectLen];
	}
		
	vect = tempVect;
}
