#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>

using namespace std;

class Story
{
    private:
        string date;
        string storyName;
        string story;
    
    public:
        Story(const string& date, const string& storyName, const string& story)
        {
            if(date.empty() && storyName.empty() && story.empty())
                throw "Invalid data";
            this->date = date;
            this->storyName = storyName;
            this->story = story;
        }
        const string& getDate()const{  return this->date;  }
        const string& getStoryName()const{  return this->storyName;  }
        const string& getStory()const{  return this->story;  }
        

    void writeStory(const Story& story1, const string& user)
{
    fstream newfile;
    string fileName;
    fileName = user + ".txt";
    newfile.open(fileName,ios::app);  
    if(newfile.is_open()) 
    {
        newfile << "Story date: " << story1.getDate() << endl << "Story name: " << story1.getStoryName() << endl << "Story: " << endl << story1.getStory() << endl;  
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
    cout << "1: Search by name" << endl << "2: Search by date" << endl << "3: Go back" << endl;
    cin >> choice;
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
    
void menu(const string& username)
{
    size_t choice;
    while(choice != 4)
    {
        cout << "1: Write a story." << endl << "2: Read your stories." << endl << "3: Search for a story" << endl << "4: Exit." << endl;
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
                while(!getline(cin, storyTemp, '\t'))
                {
                    story += storyTemp;
                }
                Story story1(date, storyName, story);
                story1.writeStory(story1, username);
            }
            
            case 2:
                break;
                
            case 3:
                search();
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
            fstream newfile;
            string username, password, data;
            cin >> username;
            cin >> password;
            if(newfile.is_open()) 
            {
                while(getline(newfile, data)) 
                {
                    if(data == username + " " + password)
                        menu(username);
                }
            }
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
                        menu(username);
                }
            }
        }
    }
}

int main()
{
    menu("dab");
    return 0;
}
