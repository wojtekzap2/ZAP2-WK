#include "funkcje.h"

void tworzenie(char **&a, int *&pion, int x){

    for (int i=0; i<(x*2-1); i=i+2){
        for (int j=0;j<(x*2-1);j=j+2){
            a[i][j]=' ';
        }
    }

    for (int i=1;i<(x*2-1);i=i+2){
        for (int j=0;j<(x*2-1);j++){
            a[j][i]='|';
        }
    }

    for (int i=1;i<(x*2-1);i=i+2){
        for (int j=0;j<(x*2-1);j++){
            a[i][j]='-';
        }
    }

    char litera1 = 'A';

    for (int i=0;i<(x*2-1);i=i+2){
        a[i][x*2-1]=litera1;
        litera1++;
    }

    for (int i=1;i<(x*2);i=i+2){
        a[i][x*2-1]=' ';
    }

    int pion1=0;

    for (int i=0;i<(x*2-1);i=i+2){
        pion1++;
        pion[i]=pion1;
    }

}

void druk(char **a, int *pion, int x) {

    cout << " ";

    for (int i=0;i<(x*2-1);i=i+2){
        cout << fixed << pion[i] << setw(4);
    }

    cout << endl;


    for (int i=0;i<(x*2-1);i++){
        for (int j=0;j<(x*2);j++){
            cout << fixed << setw(2) << a[i][j];
        }
        cout << endl;
    }
}


void wielkosc(int &y){
    do {
        cout << "Podaj rozmiar planszy." << endl;
        cin >> y;
        if( !cin )
        {
            cin.clear();
            cin.sync();
        }
    } while (!(y>2&&y<30));
}

void wstawienie(char **&a, char z, string kto, int x){

    char litera;
    int liczba;
    int licznik=0;

    do {
        licznik=0;
    do {
    cout << "Gracz " << kto << endl << "Wpisz nr pola (np.B4)" << endl;
    cin >> litera;
    if( !cin )
    { // wpisano coś, co nie jest literą

        cin.clear(); // czyścimy flagi błędu strumienia
        cin.sync(); // czyścimy bufor strumienia
    }
    cin >> liczba;
    if( !cin )
    { // wpisano coś, co nie jest liczbą

        cin.clear(); // czyścimy flagi błędu strumienia
        cin.sync(); // czyścimy bufor strumienia
    }
    }
        while (!((liczba>0&&liczba<=x)&&((litera>='A'&&litera<('A'+x))||(litera>='a'&&litera<('a'+x)))));

    if (litera>='A'&&litera<('A'+x)){

    if (a[int(litera)*2-130][2*liczba-2]!='O' && a[int(litera)*2-130][2*liczba-2]!='X'){
        a[int(litera)*2-130][2*liczba-2]=z;
    }
    else {
        licznik++;
    }
    }

    if (litera>='a'&&litera<('a'+x)){
        if(a[int(litera)*2-194][2*liczba-2]!='O' && a[int(litera)*2-194][2*liczba-2]!='X'){
        a[int(litera)*2-194][2*liczba-2]=z;
}
        else {
        licznik++;
}
}

    } while(licznik!=0);
}

