#ifndef USERS_H
#define USERS_H

#include "stories.h"

using namespace std;

class User
{
    string username;
    string password;
    vector<Story> stories;

    public:
    
        User(const string& username, const string& password)
        : username(username), password(password)
        {
            if(username.empty() || password.empty())
                throw invalid_argument("Invalid data");
        }
    
        User(const string& username, const string& password, vector<Story> stories)
        : username(username), password(password), stories(stories)
        {
            if(username.empty() || password.empty() || stories.empty())
                throw invalid_argument("Invalid data");
        }
        
        User(const User& other)
        : username(other.username), password(other.password), stories(other.stories){}
        
        const string& getUsername()const { return this->username; }
        const string& getPassword()const { return this->password; }
        vector<Story> getStories() const { return this->stories; }
        
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
            
            this->stories.push_back(story);
            return *this;
        }

};

#endif
