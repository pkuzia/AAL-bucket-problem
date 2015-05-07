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
        cout << endl;
    }
}
vector < Container > Node::get_containers()
{
    return containers;
}

bool Node::compare(Node & node)
{
    for(vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it)
    {
        
    }
    return true;
}
void Node::delete_duplicates()
{
    
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
    if(containers[0].compare(containers[1]))
    {
        cout << " 0 i 1 takie same" << endl;
    }
    
    
}
