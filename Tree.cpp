/** 
 * @file    Tree.cpp
 * @author  Maximilian Hartmann 
 * @date    0.0.1
 * @brief   Builds a Tree using the Node.cpp class and deletes it
 * */
#include "Node.h"
#include <iostream>
using namespace std;

int main(){
string nameOfNewNode ="root";
Node * root = new Node::Node(&nameOfNewNode); 
nameOfNewNode="leftChild";
Node * leftchild = new Node::Node(&nameOfNewNode); 
nameOfNewNode="rightChild";
Node * rightchild = new Node::Node(&nameOfNewNode);

root->addChild(leftchild);
root->addChild(rightchild);
cout << root->getChild(0)->getName() << endl;
}