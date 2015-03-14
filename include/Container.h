#ifndef CONTAINER_H
#define CONTAINER_H

#include "Block.h"
#include "vector"
#include <map>
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

    protected:
    private:
        map<string, int> info;
        int size;
        int index;
        vector < Block > blocks;

};

#endif // CONTAINER_H