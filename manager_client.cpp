#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include <cstring>  

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
    std::cout << p;
    if(status_known(s) ? exists(s) : exists(p))
        return true;
    else
        return false;
}


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
    cout<< MAGENTA <<"===================================================== \n" << RESET;
    cout<<"\n";
}

void addMember()
{
    cout<< "\nyou have selected add member\n";
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
    newfile << memberName <<"\n" << memberAnniv << "\n" << "Points: 0";
    newfile.close();
    cout<< MAGENTA <<"===================================================== \n" << RESET;
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
    cout<< MAGENTA <<"===================================================== \n" << RESET;
}

void ViewAllMembers()
{
    cout<< "\nView all member records\n";
    // Loop though dir
    string path = "./members";
    for (const auto & entry : directory_iterator(path)){
        cout << YELLOW << entry.path() << RESET << endl;
    }
    cout<< MAGENTA <<"===================================================== \n" << RESET;
}

void updateMember()
{
    cout<< "\nyou have selected update member\n";

    //Display all members
    ViewAllMembers();

    //Take member to modify
    cout << "\nType the member name to modify: ";
    string memberName;
    cin >> memberName;
    ostringstream fileDestination;
    fileDestination << "./members/" << memberName << ".txt";
    if(file_exists(fileDestination.str())){
        // Delete file
        remove(fileDestination.str());
    }else{
        // Retry
        cout << "\nMember does not exist\n";
        system("clear");
        updateMember();
    }


    //Take inputs
    cout << "\nName: ";
    cin >> memberName;

    cout << "\nAnniversary: ";
    string memberAnniv;
    cin >> memberAnniv;

    // Prepare file
    ofstream newfile;
    // used to add string + vars
    ostringstream nfileDestination;
    nfileDestination << "./members/" << memberName << ".txt";
    // Create file
    newfile.open(nfileDestination.str());
    // Write
    newfile << memberName <<"\n" << memberAnniv << "\n" << "Points: 0";
    newfile.close();
    cout<< MAGENTA <<"===================================================== \n" << RESET;
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
    { cout<<"Enter your choice(1-4):";
    cin>>yourchoice;
    // Switch case for each options
    switch (yourchoice)
    {
        case 0: exit(0); break;
        case 1: deleteMember(); break;
        case 2: addMember();break;
        case 3: updateMember(); break;
        case 4: ViewAllMembers(); break;
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
