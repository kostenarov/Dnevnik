#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class User
{
    private:
        string username;
        string password;
    
    public:
        User(const string& username, const string& password)
        {
            if(username.empty() && password.empty())
                throw "Invalid data";
            this->username = username;
            this->password = password;
        }
        const string& getName()const{  return this->username;  }
        const string& getPassword()const{  return this->password;  }
};


int main()
{
    fstream newfile;
    string username, password;
    
    cout << "Please input valid username and password" << endl;
    cout << "Username:";
    cin >> username;
    cout << "Password:";
    cin >> password;
    User user1(username, password);
    newfile.open("logins.txt",ios::app);  
    if(newfile.is_open()) 
    {
        newfile<<user1.getName() << " " << user1.getPassword() << endl;   
        newfile.close();    
    }
    newfile.open("logins.txt",ios::in); 
    if (newfile.is_open())
    {   
          string tp;
          while(getline(newfile, tp))
          { 
              if(username + " " + password == tp)
              {
                  string filename = username + ".txt";
                  newfile.open(filename, ios::app);
                  newfile << "dab";
              }
          }
          newfile.close(); 
    }
    return 0;
}
