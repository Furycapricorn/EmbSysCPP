/** 
 * @file    Node.cpp
 * @author  Maximilian Hartmann 
 * @date    0.0.1
 * @brief   A class that functions as a Tree node
 * 
 * const: You can use const to lock the type and value of a variable
 * into place. When const is used these two things can no loger be changed. 
 * 
 * */

/*
* To:Do:

* #Konstruktor Type const std::string&  
* #destruktor delete
* #getName(name) const
* setName
* #getNrOfChildren()  
* #getChild(i)
* #addChild(child)
*/

#include "Node.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;


//this is needed to keep track of the nodes and is used for the searching
int Node::nodeId =0;

Node::Node(const std::string* constructString){
    Node::nodeId++;
    Node::nodeName= *constructString;
}
Node::~Node(){
    
    //this calls the deconstructor of the children 
    for(;this->getNumberOfChildren()>0;){
        cout << "Trying to delete CHild" << endl;
        cout << this->getNumberOfChildren();
        cout << this->getChild(this->getNumberOfChildren()-1)->getName() << endl;
        delete this->getChild(this->getNumberOfChildren()-1);
    }

}
//
std::string Node::getName() const{
    return this->nodeName;
}
//
int Node::getNumberOfChildren(){
    return this->listOfChildren.size();
}
//
Node* Node::getChild(int childIndex){
    int i = this->getNumberOfChildren();
    if (i< childIndex || childIndex < 0)
    {
        cout << "ChildIndex out of range!" << endl;
        //throw "ChildIndex out of range!";
        return NULL;
    }else{
        cout << "Trying to find CHild" << endl;
        return this->listOfChildren[childIndex];
    }
}
//addChild
void Node::addChild(Node* newChild){
    this->listOfChildren.push_back(newChild);
}