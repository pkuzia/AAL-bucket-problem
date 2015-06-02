//-------------------------------
/*  Politechnika Warszawska WEiTI
    Przemys³aw Kuzia ISI
    Projekt z Analizy Algorytmów
    Pojemniki i klocki
*///----------------------------
#ifndef NAIVESOLVER_H
#define NAIVESOLVER_H

#include <vector>
#include "Container.h"
#include <iostream>
#include "Tree.h"

class NaiveSolver
{
    public:
        NaiveSolver(vector < Container > content);
        virtual ~NaiveSolver();
        bool solve_right_method();
        void print_containers();
        bool solve_random_method();
        bool optimal_method(bool logs);
        void build_tree();
        bool color_method(bool logs);
        map<string,int> get_colors();
        bool color_solved(string color);
    protected:
    private:
        bool check_start_conditions(vector < Container > containers);
        bool check_container(Container &container);
        void move_to_right(Container &container,string color);
        void move_to_left(Container &container,string color);
        void random_move(Container &container);
        bool solved();

        vector < Container > containers;
};

#endif // NAIVESOLVER_H
