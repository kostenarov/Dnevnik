#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class User
{
    string username;
    string password;
    vector<Diary> diaries;
    //if multiple diaries are needed
    
    public:
        User(const string& username, const string& password, vector<Diary> diaries)
        : username(username), password(password), diaries(diaries)
        {
            if(username.empty() || password.empty() || diaries.empty())
                throw invalid_argument("Invalid data");
        }
        
        const string& getUsername()const{  return this->username;  }
        const string& getPassword()const{  return this->password;  }
        const vector<Diary>& getDiaries() const { return this->diaries; }
        
        void setUsername(const string& username){ 
            
            if(username.empty())
                throw invalid_argument("Invalid data");
                
            this->username = username;
        }
        void setPassword(const string& password){  
            
            if(password.empty())
                throw invalid_argument("Invalid data");
                
            this->password = password;
        }
        
        User& addDiary(const Diary& diary){
            
            if(diary.empty())
                throw invalid_argument("Invalid diary provided!");
                
            this->diaries.push_back(diary);
            return *this;
        }

};

int main(){
    
    return 0;
}