void sprawdzenie (char **a, int x, int &win){

    if (x>=5){
    for (int i=0;i<(x*2-1);i=i+2){
        for (int j=0;j<(x*2-9);j=j+2){
            if (a[i][j]==a[i][j+2]&&a[i][j]==a[i][j+4]&&a[i][j]==a[i][j+6]&&a[i][j]==a[i][j+8]&&a[i][j]!=' '){
                if (a[i][j]=='O'){
                    cout << "Wygrywa gracz kolko. BRAWO!" << endl;
                    win=1;
                }
                if (a[i][j]=='X'){
                    cout << "Wygrywa gracz krzyzyk. BRAWO!" << endl;
                    win=1;
                }
            }
        }
    }

    //sprawdzanie w kolumnach

    for (int j=0;j<(x*2-1);j=j+2){
        for (int i=0;i<(x*2-9);i=i+2){
            if (a[i][j]==a[i+2][j]&&a[i][j]==a[i+4][j]&&a[i][j]==a[i+6][j]&&a[i][j]==a[i+8][j]&&a[i][j]!=' '){
                if (a[i][j]=='O'){
                    cout << "Wygrywa gracz kolko. BRAWO!" << endl;
                    win=1;
                }
                if (a[i][j]=='X'){
                    cout << "Wygrywa gracz krzyzyk. BRAWO!" << endl;
                    win=1;
                }
            }
        }
    }

    //sprawdzanie na przekatnych (normalnych)

    for (int i=0;i<(x*2-9);i=i+2){
        for (int j=0;j<(x*2-9);j=j+2){
            if (a[i][j]==a[i+2][j+2]&&a[i][j]==a[i+4][j+4]&&a[i][j]==a[i+6][j+6]&&a[i][j]==a[i+8][j+8]&&a[i][j]!=' '){
                if (a[i][j]=='O'){
                    cout << "Wygrywa gracz kolko. BRAWO!" << endl;
                    win=1;
                }
                if (a[i][j]=='X'){
                    cout << "Wygrywa gracz krzyzyk. BRAWO!" << endl;
                    win=1;
                }
            }
        }
    }

    //sprawdzanie po przekatnych (nienormalnie)

    for (int i=0;i<(x*2-9);i=i+2){
        for (int j=8;j<(x*2-1);j=j+2){
            if (a[i][j]==a[i+2][j-2]&&a[i][j]==a[i+4][j-4]&&a[i][j]==a[i+6][j-6]&&a[i][j]==a[i+8][j-8]&&a[i][j]!=' '){
                if (a[i][j]=='O'){
                    cout << "Wygrywa gracz kolko. BRAWO!" << endl;
                    win=1;
                }
                if (a[i][j]=='X'){
                    cout << "Wygrywa gracz krzyzyk. BRAWO!" << endl;
                    win=1;
                }
            }
        }
    }}

    if (x==4){
    for (int i=0;i<(x*2-1);i=i+2){
        for (int j=0;j<(x*2-7);j=j+2){
            if (a[i][j]==a[i][j+2]&&a[i][j]==a[i][j+4]&&a[i][j]==a[i][j+6]&&a[i][j]!=' '){
                if (a[i][j]=='O'){
                    cout << "Wygrywa gracz kolko. BRAWO!" << endl;
                    win=1;
                }
                if (a[i][j]=='X'){
                    cout << "Wygrywa gracz krzyzyk. BRAWO!" << endl;
                    win=1;
                }
            }
        }
    }

    //sprawdzanie w kolumnach

    for (int j=0;j<(x*2-1);j=j+2){
        for (int i=0;i<(x*2-7);i=i+2){
            if (a[i][j]==a[i+2][j]&&a[i][j]==a[i+4][j]&&a[i][j]==a[i+6][j]&&a[i][j]!=' '){
                if (a[i][j]=='O'){
                    cout << "Wygrywa gracz kolko. BRAWO!" << endl;
                    win=1;
                }
                if (a[i][j]=='X'){
                    cout << "Wygrywa gracz krzyzyk. BRAWO!" << endl;
                    win=1;
                }
            }
        }
    }

    //sprawdzanie na przekatnych (normalnych)

    for (int i=0;i<(x*2-7);i=i+2){
        for (int j=0;j<(x*2-7);j=j+2){
            if (a[i][j]==a[i+2][j+2]&&a[i][j]==a[i+4][j+4]&&a[i][j]==a[i+6][j+6]&&a[i][j]!=' '){
                if (a[i][j]=='O'){
                    cout << "Wygrywa gracz kolko. BRAWO!" << endl;
                    win=1;
                }
                if (a[i][j]=='X'){
                    cout << "Wygrywa gracz krzyzyk. BRAWO!" << endl;
                    win=1;
                }
            }
        }
    }

    //sprawdzanie po przekatnych (nienormalnie)

    for (int i=0;i<(x*2-7);i=i+2){
        for (int j=8;j<(x*2-1);j=j+2){
            if (a[i][j]==a[i+2][j-2]&&a[i][j]==a[i+4][j-4]&&a[i][j]==a[i+6][j-6]&&a[i][j]!=' '){
                if (a[i][j]=='O'){
                    cout << "Wygrywa gracz kolko. BRAWO!" << endl;
                    win=1;
                }
                if (a[i][j]=='X'){
                    cout << "Wygrywa gracz krzyzyk. BRAWO!" << endl;
                    win=1;
                }
            }
        }
    }}

    if(x==3){

        for (int i=0;i<(x*2-1);i=i+2){
            for (int j=0;j<(x*2-5);j=j+2){
                if (a[i][j]==a[i][j+2]&&a[i][j]==a[i][j+4]&&a[i][j]!=' '){
                    if (a[i][j]=='O'){
                        cout << "Wygrywa gracz kolko. BRAWO!" << endl;
                        win=1;
                    }
                    if (a[i][j]=='X'){
                        cout << "Wygrywa gracz krzyzyk. BRAWO!" << endl;
                        win=1;
                    }
                }
            }
        }

        //sprawdzanie w kolumnach

        for (int j=0;j<(x*2-1);j=j+2){
            for (int i=0;i<(x*2-5);i=i+2){
                if (a[i][j]==a[i+2][j]&&a[i][j]==a[i+4][j]&&a[i][j]!=' '){
                    if (a[i][j]=='O'){
                        cout << "Wygrywa gracz kolko. BRAWO!" << endl;
                        win=1;
                    }
                    if (a[i][j]=='X'){
                        cout << "Wygrywa gracz krzyzyk. BRAWO!" << endl;
                        win=1;
                    }
                }
            }
        }

        //sprawdzanie na przekatnych (normalnych)

        for (int i=0;i<(x*2-5);i=i+2){
            for (int j=0;j<(x*2-5);j=j+2){
                if (a[i][j]==a[i+2][j+2]&&a[i][j]==a[i+4][j+4]&&a[i][j]!=' '){
                    if (a[i][j]=='O'){
                        cout << "Wygrywa gracz kolko. BRAWO!" << endl;
                        win=1;
                    }
                    if (a[i][j]=='X'){
                        cout << "Wygrywa gracz krzyzyk. BRAWO!" << endl;
                        win=1;
                    }
                }
            }
        }

        //sprawdzanie po przekatnych (nienormalnie)

        for (int i=0;i<(x*2-5);i=i+2){
            for (int j=4;j<(x*2-1);j=j+2){
                if (a[i][j]==a[i+2][j-2]&&a[i][j]==a[i+4][j-4]&&a[i][j]!=' '){
                    if (a[i][j]=='O'){
                        cout << "Wygrywa gracz kolko. BRAWO!" << endl;
                        win=1;
                    }
                    if (a[i][j]=='X'){
                        cout << "Wygrywa gracz krzyzyk. BRAWO!" << endl;
                        win=1;
                    }
                }
            }
        }
    }
}

