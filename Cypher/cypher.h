#ifndef CYPHER_H
#define CYPHER_H
  
char charCipherN(char& c, unsigned short n);
char charDecipherN(char& c, unsigned short n);
void cipherN(std::string& str, size_t len, unsigned short n);
void decipherN(std::string& str, size_t len, unsigned short n);
size_t keyToNum(std::string& key);
void CBC(std::string& str, std::string& key, std::string& vect);
void DeCBC(std::string& str, std::string& key, std::string& vect, size_t vectLen);

#endif
