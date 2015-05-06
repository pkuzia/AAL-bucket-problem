#include "Root.h"

Root::Root(Containers cont)
{
    containers = new Containers(cont.get_containers());
}

