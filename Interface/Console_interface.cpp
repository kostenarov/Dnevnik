#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

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

void menu(const string& username)
{
    size_t choice;
    while(choice != 3)
    {
        cout << "1: Write a story." << endl << "2: Read your stories." << endl << "3:Exit." << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                string date, storyName, storyTemp, story;
                cout << "Date:";
                cin >> date;
                cout << "Story:";
                cin >> storyName;
                cout << "Enter story:";
                while(getline(cin, storyTemp))
                {
                    story += storyTemp;
                }
                Story story1(date, storyName, story);
                story1.writeStory(story1, username);
            }
            case 2:
                break;
        }
    }
}

void login()
{
    cout << "1: Login" << endl << "2: Register";
    size_t choice;
    cin >> choice;
    fstream newfile;
    switch(choice)
    {
        case 1:
        {
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
            string username, password, data;
            cin >> username;
            cin >> password;
            newfile.open("logins.txt",ios::in, ios::app);  
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
    
    return 0;
}
