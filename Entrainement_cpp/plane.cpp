#include "plane.h"
#include"flying_object.h"
#include<iostream>
using namespace std;


Plane :: Plane( int id )
{
    this->identifiant = id ;
    this->state=20;
}

Plane :: ~Plane ()
{
    // cout<<"Destruction de l'avion !"<< identifiant <<endl;
}

int Plane :: fly ()
{
    if (flying_object::CheckWeather()<40)
    {
        this->state-=1;
    }
    Plane::log();

    return(this->state<3);
}

void Plane :: log ()
{
    cout << "Log_plane "<< this->identifiant <<" -> state = "<< this->state << endl;
}
