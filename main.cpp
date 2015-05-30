#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "Block.h"
#include "Container.h"
#include <map>
#include "NaiveSolver.h"
#include <cstdlib>
#include <fstream>
#include "Creator.h"



using namespace std;

vector < Container > enter_data()
{
    vector < Container > containers;

    int containers_quantity;
    cout << "Podaj liczbe pojemnikow." << endl;
    cin >> containers_quantity;

    for( int i = 1; i <= containers_quantity; i++)
    {
        int size;
        cout << "Podaj pojemnosc dla pojemnika " << i << endl;
        cin >> size;
        Container container(size,i);
        containers.push_back(container);
    }

    int blocks_quantity;
    cout << "Podaj liczbe klockow." << endl;
    cin >> blocks_quantity;

    for( int i = 1; i <= blocks_quantity; i++)
    {
        string color;
        int index;
        cout << "Podaj kolor klocka nr " << i << endl;
        cin >> color;

        Block block(color);

        bool flag = true;
        while(flag)
        {
            cout << "Podaj index pojemnika do ktorego klocek ma byc wrzucony." << endl;
            cin >> index;

            if(index > (int)containers.size())
            {
                cout << "Bledny index" << endl;
            }
            else if(containers[index-1].get_number_of_blocks() == containers[index-1].get_size())
            {
                cout << "Blad, pojemnik jest pelny." << endl;
            }
            else
            {
                containers[index-1].add_block(block);
                flag = false;
            }
        }
    }
    return containers;
}


int main()
{

//    vector < Container > containers;
//    cout << "Menu " << endl << "Wybierz rodzaj wykonania." << endl;
//    cout << "1. Wprowadzanie danych" << endl;
//    cout << "2. Ustalenie parametrow wejsciowych i obserwacja." << endl;
//    cout << "3. Ustalenie parametrow wejsciowych i pomiar czasu." << endl;
//    int choise;
//
//    cin >> choise ;
//
//    if(choise == 1)
//    {
//        containers = enter_data();
//        NaiveSolver solv(containers);
//        solv.print_containers();
//        int ch;
//        cout << "Rodzaje algorytmow:" << endl;
//        cout << "1. Algorytm rozwiazywania drzewem." << endl;
//        cout << "2. Alborytm rozwiazywania pojemnikami." << endl;
//        cout << "3. Algorytm rozwiazywania kolorami. " << endl;
//        cin >> ch;
//
//        if(ch == 1)
//        {
//            solv.build_tree();
//        }
//        else if(ch == 2)
//        {
//            solv.optimal_method(true);
//        }
//        else if(ch == 3)
//        {
//            solv.color_method(true);
//        }
//        else
//        {
//            cout << "Error." << endl;
//        }
//    }
//    if(choise == 2)
//    {
//        int color_quantity;
//        double average_fill;
//        int number_of_containers;
//        int size_container;
//
//        cout << "Podaj ilosc kolorow." << endl;
//        cin >> color_quantity;
//        cout << "Podaj srednie wypelnienie." << endl;
//        cin >> average_fill;
//        cout << "Podaj liczbe pojemnikow." << endl;
//        cin >> number_of_containers;
//        cout << "Podaj maksymalna pojemnosc pojemnika." << endl;
//        cin >> size_container;
//
//        Creator creator;
//        creator.read_file();
//        creator.average_fill(number_of_containers,size_container,average_fill,color_quantity);
//        containers = creator.get_containers();
//
//        NaiveSolver solv(containers);
//        int ch;
//        cout << "Rodzaje algorytmow:" << endl;
//        cout << "1. Algorytm rozwiazywania drzewem." << endl;
//        cout << "2. Alborytm rozwiazywania pojemnikami." << endl;
//        cout << "3. Algorytm rozwiazywania kolorami. " << endl;
//        cin >> ch;
//
//        if(ch == 1)
//        {
//            solv.build_tree();
//        }
//        else if(ch == 2)
//        {
//            solv.optimal_method(true);
//        }
//        else if(ch == 3)
//        {
//            solv.color_method(true);
//        }
//        else
//        {
//            cout << "Error." << endl;
//        }
//    }
//    if(choise == 3)
//    {
//        int color_quantity;
//        double average_fill;
//        int number_of_containers;
//        int size_container;
//
//        cout << "Podaj ilosc kolorow." << endl;
//        cin >> color_quantity;
//        cout << "Podaj srednie wypelnienie." << endl;
//        cin >> average_fill;
//        cout << "Podaj liczbe pojemnikow." << endl;
//        cin >> number_of_containers;
//        cout << "Podaj maksymalna pojemnosc pojemnika." << endl;
//        cin >> size_container;
//
//        Creator creator;
//        creator.read_file();
//        creator.average_fill(number_of_containers,size_container,average_fill,color_quantity);
//        containers = creator.get_containers();
//
//        NaiveSolver solv(containers);
//        int ch;
//        cout << "Rodzaje algorytmow:" << endl;
//        cout << "1. Algorytm rozwiazywania drzewem." << endl;
//        cout << "2. Alborytm rozwiazywania pojemnikami." << endl;
//        cout << "3. Algorytm rozwiazywania kolorami. " << endl;
//        cin >> ch;
//
//        if(ch == 1)
//        {
//            clock_t time = clock();
//            solv.build_tree();
//            double duration = ( clock() - time ) / (double) CLOCKS_PER_SEC;
//            cout<<"Czas trwania: " << duration << " sek" << endl;
//        }
//        else if(ch == 2)
//        {
//            clock_t time = clock();
//            solv.optimal_method(false);
//            double duration = ( clock() - time ) / (double) CLOCKS_PER_SEC;
//            cout<<"Czas trwania: " << duration << " sek" << endl;
//        }
//        else if(ch == 3)
//        {
//            clock_t time = clock();
//            solv.color_method(false);
//            double duration = ( clock() - time ) / (double) CLOCKS_PER_SEC;
//            cout<<"Czas trwania: " << duration << " sek" << endl;
//        }
//        else
//        {
//            cout << "Error." << endl;
//        }
//    }

        vector < Container > containers;
        Creator creator;
        creator.read_file();
        creator.average_fill(3,13,0.70,20);
        containers = creator.get_containers();
        NaiveSolver solv(containers);
        clock_t time = clock();
        solv.build_tree();
        double duration = ( clock() - time ) / (double) CLOCKS_PER_SEC;
        cout<<"Czas trwania: " << duration << " sek" << endl;


    return 0;
}
