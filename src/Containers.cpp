#include "Containers.h"

Containers::Containers(vector < Container > cont)
{
    containers = cont;
}

vector < Container > Containers::get_containers()
{
    return containers;
}

