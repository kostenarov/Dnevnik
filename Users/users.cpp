#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class User
{
    private:
        string username;
        string password;
    
    public:
        User(const string& username, const string& password)
        {
            if(username.empty() && password.empty())
                throw "Invalid data";
            this->username = username;
            this->password = password;
        }
        const string& getName()const{  return this->username;  }
        const string& getPassword()const{  return this->password;  }
};
