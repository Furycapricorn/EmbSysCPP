/** 
 * @file    Tree.cpp
 * @author  Maximilian Hartmann 
 * @date    0.0.1
 * @brief   Builds a Tree using the Node.cpp class and deletes it
 * */
#include "Node.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    
string nameOfNewNode ="root";
try{
Node * treeRoot = new Node(&nameOfNewNode); 
nameOfNewNode="leftChild";
Node * leftchild = new Node(&nameOfNewNode); 
nameOfNewNode="rightChild";
Node * rightchild = new Node(&nameOfNewNode);

treeRoot->addChild(leftchild);
treeRoot->addChild(rightchild);
nameOfNewNode="wurzel";
treeRoot->setName(&nameOfNewNode);
Node * babyChild =new Node();
rightchild->addChild(babyChild);


delete treeRoot;
/*
The reason the debugging was printed like that is that the dekonstructor 
"sorrounds" the tree and every time it goes back to a "higher level" the last node
he was on gets deletet. 

To better understand what i mean by that, check out the deconstructor.jpg in the source folder. 
*/
}catch(const char* msg)
{
    cout << "ERROR:" << msg <<endl;
}


nameOfNewNode ="root";

Node * tree = new Node(&nameOfNewNode); 
try
{   cout << "This creates a complete ree at once tree" <<endl;
    tree->Node::createCompleteTree(2,4);
    cout << "this will fail" <<endl;
    tree->Node::createCompleteTree(-1,2);
}
catch(const char* msg)
{
    cout << "ERROR:" << msg <<endl;
}


}