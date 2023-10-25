#include <iostream>
using namespace std;
#include <string>
#include<cstdlib>
using std::rand;
using std::srand;
#include<ctime>
using std::time;
using std::time;
#include "rlutil.h"
// Declaracion de funciones.


void FuncionEstadisticas(int TotalPuntos1,int TotalPuntos2,int PartidasGanadas1,int PartidasGanadas2,string  Jugador1,string  Jugador2,bool PrimerPartida);

void MostrarLogo();

void Creditos();

int FuncionMenu(bool & PrimerPartida,string & Jugador1,string & Jugador2,int &PartidasGanadas1,int &PartidasGanadas2,int &TotalPuntos1,int &TotalPuntos2);

void FuncionJugar(bool & PrimerPartida,string & Jugador1,string & Jugador2,int &PartidasGanadas1,int &PartidasGanadas2,int &TotalPuntos1,int &TotalPuntos2);

void FuncionNombres(string&Jugador1,string&Jugador2);
void FuncionNombresElejidos(string&Jugador1,string&Jugador2);

void FuncionMezclarBaraja(int Mazo[20],int CartaRandom,int MazoRestante[10],int BarajaJugadores[10]);

void MezclarMazoRestante(int MazoRestante[10]);

bool Verificar( int CartaRandom,int BarajaJugadores[20]);

void FuncionRepartirCartas(int BarajaJugadores[10],int Mazo[20],int MazoRestante[10]);

int FuncionJuegoTerminado(int BarajaJugadores[10]);

void FuncionCambiosJugador1(int CartaBloqueadas[2],char Presionar,int Mazo[10],int BarajaJugadores[10],string PrimerTurno,string MazoNombres[20],int AuxBaraJugadores[],int MazoRestante[],int &UltimaCarta1,bool & TurnoVictoria,bool &TurnoVictoria2,bool &RoboDeCarta1,bool &RoboDeCarta2);

//id FuncionCambiosJugador2(char Presionar,int Mazo[10],int BarajaJugadores[10],string PrimerTurno,string MazoNombres[20],int AuxBaraJugadores[],int MazoRestante[]);
bool FuncionPrimerJugador(int BarajaJugadores[],int Mazo[]);

void FuncionMostrarMano2(string MazoNombres[20],int BarajaJugadores[10]);
void FuncionMostrarMano1(string MazoNombres[20],int BarajaJugadores[10]);
void FuncionOpcionesDejuego(char Presionar);

//void FuncionMazoNombres(string MazoNombres[20]);

//main_______________________________________________________________________________________________________________________
int main ()
{


     rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::GREEN);

    int PartidasGanadas1=0;
     int PartidasGanadas2=0;
     int TotalPuntos1=0;
     int TotalPuntos2=0;


    bool PrimerPartida=true;
    string Jugador1,Jugador2;

    MostrarLogo();

    FuncionNombres(Jugador1,Jugador2);
    FuncionMenu(PrimerPartida,Jugador1,Jugador2,PartidasGanadas1,PartidasGanadas2,TotalPuntos1,TotalPuntos2);
    /*switch(FuncionMenu(PrimerPartida,Jugador1,Jugador2,PartidasGanadas1,PartidasGanadas2,TotalPuntos1,TotalPuntos2))
    {
    case 1:
        return 1;
        break;
    case 2:
        return 2;
        break;
    case 3:
        return 3;
        break;
    case 0:
        return 4;
        break;

    }
    return 0;*/

}
// Funciones__________________________________________________________________________________________________________________

int FuncionMenu(bool & PrimerPartida,string & Jugador1,string & Jugador2,int &PartidasGanadas1,int &PartidasGanadas2,int &TotalPuntos1,int &TotalPuntos2) // Funcion Menu de juego.
{

    int Menu;

    do {

        system("cls");
     rlutil::locate(40, 15);
   MostrarLogo();
    cout <<endl;
    rlutil::locate(40, 16);
    cout << "1 - JUGAR"<<endl;
    rlutil::locate(40, 17);
    cout << "2 - ESTADISTICAS"<<endl;
    rlutil::locate(40, 18);
    cout << "3 - CREDITOS"<<endl;
    cout <<endl;
    rlutil::locate(40, 19);
    cout << "0 - SALIR"<<endl;
    rlutil::locate(40, 20);

    cout << ">";

    cin >> Menu;
    } while(Menu!=1&&Menu!=2&&Menu!=3&&Menu!=0);

   //string Jugador1,Jugador2;

    switch(Menu)
    {
    case 1:
        system("cls");
        FuncionJugar(PrimerPartida,Jugador1,Jugador2,PartidasGanadas1,PartidasGanadas2,TotalPuntos1,TotalPuntos2);
        break;
    case 2:
    FuncionEstadisticas(TotalPuntos1,TotalPuntos2,PartidasGanadas1,PartidasGanadas2,Jugador1,Jugador2,PrimerPartida);

        break;
    case 3:
    Creditos();
        break;
    case 0:
        return 0;
        break;


    }
}

