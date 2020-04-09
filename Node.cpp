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

#include "Node.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;


//this is needed to keep track of the nodes and is used for the searching
int Node::nodeId =0;
Node::Node(){
    Node::nodeId++;
    std::stringstream generatedName;
    generatedName << "node_" << nodeId;
    Node::nodeName= generatedName.str();
    #ifdef DEBUG
    cout << "New Node Created: " << this->nodeName << endl;
    #endif
}
Node::Node(const std::string* constructString){
    Node::nodeId++;
    Node::nodeName= *constructString;
    #ifdef DEBUG
    cout << "New Node Created: " << this->nodeName << endl;
    #endif
}
Node::~Node(){
    #ifdef DEBUG
    cout << "Enter ~Node() of " << this->nodeName <<  endl;
    #endif
    //this calls the deconstructor of the children 
    for(;this->getNumberOfChildren()>0;){
        
        int i = this->getNumberOfChildren()-1;
        if(this->getChild(i)!= NULL){
            #ifdef DEBUG_MORE
            cout <<"Deleting Child: "<< this->getChild(i)->getName()<< endl;
            #endif
            delete this->getChild(i);
            listOfChildren[i] = NULL; 
            /*This is necessary because 
            in the vector there is still a pointer to NULL and 
            that confuses my getNumberOFChildren() method!*/
        }else
        {
            #ifdef DEBUG_MORE
            cout <<"Child was NULL"<< endl;
            #endif
        }
        
        
    }
    #ifdef DEBUG
    cout <<"Leaving ~Node() of:  " << this->nodeName << endl;
    #endif

}
//
std::string Node::getName() const{
    return this->nodeName;
}
//
void Node::setName(std::string* newNamePointer){
    this-> nodeName = *newNamePointer;
    #ifdef DEBUG_MORE
    cout << this->nodeName <<endl;
    #endif
}
//  NEEDS TO COUNT THE REAL CHILDREN AND NOT JUST THE SIZE OF THE VECTOR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int Node::getNumberOfChildren(){
    int c=0;
    #ifdef DEBUG_MORE
    cout << "Counting number of children" << endl;
    #endif

    for(int i= 0; i < this->listOfChildren.size(); i++){
        if(listOfChildren[i] != NULL){
            #ifdef DEBUG_MORE
            cout <<"Counted Child" << listOfChildren[i]<<endl;
            #endif
            c=c+1;
        }else{
            #ifdef DEBUG_MORE
            cout << "Child to Count = NULL" <<endl;
            #endif
        }
    }
    #ifdef DEBUG_MORE
    cout << c << endl;
    #endif
    return c;
}
//
Node* Node::getChild(int childIndex){
    int i = this->getNumberOfChildren();
    if (i< childIndex || childIndex < 0 || i==0)
    {
        #ifdef DEBUG_MORE
        cout << "ChildIndex out of range!" << endl;
        //throw "ChildIndex out of range!";
        #endif
        return NULL;
    }else{
        #ifdef DEBUG_MORE
        cout << "Trying to find Child" << endl;
        cout << childIndex << endl;
        cout << this->listOfChildren[childIndex]->getName() << endl;
        #endif
        return this->listOfChildren[childIndex];
    }
}
//addChild
void Node::addChild(Node* newChild){
    this->listOfChildren.push_back(newChild);
}