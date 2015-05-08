#ifndef NODE_H
#define NODE_H
#include "Container.h"
#include "Node.h"
#include <vector>
#include "Block.h"
#include <algorithm>

class Node
{
    public:
        Node(vector <Container> cont, Node* previous);
        void build();
        void print_node();
        void print_containers( vector < Container > containers);
        vector < Container > get_containers();
        void delete_duplicates();
        void check_history();
        void build_level();
        Node * get_parent();
        Node* get_successor();
        vector < Node* > get_nodes();
        Node* get_left();
        bool check_start_conditions(vector < Container > containers);
    protected:
    private:
        vector <Container> containers;
        vector < Node* > nodes;
        Node *parent;

        bool compare(Node & node);
};

#endif // NODE_H
