#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include <cstring>  

namespace fs = std::filesystem;

using namespace fs;
using namespace std;

void displaymenu()
{ 
    cout<<"===================================================== \n";
    cout<<" \t\tCSR Members manager \t \n ";
    cout<<"===================================================== \n";
    cout<<" 1.Delete a member \n";
    cout<<"\n";
    cout<<" 2.Add a member\n";
    cout<<" 3.Update a member\n";
    cout<<"\n";
    cout<<" 4.Show all members\n";
    cout<<" 5.Find a member by ID \n";
    cout<<"===================================================== \n";
    cout<<"\n";
}

void addMember()
{
    cout<< "\nyou have selected add member\n";
    //Take input
    cout << "\nName: ";
    string memberName;
    cin >> memberName;

    // Prepare file
    ofstream newfile;
    // used to add string + vars
    ostringstream fileDestination;
    fileDestination << "./members/-" << memberName << ".txt";
    // Create file
    newfile.open(fileDestination.str());
    // Write
    newfile << memberName <<"\n";
    newfile.close();
}
void deleteMember()
{
    cout<< "\nyou have selected delete member \n";
    // Loop though dir
    string path = "./members";
    for (const auto & entry : directory_iterator(path)){
        cout << entry.path() << endl;
    }
    // Input
    cout << "\nType the member name to delete: ";
    string memberName;
    cin >> memberName;
    // Prepare a ostring for the file name
    ostringstream fileDestination;
    fileDestination << "./members/" << memberName << ".txt";
    // Delete file
    remove(fileDestination.str());
}
void updateMember()
{
    cout<< "\nyou have selected update member 3\n";
}
void ViewAllMembers()
{
    cout<< "\nView all member records\n";
    // Loop though dir
    string path = "./members";
    for (const auto & entry : directory_iterator(path)){
        cout << entry.path() << endl;
        /*
        string ent = entry.path();
        char* c = strcpy(new char[ent.length() + 1], ent.c_str());
        cout << c[16, sizeof(c)] << "\n";
        cout << sizeof(c) << "\n";
        cout << strtok(c, "-") << endl;*/
    }
}
void FindMember()
{
    cout<< "\nyou have selected Find a member \n";
}
 
//Code by devenum.com
 
int main()
{
    string st[20];
    int itemcount = 0;
    
    //function to display Menu
    displaymenu();
    int yourchoice;
    string confirm;
    do
    { cout<<"Enter your choice(1-5):";
    cin>>yourchoice;
    // Switch case for each options
    switch (yourchoice)
    {
        case 1: deleteMember(); break;
        case 2: addMember();break;
        case 3: updateMember(); break;
        case 4: ViewAllMembers(); break;
        case 5: FindMember();break;
        default: cout<<"invalid"; break;
    }
    cout<<"\nPress y or Y to continue:";
    cin>>confirm;
    // Clear cli and reprint menu
    system("clear");
    displaymenu();
    } 
    while (confirm == "y" || confirm == "Y");
    return 0;
}
