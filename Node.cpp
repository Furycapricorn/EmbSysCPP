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
    cout << "------------Trying to delete " << this->nodeName <<  endl;
    //this calls the deconstructor of the children 
    for(;this->getNumberOfChildren()>0;){
        
        int i = this->getNumberOfChildren()-1;
        if(this->getChild(i)!= NULL){
            
            cout <<"deleting:----" << endl;
            cout  << this->getChild(i)->getName() << endl;
            cout <<"deleting: now"<< endl;
            delete this->getChild(i);
            listOfChildren[i] = NULL; 
            /*This is necessary because 
            in the vector there is still a pointer to NULL and 
            that confuses my getNumberOFChildren() method!*/
        }else
        {
            cout <<"Child NULL"<< endl;
        }
        
        
    }
    cout <<":::::: Finish: " << this->nodeName << endl;

}
//
std::string Node::getName() const{
    cout << "getting Node Name" << endl;
    return this->nodeName;
}
//  NEEDS TO COUNT THE REAL CHILDREN AND NOT JUST THE SIZE OF THE VECTOR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int Node::getNumberOfChildren(){
    int c=0;
    cout << "getting number of children" << endl;

    for(int i= 0; i < this->listOfChildren.size(); i++){
        if(listOfChildren[i] != NULL){
            cout << listOfChildren[i]<<endl;
            c=c+1;
        }else{
            cout << "Child to Count = Null" <<endl;
        }
    }
    cout << c << endl;
    return c;
}
//
Node* Node::getChild(int childIndex){
    int i = this->getNumberOfChildren();
    if (i< childIndex || childIndex < 0 || i==0)
    {
        cout << "ChildIndex out of range!" << endl;
        //throw "ChildIndex out of range!";
        return NULL;
    }else{
        cout << "Trying to find Child" << endl;
        cout << childIndex << endl;
        cout << this->listOfChildren[childIndex]->getName() << endl;
        return this->listOfChildren[childIndex];
    }
}
//addChild
void Node::addChild(Node* newChild){
    this->listOfChildren.push_back(newChild);
}