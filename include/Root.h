#ifndef ROOT_H
#define ROOT_H
#include <Containers.h>
#include <Node.h>

class Root
{
    public:
        Root(Containers cont);
    protected:
    private:
        Containers *containers;
        vector < Node* > nodes;

};

#endif // ROOT_H
