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
bool NaiveSolver::check_start_conditions(vector < Container > containers)
{
    map<string,int> all_colors;
    for( size_t i = 0; i < containers.size(); i++ )
    {
        vector < Block > blocks = containers[i].get_blocks();
        map<string, int> info = containers[i].get_map();
        for( size_t i = 0; i < blocks.size(); i++ )
        {
            Block block = blocks[i];
            map<string,int>::iterator pos = all_colors.find(block.get_color());
            if ( pos == all_colors.end() )
            {
                all_colors.insert(std::pair<string, int>(block.get_color(), 1));
            }
            else
            {
                pos->second = ++pos->second;
            }
        }
    }
    int n_k_colors  = 0;
    for (map<string,int>::iterator it = all_colors.begin(); it != all_colors.end(); ++it)
    {
       if(it->second > containers.size())
       {
           return false;
       }
       if(it->second == containers.size())
       {
            n_k_colors++;
       }
    }
    for( size_t i = 0; i < containers.size(); i++ )
    {
        if(n_k_colors > containers[i].get_size())
        {
            return false;
        }
    }
    return true;
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
bool NaiveSolver::solve_right_method()
{
    bool start = check_start_conditions(containers);
    if(start)
    {
        int steps = 0;
        int i = (int)containers.size();
        i--; // wyrownanie indexow

        while(!solved())
        {
            ++steps;
            //cout << "Krok " << steps << endl;
            i = ( i + 1)% containers.size();
            //cout << "Sprawdzam pojemnik o indexie " << i <<endl;
            if(!check_container(containers[i]))
            {
                 move_to_right(containers[i],containers[i].get_unnecessary_color());
            }
            //print_containers();
        }
      //print_containers();
      cout << "Krok " << steps << endl;
      return true;
    }
    else
    {
        cout << "Problem nie do rozwiazania - niepoprawne warunku poczatkowe" << endl;
        return false;
    }

}


bool NaiveSolver::optimal_method()
{
    bool start = check_start_conditions(containers);
    if(start)
    {
        int steps = 0;
        int i = (int)containers.size();
        i--; // wyrownanie indexow
        
        while(!solved())
        {
            ++steps;
            //cout << "Krok " << steps << endl;
            i = ( i + 1)% containers.size();
            //cout << "Sprawdzam pojemnik o indexie " << i <<endl;
        
            if(!check_container(containers[i]))
            {
                int index = i;
                
                if(i == 0 )
                {
                    index = (int)containers.size() - 1;
                }
                else
                {
                    --index;
                }
                
                if(containers[index].get_block_of_color(containers[i].get_unnecessary_color()) == 999 && containers[index].free_slot())
                {
                    move_to_left(containers[i], containers[i].get_unnecessary_color());
                }
                else
                {
                    move_to_right(containers[i],containers[i].get_unnecessary_color());
                }
            }
            //print_containers();
        }
        cout << "Krok " << steps << endl;
        //print_containers();
        return true;
    }
    else
    {
        cout << "Problem nie do rozwiazania - niepoprawne warunku poczatkowe" << endl;
        return false;
    }
    
}
void NaiveSolver::move_to_right(Container &container,string color) // Kontener z ktorego chcemy przeniesc na prawo
{
    int index_block = container.get_block_of_color(color);
    int index_next_container = (container.get_index() + 1) % (containers.size() + 1);
    if(index_next_container == 0)
    {
        index_next_container++;     // zgranie indexow
    }
        //cout<<" FUNKCJA MOVE : Przenosze " << color << " z pojemnika : " << container.get_index() << " do : " << index_next_container << endl;
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


void NaiveSolver::move_to_left(Container &container,string color) // Kontener z ktorego chcemy przeniesc na lewo
{
    int index_block = container.get_block_of_color(color);
    int index_previous_container = (container.get_index() - 1); // zamiana indexow, gdy 0 dajemy ostatni
    if(index_previous_container == 0)
    {
        index_previous_container = (int)containers.size();
    }
    if(index_previous_container == 0)
    {
        index_previous_container++;     // zgranie indexow
    }
    //cout<<" FUNKCJA MOVE : Przenosze " << color << " z pojemnika : " << container.get_index() << " do : " << index_previous_container << endl;
    if(containers[index_previous_container - 1].get_size() == containers[index_previous_container - 1].get_number_of_blocks())
    {
        if(containers[index_previous_container - 1].get_block_of_color(color) == 999)
        {
            move_to_right(containers[index_previous_container - 1],containers[index_previous_container - 1].get_first_color());
        }
        else
        {
            move_to_right(containers[index_previous_container - 1],color);
        }
    }
    container.delete_block(index_block);
    Block newBlock(color);
    containers[index_previous_container - 1].add_block(newBlock);
    //print_containers();
}


void NaiveSolver::random_move(Container &container) // losowy klocek z podaneo kontenera wyrzucamy na lewo lub na prawo
{
    string random_color = container.get_random_color();
    //cout << " Wylosowany kolor to : " << random_color << endl;
    int left_or_right = rand() % 2;
    
    if(left_or_right == 1 )
    {
        move_to_right(container, random_color);
    }
    else
    {
        move_to_left(container, random_color);
    }
}

bool NaiveSolver::solve_random_method()
{
    bool start = check_start_conditions(containers);
    if(start)
    {
        int steps = 0;
        int i = (int)containers.size();
        i--; // wyrownanie indexow
        
        while(!solved())
        {
            ++steps;
            cout << "Krok " << steps << endl;
            i = ( i + 1)% containers.size();
            cout << "Sprawdzam pojemnik o indexie " << i <<endl;
            if(!check_container(containers[i]))
            {
                random_move(containers[i]);
            }
        }
        //print_containers();
        return true;
    }
    else
    {
        cout << "Problem nie do rozwiazania - niepoprawne warunku poczatkowe" << endl;
        return false;
    }
    
}
