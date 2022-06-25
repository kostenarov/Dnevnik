#include <iostream>
#include <unordered_map>
#include <vector>
#include <ecxeption>
#include "console_interface.cpp"

unordered_map<string, vector<Story>> addElementToDatesTable(string key, Story& story, unordered_map<string, vector<Story>> map)
{
    if(key.empty())
        throw invalid_argument("No key provided!");

    map[key].push_back(story);
    return map;
}

unordered_map<string, Story> addElementToNamesTable(string key, Story& story, unordered_map<string, Story> map)
{
    if(key.empty())
        throw invalid_argument("No key provided!");

    map[key] = story;
    return map;
}

unordered_map<string, vector<Story>> removeElementFromDatesTable(string key, Story& story, unordered_map<string, vector<Story>> map)
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
        //map[key].erase(map[key].begin() + index - 1);
        return map;
    }

    map[key].pop_back();
    return map;
}

unordered_map<string, Story> removeElementFromNamesTable(string key, Story& story, unordered_map<string, Story> map)
{
    if(key.empty())
        throw invalid_argument("No key provided!");

    map.erase(key);
    return map;
}

Story& fastSearchDate(string key, unordered_map<string, vector<Story>> map)
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
        return map[key][index - 1];
    }
    return map[key][0];
}

Story& fastSearchName(string key, unordered_map<string, Story> map)
{
    if(key.empty())
        throw invalid_argument("No key provided!");

    return map[key];
}
