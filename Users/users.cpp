#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class User
{
    string username;
    string password;
    vector <Diary> diary;
    //if multiple diaries are needed
    
    public:
        User(const string& username, const string& password){
            
        if(username.empty() || password.empty())
            throw invalid_argument("Invalid data");
            this->username = username;
            this->password = password;
        }
        
        const string& getName()const{  return this->username;  }
        const string& getPassword()const{  return this->password;  }
        
        void setName(string username){  
            if(!username.empty())
                throw invalid_argument("Invalid data");
            this->username = username;
        }
        void setPassword(string password){        
            if(!password.empty())
                throw invalid_argument("Invalid data");
            this->password = password;
        }
};

int main(){

    return 0;
}
