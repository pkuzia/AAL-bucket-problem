#ifndef NODE_H
#define NODE_H
#include <Container.h>
#include <Node.h>
#include <vector>
#include "Block.h"

class Node
{
    public:
        Node(vector <Container> cont, Node* previous);
        void build();
    protected:
    private:
        vector <Container> containers;
        vector < Node* > nodes;
        Node *prev;
};

#endif // NODE_H
