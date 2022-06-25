#include <iostream>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <exception>
using namespace std;

class User
{
    string username;
    string password;
    vector<Story> stories;
    //if multiple diaries are needed
    
    public:
        User(const string& username, const string& password, vector<Story> stories)
        : username(username), password(password), stories(stories)
        {
            if(username.empty() || password.empty() || stories.empty())
                throw invalid_argument("Invalid data");
        }
        
        User(const User& other)
        : username(other.username), password(other.password), stories(other.stories){}
        
        const string& getUsername()const{  return this->username;  }
        const string& getPassword()const{  return this->password;  }
        const vector<Story>& getStories() const { return this->stories; }
        
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
        
        User& addStory(const Story& story){
            
            if(story.empty())
                throw invalid_argument("Invalid story provided!");
                
            this->stories.push_back(story);
            return *this;
        }

};

int main(){
    
    return 0;
}
