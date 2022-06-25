#ifndef INTERFACE_H
#define INTERFACE_H

#include "cipher.h"
#include "users.h"

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
    
void menu(const string& username)
{
    size_t choice;
    string vectDe = "kuskus", vectEn = "kuskus", password = "kus";
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
                cin.ignore();
                getline(cin, story, '#');
                cin.ignore();
                Story story1(date, storyName, story);
                story1.writeStory(story1, username, password, vectEn);
                //cout << vect;
                continue;
            };
            
            case 2:
            {
            //cout <<vect << endl;
                Story story2;
                story2.readStory(username, password, vectDe);
                continue;
            };
            
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

#endif
