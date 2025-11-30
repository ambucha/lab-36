#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"
using namespace std;

// i needa make a function to fill up the tree using the given codes.txt file
void load(const string &fName, IntBinaryTree &tree){
    ifstream file(fName);

    // check if the file was openned to begin with
    if(!file){
        cout << "ERROR: file couldnt be opened " << endl;
        return;
    }

    // create variables for each line, as well as a counter to make suer all the coeds were laoded in
    string code;
    int count = 0;

    while(getline(file, code)){
        if(!code.empty()) {
            tree.insertNode(code);
            count++;
        }
    }

    cout << count << " codes loaded in" << endl;
}

void menu();


int main() {
    // test it
    IntBinaryTree tree;

    // variable for the filename
    string file = "codes.txt";

    // create the bst
    load(file,tree);

    int choice = -1;

    // variables for codes and temp codes for the modifier part
    string code;
    string tempcode;

    // alr now i needa make the menu for milestone 4
    do {
        // first lets just make a function to call that shows all the options
        menu();
        cin >> choice;
        cin.ignore();

        // now lets flesh out the choices
        switch (choice){
            case 1:
                cout << "Enter code to add: ";
                getline(cin, code);
                // now we needa check if the code already exists before adding it
                if(tree.searchNode(code)){
                    cout << "Not adding a duplicate" << endl;
                }
                else{
                    tree.insertNode(code);
                    cout << "Code inserted" << endl;
                }
                break;
            case 2:
                cout << "Enter code to delete: ";
                getline(cin,code);

                // look for if the code is in t here
                if(tree.searchNode(code)){
                    tree.remove(code); // remove the code from th ebst
                    cout << "Code deleted" << endl;
                }
                // if not ther then say that the coed couldnt be found
                else{
                    cout << "Code not found" << endl;
                }
                break;
            case 3:
                cout << "Enter code to search for: ";
                getline(cin,code);

                // display weether or not the code was found
                if(tree.searchNode(code)){
                    cout << "Code found" << endl;
                }
                else{
                    cout << "Code not found" << endl;
                }
                break;
            case 4:
                cout << "Enter code to modify: ";
                getline(cin,code);
                
                // chcek to see if the code even exists in the first place
                if(!tree.searchNode(code)){
                    cout << "The code you want to modify does not exist" << endl;
                }
                else{
                    cout << "Enter the new code: ";
                    // here is where we use temp code to be the new code added
                    getline(cin,tempcode);

                    // easiest way to modify would be to simply remove the old and insert the new tbh
                    tree.remove(code);
                    tree.insertNode(tempcode);
                    cout << "Code modified" << endl;
                }
                // forgot to put break statements in the cases
                break;
            case 5:
            // just displaying all the codes in order 
                cout << endl << "Codes In Order:" << endl;
                tree.displayInOrder();
                break;
            case 0:
            // 0 case to make sure we exit at some point
                cout << "Exiting..." << endl;
                break;
            default:
                // default case should jsut be saying that the choice was wrong and keep us in the loop until vbvalid chocie given
                cout << "Invalid choice, trying again..." << endl;
                break;
                 
        }

    } while(choice != 0);
}


void menu(){
    cout << endl << "-----BST MENU-----" << endl;
    cout << "1. Add code" << endl;
    cout << "2. Delete code" << endl;
    cout << "3. Search for code" << endl;
    cout << "4. Modify codes" << endl;
    // display all codes in order wasnt listed in the neededd menu options but i feel like it should be here lowkey
    cout << "5. Display all codes in order" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter choice: " << endl;
}