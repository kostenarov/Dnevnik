#ifndef STORIES_H
#define STORIES_H

#include "cipher.h"

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
        
        void readStory(fstream& newfile, string password, string& vect) 
        {
            string storyTemp, date, name, input;
        
            getline(newfile, date);
            DeCBC(date, password, vect);
                        
            getline(newfile, name);
            
            DeCBC(name, password, vect);
            
            getline(newfile, storyTemp, '#');
                        
            DeCBC(storyTemp, password, vect);
                
            cout << storyTemp << endl << date << endl << name << endl;
                        
            this->date = date;
            this->storyName = name;
            this->story = storyTemp;
        }
        
        friend ostream& operator<<(ostream& out, Story& other)
        {
            out << other.date << endl;
            out << other.storyName << endl;
            out << other.story << endl;
            
            return out;
        }
        
        //friend fstream& operator>>(fstream)
};

#endif
