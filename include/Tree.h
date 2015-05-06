#ifndef TREE_H
#define TREE_H
#include <Node.h>
#include <vector>

class Tree
{
    public:
        Tree(vector <Container> cont);
        void build();
    protected:
    private:
        Node *root;

};

#endif // TREE_H
