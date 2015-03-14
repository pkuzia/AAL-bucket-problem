#ifndef BLOCK_H
#define BLOCK_H
#include "string"
#include <iostream>

using namespace std;

class Block
{
    public:
        Block(string col);
        virtual ~Block();
        void print_block();
        string get_color();
    protected:
    private:
        string color;

};

#endif // BLOCK_H
