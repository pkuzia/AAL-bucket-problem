#include "Tree.h"

Tree::Tree(vector <Container> cont)
{
    root = new Node(cont, NULL);
}
void Tree::build()
{
    root->build();
    root->print_node();
    root->delete_duplicates();
    cout<<"lel"<<endl;
    root->delete_duplicates();
    root->print_node();
}
