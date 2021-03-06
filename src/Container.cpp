//-------------------------------
/*  Politechnika Warszawska WEiTI
    Przemysław Kuzia ISI
    Projekt z Analizy Algorytmów
    Pojemniki i klocki
*///----------------------------
#include "Container.h"

Container::Container(int siz, int idx)
{
    size = siz;
    index = idx;
}

Container::~Container()
{
    //dtor
}
void Container::add_block(Block block)
{
    map<string,int>::iterator pos = info.find(block.get_color());
    if ( pos == info.end() )
    {
        info.insert(std::pair<string, int>(block.get_color(), 1));
    }
    else
    {
        pos->second = ++pos->second;
    }
    blocks.push_back(block);
}
bool Container::accept()
{

    for (map<string,int>::iterator it = info.begin(); it != info.end(); ++it)
    {
        if(it->second > 1)
        {
            return false;
        }
    }
    return true;
}
 vector < Block > Container::get_blocks()
{
    return blocks;
}
map<string, int> Container::get_map()
{
    return info;
}
void Container::print_blocks()
{
    cout << "------------------------------------------------------------" << endl;
    cout << "Pojemnik nr: " << index << " Pojemnosc : "<< size << endl;
    for( size_t i = 0; i < blocks.size(); i++ )
    {
        blocks[i].print_block();
    }
    cout << endl;
}
int Container::get_block_of_color(string color)
{
    for( size_t i = 0; i < blocks.size(); i++ )
    {
        if(blocks[i].get_color() == color)
        {
            return (int)i;
        }
    }
    return 999; // ERROR
}
int Container::get_index()
{
    return index;
}
int Container::get_size()
{
    return size;
}
int Container::get_number_of_blocks()
{
    return (int)blocks.size();
}
void Container::delete_block(int index)
{
    map<string,int>::iterator pos = info.find(blocks[index].get_color());
    if ( pos != info.end() )
    {
        pos->second --;
    }
    blocks.erase(blocks.begin() + index);

}
string Container::get_unnecessary_color()
{
    for (map<string,int>::iterator it = info.begin(); it != info.end(); ++it)
    {
        if(it->second > 1)
        {
            return it->first;
        }
    }
    string s;
    return s;
}
void Container::print_map()
{
    for (map<string,int>::iterator it = info.begin(); it != info.end(); ++it)
    {
        cout << it->first << " => " << it->second << endl;
    }
    cout << endl;
}
string Container::get_first_color()
{
    if(blocks.size() > 0)
    {
        return blocks[0].get_color();
    }
    return "error";
}

bool Container::color_solved(string color)
{
    map<string,int>::iterator pos = info.find(color);
    if ( pos == info.end() )
    {
        return true;
    }
    else
    {
        if(pos -> second <= 1)
        {
            return true;
        }
        if(pos -> second > 1)
        {
            return false;
        }
    }
    return false;
}
/* Funkcja porównuj¹ca dwa kontenery.*/
bool Container::compare(Container &cont)
{
    if(get_number_of_blocks() != cont.get_number_of_blocks())
    {
        return false;
    }

    for (map<string,int>::iterator it = info.begin(); it != info.end(); ++it)
    {
        if(it->second != 0)
        {
            string color = it -> first;
            map<string,int> compare_map = cont.get_map();

            bool is_color_exist = false;
            for ( map<string,int>::iterator iter = compare_map.begin(); iter != compare_map.end(); iter++)
            {
                if(info.size() != compare_map.size())
                {
                    return false;
                }
                if(color == iter -> first )
                {
                    is_color_exist = true;
                    if(it->second != iter->second)
                    {
                        return false;
                    }
                }
            }
            if(!is_color_exist)
            {
                return false;
            }
        }
    }
    return true;

}

bool Container::free_slot()
{
    int number_blocks = 0;

    for (map<string,int>::iterator it = info.begin(); it != info.end(); ++it)
    {
        number_blocks += it->second;
    }

    if(number_blocks == size)
    {
        return false;
    }
    else
    {
        return true;
    }
}

string Container::get_random_color()
{
    int index_block = rand() % blocks.size();
    return blocks[index_block].get_color();

}