void remis (char **a, int x, int &win){
    if (win!=1){
    int licznik=0;
    for (int i=0;i<(x*2-1);i=i+2){
        for (int j=0;j<(x*2-1);j=j+2){
            if(a[i][j]=='O' || a[i][j]=='X'){
                licznik++;
            }
        }
    }
    if (licznik==x*x){
        cout << "REMIS" << endl;
        win=1;
    }
    }
}


void obrona (char **a, int x, char k, char z, int &kon){

    for (int i=0;i<(x*2-1);i=i+2){
        int j=0;
        if(a[i][j]==a[i][j+2]&&a[i][j]==k){
            if(a[i][j+4]==' '){
                a[i][j+4]=z;
                kon=1;
            }
        }
        if(kon!=1){
            if(a[i][j]==a[i][j+4]&&a[i][j]==k){
                if(a[i][j+2]==' '){
                    a[i][j+2]=z;
                    kon=1;
                }
            }
        }
        if(kon!=1){
            if(a[i][j+2]==a[i][j+4]&&a[i][j+2]==k){
                if(a[i][j]==' '){
                    a[i][j]=z;
                    kon=1;
                }
            }
        }
    }

    if(kon!=1){
    for (int j=0;j<(x*2-1);j=j+2){
        int i=0;
        if(a[i][j]==a[i+2][j]&&a[i][j]==k){
            if(a[i+4][j]==' '){
                a[i+4][j]=z;
                kon=1;
            }
        }
        if(kon!=1){
            if(a[i][j]==a[i+4][j]&&a[i][j]==k){
                if(a[i+2][j]==' '){
                    a[i+2][j]=z;
                    kon=1;
                }
            }
        }
        if(kon!=1){
            if(a[i+2][j]==a[i+4][j]&&a[i+2][j]==k){
                if(a[i][j]==' '){
                    a[i][j]=z;
                    kon=1;
                }
            }
        }
     }}

    if(kon!=1){
        if(a[0][0]==a[2][2]&&a[0][0]==k){
            if(a[4][4]==' '){
            a[4][4]=z;
            kon=1;}
        }
        if (kon!=1){
            if(a[2][2]==a[4][4]&&a[2][2]==k){
                if(a[0][0]==' '){
                    a[0][0]=z;
                    kon=1;
                }
            }
        }
        if (kon!=1){
            if(a[0][4]==a[2][2]&&a[0][4]==k){
                if(a[4][0]==' '){
                    a[4][0]=z;
                    kon=1;
                }
            }
        }
        if (kon!=1){
            if(a[2][2]==a[4][0]&&a[2][2]==k){
                if(a[0][4]==' '){
                    a[0][4]=z;
                    kon=1;
                }
            }
        }
        if (kon!=1){
            if(a[0][0]==a[4][4]&&a[0][0]==k){
                if(a[2][2]==' '){
                    a[2][2]=z;
                    kon=1;
                }
            }
        }
        if (kon!=1){
            if(a[0][4]==a[4][0]&&a[0][4]==k){
                if(a[2][2]==' '){
                    a[2][2]=z;
                    kon=1;
                }
            }
        }
    }
}

