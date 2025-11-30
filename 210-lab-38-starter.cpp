#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

int main() {
    // test it
    IntBinaryTree tree;
    tree.insertNode("manga");
    tree.insertNode("maracuja");
    tree.displayInOrder();
    return 0;
}
