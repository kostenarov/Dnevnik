#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include "cypher.h"

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
        
        Story& operator=(Story& other)
        {
            if(this == &other) 
            {
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
        

    void writeStory(const Story& story1, const string& user, string& password, string& vect)
    {
        fstream newfile;
        string fileName, storyTemp;
        storyTemp = story1.getStory();
        fileName = user + ".txt";
        newfile.open(fileName, ios::app);
        if(newfile.is_open()) 
        {
            CBC(storyTemp, password, vect);
            storyTemp += '#';
            newfile << story1.getDate() << endl << story1.getStoryName() << endl << storyTemp << endl;  
            newfile.close();    
        }
    }
    
    
};

void searchByDate()
{
    string date;
    cout << "Please input the date fom which you would like to read a story: ";
    cin >> date;
}

void searchByName()
{
    string name;
    cout << "Please input the date fom which you would like to read a story: ";
    cin >> name;
}

void search()
{
    size_t choice = 0;
    cout << "1: Search by name." << endl << "2: Search by date." << endl << "3: Go back." << endl;
    cin >> choice;
    cin.ignore();
    switch(choice)
    {
        case 1:
            searchByName();
        
        case 2:
            searchByDate();
            
        case 3:
            break;
    }
}

void readStories();

void readStory(const string& user, string& password, string& vect)
    {
        fstream newfile;
        string fileName, storyTemp, date, name, input;
        fileName = user + ".txt";
        newfile.open(fileName, ios::in);
        if(newfile.is_open()) 
        {
            getline(newfile, date);
            getline(newfile, name);
            getline(newfile, storyTemp, '#');
            DeCBC(storyTemp, password, vect, 6);
            newfile.close();
            
        }
    }
    
void menu(const string& username, string& password)
{
    size_t choice;
    string vect = "kuskus";
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
                cin.ignore();
                getline(cin, story, '#');
                cin.ignore();
                Story story1(date, storyName, story);
                story1.writeStory(story1, username, password, vect);
                continue;
            };
            
            case 2:
                readStory(username, password, vect);
                continue;
                
            case 3:
                search();
                continue;
        }
    }
}

void login()
{    
    cout << "1: Login" << endl << "2: Register";
    size_t choice;
    cin >> choice;
    switch(choice)
    {
        case 1:
        {
            string username, password;
            cin >> username;
            cin >> password;
            menu(username, password);
        }
            
        case 2:
        {
            fstream newfile;
            string username, password, data;
            cin >> username;
            cin >> password;
            newfile.open("logins.txt",ios::in);  
            if(newfile.is_open()) 
            {
                while(getline(newfile, data)) 
                {
                    if(data == username + " " + password)
                        newfile << username << " " << password << endl;
                        menu(username, password);
                }
            }
        }
    }
}

int main()
{
    string password = "kus";
    menu("dab", password);
    return 0;
}
