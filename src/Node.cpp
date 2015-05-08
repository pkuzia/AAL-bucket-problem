#include "Node.h"

Node::Node(vector <Container> cont, Node* previous)
{
    containers = cont;
    prev = previous;

}
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

bool Node::compare(Node & node)
{
    vector <Container> container_two;
    container_two = node.get_containers();
    for(size_t i = 0; i< containers.size(); i++)
    {
        bool exist_the_same = false;
        for(size_t j = 0; j< container_two.size(); j++)
        {
//            cout << "Mapa 1 :" << endl;
//            containers[i].print_map();
//            cout << "Mapa 2 :" << endl;
//            container_two[j].print_map();

            if(containers[i].compare(container_two[j]))
            {
                exist_the_same = true;
                //cout << "Takie same" << endl;
            }
            //cout << "------------------" << endl << endl;
        }
        if(!exist_the_same)
        {
            return false;
        }
    }
    return true;
}
void Node::delete_duplicates() // zak³adamy, ¿e musi posiadac ju¿ ga³ezie.
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
                cout << i << " i " << j << " takie same." << endl;
                nodes_to_delete.push_back(j);
             }
            j++;
         }
    i++;
    }
    sort(nodes_to_delete.begin(), nodes_to_delete.end());
    nodes_to_delete.erase(std::unique(nodes_to_delete.begin(), nodes_to_delete.end()), nodes_to_delete.end());
    int del = 0;
    for(vector<int>::iterator it = nodes_to_delete.begin(); it != nodes_to_delete.end(); ++it)
    {
        cout << "Usuwam " << *it - del<< endl;
        nodes.erase (nodes.begin()+(*it) - del);
        del++;
    }

//    nodes[2]->print_node();
//    nodes[0]->print_node();
//
//    if(nodes[0]->compare(*nodes[2]))
//    {
//       cout << "Takie same." << endl;
//    }

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
