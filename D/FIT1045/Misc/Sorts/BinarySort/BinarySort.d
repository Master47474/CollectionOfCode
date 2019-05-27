
import std.stdio;
import std.array;


void binsort(int[] lstSort);


void main(){
  int[] test = [5,2,1,-5,20,3,4];
  binsort(test[]);
}

void binsort(int[] lstSort){
  Tree TopNode = new Tree;
  TopNode.val = lstSort[0];
  foreach(value; lstSort[1 .. $]){
    TopNode.addNode(TopNode, value);
  }
  TopNode.printf(0);
}

class Tree{
  public{
    int val;
    Tree parent, left, right;
  }
  private void makeNode(Tree parent, int value, int side);

  void printf(int count){
    if(left !is null) left.printf(count + 1);
    writeln(replicate("    ", count ),"--->", val);
    if(right !is null) right.printf(count + 1);
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
