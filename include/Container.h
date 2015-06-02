//-------------------------------
/*  Politechnika Warszawska WEiTI
    Przemysław Kuzia ISI
    Projekt z Analizy Algorytmów
    Pojemniki i klocki
*///----------------------------
#ifndef CONTAINER_H
#define CONTAINER_H

#include "Block.h"
#include "vector"
#include <map>
#include <cstdlib>

class Container
{
    public:
        Container(int siz,int idx);
        virtual ~Container();
        void add_block(Block block);
        void print_blocks();
        bool accept();
        int get_block_of_color(string color);
        int get_index();
        void delete_block(int index);
        void print_map();
        int get_size();
        int get_number_of_blocks();
        string get_first_color();
        string get_unnecessary_color();
        vector < Block > get_blocks();
        map<string, int> get_map();
        bool free_slot();
        string get_random_color();
        bool compare(Container &cont);
        bool color_solved(string color);

    protected:
    private:
        map<string, int> info;
        int size;
        int index;
        vector < Block > blocks;

};

#endif // CONTAINER_H