void losowy_ruch_latwy(char **a, char z, int &kon){
        srand(time(0));
        int i;
        int j;
        do{
            i = 0 + rand( ) %(4+1-0);
            j = 0 + rand( ) %(4+1-0);
            if(a[i][j]==' '){
                a[i][j]=z;
                kon=1;
            }
        }while(kon!=1);
}

void losowy_ruch_trudny_1 (char **a, char z, int &kon){
        if (a[2][2]==' '){
            a[2][2]=z;
            kon=1;
        }
}

void losowy_ruch_trudny_2 (char **a, char z, int &kon){
    if(a[0][0]==' '){
        a[0][0]=z;
        kon=1;
    }
    if (kon!=1){
        if(a[0][4]==' '){
            a[0][4]=z;
            kon=1;
        }
    }
    if(kon!=1){
        if(a[4][0]==' '){
            a[4][0]=z;
            kon=1;
        }
    }
    if(kon!=1){
        if(a[4][4]==' '){
            a[4][4]=z;
            kon=1;
        }
    }
}

void losowy_ruch_niemozliwy (char **a, char k, char z, int &kon){
    if (a[0][0]==a[4][4]&&a[0][0]==k&&a[0][0]!=' '){
        if(a[0][2]==' '){
            a[0][2]=z;
            kon=1;
        }
    }
    if (kon!=1){
        if(a[4][0]==a[0][4]&&a[4][0]==k&&a[4][0]!=' '){
            if(a[0][2]==' '){
                a[0][2]=z;
                kon=1;
            }
        }
    } 
    if (kon!=1){
        int licznik=0;
        for (int i=0;i<5;i=i+2){
            for(int j=0;j<5;j=j+2){
                if (a[i][j]==' '){
                    licznik++;
                }
            }
        }
        if(licznik==6){
            if( (a[0][0]==k&&a[2][4]==k) || (a[0][0]==k&&a[4][2]==k) ){
                a[4][4]=z;
                kon=1;
            }
            if( (a[0][4]==k&&a[4][2]==k) || (a[0][4]==k&&a[2][0]==k)){
                a[4][0]=z;
                kon=1;
            }
            if( (a[4][0]==k&&a[0][2]==k) || (a[4][0]==k&&a[2][4]==k)){
                a[0][4]=z;
                kon=1;
            }
        }
    }
}
void niemozliwosc (char **a, char k, char z, int &kon){
    if (kon!=1){
        if ((a[4][2]==k&&a[0][0]==' '&&a[0][2]==' '&&a[0][4]==' '&&a[2][0]==' '&&a[2][2]==' '&&a[2][4]==' '&&a[4][0]==' '&&a[4][4]==' ') || (a[4][2]==' '&&a[0][0]==' '&&a[0][2]==' '&&a[0][4]==' '&&a[2][0]==' '&&a[2][2]==' '&&a[2][4]==k&&a[4][0]==' '&&a[4][4]==' ')){
            a[4][4]=z;
            kon=1;
        }
    }
}
