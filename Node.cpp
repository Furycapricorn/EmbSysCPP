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


//this is needed to keep track of the nodes and is used for the searching
int Node::nodeId =0;

Node::Node(const std::string* constructString){
    Node::nodeId++;
    Node::nodeName= *constructString;
}
Node::~Node(){
    
    //this calls the deconstructor of the children 
    for(;getNumberOfChildren()>0;){
        delete getChild(getNumberOfChildren()-1);
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
    int i = getNumberOfChildren();
    if (i> childIndex || i<0)
    {
        throw "ChildIndex out of range!";
        return NULL;
    }else{
        return this->listOfChildren[childIndex];
    }
}
//addChild
void Node::addChild(Node* newChild){
    this->listOfChildren.push_back(newChild);
}