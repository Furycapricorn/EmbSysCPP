

#include <string>
#include <vector>

#define DEBUG
//Debug more is for percise debugging
//#define DEBUG_MORE

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