#ifndef INTERFACE_H
#define INTERFACE_H

#include "cipher.h"
#include "users.h"
#include "search.h"
#include "stories.h"

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

void login(){
    
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    size_t choice;
    
    cout << "1: Login" << endl << "2: Register"<< endl;
    cin >> choice;
    
    switch(choice)
    {
        case 1:
        {
            
            fstream newfile;
            string username;
            string password;
            string data;
            
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            newfile.open("logins.txt", ios::in);
            
            if(newfile.is_open()){
                while(getline(newfile, data)){
                    
                    hash<string> hash_obj;
                    string hashedPass;
                
                    for(int i = 0; i < 53; i++){
                        hashedPass = to_string(hash_obj(password + alphabet[i]));
        
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
            string username;
            string password;
            string data;
            
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            
            hash<string> hash_obj;
            string hashedPass = to_string(hash_obj(password + alphabet[rand() % 52]));
            
            User user(username, hashedPass);
            
            newfile.open("logins.txt",ios::app);  
            
            if(newfile.is_open()){
                
                newfile << user.getUsername() << "\t" << user.getPassword() << endl;
                newfile.close();
                menu(user);
            }
            
            break;
        };
    }
}

#endif
