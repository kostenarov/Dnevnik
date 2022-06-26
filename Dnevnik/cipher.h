#ifndef CIPHER_H
#define CIPHER_H

using namespace std;

size_t keyToNum(const std::string& key) {
    size_t n = 0;
    size_t len = key.size();
    for (size_t i = 0; i < len; i++)
        n += key[i];
    return n;
}

void sub(string& str, string& key, int n) {
    
    //n = n - (n % 7);
    
    int len = str.size();
    string ciphered;

    ciphered[len] = '\0';
    int alphaNum = 256;

    for(int i = 0; i < len; ++i) {
        char c = key[i % key.size()];
        
        int ch = str[i] + ((c * n) % alphaNum);
        
        ch = ch % alphaNum;
        
        ciphered.push_back(ch);
    }
    
    str = ciphered;

    //printf("%s\n", ciphered);
}

void CBC(std::string& str, std::string& key, std::string& vect) {
    size_t strLen = str.size();
    size_t vectLen = vect.size();
    
    for (size_t i = 0; i < strLen; ++i) {
        str[i] = str[i] ^ vect[i % vectLen];
    }
    
    sub(str, key, keyToNum(key));
    
    vect = str;
}

void desub(string& str, string& key, int n) {
    
    //n = n - (n % 7);
    
    int len = str.size();
    string deciphered;
    deciphered[len] = '\0';

    int alphaNum = 256;

    for(int i = 0; i < len; ++i) {
        char c = key[i % key.size()];
        
        short ch =  str[i] - ((c * n) % alphaNum);
        if(ch < 0) ch = 256 - abs(ch) % alphaNum;
        else ch = ch % alphaNum;
        
        deciphered.push_back(ch);
    }
    
    str = deciphered;
    
    //printf("%s\n", deciphered);
}

void DeCBC(std::string& str, std::string& key, std::string& vect) {
    size_t strLen = str.size();
    size_t vectLen = vect.size();
    string tempVect = str;
    
    desub(str, key, keyToNum(key));
    
    for (size_t i = 0; i < strLen; ++i) {
        str[i] = str[i] ^ vect[i % vectLen];
    }
        
    vect = tempVect;
}

#endif
