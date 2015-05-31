#include "Tree.h"

Tree::Tree(vector <Container> cont)
{
    root = new Node(cont, NULL);
}
/* Funkcja buduj¹ca drzewo oraz szukaj¹ca rozwi¹zania.*/
void Tree::build()
{
    int level = 0;
    root->build();
    root->delete_duplicates();
    Node* node = root;
    int i = 0;
    bool solved = false;
    while(true)
    {
        level++;
        cout << "Poziom : " << level << endl;
        node = root->get_left();
        int k = 0;
        while(node != NULL)
        {
            if(node->solved())
            {
                cout << "Poprawne rozwiazanie, KROK: " << i << " Pojemnik nr: " << k << " Poziom drzewa: "<< level << endl;
                node -> print_node();
                solved = true;
                break;
            }
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
            node = node->get_successor();
        }
        ++i;
    }
}
