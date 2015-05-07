#ifndef NODE_H
#define NODE_H
#include "Container.h"
#include "Node.h"
#include <vector>
#include "Block.h"

class Node
{
    public:
        Node(vector <Container> cont, Node* previous);
        void build();
        void print_node();
        void print_containers( vector < Container > containers);
        vector < Container > get_containers();
    protected:
    private:
        vector <Container> containers;
        vector < Node* > nodes;
        Node *prev;
        void delete_duplicates();
        bool compare(Node & node);
};

#endif // NODE_H
