#include <iostream>
#include <string>


class Node{
  int val;
  Node *parent, *left, *right;
public:
  Node (int);
  void printp(int count);
  void addNode(Node parent, int val);
  void makeNode(Node parent, int value, int side);
};

Node::Node (int value){
  val = value;
}

void Node::printp(int count = 0){
  if (!left) left->printp(count + 1);
  std::cout << std::string(count, '\t') << "--->" << val << std::endl;
  if (!right) right->printp(count + 1);
}

void Node::addNode(Node parent, int value){
  if(value < parent.val){
    (!parent.left) ? (addNode(parent.left, value)) : (makeNode(parent, value, 0));
  }else{
    (!parent.right) ? (addNode(parent.right, value)) : (makeNode(parent, value, 1));
  }
}

void Node::makeNode(Node parent, int value, int side){
  Node newNode (value);
  (side == 0) ? (parent.left = &newNode) : (parent.right = &newNode);
}






int main(){
  Node TopNode (10);
  TopNode.printp();

  return 0;
}
