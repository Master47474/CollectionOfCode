class Tree{
  int val;
  Tree parent, left, right;
  private void makeNode(Tree parent, int value, int side);

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
