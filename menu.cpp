#include "rozgrywka_z_graczem.h"
#include "komputer_latwy.h"
#include "komputer_sredni.h"
#include "komputer_trudny.h"
#include "komputer_niemozliwy.h"
#include "menu.h"

using namespace std;

void komputer(){

    string poziom;

    do {
        cout << "Podaj poziom trudnosci." << endl << "Latwy - komputer tylko sie broni, wygrywa przez przypadek. (obrona>wygrana)" << endl << "Sredni - komputer sie broni, potrafi wygrywac. (wygrana>obrona)" << endl << "Trudny." << endl <<"Niemozliwy - nie da sie wygrac, max remis" << endl;
        cin >> poziom;
    } while (!(poziom=="latwy" || poziom=="trudny" || poziom=="sredni" || poziom=="niemozliwy"));

    if (poziom=="latwy"){
        latwy();
    }

    if (poziom=="trudny"){
        trudny();
    }

    if (poziom=="sredni"){
        sredni();
    }

    if (poziom=="niemozliwy"){
        niemozliwy();
    }
}

void gra(){
    char z_kim;
    do {
        cout << "Chcesz zagrac z komputerem czy z czlowiekiem? (k/c)" << endl;
        cin >> z_kim;
        {
            cin.clear();
            cin.sync();
        }
        if (z_kim=='k' || z_kim=='K'){
            komputer();
        }
        if (z_kim=='c' || z_kim=='C'){
            czlowiek();
        }
    }while (!(z_kim=='k' || z_kim=='K' || z_kim=='C' || z_kim=='c'));
}

void begining(){
    char odp;
    do {
        cout << "Chcesz zagrac w kolko i krzyzyk? (t/n)" << endl;
        cin >> odp;
        if( !cin )
        {
            cin.clear();
            cin.sync();
        }
        if (odp=='t' || odp=='T'){
            gra();
                begining();
        }
    } while (!(odp=='t' || odp=='T' || odp=='N' || odp=='n'));
}
