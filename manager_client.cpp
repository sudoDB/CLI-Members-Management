#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include <cstring>  
#include <bits/stdc++.h>

namespace fs = std::filesystem;

using namespace fs;
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */



bool file_exists(const path& p, file_status s = file_status{})
{
    cout << p;
    if(status_known(s) ? exists(s) : exists(p))
        return true;
    else
        return false;
}

bool member_exists(string memberName){
    string path = "./members";
    // Loop thought folder
    for (const auto & entry : directory_iterator(path)){
        // If substring memeberName in the current filename string
        if(strstr(entry.path().c_str(),memberName.c_str())){
            return true;
        }
    }
    return false;
}

void write_member(int points){
    //Take inputs
    cout << "\nName: ";
    string memberName;
    cin >> memberName;

    cout << "\nAnniversary: ";
    string memberAnniv;
    cin >> memberAnniv;

    // Prepare file
    ofstream newfile;
    // used to add string + vars
    ostringstream fileDestination;
    fileDestination << "./members/" << memberName << ".txt";
    // Create file
    newfile.open(fileDestination.str());
    // Write
    newfile << memberName <<"\n" << memberAnniv << "\n" << "Points: " << points;
    newfile.close();
}

void memberList(){
    // Loop though dir
    string path = "./members";
    for (const auto & entry : directory_iterator(path)){
        cout << YELLOW << entry.path() << RESET << endl;
    }
}


////////////////////////////////////////////////////////////

void displaymenu()
{ 
    cout<< MAGENTA <<"===================================================== \n";
    cout<<" \t\tMembers manager\n";
    cout<<"===================================================== \n" << RESET;
    cout<<" 0." << RED <<" Quit" << RESET << "\n";
    cout<<" 1." << RED <<" Delete" << RESET << " a member\n";
    cout<<"\n";
    cout<<" 2." << GREEN << " Add" << RESET << " a member\n";
    cout<<" 3." << BLUE << " Update" << RESET << " a member\n";
    cout<<"\n";
    cout<<" 4. Show all members\n";
    cout<<"\n";
    cout<<" 5." << GREEN << " Add" << RESET << " point(s) to a member\n";
    cout<<" 6." << RED << " Remove" << RESET << " point(s) to a member\n";
    cout<< MAGENTA <<"===================================================== \n" << RESET;
    cout<<"\n";
}

void addMember()
{
    cout<< "\nYou have selected add member\n";

    write_member(0);
    
    cout<< MAGENTA <<"===================================================== \n" << RESET;
}
void deleteMember()
{
    cout<< "\nYou have selected delete member \n";
    memberList();
    // Input
    cout << "\nType the member name to delete (type /q to go back): ";
    string memberName;
    cin >> memberName;

    // Check if user to exit
    if (memberName == "/q"){return;}

    // Prepare a ostring for the file name
    ostringstream fileDestination;
    fileDestination << "./members/" << memberName << ".txt";
    // Check if member exist
    bool mpresent = member_exists(memberName);
    if (mpresent){
        remove(fileDestination.str());
    }else{
        cout << "No member named " << memberName << endl;
        system("clear");
        deleteMember();
    }
    
    cout<< MAGENTA <<"===================================================== \n" << RESET;
}

void ViewAllMembers()
{
    cout<< "\nYou have selected view member(s) record(s)\n";
    memberList();
    cout<< MAGENTA <<"===================================================== \n" << RESET;
}

void updateMember()
{
    cout<< "\nYou have selected update member\n";

    memberList();

    //Take member to modify
    cout << "\nType the member name to modify (type /q to go back): ";
    string memberName;
    cin >> memberName;

    // Check if user to exit
    if (memberName == "/q"){return;}

    ostringstream fileDestination;
    fileDestination << "./members/" << memberName << ".txt";
    bool mpresent = member_exists(memberName);
    if (mpresent){
        remove(fileDestination.str());
    }else{
        cout << "No member named " << memberName << endl;
        system("clear");
        updateMember();
    }

    write_member(0);

    cout<< MAGENTA <<"===================================================== \n" << RESET;
}
 
void addPoint(){

    cout<< "\nYou have selected add point\n";
    memberList();

    //Take member to modify
    cout << "\nType the member name to modify (type /q to go back): ";
    string memberName;
    cin >> memberName;

    // Check if user to exit
    if (memberName == "/q"){return;}

    bool mpresent = member_exists(memberName);
    if (mpresent){
        // Add Point
    }else{
        cout << "No member named " << memberName << endl;
    }

}

void removePoint(){

    cout<< "\nYou have selected remove point\n";
    memberList();

    //Take member to modify
    cout << "\nType the member name to modify (type /q to go back): ";
    string memberName;
    cin >> memberName;

    // Check if user to exit
    if (memberName == "/q"){return;}

    bool mpresent = member_exists(memberName);
    if (mpresent){
        // Remove Point
    }else{
        cout << "No member named " << memberName << endl;
    }
}

///////////////////////////////////////////////////////////////// 
int main()
{
    string st[20];
    int itemcount = 0;
    
    //function to display Menu
    displaymenu();
    int yourchoice;
    string confirm;
    do
    { cout<<"Enter your choice(0-6):";
    cin>>yourchoice;
    // Switch case for each options
    switch (yourchoice)
    {
        case 0: exit(0); break;
        case 1: deleteMember(); break;
        case 2: addMember();break;
        case 3: updateMember(); break;
        case 4: ViewAllMembers(); break;
        case 5: addPoint(); break;
        case 6: removePoint(); break;
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
