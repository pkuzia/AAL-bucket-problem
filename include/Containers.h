#ifndef CONTAINERS_H
#define CONTAINERS_H
#include <Container.h>
#include <vector>

class Containers
{
    public:
        Containers(vector < Container > cont);
        vector < Container > get_containers();
    protected:
    private:
        vector <Container> containers;
};

#endif // CONTAINERS_H
