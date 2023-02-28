#ifndef _TREE_H_
#define _TREE_H_
// Todo: define the general class to represent the trees
//       it needs to be an abstract class
class Tree {
    virtual void createTree() = 0;
    virtual void displayTree() = 0;
};

// Todo: implement the BinaryTree inherits from the general Tree
class BinaryTree : public Tree {
    void createTree() override;
    void displayTree() override;
};
#endif