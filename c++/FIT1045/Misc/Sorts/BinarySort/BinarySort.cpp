#include <iostream>
#include <string>


class Node{
  int val;
  Node *parent, *left, *right;
public:
  Node (int);
  void printp(int count);
};

Node::Node (int value){
  val = value;
}

void Node::printp(int count = 0){
  if (!left) left->printp(count + 1);
  std::cout << std::string(count, '\t') << "--->" << val << std::endl;
  if (!right) right->printp(count + 1);
}









int main(){
  Node TopNode (10);
  TopNode.printp();

  return 0;
}
