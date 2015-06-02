//-------------------------------
/*  Politechnika Warszawska WEiTI
    Przemysław Kuzia ISI
    Projekt z Analizy Algorytmów
    Pojemniki i klocki
*///----------------------------
#include "Block.h"
using namespace std;

Block::Block(string col)
{
    color = col;
}

Block::~Block()
{
    //dtor
}
void Block::print_block()
{
    cout << color << endl;
}
string Block::get_color()
{
    return color;
}
