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
    Node* node = root;
    //cout << "-----------------------" << endl;
    //node->build_level();
    //node = node->get_left();
    int i = 0;
    bool solved = false;
    while(1)
    {
        //node = node -> get_successor();
        node = root->get_left();
        int k = 0;
        while(node != NULL)
        {
            if(node->solved())
            {
                cout << "Poprawne rozwiazanie" << endl;
                node -> print_node();
                solved = true;
                break;
            }
            cout <<"SPRAWDZAM " <<k << endl; k++;
            node = node->get_successor();
        }
        if(solved)
        {
            break;
        }
        node = root->get_left();
        k = 0;
        while(node != NULL)
        {
            node->build();
            node->delete_duplicates();
            node->check_history();
            cout <<"P2 " << k << endl; k++;
            node = node->get_successor();
        }
        cout << i << endl;
        ++i;
    }
    //node->print_node();
}
