#include <iostream>
#include <stdlib.h>
#include "Block.h"
#include "Container.h"
#include <map>
#include "NaiveSolver.h"

using namespace std;

void print_containers(vector < Container > containers)
{
    for( size_t i = 0; i < containers.size(); i++ )
    {
        containers[i].print_blocks();
    }
}

int main()
{
    vector < Container > containers;
    Container nr1(4,1);
    Container nr2(2,2);
    Container nr3(2,3);
    Container nr4(7,4);

    Block blockGreen1("Zielony");
    Block blockGreen2("Zielony");
    Block blockGreen3("Zielony");
    Block blockGreen4("Zielony");

    Block blockRed1("Czerwony");
    Block blockRed2("Czerwony");
    Block blockRed3("Czerwony");
    Block blockRed4("Czerwony");

    Block blockBlack1("Czarny");
    Block blockBlack2("Czarny");
    Block blockBlack3("Czarny");
    Block blockBlack4("Czarny");

    Block blockBlue1("Niebieski");
    Block blockBlue2("Niebieski");

    nr1.add_block(blockBlack1);
    nr1.add_block(blockRed1);
    nr1.add_block(blockRed2);
    nr1.add_block(blockRed3);

    nr2.add_block(blockBlack2);
    nr2.add_block(blockBlue1);

    nr3.add_block(blockBlue2);
    nr3.add_block(blockGreen1);
    nr3.add_block(blockGreen2);
    nr3.add_block(blockGreen3);
    nr3.add_block(blockRed4);

    nr4.add_block(blockGreen4);

    containers.push_back(nr1);
    containers.push_back(nr2);
    containers.push_back(nr3);
    containers.push_back(nr4);

    NaiveSolver solv(containers);

    solv.solve();

    return 0;
}
