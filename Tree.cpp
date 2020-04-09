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

Node * treeRoot = new Node(&nameOfNewNode); 
nameOfNewNode="leftChild";
Node * leftchild = new Node(&nameOfNewNode); 
nameOfNewNode="rightChild";
Node * rightchild = new Node(&nameOfNewNode);

treeRoot->addChild(leftchild);
treeRoot->addChild(rightchild);
nameOfNewNode="wurzel";
treeRoot->setName(&nameOfNewNode);

delete treeRoot;

}