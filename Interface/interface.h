#ifndef INTERFACE_H
#define INTERFACE_H

#include "cipher.h"
#include "users.h"
#include "fast_search.h"

void search(User& user)
{
    unordered_map<string, Story> names_map;
    unordered_map<string, vector<Story>> dates_map;
    vector <Story> stories = user.getStories();
    	
    for(int i = 0; i < stories.size(); ++i)
    {
    	addElementToDatesTable(stories[i].getDate(), stories[i], dates_map);
    	addElementToNamesTable(stories[i].getStoryName(), stories[i], names_map);
    }
    	
    size_t choice = 0;
    cout << "1: Search by name." << endl << "2: Search by date." << endl << "3: Go back." << endl;
    cin >> choice;
    cin.ignore();
    switch(choice)
    {
        case 1:
        {
            string name;
            cout << "Enter story name: ";
            cin >> name;
            cout << fastSearchName(name, names_map).getStory() << endl;
            break;
       	};
        
        case 2:
        {
            string date;
            cout << "Enter story date: ";
            cin >> date;
            cout << fastSearchDate(date, dates_map).getStory() << endl;
            break;
       	};
        case 3:
            break;
    }
}
    
void menu(User& user)
{
    string vectDe = "kuskus", vectEn;
    string fileName = user.getUsername() + ".txt";
    string temp1;
    fstream newfile;
    newfile.open(fileName, ios::in);
    
    while(newfile.is_open() && !newfile.eof() && getline(newfile, temp1, '#')) {
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
            try{
                search(user);
            }catch(exception& e)
            {
            	cout << e.what() << endl;
            }
                break;
        }
    }
}

#endif
