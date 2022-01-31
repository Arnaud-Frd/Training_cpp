#include "flying_object.h"
#include<random>
#include<iostream>
#include<time.h>
#include<chrono>
using namespace std;

flying_object :: flying_object()
{
    this->state=20;
}

flying_object :: ~flying_object()
{
    //cout<<"destruction de flying_object : "<< identifiant <<endl;
}

flying_object::flying_object( int id )
{
    this->identifiant=id;
    this->state=20;
}

int flying_object::CheckWeather()
{
    if (this->flag==0)
    {
        this->flag=1;
        srand(time(NULL));
        return rand()%100+1;
    }
    return rand()%100+1;
}

int flying_object::fly()
{
    if (flying_object::CheckWeather()<50)
        this->state-=3;

    flying_object :: log ();

    return(this->state<3);
}

void flying_object :: log ()
{
    cout << "Log_Other "<< this->identifiant <<" : -> state = "<< this->state << endl;
}
