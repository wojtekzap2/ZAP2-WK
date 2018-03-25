#include "komputer_latwy.h"

void latwy (){
    int rozmiar = 3;
    int zw=100;
    int koniec=0;

    int*mala;
    mala = new int[rozmiar*2];

    char **tab = new char *[rozmiar*2];
    for ( int i = 0; i < rozmiar*2; ++i )
     {
     tab[i] = new char [rozmiar*2-1];}

    cout<<endl;
    tworzenie(tab,mala,rozmiar);
    druk(tab,mala,rozmiar);
    cout << endl;

    string kto;

    do{
        cout << "Kto zaczyna ty czy komputer? (ja/komp)" << endl;
        cin >> kto;
    } while (!(kto=="ja" || kto=="komp"));

    if (kto=="ja"){
        do{
            wstawienie(tab,'O',"kolko",rozmiar);
            cout << endl;
            druk(tab,mala,rozmiar);
            cout << endl;
            sprawdzenie(tab,rozmiar,zw);
            remis(tab,rozmiar,zw);
            if(zw==1){
                break;
            }
            obrona(tab,rozmiar,'O','X',koniec);
            if(koniec==0){
                losowy_ruch_latwy(tab,'X',koniec);
            }
            koniec=0;
            druk(tab,mala,rozmiar);
            cout << endl;
            sprawdzenie(tab,rozmiar,zw);
            remis(tab,rozmiar,zw);
        } while (zw!=1);
    }

    if (kto=="komp"){
        do{
            obrona(tab,rozmiar,'O','X',koniec);
            if(koniec==0){
                losowy_ruch_latwy(tab,'X',koniec);
            }
            koniec=0;
            druk(tab,mala,rozmiar);
            cout << endl;
            sprawdzenie(tab,rozmiar,zw);
            remis(tab,rozmiar,zw);
            if(zw==1){
                break;
            }
            wstawienie(tab,'O',"kolko",rozmiar);
            cout << endl;
            druk(tab,mala,rozmiar);
            cout << endl;
            sprawdzenie(tab,rozmiar,zw);
            remis(tab,rozmiar,zw);
        } while(zw!=1);
    }

    for ( int i(0); i < rozmiar*2; ++i )
    delete [] tab[i];
    delete [] tab;

    delete[]mala;
}
