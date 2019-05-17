
import std.stdio;

class Tree{
  public{
    int val;
    Tree parent, left, right;
  }
  private void makeNode(Tree parent, int value, int side);

  void printf(){
    if(left !is null) left.printf();
    writeln(val);
    if(right !is null) right.printf();
  }

  void addNode(Tree parent, int value){
    if (value < parent.val){
      (parent.left !is null) ? (addNode(parent.left, value)) : (makeNode(parent, value, 0));
    }else{
      (parent.right !is null) ? (addNode(parent.right, value)) : (makeNode(parent, value, 1));
    }
  }

  private void makeNode(Tree parent, int value, int side){
    Tree newNode = new Tree;
    (side == 0) ? (parent.left = newNode) : (parent.right = newNode);
    newNode.val = value;
  }
}

void main(){
  int[] test = [5,3,7,-1,5,-10,10,6];
  Tree TopNode = new Tree;
  TopNode.val = test[0];
  foreach(value; test[1 .. $-1]){
    TopNode.addNode(TopNode, value);
  }
  TopNode.printf();
}
