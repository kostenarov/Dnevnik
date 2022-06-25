#include <iostream>
#include <unordered_map>
#include <vector>
#include "console_interface.cpp"

void addElementToDatesTable(string key, Story& story, unordered_map<string, vector<Story>> map)
{
    if(key.empty())
        throw invalid_argument("No key provided!");

    map[key].push_back(story);
}

void addElementToNamesTable(string key, Story& story, unordered_map<string, Story> map)
{
    if(key.empty())
        throw invalid_argument("No key provided!");

    map[key] = story;
}

void removeElementFromDatesTable(string key, Story& story, unordered_map<string, vector<Story>> map)
{
    if(key.empty())
        throw invalid_argument("No key provided!");

    if(map[key].empty())
        throw invalid_argument("There is no such story!");

    if(map[key].size() > 1)
    {
        cout << "There are multiple stories here!" << endl;
        for(int i = 0; i < map[key].size(); ++i)
            cout << map[key][i].getStoryName() << endl;
        cout << "Choose which one you want! (1, 2, 3... etc)" << endl;

        short index;
        cin >> index;
        map[key].erase(map[key].begin() + index - 1);
        return;
    }

    map[key].pop_back();
}

void removeElementFromNamesTable(string key, Story& story, unordered_map<string, Story> map)
{
    if(key.empty())
        throw invalid_argument("No key provided!");

    map.erase(key);
}

Story& fastSearchDate(string key, unordered_map<string, vector<Story>> map)
{
    if(map[key].empty())
        throw invalid_argument("There is no such story!");

    if(map[key].size() > 1)
    {
        cout << "There are multiple stories here!" << endl;
        for(int i = 0; i < map[key].size(); ++i)
            cout << map[key][i].getStoryName() << endl;
        cout << "Choose which one you want! (1, 2, 3... etc)" << endl;
        short index;
        cin >> index;
        return map[key][index - 1];
    }
    return map[key][0];
}
