#include "Creator.h"
#include <cstdlib>
#include <fstream>

Creator::Creator()
{
    //ctor
}

Creator::~Creator()
{
    //dtor
}
/* Funckja czytajaca plik tekstowy z kolorami.*/
void Creator::read_file()
{
  string line;
  ifstream myfile ("colors.txt");//("/Users/przemyslawkuzia/Praca/XCode Projects/Projekt AAL/Projekt AAL/colors.txt");

  if (myfile.is_open())
  {
    int i = 0;
    while ( getline (myfile,line) )
    {
      colors.insert(std::pair<int, string>(i, line));
      ++i;
    }
    myfile.close();
  }

  else cout << "Unable to open file";
}

/* Funckja tworz¹ca problem do rozwi¹zania o zadanych parametrach tj. liczba pojemników, maksymalna pojemnosc pojemnika, srednie wypelnienie oraz liczbe kolorow.*/
void Creator::average_fill(int number_containers, int size_cont, double average_fill, int color_quantity )
{
    for(int i = 1; i<= number_containers ; i++)
    {
        int size_container = rand()%size_cont + 1;
        Container container(size_container,i);
        containers.push_back(container);

        while(((double)containers[i-1].get_number_of_blocks() / (double)containers[i-1].get_size()) < average_fill )
        {
            int color_id = rand()%color_quantity;
            Block block(colors.find(color_id)->second);
            containers[i-1].add_block(block);
        }
    }
}

map<int, string> Creator::get_colors()
{
    return colors;
}

vector < Container > Creator::get_containers()
{
    return containers;
}

void Creator::print_colors()
{
    for (map<int,string>::iterator it = colors.begin(); it != colors.end(); ++it)
    {
        cout << it->first << " => " << it->second << endl;
    }
    cout << endl;
}
