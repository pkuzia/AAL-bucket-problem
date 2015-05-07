#ifndef CREATOR_H
#define CREATOR_H

#include "Container.h"
#include <cstdlib>
#include <fstream>
#include <map>
#include "vector"
#include "string"
#include "Block.h"

class Creator
{
    public:
        void read_file();
        Creator();
        virtual ~Creator();
        void random ();
        map<int, string> get_colors();
        void print_colors();
        vector < Container > get_containers();
        void average_fill(double value);
    protected:
    private:
        map<int, string> colors;
        vector < Container > containers;
};

#endif // CREATOR_H
