#ifndef LOGIN_H
#define LOGIN_H

#include "interface.h"

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
