#ifndef INTERFACE_H
#define INTERFACE_H

#include "cipher.h"
#include "users.h"

void searchByDate()
{
    string date;
    cout << "Please input the date fom which you would like to read a story: ";
    cin >> date;
    if(!date.empty())
    {
        
    }
    else
    {
        cout << "Date is invalid" << endl; // throw "Invalid date!"
        break;
    }
}

void searchByName()
{
    string name;
    cout << "Please input the date fom which you would like to read a story: ";
    cin >> name;
    if(!name.empty())
    {
        
    }
    else
    {
        cout << "Name is invalid" << endl; // throw "Invalid name!"
        break;
    }
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
                getline(cin, story, '#');
                cin.ignore();
                Story story1(date, storyName, story);
                
                user.addStory(story1);
                story1.writeStory(story1, user.getUsername(), user.getPassword(), vectEn);
                break;
            };
            
            case 2:
            {
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
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
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

            newfile.open("logins.txt", ios::in);
            
            if(newfile.is_open()) 
            {
                while(getline(newfile, data)) 
                {
                    //cout << data << endl;
                    hash<string> hash_obj;
                    string hashedPass;
                
                    for(int i = 0; i < 53; i++){
                        hashedPass = to_string(hash_obj(password + alphabet[i]));
                        
                        cout << "Data: " << data << endl;
                        cout << "Hash: " << hashedPass << endl << endl;
        
                        if(data == username + "\t" + hashedPass){
                            User user(username, hashedPass);
                            menu(user);
                            break;
                        }
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
            
            hash<string> hash_obj;
            string hashedPass = to_string(hash_obj(password + alphabet[rand() % 52]));
            
            User user(username, hashedPass);
            
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
