#ifndef INTERFACE_H
#define INTERFACE_H

#include "cipher.h"
#include "users.h"
#include "search.h"

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


void search()
{
    /*
    size_t choice = 0;
    cout << "1: Search by name." << endl << "2: Search by date." << endl << "3: Go back." << endl;
    cin >> choice;
    cin.ignore();
    switch(choice)
    {
        case 1:
            string name;
            cout << "Enter story name: ";
            cin >> name;
            fastSearchName(name);
        
        case 2:
            string date;
            cout << "Enter story date: ";
            cin >> date;
            fastSearchDate(date);
            
        case 3:
            break;
    }*/
}
    
void menu(User& user)
{
    string vectDe = "kuskus", vectEn;
    string fileName = user.getUsername() + ".txt";
    fstream newfile;
    newfile.open(fileName, ios::in);
    
    while(newfile.is_open() && !newfile.eof()) {
        Story temp;
        cout << "here 1" << endl;
        temp.readStory(newfile, user.getPassword(), vectDe);
        user.addStory(temp);
    }
    
    cout << "here 2" << endl;
    newfile.close();
    
    vectEn = vectDe;
    
    cout << vectDe.size() << " " << vectEn.size() << endl;
    
    cout << user.getStories().size() << endl;
    
    size_t choice;
    while(choice != 4)
    {
        cout << "1: Write a story." << endl << "2: Read your stories." << endl << "3: Search for a story." << endl << "4: Exit." << endl;
        cin >> choice;
        system("cls");
        switch(choice)
        {
            case 1:
            {
                string date, storyName, storyTemp, story;
                size_t counter = 0;
                cout << "Date:";
                cin >> date;
                cout << "Story name:";
                cin >> storyName;
                cout << "Enter story:";
                //getline(cin, story);
                getline(cin, story, '#');
                cin.ignore();
                Story story1(date, storyName, story);
                
                user.addStory(story1);
                story1.writeStory(story1, user.getUsername(), user.getPassword(), vectEn);
                break;
            };
            
            case 2:
            {
                vector<Story> stories = user.getStories();
                for(int i = 0; i < stories.size(); ++i) {
                    cout << stories[i];
                }
                
                break;
            };
            
            case 3:
                search();
                break;
        }
    }
}

#endif
