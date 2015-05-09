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

void Creator::read_file()
{
  string line;
  ifstream myfile ("colors.txt");

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


void Creator::random ()
{
    int number_containers = 100;//rand()%100;
    cout << "Liczba kontenerow :" << number_containers << endl;

    int number_blocks = 800;//rand()%100+50;
    //cout << "Liczba blokow :" << numer_blocks << endl;

    for(int i = 1; i<= number_containers ; i++)
    {
        int size_container = number_blocks/number_containers + rand()%3 + 1; //rand()%20 + 1;
        Container container(size_container,i);
        containers.push_back(container);
        //cout << "Pojemnosc konternera " << i << " : " <<  size_container << endl;
    }

    for(int i = 1; i<= number_blocks ; i++)
    {
        int color_id = rand()%10;

        Block block(colors.find(color_id)->second);
        //cout << "Blok " << i << " ma kolor " << block.get_color() << endl;
        int nr_container = rand()% number_containers;
        //cout << "Wylosowany kontener to :" << nr_container << endl;

        while(!containers[nr_container].free_slot())
        {
            nr_container = rand()% number_containers;
        }
        containers[nr_container].add_block(block);
    }
}

void Creator::average_fill(double value)
{
    int number_containers = 10;//rand()%100;
    //cout << "Liczba kontenerow :" << number_containers << endl;

    for(int i = 1; i<= number_containers ; i++)
    {
        int size_container = rand()%8 + 1;
        Container container(size_container,i);
        containers.push_back(container);

        while(((double)containers[i-1].get_number_of_blocks() / (double)containers[i-1].get_size()) < value )
        {
            //cout << (double)containers[i-1].get_number_of_blocks()/(double)containers[i-1].get_size() << " :: " << value << endl ;
            int color_id = rand()%5;
            //cout << colors.find(color_id)->second << endl;
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
