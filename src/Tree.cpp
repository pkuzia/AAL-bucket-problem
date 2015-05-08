#include "Tree.h"

Tree::Tree(vector <Container> cont)
{
    root = new Node(cont, NULL);
}
void Tree::solve()
{
    while(1)
    {

    }
}
void Tree::build()
{
    root->build();
    root->delete_duplicates();
    vector <Node*> nodes = root->get_nodes();
    Node* node = root;
    node = node->get_left();
    int i = 0;
    while(node != NULL)
    {
        node = node->get_successor();
        cout << i << endl;
        ++i;
    }
}
