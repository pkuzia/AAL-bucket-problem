#include "Node.h"

Node::Node(vector <Container> cont, Node* previous)
{
    containers = cont;
    parent = previous;

}
/* Funkcja budująca wszystkie mozliwe ruchu z obecnej sytuacji.*/
//-------------------------------
/*  Politechnika Warszawska WEiTI
    Przemysław Kuzia ISI
    Projekt z Analizy Algorytmów
    Pojemniki i klocki
*///----------------------------
void Node::build()
{
    for(size_t i = 0; i< containers.size(); i++)
    {
        vector < Block > blocks = containers[i].get_blocks();
        for(size_t j = 0; j< blocks.size(); j++)
        {
            int index_left, index_right;
            if( i == 0 )
            {
                index_left = containers.size() - 1;
            }
            else
            {
                index_left = i - 1;
            }
            if(i == containers.size() - 1)
            {
                index_right = 0;
            }
            else
            {
                index_right = i + 1;
            }
            vector <Container> newContainers = containers;
            if(newContainers[index_left].free_slot())
            {
                string color = blocks[j].get_color();
                Block block(color);
                newContainers[index_left].add_block(block);
                newContainers[i].delete_block(j);
                Node* node = new Node(newContainers,this);
                nodes.push_back(node);
            }
            newContainers = containers;
            if(newContainers[index_right].free_slot())
            {
                string color = blocks[j].get_color();
                Block block(color);
                newContainers[index_right].add_block(block);
                newContainers[i].delete_block(j);
                Node* node = new Node(newContainers,this);
                nodes.push_back(node);
            }
        }
    }
}
bool Node::solved()
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
void Node::print_containers(vector < Container > containers )
{
    for(size_t i = 0; i< containers.size(); i++)
    {
        vector < Block > blocks = containers[i].get_blocks();
        for(size_t j = 0; j< blocks.size(); j++)
        {
            cout << blocks[j].get_color() << endl;
        }
//        cout << "WYPISANIE MAPY" << endl;
//        containers[i].print_map();
        cout << endl;
    }
}
vector < Container > Node::get_containers()
{
    return containers;
}
/* Funckja porównująca dwa węzły drzewa.*/
bool Node::compare(Node & node)
{
    vector <Container> container_two;
    container_two = node.get_containers();
    for(size_t i = 0; i< containers.size(); i++)
    {
        if(!containers[i].compare(container_two[i]))
        {
            return false;
        }
    }
    return true;
}
/* Funckja usująca duplikaty w swojej tablicy gałęzi, zakładamy że one istnieją*/
void Node::delete_duplicates()
{
    int i = 0;
    vector <int> nodes_to_delete;
    for(vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it)
    {
        int j = 0;
         for(vector<Node*>::iterator iter = nodes.begin(); iter != nodes.end(); ++iter)
         {
             if((*it)->compare(*(*iter)) && i != j)
             {
                if(std::find(nodes_to_delete.begin(), nodes_to_delete.end(), j) == nodes_to_delete.end())
                {
                    if(std::find(nodes_to_delete.begin(), nodes_to_delete.end(), i) == nodes_to_delete.end())
                    {
                        nodes_to_delete.push_back(j);
                    }
                }
             }
            j++;
         }
    i++;
    }
    sort(nodes_to_delete.begin(), nodes_to_delete.end(), std::greater<int>());
    for(vector<int>::iterator it = nodes_to_delete.begin(); it != nodes_to_delete.end(); ++it)
    {
        nodes.erase (nodes.begin()+(*it) );
    }
}

vector < Node* > Node::get_nodes()
{
    return nodes;
}

Node* Node::get_left()
{
    Node * node = this;
    while(node->get_nodes().size() != 0)
    {
        node = node->get_nodes()[0];
    }
    return node;

}

/* Funckja zwracająca następnik w drzewie.*/
Node* Node::get_successor()
{
    Node * parentt = parent;
    if(parentt == NULL)
    {
        return NULL;
    }
    int index = 0;
    vector <Node *> children = parent->get_nodes();
    for(vector<Node*>::iterator it = children.begin(); it != children.end(); ++it)
    {
        if(compare((*(*it))))
        {
            if(index == (int)children.size()-1)
            {
                if(parentt->get_successor() == NULL)
                {
                    return NULL;
                }
                return parentt->get_successor()->get_nodes()[0];
            }
            return children[index +1];
        }
        index++;
    }
    return NULL; // macbook
}

Node * Node::get_parent()
{
    return parent;
}
void Node::check_history() // zakładamy że węzeł musi mieć gałęzie.
{
    int index = 0;
    vector <int> nodes_to_delete;
    for(vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it)
    {
        Node *par = parent;
        while(par != NULL)
        {
            if((*it)->compare(*par))
            {
                //cout << "Znalazlem w histori taka sama sytuacje." << endl;
                //cout << "Push " << index << endl;
                nodes_to_delete.push_back(index);
                break;
            }
            par = par->get_parent();
        }
        index++;
    }
    sort(nodes_to_delete.begin(), nodes_to_delete.end(), std::greater<int>());
    for(vector<int>::iterator it = nodes_to_delete.begin(); it != nodes_to_delete.end(); ++it)
    {
        //cout << "Usuwam " << *it << endl;
        nodes.erase (nodes.begin()+(*it) );
    }
}
void Node::print_node()
{
    cout << "Wezel glowny :" << endl;
    print_containers(containers);
    int i = 0;
    for(vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it)
    {
        cout << "Sytuacja nr : " << i << endl;
        if(*it != NULL)
        {
            Node * node;
            node = *it;
            node->print_containers(node->get_containers());
        }
        i++;
    }
}
