#include "NaiveSolver.h"
using namespace std;

NaiveSolver::NaiveSolver(vector < Container > content)
{
    containers = content;
}

NaiveSolver::~NaiveSolver()
{
    //dtor
}
void NaiveSolver::check_start_conditions(Container &container)
{
    
}
void NaiveSolver::print_containers()
{
    cout << "-------------------------------------------------------------------------------------------------" << endl;
    for( size_t i = 0; i < containers.size(); i++ )
    {
        containers[i].print_blocks();
        containers[i].print_map();
    }
}
bool NaiveSolver::solved()
{
    for( size_t i = 0; i < containers.size(); i++ )
    {
        if(!containers[i].accept())
        {
            return false;
        }
    }
    return true;
}
bool NaiveSolver::check_container(Container &container)
{
    return container.accept();
}
bool NaiveSolver::solve()
{
    
    int steps = 0;
    int i = containers.size();
    i--; // wyrownanie indexow

    while(!solved())
    {
        ++steps;
        cout << "Krok " << steps << endl;
        i = ( i + 1)% containers.size();
        cout << "Sprawdzam pojemnik o indexie " << i <<endl;
        if(!check_container(containers[i]))
        {
             move_to_right(containers[i],containers[i].get_unnecessary_color());
        }
    }
    print_containers();
    return true;
}
void NaiveSolver::move_to_right(Container &container,string color) // Kontener z którego chcemy przeniesc na prawo
{
    int index_block = container.get_block_of_color(color);
    int index_next_container = (container.get_index() + 1) % (containers.size() + 1);
    if(index_next_container == 0)
    {
        index_next_container++;     // zgranie indexow
    }
    cout<<" FUNKCJA MOVE : Przenosze " << color << " z pojemnika : " << container.get_index() << " do : " << index_next_container << endl;
    if(containers[index_next_container - 1].get_size() == containers[index_next_container - 1].get_number_of_blocks())
    {
        if(containers[index_next_container - 1].get_block_of_color(color) == 999)
        {
            move_to_right(containers[index_next_container - 1],containers[index_next_container - 1].get_first_color());
        }
        else
        {
            move_to_right(containers[index_next_container - 1],color);
        }
    }
    container.delete_block(index_block);
    Block newBlock(color);
    containers[index_next_container - 1].add_block(newBlock);
    //print_containers();
}
