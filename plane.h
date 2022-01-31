#ifndef PLANE_H
#define PLANE_H
#include"flying_object.h"

class Plane : public flying_object
{
private:

public:
    Plane( int id );
    ~Plane();
    int fly ();
    void log();
};

#endif // PLANE_H
