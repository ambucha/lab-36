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


int main() {
    // test it
    IntBinaryTree tree;

    // variable for the filename
    string file = "codes.txt";

    // create the bst
    load(file,tree);

    //display
    tree.displayInOrder();
    return 0;
}
