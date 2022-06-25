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
    
void menu(User& user)
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
                
                user.addStory(story1);
                story1.writeStory(story1, user.getUsername(), user.getPassword(), vectEn);
                //cout << vect;
                break;
            };
            
            case 2:
            {
            //cout <<vect << endl;
                Story story2;
                story2.readStory(user.getUsername(), user.getPassword(), vectDe);
                break;
            };
            
            case 3:
                search();
                break;
        }
    }
}

void login()
{
    cout << "1: Login" << endl << "2: Register"<< endl;
    size_t choice;
    cin >> choice;
    switch(choice)
    {
        case 1:
        {
            fstream newfile;
            string username, password, data;
            
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            
            User user(username, password);
            
            newfile.open("logins.txt", ios::in);
            
            if(newfile.is_open()) 
            {
                while(getline(newfile, data)) 
                {
                    cout << data << endl;
                    if(data == user.getUsername() + "\t" + user.getPassword()){
                        newfile.close();
                        menu(user);
                    }
                }
            }
            
            newfile.close();
            break;
        };
            
        case 2:
        {
            fstream newfile;
            string username, password, data;
            
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            
            User user(username, password);
            
            newfile.open("logins.txt",ios::app);  
            if(newfile.is_open()) 
            {
                newfile << user.getUsername() << "\t" << user.getPassword() << endl;
                newfile.close();
                menu(user);
            }
            break;
        };
    }
}

#endif
