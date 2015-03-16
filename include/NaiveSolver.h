#ifndef NAIVESOLVER_H
#define NAIVESOLVER_H

#include <vector>
#include "Container.h"
#include <iostream>

class NaiveSolver
{
    public:
        NaiveSolver(vector < Container > content);
        virtual ~NaiveSolver();
        bool solve();
        void print_containers();
    protected:
    private:
        void check_start_conditions(Container &container);
        bool check_container(Container &container);
        void move_to_right(Container &container,string color);
        bool solved();
        vector < Container > containers;
};

#endif // NAIVESOLVER_H
