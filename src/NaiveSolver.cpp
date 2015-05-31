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

/* Funkcja sprawdzaja warunek u³o¿ena */
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
       if(it->second > (int)containers.size())
       {
           return false;
       }
       if(it->second == (int)containers.size())
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
/* Funckja zwracaja mape wszystkich kolorów w pojemnikach */
map<string,int> NaiveSolver::get_colors()
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
    return all_colors;
}

bool NaiveSolver::color_solved(string color)
{
    for( size_t i = 0; i < containers.size(); i++ )
    {
        if(!containers[i].color_solved(color))
        {
            return false;
        }
    }
    return true;
}

/* Algorytm rozwiazywanie problem uk³adac klocki po kolorach.*/
bool NaiveSolver::color_method(bool logs)
{
    bool start = check_start_conditions(containers);
    if(start)
    {
        int steps = 0;
        int i = (int)containers.size();
        i--; // wyrownanie indexow

        map<string,int> colors = get_colors();

        while(!solved())
        {
            for (map<string,int>::iterator it = colors.begin(); it != colors.end(); ++it)
            {
                while(!color_solved(it->first))
                {
                    ++steps;
                    i = ( i + 1)% containers.size();
                    if(!containers[i].color_solved(it->first))
                    {
                        move_to_right(containers[i],it->first);
                    }
                }
            }
            if(logs)
            {
                print_containers();
            }
        }
        cout << "Krok " << steps << endl;
        return true;
    }
    else
    {
        cout << "Problem nie do rozwiazania - niepoprawne warunku poczatkowe" << endl;
        return false;
    }
}

/* Algorytm rozwiazywanie problem uk³adac klocki przechac po kazdym pojemniku. */
bool NaiveSolver::optimal_method(bool logs)
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
            i = ( i + 1)% containers.size();

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
            if(logs)
            {
                print_containers();
            }
        }
        cout << "Krok " << steps << endl;
        return true;
    }
    else
    {
        cout << "Problem nie do rozwiazania - niepoprawne warunku poczatkowe" << endl;
        return false;
    }

}
/* Funkcja przenosz¹ca klocek z zadanego pojemnika i o zadanym kolorze w prawo.*/
void NaiveSolver::move_to_right(Container &container,string color) // Kontener z ktorego chcemy przeniesc na prawo
{
    int index_block = container.get_block_of_color(color);
    int index_next_container = (container.get_index() + 1) % (containers.size() + 1);
    if(index_next_container == 0)
    {
        index_next_container++;     // zgranie indexow
    }
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
}

/* Funkcja przenosz¹ca klocek z zadanego pojemnika i o zadanym kolorze w lewo.*/
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
}

/* Funkcja budujaca drzewo rozwiazan, i szukaj¹ca go.*/
void NaiveSolver::build_tree()
{
    Tree tree(containers);
    tree.build();
}
