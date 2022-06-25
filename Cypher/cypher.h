#ifndef CIPHER_H
#define CIPHER_H
  
using namespace std;

char charCipherN(char& c, unsigned short n) {
    size_t alphaLen = 'z' - 'a' + 1;
    
    return c + n;    
}

char charDecipherN(char& c, unsigned short n) {
    size_t alphaLen = 'z' - 'a' + 1;
    
    return c - n;    
}

void cipherN(std::string& str, size_t len, unsigned short n) {
    for (size_t i = 0; i < len; ++i) {
        str[i] = charCipherN(str[i], n);
    }
}

void decipherN(std::string& str, size_t len, unsigned short n) {
    size_t alphaLen = 'z' - 'a' + 1;
    for (size_t i = 0; i < len; ++i) {
        str[i] = charDecipherN(str[i], n);
    }
}

size_t keyToNum(const std::string& key) {
    size_t n = 0;
    size_t len = key.size();
    for (size_t i = 0; i < len; i++)
        n += key[i];
    return n;
}

void CBC(std::string& str, std::string& key, std::string& vect) {
        size_t strLen = str.size();
    size_t vectLen = vect.size();
    
    for (size_t i = 0; i < strLen; ++i) {
        str[i] = str[i] ^ vect[i % vectLen];
    }
    
    cipherN(str, strLen, keyToNum(key));
    
    vect = str;
}


void DeCBC(std::string& str, const std::string& key, std::string& vect, size_t vectLen) {
    size_t strLen = str.size();
    string tempVect = str;
    
    decipherN(str, strLen, keyToNum(key));
    cout << str << std::endl << key << std::endl << vect << std::endl << vectLen << endl;
    for (size_t i = 0; i < strLen; ++i) {
        str[i] = str[i] ^ vect[i % vectLen];
    }
        
    vect = tempVect;
}

#endif
