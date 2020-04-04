#include <string>
#include <vector>

/*
* To:Do
* Konstruktor Type const std::string&  
* destruktor delete
* getName(name) const 
* getNrOfChildren() 
* getChild(i)
* addChild(child)
*/

class Node{
    private:
    std::string nodeName;
    std::vector<Node*> listOfChildren;
    static int nodeId;
    public:
    Node(const std::string* pointerToName);
    ~Node();
    std::string getName() const;
    int getNumberOfChildren();
    Node* getChild(int childIndex);
    void setName(std::string* newNamePointer);
    void addChild(Node* childNode);
};