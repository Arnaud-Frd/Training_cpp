#include "helicopter.h"
#include"flying_object.h"
#include<iostream>
using namespace std;


// Peut etre essayer d'utiliser le constructeur de flying object
Helicopter :: Helicopter( int id )
{
    this->identifiant = id;
    this->state=20;
}

Helicopter :: ~Helicopter()
{
   // cout<<"Destruction de l'helicoptere"<< identifiant <<endl;
}

int Helicopter :: fly ()
{
    if (flying_object::CheckWeather()<25)
    {
        this->state-=2;
    }
    Helicopter :: log ();

    return(this->state<3);
}

void Helicopter :: log ()
{
    cout << "Log_helico "<< this->identifiant <<" : -> state = "<< this->state << endl;
}

