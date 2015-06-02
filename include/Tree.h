//-------------------------------
/*  Politechnika Warszawska WEiTI
    Przemys³aw Kuzia ISI
    Projekt z Analizy Algorytmów
    Pojemniki i klocki
*///----------------------------
#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include <vector>

class Tree
{
    public:
        Tree(vector <Container> cont);
        void build();
        void solve();
    protected:
    private:
        Node *root;

};

#endif // TREE_H