void FuncionJugar(bool & PrimerPartida,string & Jugador1,string & Jugador2,int &PartidasGanadas1,int &PartidasGanadas2,int &TotalPuntos1,int &TotalPuntos2) //Funcion para el juego.
{

// Baraja.
    const int Cartas=20;
    int CartaRandom=0;
    int CartaElejida;
    int CartasMano=10;
    int Mazo[Cartas];
    int MazoRestante[CartasMano]= {};
    int BarajaJugadores[CartasMano]= {};
    int AuxBaraJugadores[CartasMano]= {};
    string MazoNombres[Cartas]= {"10 CORAZON","10 PICA","10 TREBOL","10 DIAMENTES",
                                 "J CORAZON","J PICA","J TREEBOL","J DIAMANTE",
                                 "Q CORAZON","Q PICA","Q TREBOL","Q DIAMENTES",
                                 "K CORAZON","K PICA","K TREBOL","K DIAMANTES",
                                 "A CORAZON","A PICA","A TREBOL","A DIAMANTES",
                                };
    int CartaBloqueadas[2];
    int UltimaCarta2;
    int UltimaCarta1;
    bool TurnoVictoria=false;
    bool TurnoVictoria2=false;
    bool RoboDeCarta1=false;
    bool RoboDeCarta2=false;

// Mezclo mazo.

do {
    srand(time(NULL));
    for(int i=0; i<20; i++)
    {
        //cout << Mazo[i]<< " "<< i;
        while(Verificar(CartaRandom,Mazo))
        {

            CartaRandom = rand()% 20;
        }

        Mazo[i]=CartaRandom;
//cout << Mazo[i]<< " "<< i<< " - ";
    }
// Verficar baraja mezclada.
    for(int i=0; i<20; i++)
    {
       // cout << MazoNombres[Mazo[i]] << " ";
    }
  //  cout << endl<<endl;

    FuncionRepartirCartas(BarajaJugadores,Mazo,MazoRestante);


// ya tengo las cartas repartidas y mezcladas

// do while para que las cartas servidas
} while (BarajaJugadores[0]<4&&BarajaJugadores[1]>=4&&BarajaJugadores[1]<=7&&BarajaJugadores[2]>=8&&BarajaJugadores[2]<=11&&BarajaJugadores[3]>=12&&BarajaJugadores[3]<=15&&BarajaJugadores[4]>=16&&BarajaJugadores[4]<20||BarajaJugadores[4]<4&&BarajaJugadores[5]>=4&&BarajaJugadores[5]<=7&&BarajaJugadores[6]>=8&&BarajaJugadores[6]<=11&&BarajaJugadores[7]>=12&&BarajaJugadores[7]<=15&&BarajaJugadores[8]>=16&&BarajaJugadores[8]<20);

bool JuegoTerminado=false;

    int Ronda=0;

    string PrimerTurno=Jugador1,SegundoTurno=Jugador2;

    if(FuncionPrimerJugador(BarajaJugadores,Mazo))
    {
        PrimerTurno=Jugador1;;
        SegundoTurno=Jugador2;

    }
    else
    {
        PrimerTurno=Jugador2;;
        SegundoTurno=Jugador1;
    }

    while (JuegoTerminado!=true)
    {
        Ronda++;
         UltimaCarta2=0;
         UltimaCarta1=0;

// Muestro barajas comienzo de juego.

        cout << "                                  <CLUTCH>       " << "Ronda> ";
        cout << Ronda<<endl;
        cout << "        _____________________________________________________________________________"<<endl;
        rlutil::locate(86, 3);
        cout << "|"<<endl;
        rlutil::locate(86, 4);
        cout << "|"<<endl;
        rlutil::locate(86, 5);
        cout << "|"<<endl;
        rlutil::locate(86, 6);
        cout << "|"<<endl;
        rlutil::locate(86, 7);
        cout << "|"<<endl;
        rlutil::locate(86, 8);
        cout << "|"<<endl;
        rlutil::locate(86, 9);
        cout << "|"<<endl;
        rlutil::locate(86, 10);
        cout << "|"<<endl;
        rlutil::locate(86, 11);
        cout << "|"<<endl;
        rlutil::locate(86, 12);
        cout << "|"<<endl;
        rlutil::locate(86, 13);
        cout << "|"<<endl;
        rlutil::locate(86, 14);
        cout << "|"<<endl;
        rlutil::locate(86, 15);
        cout << "|"<<endl;
        rlutil::locate(86, 16);
        cout << "|"<<endl;
        rlutil::locate(86, 17);
        cout << "|"<<endl;
        rlutil::locate(86, 18);

        rlutil::locate(8, 3);
        cout << "|"<<endl;
        rlutil::locate(8, 4);
        cout << "|"<<endl;
        rlutil::locate(8, 5);
        cout << "|"<<endl;
        rlutil::locate(8, 6);
        cout << "|"<<endl;
        rlutil::locate(8, 7);
        cout << "|"<<endl;
        rlutil::locate(8, 8);
        cout << "|"<<endl;
        rlutil::locate(8, 9);
        cout << "|"<<endl;
        rlutil::locate(8, 10);
        cout << "|"<<endl;
        rlutil::locate(8, 11);
        cout << "|"<<endl;
        rlutil::locate(8, 12);
        cout << "|"<<endl;
        rlutil::locate(8, 13);
        cout << "|"<<endl;
        rlutil::locate(8, 14);
        cout << "|"<<endl;
        rlutil::locate(8, 15);
        cout << "|"<<endl;
        rlutil::locate(8, 16);
        cout << "|"<<endl;
        rlutil::locate(8, 17);
        cout << "|"<<endl;
        rlutil::locate(8, 18);



        rlutil::locate(15, 7);
        cout << "Cartas del jugador #1 "<< Jugador1 <<endl<<endl;

        for (int x=0; x<5; x++)
        {
            rlutil::locate(20, x+9);
            BarajaJugadores[x];
            cout << "#" << x+1 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
        cout <<endl;
        rlutil::locate(55, 7);
        cout << "Cartas del jugador #2 "<< Jugador2 <<endl<<endl;


        for (int x=5; x<10; x++)
        {   rlutil::locate(60, x+4);
            BarajaJugadores[x];
            cout << "#" << x-4 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
        cout << endl;

        // Muestro Mazo restante

       // cout << "Mazo es: "<<endl<<endl;
        for(int i=0; i<10; i++)
        {
           // cout <<  MazoNombres[MazoRestante[i]] << " ";
        }


        char Presionar;
        cout << endl<<endl;
        cout << "       |_____________________________________________________________________________"<<endl;
        cout << endl<<endl;
        cout << "Turno del jugador: ";

        if (PrimerTurno==Jugador1)
        {
            cout << Jugador1<<endl;
            FuncionCambiosJugador1(CartaBloqueadas,Presionar,Mazo,BarajaJugadores,PrimerTurno,MazoNombres,AuxBaraJugadores,MazoRestante,UltimaCarta1,TurnoVictoria,TurnoVictoria2,RoboDeCarta1,RoboDeCarta2);
        }
        if (PrimerTurno==Jugador2)
        {
            cout << Jugador2<<endl;
            cout << endl;

           // cout << "Lanzador: " << PrimerTurno << " "<<endl;
            cout << "Preciona cualquier tecla para lanzar el dado >";
            rlutil:: anykey();
            cout << endl;


            int DadoRandom;
            DadoRandom = rand () % 5;
            DadoRandom=DadoRandom+1;
            DadoRandom=6;
            int CartaElejida;
            int CartaElejidaContraria;
            int Pick;

            if (DadoRandom==6) {
                FuncionOpcionesDejuego(Presionar);


                cin >> DadoRandom;
                while(DadoRandom<1||DadoRandom>7) {
                    cout << "Marque una opcion correcta (1-6) ";
                    cin >> DadoRandom;
                }
            }



          // system("cls");
            switch(DadoRandom)
            {

            case 1:
                cout << "Dado numero: "<< DadoRandom <<endl<<endl;
                cout << "____________________________________________________________________________________________"<<endl<<endl;
                cout << "***Elegir una carta de tu propio corral y robar una carta del mazo (1-5)***"<<endl<<endl;

                cout<< "Tus cartas: "<<endl<<endl;

                for (int x=5; x<10; x++)
                {
                    cout << "#"<< x-4<<" " << MazoNombres[BarajaJugadores[x]]<<endl;
                }
                cout <<endl<<endl;
                cout << "Carta elejida >";
                cin >> CartaElejida;

                while(CartaElejida<1||CartaElejida>5)
                {
                    cout << "Ingrese un numero correcto >";
                    cin >> CartaElejida;

                }

                CartaElejida=CartaElejida+4;

                srand(time(NULL));
                Pick=((rand() % 9));
                AuxBaraJugadores[CartaElejida]=BarajaJugadores[CartaElejida];
                BarajaJugadores[CartaElejida]=MazoRestante[Pick];
                MazoRestante[Pick]=AuxBaraJugadores[CartaElejida];


                break;
            case 2:
                cout << "Dado numero: "<< DadoRandom <<endl<<endl;
                cout << "____________________________________________________________________________________________"<<endl<<endl;
                cout << "***Elegir una carta del corral contrario y robar una carta del mazo (1-5)***"<<endl<<endl;
                cout<< "Cartas Contrarias: "<<endl<<endl;

                FuncionMostrarMano2(MazoNombres,BarajaJugadores);

                cout <<endl<<endl;
                cout << "Carta elejida >";
                cin >> CartaElejida;
                while(CartaElejida<1||CartaElejida>5||(CartaElejida-1)==CartaBloqueadas[1])
                {
                    if((CartaElejida-1)==CartaBloqueadas[1]) {
                        cout << "Esta Carta esta esta bloqueada por parte del rival elije otra >";
                        cin >> CartaElejida;
                    }
                    else {
                    cout << "Ingrese un numero correcto >";
                    cin >> CartaElejida;
                    }

                }
                CartaElejida=CartaElejida-1;


            /**   while(CartaElejida==CartaBloqueadas[1]) {
            cout << "Esta Carta esta esta bloqueada por parte del rival elije otra >";
            cin >> CartaElejida;
            CartaElejida=CartaElejida-1;


        }*/

                srand(time(NULL));

                Pick=((rand() % 9));
                AuxBaraJugadores[CartaElejida]=BarajaJugadores[CartaElejida];
                BarajaJugadores[CartaElejida]=MazoRestante[Pick];
                MazoRestante[Pick]=AuxBaraJugadores[CartaElejida];

                break;
            case 3:
            cout << "Dado numero: "<< DadoRandom <<endl<<endl;
            cout << "____________________________________________________________________________________________"<<endl<<endl;
        cout << "***Elegir una carta de tu propio corral y robar una del corral contrario (1-5)***"<<endl<<endl;
        cout<< "Tus cartas: "<<endl<<endl;

        for (int x=5; x<10; x++)
        {
            cout << "#"<< x-4<<" " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
        cout << endl;


        cout<< "Cartas contrarias: "<<endl<<endl;

        for (int x=0; x<5; x++)
        {
            cout << "#"<< x+1 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
        cout <<endl<<endl;

        cout << "Carta propia elejida >";
        cin >> CartaElejida;
        while(CartaElejida<1||CartaElejida>5)
        {
            cout << "Ingrese un numero correcto >";
            cin >> CartaElejida;

        }

        cout << "Carta del rival elejida >";
        cin >> CartaElejidaContraria;
        while(CartaElejidaContraria<1||CartaElejidaContraria>5||(CartaElejidaContraria-1)==CartaBloqueadas[1])
                {
                    if((CartaElejidaContraria-1)==CartaBloqueadas[1]) {
                        cout << "Esta Carta esta esta bloqueada por parte del rival elije otra >";
                        cin >> CartaElejidaContraria;
                    }
                    else {
                    cout << "Ingrese un numero correcto >";
                    cin >> CartaElejidaContraria;
                    }

                }





        CartaElejida=CartaElejida+4;
        CartaElejidaContraria=CartaElejidaContraria-1;

        AuxBaraJugadores[CartaElejida]=BarajaJugadores[CartaElejida];
        BarajaJugadores[CartaElejida]=BarajaJugadores[CartaElejidaContraria];
        BarajaJugadores[CartaElejidaContraria]=AuxBaraJugadores[CartaElejida];

        UltimaCarta2=1;
        RoboDeCarta2=true;



                break;
            case 4:
            cout << "Dado numero: "<< DadoRandom <<endl<<endl;
            cout << "____________________________________________________________________________________________"<<endl<<endl;
        cout << "***Elegir una carta de tu propio corral e intercambiarla por una de tu mismo corral  (1-5)***"<<endl<<endl;
        cout<< "Tus cartas: "<<endl<<endl;

         for (int x=5; x<10; x++)
        {
            cout << "#"<< x-4 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
         cout <<endl<<endl;

        cout << "Elija la primer carta de su mazo >";
        cin >> CartaElejida;
        while(CartaElejida<1||CartaElejida>5)
        {
            cout << "Ingrese un numero correcto >";
            cin >> CartaElejida;

        }

        cout << "Elija la segunda carta de su mazo >";
        cin >> CartaElejidaContraria;
        while(CartaElejida<1||CartaElejida>5)
        {
            cout << "Ingrese un numero correcto >";
            cin >> CartaElejidaContraria;

        }
        CartaElejida=CartaElejida+4;
        CartaElejidaContraria=CartaElejidaContraria+4;

        AuxBaraJugadores[CartaElejida]=BarajaJugadores[CartaElejida];
        BarajaJugadores[CartaElejida]=BarajaJugadores[CartaElejidaContraria];
        BarajaJugadores[CartaElejidaContraria]=AuxBaraJugadores[CartaElejida];
                break;
            case 5:
            cout << "Dado numero: "<< DadoRandom <<endl<<endl;
            cout << "____________________________________________________________________________________________"<<endl<<endl;
        cout << "***Elije una carta de tu propia corral y bloqueala para que tu rival no pueda modificarla  (1-5)***"<<endl<<endl;
        cout<< "Tus cartas: "<<endl<<endl;

FuncionMostrarMano1(MazoNombres,BarajaJugadores);

        cout << "Seleccione la carta >";
        cin >> CartaElejida;
        while(CartaElejida<1||CartaElejida>5)
        {
            cout << "Ingrese un numero correcto >";
            cin >> CartaElejida;

        }
        CartaElejida=CartaElejida+4;

        CartaBloqueadas[0]=CartaElejida;



                break;
            case 6:

            break;
            }

        if (DadoRandom==6) {
            cout <<endl;
            cout << "Jugador pasa de turno X.x";
            cout << endl;
            cout << "Presione cualquier tecla para continuar";
            rlutil::anykey();
            TurnoVictoria2=true;

        }

        }

        if (PrimerTurno==Jugador1)
        {
            PrimerTurno=Jugador2;
        }
        else
        {
            PrimerTurno=Jugador1;
        }
        cout << endl;
        cout << "-------------------------------------------------------------------------"<<endl;

        // Indice para terminar el juego


        switch (FuncionJuegoTerminado(BarajaJugadores)) {
        case 1:
            cout << "El ganador es: "<< Jugador1<<endl;
            JuegoTerminado=true;
            PrimerPartida=false;

            PartidasGanadas1++;
            if (TurnoVictoria==false) {
                TotalPuntos1=TotalPuntos1+10;
            }


            TotalPuntos1=TotalPuntos1+15;
            if (UltimaCarta1==1) {
                TotalPuntos1=TotalPuntos1+10;
             }

             if(RoboDeCarta2==false) {
                TotalPuntos1=TotalPuntos1+5;
             }

             // Puntos por cada carta desordenada del rival

             /*if(BarajaJugadores[5]>3) {
                TotalPuntos1=TotalPuntos1+5;
             }
             if(BarajaJugadores[6]<3||BarajaJugadores[6]>7) {
                TotalPuntos1=TotalPuntos1+5;
             }
             if(BarajaJugadores[7]<7||BarajaJugadores[6]>11) {
                TotalPuntos1=TotalPuntos1+5;
             }
             if(BarajaJugadores[8]<11||BarajaJugadores[6]>15) {
                TotalPuntos1=TotalPuntos1+5;
             }
             if(BarajaJugadores[9]<15) {
                TotalPuntos1=TotalPuntos1+5;
             }*/


            cout<< "Preciona cualquiera tecla para retornar al menu >";
            rlutil:: anykey();

            break;
        case 5:
             cout << "El ganador es: "<< Jugador2<<endl;
             JuegoTerminado=true;
             PrimerPartida=false;
             PartidasGanadas2++;


             TotalPuntos2=TotalPuntos2+15;

             if (UltimaCarta2==1) {
                TotalPuntos2=TotalPuntos2+10;
             }

             if (TurnoVictoria2==false) {
                TotalPuntos2=TotalPuntos2+10;
            }

            if(RoboDeCarta1==false) {
                TotalPuntos2=TotalPuntos2+5;
             }

             /*if(BarajaJugadores[0]>3) {
                TotalPuntos1=TotalPuntos1+5;
             }
             if(BarajaJugadores[1]<3||BarajaJugadores[6]>7) {
                TotalPuntos1=TotalPuntos1+5;
             }
             if(BarajaJugadores[2]<7||BarajaJugadores[6]>11) {
                TotalPuntos1=TotalPuntos1+5;
             }
             if(BarajaJugadores[3]<11||BarajaJugadores[6]>15) {
                TotalPuntos1=TotalPuntos1+5;
             }
             if(BarajaJugadores[4]<15) {
                TotalPuntos1=TotalPuntos1+5;
             }*/

             // Puntos por cada carta desordenada del rival



             cout<< "Preciona cualquiera tecla para retornar al menu >";
             rlutil:: anykey();
             //rlutil:: anykey();
            break;
        case 3:
        cout << "El juego continua"<<endl;
            break;
        }

        //MezclarMazoRestante(MazoRestante);
        //cin >> JuegoTerminado;

        system("cls");
    }
    FuncionMenu(PrimerPartida,Jugador1,Jugador2,PartidasGanadas1,PartidasGanadas2,TotalPuntos1,TotalPuntos2);

}

void FuncionMezclarBaraja(int Mazo[20],int CartaRandom,int MazoRestante[10],int BarajaJugadores[10])
{
// Mezclo.

    srand(time(NULL));


    for(int i=0; i<20; i++)
    {
        //cout << Mazo[i]<< " "<< i;
        while(Verificar(CartaRandom,Mazo))
        {

            CartaRandom = rand()% 20;
        }

        Mazo[i]=CartaRandom;
        cout << Mazo[i]<< " "<< i<< " - ";
    }
}

void FuncionRepartirCartas(int BarajaJugadores[10],int Mazo[20],int MazoRestante[])
{
//repartir cartas

    for(int i=0; i<10; i++)
    {
        BarajaJugadores[i]=Mazo[i];
    }

// rellenar mazo Restante

    for(int i=0; i<10; i++)
    {
        MazoRestante[i]=Mazo[i+10];
    }


}

bool Verificar( int CartaRandom,int BarajaJugadores[20])
{
    for(int i=0; i<20; i++)
    {
        if (CartaRandom==BarajaJugadores[i])
        {
            return true;
        }

    }
    return false;
}

void FuncionNombres(string&Jugador1,string&Jugador2) //Funcion nombre de jugadores.

{

    int Entrada;
    char Confirmacion;
    rlutil::locate(27, 17);
   cout << "Para comenzar Ingrese los nombres de los jugadores"<<endl<<endl<<endl;

    do
    {
        if (Entrada==false)
        {
            system("cls");
            MostrarLogo();
            rlutil::locate(27, 17);
            cout << "Ingrese nuevamente los nombres de usuario:"<<endl<<endl;
        }
        rlutil::locate(27, 19);
        cout << "Ingrese el nombre del primer jugador: >";
        cin >> Jugador1;
        cout << endl;
        rlutil::locate(27, 20);
        cout << "Ingrese el nombre del segundo jugador: >";
        cin >> Jugador2;
        cout << endl;

        system("cls");
        MostrarLogo();
        rlutil::locate(27, 17);
        cout << "Jugador #1: " << Jugador1 <<endl;
        rlutil::locate(27, 18);
        cout << "Jugador #2: " << Jugador2 <<endl;


        rlutil::locate(27, 20);
        cout << "Desea confirmar los nombres? y/n >";
        cin >> Confirmacion;



        Entrada=false;
    }
    while (Confirmacion!='Y'&&Confirmacion!='y');

    system("cls");


}

void FuncionNombresElejidos(string&Jugador1,string&Jugador2) {

}

int FuncionJuegoTerminado(int BarajaJugadores[10])
{

    if (BarajaJugadores[0]<4&&BarajaJugadores[1]>=4&&BarajaJugadores[1]<=7&&BarajaJugadores[2]>=8&&BarajaJugadores[2]<=11&&BarajaJugadores[3]>=12&&BarajaJugadores[3]<=15&&BarajaJugadores[4]>=16&&BarajaJugadores[4]<20)
    {
        return 1;
    }

    if (BarajaJugadores[5]<4&&BarajaJugadores[6]>=4&&BarajaJugadores[6]<=7&&BarajaJugadores[7]>=8&&BarajaJugadores[7]<=11&&BarajaJugadores[8]>=12&&BarajaJugadores[8]<=15&&BarajaJugadores[9]>=16&&BarajaJugadores[9]<20)
    {
        return 5;
    }
    else {
        return 0;
    }

}

void FuncionCambiosJugador1(int CartaBloqueadas[2],char Presionar,int Mazo[10],int BarajaJugadores[10],string PrimerTurno,string MazoNombres[20],int AuxBaraJugadores[],int MazoRestante[],int &UltimaCarta1,bool & TurnoVictoria,bool &TurnoVictoria2bool,bool &RoboDeCarta1,bool &RoboDeCarta2)
{

    //cout << "Lanzador: " << PrimerTurno << " "<<endl;
    cout << endl;
    cout << "Preciona cualquier tecla para lanzar el dado >";
    rlutil:: anykey();
    cout << endl;

    int Pick;
    int DadoRandom;
    DadoRandom = rand () % 5;
    DadoRandom=DadoRandom+1;
    DadoRandom=6;
    int CartaElejida;
    int CartaElejidaContraria;

    if (DadoRandom==6) {
                FuncionOpcionesDejuego(Presionar);


                cin >> DadoRandom;
                while(DadoRandom<1||DadoRandom>7) {
                    cout << "Marque una opcion correcta (1-6) ";
                    cin >> DadoRandom;
                }
            }
    //system("cls");
    switch(DadoRandom)
    {
    case 1:
        cout << "Dado numero: "<< DadoRandom <<endl<<endl;
        cout << "____________________________________________________________________________________________"<<endl<<endl;
        cout << "***Elegir una carta de tu propio corral y robar una carta del mazo (1-5)***"<<endl<<endl;
        cout<< "Tus cartas: "<<endl<<endl;

        for (int x=0; x<5; x++)
        {
            cout << "#"<< x+1 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
        cout <<endl<<endl;
        cout << "Carta elejida >";
        cin >> CartaElejida;
        while(CartaElejida<1||CartaElejida>5)
        {
            cout << "Ingrese un numero correcto >";
            cin >> CartaElejida;

        }
        CartaElejida=CartaElejida-1;
        srand(time(NULL));

        Pick=((rand() % 9));
        AuxBaraJugadores[CartaElejida]=BarajaJugadores[CartaElejida];
        BarajaJugadores[CartaElejida]=MazoRestante[Pick];
        MazoRestante[Pick]=AuxBaraJugadores[CartaElejida];

        break;
    case 2:

        cout << "Dado numero: "<< DadoRandom <<endl<<endl;
        cout << "____________________________________________________________________________________________"<<endl<<endl;
        cout << "***Elegir una carta del corral contrario y robar una carta del mazo (1-5)***"<<endl<<endl;
        cout<< "Cartas contrarias: "<<endl<<endl;

        for (int x=5; x<10; x++)
        {
            cout << "#"<< x-4<<" " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
        cout <<endl<<endl;
        cout << "Carta elejida >";
        cin >> CartaElejida;

        while(CartaElejida<1||CartaElejida>5||(CartaElejida+4)==CartaBloqueadas[0])
                {
                    if((CartaElejida+4)==CartaBloqueadas[0]) {
                        cout << "Esta Carta esta esta bloqueada por parte del rival elije otra >";
                        cin >> CartaElejida;
                    }
                    else {
                    cout << "Ingrese un numero correcto >";
                    cin >> CartaElejida;
                    }

                }

        CartaElejida=CartaElejida+4;
       // CartaElejida=CartaElejida-1;

        srand(time(NULL));
        Pick=((rand() % 9));
        AuxBaraJugadores[CartaElejida]=BarajaJugadores[CartaElejida];
        BarajaJugadores[CartaElejida]=MazoRestante[Pick];
        MazoRestante[Pick]=AuxBaraJugadores[CartaElejida];
        break;
    case 3:
    cout << "Dado numero: "<< DadoRandom <<endl<<endl;
    cout << "____________________________________________________________________________________________"<<endl<<endl;
        cout << "***Elegir una carta de tu propio corral y robar una del corral contrario (1-5)***"<<endl<<endl;
        cout<< "Tus cartas: "<<endl<<endl;

         for (int x=0; x<5; x++)
        {
            cout << "#"<< x+1 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
         cout << endl;
        cout<< "Cartas contrarias: "<<endl<<endl;


        for (int x=5; x<10; x++)
        {
            cout << "#"<< x-4<<" " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
        cout <<endl<<endl;

        cout << "Carta propia elejida >";
        cin >> CartaElejida;
        while(CartaElejida<1||CartaElejida>5)
        {
            cout << "Ingrese un numero correcto >";
            cin >> CartaElejida;

        }

        cout << "Carta del rival >";
        cin >> CartaElejidaContraria;
        while(CartaElejidaContraria<1||CartaElejidaContraria>5||(CartaElejidaContraria+4)==CartaBloqueadas[0])
                {
                    if((CartaElejidaContraria+4)==CartaBloqueadas[0]) {
                        cout << "Esta Carta esta esta bloqueada por parte del rival elije otra >";
                        cin >> CartaElejidaContraria;
                    }
                    else {
                    cout << "Ingrese un numero correcto >";
                    cin >> CartaElejidaContraria;
                    }

                }



        CartaElejidaContraria=CartaElejidaContraria+4;
        CartaElejida=CartaElejida-1;

        AuxBaraJugadores[CartaElejida]=BarajaJugadores[CartaElejida];
        BarajaJugadores[CartaElejida]=BarajaJugadores[CartaElejidaContraria];
        BarajaJugadores[CartaElejidaContraria]=AuxBaraJugadores[CartaElejida];

        UltimaCarta1=1;
        RoboDeCarta1=true;


        break;
    case 4:
    cout << "Dado numero: "<< DadoRandom <<endl<<endl;
    cout << "____________________________________________________________________________________________"<<endl<<endl;
        cout << "***Elegir una carta de tu propio corral e intercambiarla por una de tu mismo corral (1-5)***"<<endl<<endl;
        cout<< "Tus cartas: "<<endl<<endl;

         for (int x=0; x<5; x++)
        {
            cout << "#"<< x+1 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
         cout <<endl<<endl;

        cout << "Elija la primer carta de su mazo >";
        cin >> CartaElejida;
        while(CartaElejida<1||CartaElejida>5)
        {
            cout << "Ingrese un numero correcto >";
            cin >> CartaElejida;

        }

        cout << "Elija la segunda carta de su mazo >";
        cin >> CartaElejidaContraria;
        while(CartaElejida<1||CartaElejida>5)
        {
            cout << "Ingrese un numero correcto >";
            cin >> CartaElejidaContraria;

        }
        CartaElejida=CartaElejida-1;
        CartaElejidaContraria=CartaElejidaContraria-1;

        AuxBaraJugadores[CartaElejida]=BarajaJugadores[CartaElejida];
        BarajaJugadores[CartaElejida]=BarajaJugadores[CartaElejidaContraria];
        BarajaJugadores[CartaElejidaContraria]=AuxBaraJugadores[CartaElejida];

        break;
    case 5:
    cout << "Dado numero: "<< DadoRandom <<endl<<endl;
    cout << "____________________________________________________________________________________________"<<endl<<endl;
        cout << "***Elije una carta de tu propia corral y bloqueala para que tu rival no pueda modificarla  (1-5)***"<<endl<<endl;
        cout<< "Tus cartas: "<<endl<<endl;

        for (int x=0; x<5; x++)
        {
            cout << "#"<< x+1 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
         cout << endl;

        cout << "Seleccione la carta >";
        cin >> CartaElejida;
        while(CartaElejida<1||CartaElejida>5)
        {
            cout << "Ingrese un numero correcto >";
            cin >> CartaElejida;

        }

        CartaElejida=CartaElejida-1;

        CartaBloqueadas[1]=CartaElejida;
        break;
    case 6:
        break;
    }
    if (DadoRandom==6) {
            cout <<endl;
            cout << "Jugador pasa de turno X.x";
            cout << endl;
            cout << "Presione cualquier tecla para continuar";
            rlutil::anykey();
            TurnoVictoria=true;
    }

}

bool FuncionPrimerJugador(int BarajaJugadores[],int Mazo[])
{
    // Ases
    int ContadorA=0,ContadorA2=0;

    for (int i=0; i<5; i++)
    {
        if (BarajaJugadores[i]==16||BarajaJugadores[i]==17||BarajaJugadores[i]==18||BarajaJugadores[i]==19)
        {
            ContadorA++;
        }

    }
    for (int i=4; i<9; i++)
    {
        if (BarajaJugadores[i]==16||BarajaJugadores[i]==17||BarajaJugadores[i]==18||BarajaJugadores[i]==19)
        {
            ContadorA2++;
        }
    }
    if (ContadorA>ContadorA2)
    {
        return true;
    }
    if (ContadorA2>ContadorA)
    {
        return false;
    }

    //Ks
    int ContadorK=0,ContadorK2=0;

    for (int i=0; i<5; i++)
    {
        if (BarajaJugadores[i]==12||BarajaJugadores[i]==13||BarajaJugadores[i]==14||BarajaJugadores[i]==15)
        {
            ContadorK++;
        }

    }
    for (int i=4; i<9; i++)
    {
        if (BarajaJugadores[i]==12||BarajaJugadores[i]==13||BarajaJugadores[i]==14||BarajaJugadores[i]==15)
        {
            ContadorK2++;
        }
    }
    if (ContadorK>ContadorK2)
    {
        return true;
    }
    if (ContadorK2>ContadorK)
    {
        return false;
    }
    //Qs
    int ContadorQ=0,ContadorQ2=0;

    for (int i=0; i<5; i++)
    {
        if (BarajaJugadores[i]==8||BarajaJugadores[i]==9||BarajaJugadores[i]==10||BarajaJugadores[i]==11)
        {
            ContadorQ++;
        }

    }
    for (int i=4; i<9; i++)
    {
        if (BarajaJugadores[i]==8||BarajaJugadores[i]==9||BarajaJugadores[i]==10||BarajaJugadores[i]==11)
        {
            ContadorQ2++;
        }
    }
    if (ContadorQ>ContadorQ2)
    {
        return true;
    }
    if (ContadorQ2>ContadorQ)
    {
        return false;
    }

    //Js

    int ContadorJ=0,ContadorJ2=0;

    for (int i=0; i<5; i++)
    {
        if (BarajaJugadores[i]==4||BarajaJugadores[i]==5||BarajaJugadores[i]==6||BarajaJugadores[i]==7)
        {
            ContadorJ++;
        }

    }
    for (int i=4; i<9; i++)
    {
        if (BarajaJugadores[i]==4||BarajaJugadores[i]==5||BarajaJugadores[i]==6||BarajaJugadores[i]==7)
        {
            ContadorJ2++;
        }
    }
    if (ContadorJ>ContadorJ2)
    {
        return true;
    }
    if (ContadorJ2>ContadorJ)
    {
        return false;
    }
}

void FuncionMostrarMano2(string MazoNombres[20],int BarajaJugadores[10])
{

    for (int x=0; x<5; x++)
    {
        cout << "#"<< x+1 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
    }

}
void FuncionMostrarMano1(string MazoNombres[20],int BarajaJugadores[10])
{

    for (int x=5; x<10; x++)
    {
        cout << "#"<< x-4 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
    }

}

void FuncionOpcionesDejuego(char Presionar) {
    cout << "-------------------------------------------------------------------------"<<endl;
                cout << "Dado numero <6> puedes seleccionar el juego que quieras o puedes pasar de turno "<<endl;
                cout << "Marque cualquier tecla para ver opciones de juego >";
                rlutil:: anykey();
                cout << "-------------------------------------------------------------------------"<<endl;
                cout << "1> Elegir una carta de tu propio corral y robar una carta del mazo "<<endl;
                cout << "2> Elegir una carta del corral contrario y robar una carta del mazo "<<endl;
                cout << "3> Elegir una carta de tu propio corral y robar una del corral contrario "<<endl;
                cout << "4> Elegir una carta de tu propio corral e intercambiarla por una de tu mismo corral "<<endl;
                cout << "5> Elije una carta de tu propia corral y bloqueala para que tu rival no pueda modificarla "<<endl;
                cout << "6> Pasar turno"<<endl;
                cout << "-------------------------------------------------------------------------"<<endl;
                cout << "Su opcion >";

}


void MezclarMazoRestante(int Mazo[20]) {

    int BarajaAuxiliar[10]={};

    for (int x=10;x<14;x++) {

    BarajaAuxiliar[x]=Mazo[x];
    Mazo[x]=Mazo[x+4];
    Mazo[x+4]=BarajaAuxiliar[x];
    }

    BarajaAuxiliar[10]=Mazo[10];
    Mazo[10]=Mazo[19];
    Mazo[19]=BarajaAuxiliar[10];

    BarajaAuxiliar[11]=Mazo[11];
    Mazo[11]=Mazo[18];
    Mazo[18]=BarajaAuxiliar[11];

    BarajaAuxiliar[12]=Mazo[12];
    Mazo[12]=Mazo[17];
    Mazo[17]=BarajaAuxiliar[12];

    BarajaAuxiliar[13]=Mazo[13];
    Mazo[13]=Mazo[16];
    Mazo[16]=BarajaAuxiliar[13];

    BarajaAuxiliar[14]=Mazo[14];
    Mazo[14]=Mazo[15];
    Mazo[15]=BarajaAuxiliar[14];



}

void MostrarLogo() {

    rlutil::locate(17, 2);
    cout << "Bienvenidos a:"<<endl;
    rlutil::locate(22, 3);
    cout << "              ,,                                 ,,        "<<endl;
    rlutil::locate(22, 4);
    cout << "  .g8```bgd `7MM                mm             `7MM        "<<endl;
    rlutil::locate(22, 5);
    cout << ".dP'     `M   MM                MM               MM        "<<endl;
     rlutil::locate(22, 6);
    cout << "dM'       `   MM  `7MM  `7MM  mmMMmm   ,p6`bo    MMpMMMb.  "<<endl;
     rlutil::locate(22, 7);
    cout << "MM            MM    MM    MM    MM    6M'  OO    MM    MM  "<<endl;
     rlutil::locate(22, 8);
    cout << "MM            MM    MM    MM    MM    6M'  OO    MM    MM  "<<endl;
     rlutil::locate(22, 9);
    cout << "`Mb.     ,'   MM    MM    MM    MM    YM.    ,   MM    MM  "<<endl;
     rlutil::locate(22, 10);
    cout << "  ``bmmmd'  .JMML.  `Mbod`YML.  `Mbmo  YMbmd'  .JMML  JMML."<<endl;
     rlutil::locate(22, 12);
    cout << "                                                By Simon Nomis"<<endl;
    cout <<endl<<endl<<endl;

}

void Creditos(){


 cout << "Grupo 42"<<endl<<endl;
 cout << "Alejo ledesma y Jeremias Farias"<<endl<<endl;
char Presionar;
cout << "Ingrese cualquier tecla para volver al menu"<<endl<<endl;
rlutil:: anykey();
int PartidasGanadas1;
     int PartidasGanadas2;
     int TotalPuntos1=0;
     int TotalPuntos2=0;

    bool PrimerPartida=true;
    string Jugador1,Jugador2;

    FuncionMenu(PrimerPartida,Jugador1,Jugador2,PartidasGanadas1,PartidasGanadas2,TotalPuntos1,TotalPuntos2);

}


void FuncionEstadisticas(int TotalPuntos1,int TotalPuntos2,int PartidasGanadas1,int PartidasGanadas2,string  Jugador1,string  Jugador2,bool PrimerPartida) {

system("cls");
cout << "Estadisticas del jugador " << Jugador1<<endl;
cout << "Total puntos acumulados: " << TotalPuntos1<<endl;
cout << "Partidas ganadas: " << PartidasGanadas1<<endl;

cout << endl<<endl;

cout << "Estadisticas del jugador " << Jugador2<<endl;
cout << "Total puntos acumulados: " << TotalPuntos2<<endl;
cout << "Partidas ganadas: " << PartidasGanadas2<<endl;

 cout << "Ingrese cualquier tecla para volver al menu"<<endl<<endl;
rlutil:: anykey();

    FuncionMenu(PrimerPartida,Jugador1,Jugador2,PartidasGanadas1,PartidasGanadas2,TotalPuntos1,TotalPuntos2);






}


