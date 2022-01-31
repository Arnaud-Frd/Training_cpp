#ifndef HELICOPTER_H
#define HELICOPTER_H
#include"flying_object.h"

class Helicopter : public flying_object
{
private:

public:
    Helicopter( int id );
    ~Helicopter();
    int fly ();
    void log();
};

#endif // HELICOPTER_H
