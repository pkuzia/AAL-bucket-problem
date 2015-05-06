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
            }
            if(newContainers[index_right].free_slot())
            {
                string color = blocks[j].get_color();
                Block block(color);
                newContainers[index_right].add_block(block);
                newContainers[i].delete_block(j);
                Node* node = new Node(newContainers,this);
            }
        }
    }
}
