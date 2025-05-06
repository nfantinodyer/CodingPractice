#include <iostream>
#include <map>
#include <string>
using namespace std;

void viewCurrentList(map<int, pair<string, string>>ToDoList)
{
    if (ToDoList.empty()) {
        cout << "To Do List is empty" << endl;
    }
    for (int i = 0; i < ToDoList.size(); i++) {
        cout << "ID:" << i;
        cout << " \\/ Item:" << ToDoList.at(i).first;
        cout << " \\/ Do By:" << ToDoList.at(i).second << endl;
    }
}

map<int, pair<string, string>> addToList(map<int, pair<string, string>>ToDoList)
{
    string ItemName = "";
    string DateTime = "";
    int size = ToDoList.size();
    cout << "Type in the todo item:" << endl;
    
    cin.ignore(); //to clear cin buffer so i can use getline();

    getline(cin,ItemName);

    cout << "Now enter the Date and time you want "<<ItemName<<" completed by :" << endl;
    getline(cin,DateTime);

    pair<string, string> stringPair = {ItemName,DateTime};

    ToDoList.insert({size,stringPair});
    return ToDoList;
}

map<int, pair<string, string>> removeFromList(map<int, pair<string, string>>ToDoList)
{
    if (ToDoList.empty()) {
        cout << "To Do List is empty" << endl;
        return ToDoList;
    }

    int num;
    cout << "Type ID number you wish to remove (0, or 1, etc)" << endl;
    cin >> num;

    int size = ToDoList.size()-1;

    if (num > size) {
        cout << "Not a valid ID" << endl;
        ToDoList = removeFromList(ToDoList);
    }
    else {
        string temp = ToDoList.at(num).first;
        ToDoList.erase(num);
        cout << "Removed " << temp << " from your ToDo List" << endl;
    }
    return ToDoList;
}

void mainMenu() 
{
    //int: item number;
    //first string: ItemName;
    //second string: DateTime;
    map<int,pair<string, string>>ToDoList;
    bool exit = false;
    int x = 0;
    while (!exit) {
        cout << endl;
        cout << "Nuggy To Do List" << endl;
        cout << "1. View Current List" << endl;
        cout << "2. Add To Do" << endl;
        cout << "3. Remove To Do" << endl;
        cout << "4. Exit" << endl;

        cin >> x;

        if (x == 1) {
            viewCurrentList(ToDoList);
        }
        else if (x == 2) {
            ToDoList = addToList(ToDoList);
        }
        else if (x == 3) {
            ToDoList = removeFromList(ToDoList);
        }
        else if (x == 4) {
            exit = true;
            break;
        }
        else {
            cout << "Please only type 1-4" << endl;
        }
    }

}

int main() 
{
    cout << "Hewwwwwows" << endl;
    cout << "Welcums to my nuggy todo list" << endl;
    cout << "Thank yous" << endl;
    
    mainMenu();
    
    return 0;
}