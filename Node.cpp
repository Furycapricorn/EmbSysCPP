/** 
 * @file    Node.cpp
 * @author  Maximilian Hartmann 
 * @date    0.2.1
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
/**
 * \brief standard constructor
 * 
 *      This is the standard constructor for a node.
 *      It works without any parameters and automaticly generates 
 *      a name from the ID
*/
Node::Node(){
    Node::nodeId++;
    std::stringstream generatedName;
    generatedName << "node_" << nodeId;
    Node::nodeName= generatedName.str();
    #ifdef DEBUG
    cout << "New Node Created: " << this->nodeName << endl;
    #endif
}
/**
 * \brief Constructor with Name
 *      
 *      Constructor that construcs a node with a custom name.
 * 
 * \param constructString Custom name of the Node
 * 
*/
Node::Node(const std::string* constructString){
    Node::nodeId++;
    Node::nodeName= *constructString;
    #ifdef DEBUG
    cout << "New Node Created: " << this->nodeName << endl;
    #endif
}
/**
 * \brief deconstructor for the nodes
 * 
 *      Deletes the node and all children.
 * 
*/
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
/**
 * \brief method that returns the nodeName
 * 
 * \return returns the name of the node
 */
std::string Node::getName() const{
    return this->nodeName;
}
/**
 * \brief method that sets the name
 * 
 * \param newNamePointer pointer to the new name
 */

void Node::setName(std::string* newNamePointer){
    this-> nodeName = *newNamePointer;
    #ifdef DEBUG_MORE
    cout << this->nodeName <<endl;
    #endif
}
/**
 * \brief Counts the Children of a node
 * 
 *      This methode counts the number of child nodes.
 *      Its designed to ignore deleted childs and 
 *      only only pickup active ones. (so its more than "vector.size()")
 * 
 * \return number of children
 */
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
/**
 * \brief returns the x number child node
 * 
 *      Finds the child with the given index. 
 *      Throws an exception if the index is invalid.
 * 
 * \param childIndex index of the child to return 
 * 
 * \return returns a pointer to ther searched child
 */
Node* Node::getChild(int childIndex){
    int i = this->getNumberOfChildren();
    if (i< childIndex || childIndex < 0 || i==0)
    {
        #ifdef DEBUG_MORE
        cout << "ChildIndex out of range!" << endl;
        #endif
        throw "Index of Child out of range!";
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
/**
 * \brief Adds a child to the node
 * 
 * \param newChild a pointer to the child to add
 */
void Node::addChild(Node* newChild){
    this->listOfChildren.push_back(newChild);
}
/**
 * \brief Generated a treestructure
 * 
 *      Generates a tree with a given depth and branch count.
 * 
 * \param nrChildNodes Number of children for every node
 * \param treeDepth terminates the number of levels for the tree
 * 
 * \return the created root
 */
Node* Node::createCompleteTree(int nrChildNodes,int treeDepth){
    
    if(nrChildNodes <=0 || treeDepth <=0){
        throw "Index out of Bounce: Cant have 0 or less childnodes/treedepth!";
    }else if (treeDepth >1){
        #ifdef DEBUG_MORE
        cout <<"Entering: " << this->getName() << endl;
        #endif
        for(int j = 0; j<nrChildNodes; j++){
            Node * newNode =new Node();
            #ifdef DEBUG_MORE
            cout <<"Creating Child For: " << this->getName() << endl;
            #endif
            this->addChild(Node::createCompleteTree(nrChildNodes ,treeDepth-1));        
        }
        #ifdef DEBUG_MORE
        cout <<"Leaving: " << this->getName() << endl;
        #endif
    }
    return this;
}