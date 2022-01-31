#include <QCoreApplication>
#include"flying_object.h"
#include"helicopter.h"
#include"plane.h"
#include <iostream>
#include<vector>
#include<chrono>
#include<time.h>
#include<windows.h>
using namespace std;

int main()
{

        int flag,iter=0;


        vector<flying_object *> station1 = { new Plane(1) , new Helicopter(2) , new Plane(3) , new Plane(4) , new Helicopter(5) , new Helicopter(6) ,
                                             new Plane(7) , new Helicopter(8) , new Plane(9) , new Plane(10) , new Helicopter(11) , new Helicopter(12) ,
                                             new Plane(13) , new Helicopter(14) , new Plane(15) , new Plane(16) , new Helicopter(17) , new Helicopter(18) ,
                                             new flying_object(19) , new Helicopter(20)};

        vector<flying_object *> station1_temp;
        vector<flying_object *> station2;
        vector<flying_object *> station3;

        cout<<"Decollage ...\n";
        cout<<"Vol en cours ..."<<endl;

        chrono::steady_clock::time_point timer_20 = chrono::steady_clock::now()+chrono::seconds(20);

        while(chrono::steady_clock::now()<timer_20)
        {
                iter+=1;
                cout<<"\n"<<"Iteration "<<iter<<" : "<<endl;
                for (unsigned long long i=0 ; i <= station1.size()-1 ; i++)
                {
                    // la fonction int fly appel checkWeather met a jour state et renvoie (state<3)
                    flag=station1[i]->fly();

                    // state < 3 -> à déplacer dans station 3
                    if (flag)
                        station3.push_back(station1[i]);

                    // Conserver dans la station 1
                    else
                        station1_temp.push_back(station1[i]);
                }

                station1=station1_temp;
                station1_temp.clear();
                Sleep(500);

                //cout<<"\n\n";
        }
        cout<<"\n\n#------------------------------------------------------------------------------------------------#"<<endl;
        cout<<"Fin du vol ..."<<endl;

        // transfert des objets_volants
        station2=station1;
        station1.clear();

        // Apres le timer, deplacer station 1 a 2 et log vols réussis
        cout << "\n\nObjets volants arrives : "<< station2.size() <<"\n\n";
        for (unsigned long long i=0 ; i <= station2.size() -1 ; i++)
        {
            station2[i]->log();
        }

        // log avion perdu en vol
        cout << "\n\nObjets volants perdus :"<< station3.size() <<"\n\n";
        for (unsigned long long i=0 ; i <= station3.size() -1 ; i++)
        {
            station3[i]->log();
        }

        cout << "\nratio : " << station2.size() << " sur " << (station2.size()+station3.size()) << endl;

        // suppresion des pointeurs trouver comment faire ( station1 2 et 3 )
        for (unsigned long long i=0 ; i <= station2.size() -1 ; i++){ delete(station2[i]); }
        for (unsigned long long i=0 ; i <= station3.size() -1 ; i++){ delete(station3[i]); }

        return 0;

}
