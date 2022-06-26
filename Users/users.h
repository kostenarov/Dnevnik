#ifndef USERS_H
#define USERS_H

using namespace std;

class Story
{
    private:
        string date;
        string storyName;
        string story;
    
    public:
        Story() {}
        
        Story(const string& date, const string& storyName, const string& story)
        {
            if(date.empty() && storyName.empty() && story.empty())
                throw "Invalid data";
            this->date = date;
            this->storyName = storyName;
            this->story = story;
        }
        
        Story& operator=(Story& other) {
            if(this == &other) {
                return *this;
            }
            
            this->date = other.date;
            this->storyName = other.storyName;
            this->story = other.story;
            
            return *this;
        }
        
        const string& getDate()const{  return this->date;  }
        const string& getStoryName()const{  return this->storyName;  }
        const string& getStory()const{  return this->story;  }
        void setStory(const string& story)
        {
            this->story = story;
        }
        
        void writeStory(const Story& story1, const string user, string password, string& vect)
        {
            fstream newfile;
            string fileName, storyTemp, storyName, date;
            storyTemp = story1.getStory();
            storyName = story1.getStoryName();
            date = story1.getDate();
            
            fileName = user + ".txt";
            newfile.open(fileName, ios::app);
            
            if(newfile.is_open()) 
            {
                CBC(date, password, vect);
                CBC(storyName, password, vect);
                CBC(storyTemp, password, vect);
                
                storyTemp += '#';
                newfile << date << endl << storyName << endl << storyTemp << endl;  
                newfile.close();    
            }
        }
        
        void readStory(const string user, string password, string& vect)
        {
            fstream newfile;
            string fileName, storyTemp, date, name, input;
            fileName = user + ".txt";
            newfile.open(fileName, ios::in);
            if(newfile.is_open()) 
            {
                getline(newfile, date);
                DeCBC(date, password, vect);
                
                getline(newfile, name);
                DeCBC(name, password, vect);
                
                getline(newfile, storyTemp, '#');
                
                //cout << storyTemp << endl << password << endl << vect << endl;
                DeCBC(storyTemp, password, vect);
                
                cout << date << endl;
                cout << name << endl;
                cout << storyTemp << endl;
                newfile.close();
                
            }
        }
};

class User
{
    string username;
    string password;
    vector<Story> stories;
    //if multiple diaries are needed
    
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
            
            this->stories.push_back(story);
            return *this;
        }

};

#endif
