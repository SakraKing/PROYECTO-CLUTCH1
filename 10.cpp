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

void FuncionMenu(bool & PrimerPartida,string & Jugador1,string & Jugador2,int &PartidasGanadas1,int &PartidasGanadas2,int &TotalPuntos1,int &TotalPuntos2);

void FuncionJugar(bool & PrimerPartida,string & Jugador1,string & Jugador2,int &PartidasGanadas1,int &PartidasGanadas2,int &TotalPuntos1,int &TotalPuntos2);

void FuncionNombres(string&Jugador1,string&Jugador2);

void FuncionNombresElejidos(string&Jugador1,string&Jugador2);

void FuncionMezclarBaraja(int Mazo[20],int CartaRandom,int MazoRestante[10],int BarajaJugadores[10]);

bool Verificar( int CartaRandom,int BarajaJugadores[20]);

void FuncionRepartirCartas(int BarajaJugadores[10],int Mazo[20],int MazoRestante[10]);

int FuncionJuegoTerminado(int BarajaJugadores[10]);

void FuncionCambiosJugador1(int CartaBloqueadas[2],char Presionar,int Mazo[10],int BarajaJugadores[10],string PrimerTurno,string MazoNombres[20],int AuxBaraJugadores[],int MazoRestante[],int &UltimaCarta1,bool & TurnoVictoria,bool &TurnoVictoria2,bool &RoboDeCarta1,bool &RoboDeCarta2);

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

void FuncionMenu(bool & PrimerPartida,string & Jugador1,string & Jugador2,int &PartidasGanadas1,int &PartidasGanadas2,int &TotalPuntos1,int &TotalPuntos2) // Funcion Menu de juego.
{

    int Menu;
    system("cls");
    MostrarLogo();

    // do {
    int op=1;
    int y=0;


    do
    {
        rlutil::hidecursor();



        cout <<endl;
        rlutil::locate(40, 16);
        cout << "1 - JUGAR"<<endl;
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(40, 17);
        cout << "2 - ESTADISTICAS"<<endl;
        rlutil::setColor(rlutil::GREEN);
        rlutil::locate(40, 18);
        cout << "3 - CREDITOS"<<endl;
        cout <<endl;
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(40, 19);
        cout << "0 - SALIR"<<endl;

        rlutil::setColor(rlutil::GREEN);
        rlutil::locate(38, 16+y);
        cout << (char)158<<endl;

        switch(rlutil:: getkey())
        {
        case 14://up
            rlutil::locate(38, 16+y);
            cout << " "<<endl;
            y--;
            if(y<0)
            {
                y = 0;
            }
            break;
        case 15://up
            rlutil::locate(38, 16+y);
            cout << " "<<endl;
            y++;
            if(y>3)
            {
                y = 3;
            }
            break;
        case 1:
            switch(y)
            {
            case 0:
                Menu=1;
                op=0;
                break;
            case 1:
                Menu=2;
                op=0;
                break;
            case 2:
                Menu=3;
                op=0;
                break;
            case 3:
                Menu=0;
                op=0;
                break;
            default:
                break;

            }

            break;
        default:
            break;
        }
        //  system("cls");

    }
    while(op!=0);

    rlutil::CursorHider();

    /* cin >> Menu;
     rlutil::setColor(rlutil::GREEN);*/
    //} while(Menu!=1&&Menu!=2&&Menu!=3&&Menu!=0);

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
       // Creditos();
        break;
    case 0:

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

    do
    {
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
    }
    while (BarajaJugadores[0]<4&&BarajaJugadores[1]>=4&&BarajaJugadores[1]<=7&&BarajaJugadores[2]>=8&&BarajaJugadores[2]<=11&&BarajaJugadores[3]>=12&&BarajaJugadores[3]<=15&&BarajaJugadores[4]>=16&&BarajaJugadores[4]<20||BarajaJugadores[4]<4&&BarajaJugadores[5]>=4&&BarajaJugadores[5]<=7&&BarajaJugadores[6]>=8&&BarajaJugadores[6]<=11&&BarajaJugadores[7]>=12&&BarajaJugadores[7]<=15&&BarajaJugadores[8]>=16&&BarajaJugadores[8]<20);

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
        rlutil::setColor(rlutil::YELLOW);
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
        {
            rlutil::locate(60, x+4);
            BarajaJugadores[x];
            cout << "#" << x-4 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
        cout << endl;
        rlutil::setColor(rlutil::GREEN);

        // Muestro Mazo restante

        // cout << "Mazo es: "<<endl<<endl;
        for(int i=0; i<10; i++)
        {
            // cout <<  MazoNombres[MazoRestante[i]] << " ";
        }


        char Presionar;
        cout << endl<<endl;
        cout << "       |_____________________________________________________________________________"<<endl;
        cout << endl;
        rlutil::setColor(rlutil::YELLOW);

        cout << "                                 Turno del jugador: ";
        rlutil::setColor(rlutil::GREEN);

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
            cout << "                     Preciona cualquier tecla para lanzar el dado >";
            rlutil:: anykey();
            cout << endl;

            int op=1;
            int op2=1;
            int y=0;
            int DadoRandom;
            DadoRandom = rand () % 6;
            DadoRandom=DadoRandom+1;
            //DadoRandom=6;
            int CartaElejida;
            int CartaElejidaContraria;
            int Pick;

            if (DadoRandom==6)
            {
                FuncionOpcionesDejuego(Presionar);


                cin >> DadoRandom;
                while(DadoRandom<1||DadoRandom>7)
                {
                    cout << "Marque una opcion correcta (1-6) ";
                    cin >> DadoRandom;
                }
            }



            // system("cls");
            switch(DadoRandom)
            {

            case 1:
                cout << endl;
                rlutil::setColor(rlutil::YELLOW);
                cout << "                                       Dado numero: "<< DadoRandom <<endl<<endl;
                rlutil::setColor(rlutil::GREEN);
                cout << "     _____________________________________________________________________________________"<<endl<<endl;
                rlutil::locate(10,27);

                cout << "***Elegir una carta de tu propio corral y robar una carta del mazo (1-5)***"<<endl<<endl;
                rlutil::locate(40,29);
                cout<< "Tus cartas: "<<endl<<endl;
                rlutil::setColor(rlutil::YELLOW);
                for (int x=5; x<10; x++)
                {
                    rlutil::locate(40,26+x);
                    cout << "#"<< x-4<<" " << MazoNombres[BarajaJugadores[x]]<<endl;
                }

                do
        {
            rlutil::hidecursor();
            rlutil::setColor(rlutil::GREEN);
            rlutil::locate(38, 31+y);
            cout << (char)158<<endl;

            switch(rlutil:: getkey())
            {
            case 14://up
                rlutil::locate(38, 31+y);
                cout << " "<<endl;
                y--;
                if(y<0)
                {
                    y = 0;
                }
                break;
            case 15://up
                rlutil::locate(38, 31+y);
                cout << " "<<endl;
                y++;
                if(y>4)
                {
                    y = 4;
                }
                break;
            case 1:
                switch(y)
                {
                case 0:
                    CartaElejida=1;
                    op=0;
                    break;
                case 1:
                    CartaElejida=2;
                    op=0;
                    break;
                case 2:
                    CartaElejida=3;
                    op=0;
                    break;
                case 3:
                    CartaElejida=4;
                    op=0;
                    break;
                case 4:
                    CartaElejida=5;
                    op=0;
                    break;
                default:
                    break;

                }

                break;
            default:
                break;
            }

        }
        while(op!=0);

                CartaElejida=CartaElejida+4;

                srand(time(NULL));
                Pick=((rand() % 9));
                AuxBaraJugadores[CartaElejida]=BarajaJugadores[CartaElejida];
                BarajaJugadores[CartaElejida]=MazoRestante[Pick];
                MazoRestante[Pick]=AuxBaraJugadores[CartaElejida];


                break;
            case 2:
                cout << endl;
                rlutil::setColor(rlutil::YELLOW);
                cout << "                                       Dado numero: "<< DadoRandom <<endl<<endl;
                rlutil::setColor(rlutil::GREEN);
                cout << "     _____________________________________________________________________________________"<<endl<<endl;
                rlutil::locate(10,27);
                cout << "***Elegir una carta del corral contrario y robar una carta del mazo (1-5)***"<<endl<<endl;
                rlutil::setColor(rlutil::YELLOW);
                rlutil::locate(37,29);
                cout<< "Cartas Contrarias: "<<endl<<endl;

                FuncionMostrarMano2(MazoNombres,BarajaJugadores);
              do {
                do
        {
            rlutil::hidecursor();
            rlutil::setColor(rlutil::GREEN);
            rlutil::locate(38, 31+y);
            cout << (char)158<<endl;

            switch(rlutil:: getkey())
            {
            case 14://up
                rlutil::locate(38, 31+y);
                cout << " "<<endl;
                y--;
                if(y<0)
                {
                    y = 0;
                }
                break;
            case 15://up
                rlutil::locate(38, 31+y);
                cout << " "<<endl;
                y++;
                if(y>4)
                {
                    y = 4;
                }
                break;
            case 1:
                switch(y)
                {
                case 0:
                    CartaElejida=1;
                    op=0;
                    break;
                case 1:
                    CartaElejida=2;
                    op=0;
                    break;
                case 2:
                    CartaElejida=3;
                    op=0;
                    break;
                case 3:
                    CartaElejida=4;
                    op=0;
                    break;
                case 4:
                    CartaElejida=5;
                    op=0;
                    break;
                default:
                    break;

                }

                break;
            default:
                break;
            }

        }
        while(op!=0);
              }while((CartaElejida-1)==CartaBloqueadas[1]);


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
                cout << endl;
                rlutil::setColor(rlutil::YELLOW);
                cout << "                                       Dado numero: "<< DadoRandom <<endl<<endl;
                rlutil::setColor(rlutil::GREEN);
                cout << "     _____________________________________________________________________________________"<<endl<<endl;
                rlutil::locate(9,27);
                cout << "***Elegir una carta de tu propio corral y robar una del corral contrario (1-5)***"<<endl<<endl;
                rlutil::locate(29,29);
                cout<< "Tus cartas: "<<endl<<endl;
                rlutil::setColor(rlutil::YELLOW);
                for (int x=5; x<10; x++)
                {
                    rlutil::locate(29,26+x);
                    cout << "#"<< x-4<<" " << MazoNombres[BarajaJugadores[x]]<<endl;
                }
                cout << endl;

                rlutil::setColor(rlutil::GREEN);
                rlutil::locate(50,29);
                cout<< "Cartas contrarias: "<<endl<<endl;
                rlutil::setColor(rlutil::YELLOW);
                for (int x=0; x<5; x++)
                {
                    rlutil::locate(52,31+x);
                    cout << "#"<< x+1 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
                }
                do
        {
            rlutil::hidecursor();
            rlutil::setColor(rlutil::GREEN);
            rlutil::locate(27, 31+y);
            cout << (char)158<<endl;

            switch(rlutil:: getkey())
            {
            case 14://up
                rlutil::locate(27, 31+y);
                cout << " "<<endl;
                y--;
                if(y<0)
                {
                    y = 0;
                }
                break;
            case 15://up
                rlutil::locate(27, 31+y);
                cout << " "<<endl;
                y++;
                if(y>4)
                {
                    y = 4;
                }
                break;
            case 1:
                switch(y)
                {
                case 0:
                    CartaElejida=1;
                    op=0;
                    break;
                case 1:
                    CartaElejida=2;
                    op=0;
                    break;
                case 2:
                    CartaElejida=3;
                    op=0;
                    break;
                case 3:
                    CartaElejida=4;
                    op=0;
                    break;
                case 4:
                    CartaElejida=5;
                    op=0;
                    break;
                default:
                    break;

                }

                break;
            default:
                break;
            }

        }
        while(op!=0);

        do {
        do
        {
            rlutil::hidecursor();
            rlutil::setColor(rlutil::GREEN);
            rlutil::locate(50, 31+y);
            cout << (char)158<<endl;

            switch(rlutil:: getkey())
            {
            case 14://up
                rlutil::locate(50, 31+y);
                cout << " "<<endl;
                y--;
                if(y<0)
                {
                    y = 0;
                }
                break;
            case 15://up
                rlutil::locate(50, 31+y);
                cout << " "<<endl;
                y++;
                if(y>4)
                {
                    y = 4;
                }
                break;
            case 1:
                switch(y)
                {
                case 0:
                    CartaElejidaContraria=1;
                    op2=0;
                    break;
                case 1:
                    CartaElejidaContraria=2;
                    op2=0;
                    break;
                case 2:
                    CartaElejidaContraria=3;
                    op2=0;
                    break;
                case 3:
                    CartaElejidaContraria=4;
                    op2=0;
                    break;
                case 4:
                    CartaElejidaContraria=5;
                    op2=0;
                    break;
                default:
                    break;

                }

                break;
            default:
                break;
            }

        }
        while(op2!=0);

        }while((CartaElejidaContraria-1)==CartaBloqueadas[1]);





                CartaElejida=CartaElejida+4;
                CartaElejidaContraria=CartaElejidaContraria-1;

                AuxBaraJugadores[CartaElejida]=BarajaJugadores[CartaElejida];
                BarajaJugadores[CartaElejida]=BarajaJugadores[CartaElejidaContraria];
                BarajaJugadores[CartaElejidaContraria]=AuxBaraJugadores[CartaElejida];

                UltimaCarta2=1;
                RoboDeCarta2=true;



                break;
            case 4:
                cout << endl;
                rlutil::setColor(rlutil::YELLOW);
                cout << "                                       Dado numero: "<< DadoRandom <<endl<<endl;
                rlutil::setColor(rlutil::GREEN);
                cout << "     _____________________________________________________________________________________"<<endl<<endl;
                rlutil::locate(10,27);
                cout << "***Elegir una carta de tu propio corral e intercambiarla por una de tu mismo corral  (1-5)***"<<endl<<endl;
                rlutil::locate(40,29);
                cout<< "Tus cartas: "<<endl<<endl;
                rlutil::setColor(rlutil::YELLOW);
                for (int x=5; x<10; x++)
                {
                    rlutil::locate(40,26+x);
                    cout << "#"<< x-4 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
                }


                do
        {
            rlutil::hidecursor();
            rlutil::setColor(rlutil::GREEN);
            rlutil::locate(38, 31+y);
            cout << (char)158<<endl;

            switch(rlutil:: getkey())
            {
            case 14://up
                rlutil::locate(38, 31+y);
                cout << " "<<endl;
                y--;
                if(y<0)
                {
                    y = 0;
                }
                break;
            case 15://up
                rlutil::locate(38, 31+y);
                cout << " "<<endl;
                y++;
                if(y>4)
                {
                    y = 4;
                }
                break;
            case 1:
                switch(y)
                {
                case 0:
                    CartaElejida=1;
                    rlutil::locate(38, 31);
                    cout << (char)158<<endl;
                    op=0;
                    break;
                case 1:
                    CartaElejida=2;
                    rlutil::locate(38, 32);
                    cout << (char)158<<endl;
                    op=0;
                    break;
                case 2:
                    CartaElejida=3;
                    rlutil::locate(38, 33);
                    cout << (char)158<<endl;
                    op=0;
                    break;
                case 3:
                    CartaElejida=4;
                    rlutil::locate(38, 34);
                    cout << (char)158<<endl;
                    op=0;
                    break;
                case 4:
                    CartaElejida=5;
                    rlutil::locate(38, 35);
                    cout << (char)158<<endl;
                    op=0;
                    break;
                default:
                    break;

                }

                break;
            default:
                break;
            }

        }
        while(op!=0);

        do
        {
            rlutil::hidecursor();
            rlutil::setColor(rlutil::YELLOW);
            rlutil::locate(38, 31+y);
            cout << (char)158<<endl;

            switch(rlutil:: getkey())
            {
            case 14://up
                rlutil::locate(38, 31+y);
                cout << " "<<endl;
                y--;
                if(y<0)
                {
                    y = 0;
                }
                break;
            case 15://up
                rlutil::locate(38, 31+y);
                cout << " "<<endl;
                y++;
                if(y>4)
                {
                    y = 4;
                }
                break;
            case 1:
                switch(y)
                {
                case 0:
                    CartaElejidaContraria=1;
                    op2=0;

                    break;
                case 1:
                    CartaElejidaContraria=2;
                    op2=0;

                    break;
                case 2:
                    CartaElejidaContraria=3;
                    op2=0;

                    break;
                case 3:
                    CartaElejidaContraria=4;
                    op2=0;

                    break;
                case 4:
                CartaElejidaContraria=5;

                    op2=0;
                    break;
                default:
                    break;

                }

                break;
            default:
                break;
            }

        }
        while(op2!=0);

                CartaElejida=CartaElejida+4;
                CartaElejidaContraria=CartaElejidaContraria+4;
                rlutil::setColor(rlutil::GREEN);

                AuxBaraJugadores[CartaElejida]=BarajaJugadores[CartaElejida];
                BarajaJugadores[CartaElejida]=BarajaJugadores[CartaElejidaContraria];
                BarajaJugadores[CartaElejidaContraria]=AuxBaraJugadores[CartaElejida];
                break;
            case 5:
                cout << endl;
                rlutil::setColor(rlutil::YELLOW);
                cout << "                                       Dado numero: "<< DadoRandom <<endl<<endl;
                rlutil::setColor(rlutil::GREEN);
                cout << "     _____________________________________________________________________________________"<<endl<<endl;
                rlutil::locate(2,27);
                cout << "***Elije una carta de tu propia corral y bloqueala para que tu rival no pueda modificarla  (1-5)***"<<endl<<endl;
                rlutil::locate(40,29);
                rlutil::setColor(rlutil::YELLOW);
                cout<< "Tus cartas: "<<endl<<endl;

                FuncionMostrarMano1(MazoNombres,BarajaJugadores);
                do
        {
            rlutil::hidecursor();
            rlutil::setColor(rlutil::GREEN);
            rlutil::locate(38, 31+y);
            cout << (char)158<<endl;

            switch(rlutil:: getkey())
            {
            case 14://up
                rlutil::locate(38, 31+y);
                cout << " "<<endl;
                y--;
                if(y<0)
                {
                    y = 0;
                }
                break;
            case 15://up
                rlutil::locate(38, 31+y);
                cout << " "<<endl;
                y++;
                if(y>4)
                {
                    y = 4;
                }
                break;
            case 1:
                switch(y)
                {
                case 0:
                    CartaElejida=1;
                    op=0;
                    break;
                case 1:
                    CartaElejida=2;
                    op=0;
                    break;
                case 2:
                    CartaElejida=3;
                    op=0;
                    break;
                case 3:
                    CartaElejida=4;
                    op=0;
                    break;
                case 4:
                    CartaElejida=5;
                    op=0;
                    break;
                default:
                    break;

                }

                break;
            default:
                break;
            }

        }
        while(op!=0);
                CartaElejida=CartaElejida+4;

                CartaBloqueadas[0]=CartaElejida;

                rlutil::setColor(rlutil::GREEN);

                break;
            case 6:

                break;
            }

            if (DadoRandom==6)
            {
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


        switch (FuncionJuegoTerminado(BarajaJugadores))
        {
        case 1:
            cout << "El ganador es: "<< Jugador1<<endl;
            JuegoTerminado=true;
            PrimerPartida=false;

            PartidasGanadas1++;
            if (TurnoVictoria==false)
            {
                TotalPuntos1=TotalPuntos1+10;
            }


            TotalPuntos1=TotalPuntos1+15;
            if (UltimaCarta1==1)
            {
                TotalPuntos1=TotalPuntos1+10;
            }

            if(RoboDeCarta2==false)
            {
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

            if (UltimaCarta2==1)
            {
                TotalPuntos2=TotalPuntos2+10;
            }

            if (TurnoVictoria2==false)
            {
                TotalPuntos2=TotalPuntos2+10;
            }

            if(RoboDeCarta1==false)
            {
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

    rlutil::locate(25, 15);
    cout << "Para comenzar Ingrese los nombres de los jugadores >"<<endl<<endl<<endl;
    rlutil::setColor(rlutil::YELLOW);

    do
    {
        if (Entrada==false)
        {
            system("cls");
            MostrarLogo();
            rlutil::locate(27, 15);
            cout << "Ingrese nuevamente los nombres de usuario >"<<endl<<endl;
        }
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(47, 17);
        cout << "jugador #1 >";
        rlutil::setColor(rlutil::GREEN);
        cin >> Jugador1;

        cout << endl;
        rlutil::locate(47, 18);
        rlutil::setColor(rlutil::YELLOW);
        cout << "jugador #2 >";
        rlutil::setColor(rlutil::GREEN);
        cin >> Jugador2;
        cout << endl;

        system("cls");
        MostrarLogo();
        rlutil::locate(47, 17);
        rlutil::setColor(rlutil::YELLOW);
        cout << "Jugador #1: " << Jugador1 <<endl;
        rlutil::locate(47, 18);
        cout << "Jugador #2: " << Jugador2 <<endl;
        rlutil::setColor(rlutil::GREEN);


        rlutil::locate(31, 15);
        cout << "Desea confirmar los nombres? y/n >";
        rlutil::setColor(rlutil::YELLOW);
        cin >> Confirmacion;

        rlutil::setColor(rlutil::GREEN);

        Entrada=false;
    }
    while (Confirmacion!='Y'&&Confirmacion!='y');

    system("cls");


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
    else
    {
        return 0;
    }

}

void FuncionCambiosJugador1(int CartaBloqueadas[2],char Presionar,int Mazo[10],int BarajaJugadores[10],string PrimerTurno,string MazoNombres[20],int AuxBaraJugadores[],int MazoRestante[],int &UltimaCarta1,bool & TurnoVictoria,bool &TurnoVictoria2bool,bool &RoboDeCarta1,bool &RoboDeCarta2)
{

    //cout << "Lanzador: " << PrimerTurno << " "<<endl;
    cout << endl;
    cout << "                      Preciona cualquier tecla para lanzar el dado >";
    rlutil:: anykey();
    cout << endl;


    int op=1;
    int op2=1;
    int y=0;
    int Pick;
    int DadoRandom;
    DadoRandom = rand () % 6;
    DadoRandom=DadoRandom+1;
    //DadoRandom=6;
    int CartaElejida;
    int CartaElejidaContraria;

    if (DadoRandom==6)
    {
        FuncionOpcionesDejuego(Presionar);


        cin >> DadoRandom;
        while(DadoRandom<1||DadoRandom>7)
        {
            cout << "Marque una opcion correcta (1-6) ";
            cin >> DadoRandom;
        }
    }
    //system("cls");
    switch(DadoRandom)
    {
    case 1:
        cout << endl;
        rlutil::setColor(rlutil::YELLOW);
        cout << "                                       Dado numero: "<< DadoRandom <<endl<<endl;
        rlutil::setColor(rlutil::GREEN);
        cout << "____________________________________________________________________________________________"<<endl<<endl;
        rlutil::locate(10,27);
        cout << "***Elegir una carta de tu propio corral y robar una carta del mazo (1-5)***"<<endl<<endl;
        rlutil::locate(40,29);
        cout<< "Tus cartas: "<<endl<<endl;
        rlutil::setColor(rlutil::YELLOW);

        for (int x=0; x<5; x++)
        {
            rlutil::locate(40,31+x);
            cout << "#"<< x+1 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }



        do
        {
            rlutil::hidecursor();
            rlutil::setColor(rlutil::GREEN);
            rlutil::locate(38, 31+y);
            cout << (char)158<<endl;

            switch(rlutil:: getkey())
            {
            case 14://up
                rlutil::locate(38, 31+y);
                cout << " "<<endl;
                y--;
                if(y<0)
                {
                    y = 0;
                }
                break;
            case 15://up
                rlutil::locate(38, 31+y);
                cout << " "<<endl;
                y++;
                if(y>4)
                {
                    y = 4;
                }
                break;
            case 1:
                switch(y)
                {
                case 0:
                    CartaElejida=1;
                    op=0;
                    break;
                case 1:
                    CartaElejida=2;
                    op=0;
                    break;
                case 2:
                    CartaElejida=3;
                    op=0;
                    break;
                case 3:
                    CartaElejida=4;
                    op=0;
                    break;
                case 4:
                    CartaElejida=5;
                    op=0;
                    break;
                default:
                    break;

                }

                break;
            default:
                break;
            }

        }
        while(op!=0);



        CartaElejida=CartaElejida-1;
        srand(time(NULL));

        Pick=((rand() % 9));
        AuxBaraJugadores[CartaElejida]=BarajaJugadores[CartaElejida];
        BarajaJugadores[CartaElejida]=MazoRestante[Pick];
        MazoRestante[Pick]=AuxBaraJugadores[CartaElejida];

        break;
    case 2:
        cout <<endl;
        rlutil::setColor(rlutil::YELLOW);
        cout << "                                       Dado numero: "<< DadoRandom <<endl<<endl;
        rlutil::setColor(rlutil::GREEN);
        cout << "     _____________________________________________________________________________________"<<endl<<endl;
        rlutil::locate(10,27);
        cout << "***Elegir una carta del corral contrario y robar una carta del mazo (1-5)***"<<endl<<endl;
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(37,29);
        cout<< "Cartass contrarias: "<<endl<<endl;

        for (int x=5; x<10; x++)
        {
            rlutil::locate(40,26+x);
            cout << "#"<< x-4<<" " << MazoNombres[BarajaJugadores[x]]<<endl;
        }

        do {
        do
        {
            rlutil::hidecursor();
            rlutil::setColor(rlutil::GREEN);
            rlutil::locate(38, 31+y);
            cout << (char)158<<endl;

            switch(rlutil:: getkey())
            {
            case 14://up
                rlutil::locate(38, 31+y);
                cout << " "<<endl;
                y--;
                if(y<0)
                {
                    y = 0;
                }
                break;
            case 15://up
                rlutil::locate(38, 31+y);
                cout << " "<<endl;
                y++;
                if(y>4)
                {
                    y = 4;
                }
                break;
            case 1:
                switch(y)
                {
                case 0:
                    CartaElejida=1;
                    op=0;
                    break;
                case 1:
                    CartaElejida=2;
                    op=0;
                    break;
                case 2:
                    CartaElejida=3;
                    op=0;
                    break;
                case 3:
                    CartaElejida=4;
                    op=0;
                    break;
                case 4:
                    CartaElejida=5;
                    op=0;
                    break;
                default:
                    break;

                }

                break;
            default:
                break;
            }

        }
        while(op!=0);

        } while((CartaElejida+4)==CartaBloqueadas[0]);

        CartaElejida=CartaElejida+4;
        // CartaElejida=CartaElejida-1;

        srand(time(NULL));
        Pick=((rand() % 9));
        AuxBaraJugadores[CartaElejida]=BarajaJugadores[CartaElejida];
        BarajaJugadores[CartaElejida]=MazoRestante[Pick];
        MazoRestante[Pick]=AuxBaraJugadores[CartaElejida];
        break;
    case 3:
        cout << endl;
        rlutil::setColor(rlutil::YELLOW);
        cout << "                                       Dado numero: "<< DadoRandom <<endl<<endl;
        rlutil::setColor(rlutil::GREEN);
        cout << "____________________________________________________________________________________________"<<endl<<endl;
        cout << "***Elegir una carta de tu propio corral y robar una del corral contrario (1-5)***"<<endl<<endl;
        rlutil::locate(29,29);
        cout<< "Tus cartas: "<<endl<<endl;
        rlutil::setColor(rlutil::YELLOW);

        for (int x=0; x<5; x++)
        {
            rlutil::locate(29,31+x);
            cout << "#"<< x+1 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
        cout << endl;

        rlutil::locate(50,29);
        cout<< "Cartas contrarias: "<<endl<<endl;


        for (int x=5; x<10; x++)
        {
            rlutil::locate(52,26+x);
            cout << "#"<< x-4<<" " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
        do
        {
            rlutil::hidecursor();
            rlutil::setColor(rlutil::GREEN);
            rlutil::locate(27, 31+y);
            cout << (char)158<<endl;

            switch(rlutil:: getkey())
            {
            case 14://up
                rlutil::locate(27, 31+y);
                cout << " "<<endl;
                y--;
                if(y<0)
                {
                    y = 0;
                }
                break;
            case 15://up
                rlutil::locate(27, 31+y);
                cout << " "<<endl;
                y++;
                if(y>4)
                {
                    y = 4;
                }
                break;
            case 1:
                switch(y)
                {
                case 0:
                    CartaElejida=1;
                    op=0;
                    break;
                case 1:
                    CartaElejida=2;
                    op=0;
                    break;
                case 2:
                    CartaElejida=3;
                    op=0;
                    break;
                case 3:
                    CartaElejida=4;
                    op=0;
                    break;
                case 4:
                    CartaElejida=5;
                    op=0;
                    break;
                default:
                    break;

                }

                break;
            default:
                break;
            }

        }
        while(op!=0);

        do {
        do
        {
            rlutil::hidecursor();
            rlutil::setColor(rlutil::GREEN);
            rlutil::locate(50, 31+y);
            cout << (char)158<<endl;

            switch(rlutil:: getkey())
            {
            case 14://up
                rlutil::locate(50, 31+y);
                cout << " "<<endl;
                y--;
                if(y<0)
                {
                    y = 0;
                }
                break;
            case 15://up
                rlutil::locate(50, 31+y);
                cout << " "<<endl;
                y++;
                if(y>4)
                {
                    y = 4;
                }
                break;
            case 1:
                switch(y)
                {
                case 0:
                    CartaElejidaContraria=1;
                    op2=0;
                    break;
                case 1:
                    CartaElejidaContraria=2;
                    op2=0;
                    break;
                case 2:
                    CartaElejidaContraria=3;
                    op2=0;
                    break;
                case 3:
                    CartaElejidaContraria=4;
                    op2=0;
                    break;
                case 4:
                    CartaElejidaContraria=5;
                    op2=0;
                    break;
                default:
                    break;

                }

                break;
            default:
                break;
            }

        }
        while(op2!=0);

        }while((CartaElejidaContraria+4)==CartaBloqueadas[0]);




        CartaElejidaContraria=CartaElejidaContraria+4;
        CartaElejida=CartaElejida-1;

        AuxBaraJugadores[CartaElejida]=BarajaJugadores[CartaElejida];
        BarajaJugadores[CartaElejida]=BarajaJugadores[CartaElejidaContraria];
        BarajaJugadores[CartaElejidaContraria]=AuxBaraJugadores[CartaElejida];

        UltimaCarta1=1;
        RoboDeCarta1=true;


        break;
    case 4:
        cout <<endl;
        rlutil::setColor(rlutil::YELLOW);
        cout << "                                       Dado numero: "<< DadoRandom <<endl<<endl;
        rlutil::setColor(rlutil::GREEN);
        cout << "     _____________________________________________________________________________________"<<endl<<endl;
        rlutil::locate(3,27);
        cout << "***Elegir una carta de tu propio corral e intercambiarla por una de tu mismo corral (1-5)***"<<endl<<endl;
        rlutil::locate(40,29);
        cout<< "Tus cartas: "<<endl<<endl;
        rlutil::setColor(rlutil::YELLOW);

        for (int x=0; x<5; x++)
        {
            rlutil::locate(40,31+x);
            cout << "#"<< x+1 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }

        do
        {
            rlutil::hidecursor();
            rlutil::setColor(rlutil::GREEN);
            rlutil::locate(38, 31+y);
            cout << (char)158<<endl;

            switch(rlutil:: getkey())
            {
            case 14://up
                rlutil::locate(38, 31+y);
                cout << " "<<endl;
                y--;
                if(y<0)
                {
                    y = 0;
                }
                break;
            case 15://up
                rlutil::locate(38, 31+y);
                cout << " "<<endl;
                y++;
                if(y>4)
                {
                    y = 4;
                }
                break;
            case 1:
                switch(y)
                {
                case 0:
                    CartaElejida=1;
                    rlutil::locate(38, 31);
                    cout << (char)158<<endl;
                    op=0;
                    break;
                case 1:
                    CartaElejida=2;
                    rlutil::locate(38, 32);
                    cout << (char)158<<endl;
                    op=0;
                    break;
                case 2:
                    CartaElejida=3;
                    rlutil::locate(38, 33);
                    cout << (char)158<<endl;
                    op=0;
                    break;
                case 3:
                    CartaElejida=4;
                    rlutil::locate(38, 34);
                    cout << (char)158<<endl;
                    op=0;
                    break;
                case 4:
                    CartaElejida=5;
                    rlutil::locate(38, 35);
                    cout << (char)158<<endl;
                    op=0;
                    break;
                default:
                    break;

                }

                break;
            default:
                break;
            }

        }
        while(op!=0);

        do
        {
            rlutil::hidecursor();
            rlutil::setColor(rlutil::YELLOW);
            rlutil::locate(38, 31+y);
            cout << (char)158<<endl;

            switch(rlutil:: getkey())
            {
            case 14://up
                rlutil::locate(38, 31+y);
                cout << " "<<endl;
                y--;
                if(y<0)
                {
                    y = 0;
                }
                break;
            case 15://up
                rlutil::locate(38, 31+y);
                cout << " "<<endl;
                y++;
                if(y>4)
                {
                    y = 4;
                }
                break;
            case 1:
                switch(y)
                {
                case 0:
                    CartaElejidaContraria=1;
                    op2=0;

                    break;
                case 1:
                    CartaElejidaContraria=2;
                    op2=0;

                    break;
                case 2:
                    CartaElejidaContraria=3;
                    op2=0;

                    break;
                case 3:
                    CartaElejidaContraria=4;
                    op2=0;

                    break;
                case 4:
                CartaElejidaContraria=5;

                    op2=0;
                    break;
                default:
                    break;

                }

                break;
            default:
                break;
            }

        }
        while(op2!=0);


        CartaElejida=CartaElejida-1;
        CartaElejidaContraria=CartaElejidaContraria-1;
        rlutil::setColor(rlutil::GREEN);

        AuxBaraJugadores[CartaElejida]=BarajaJugadores[CartaElejida];
        BarajaJugadores[CartaElejida]=BarajaJugadores[CartaElejidaContraria];
        BarajaJugadores[CartaElejidaContraria]=AuxBaraJugadores[CartaElejida];

        break;
    case 5:
        rlutil::setColor(rlutil::YELLOW);
        cout << endl;
        cout << "                                       Dado numero: "<< DadoRandom <<endl<<endl;
        rlutil::setColor(rlutil::GREEN);
        cout << "     _____________________________________________________________________________________"<<endl<<endl;
        rlutil::locate(2,27);
        cout << "***Elije una carta de tu propia corral y bloqueala para que tu rival no pueda modificarla  (1-5)***"<<endl<<endl;
        rlutil::locate(40,29);
        rlutil::setColor(rlutil::YELLOW);
        cout<< "Tus cartas: "<<endl<<endl;

        for (int x=0; x<5; x++)
        {
            rlutil::locate(40,31+x);
            cout << "#"<< x+1 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }

        do
        {
            rlutil::hidecursor();
            rlutil::setColor(rlutil::GREEN);
            rlutil::locate(38, 31+y);
            cout << (char)158<<endl;

            switch(rlutil:: getkey())
            {
            case 14://up
                rlutil::locate(38, 31+y);
                cout << " "<<endl;
                y--;
                if(y<0)
                {
                    y = 0;
                }
                break;
            case 15://up
                rlutil::locate(38, 31+y);
                cout << " "<<endl;
                y++;
                if(y>4)
                {
                    y = 4;
                }
                break;
            case 1:
                switch(y)
                {
                case 0:
                    CartaElejida=1;
                    op=0;
                    break;
                case 1:
                    CartaElejida=2;
                    op=0;
                    break;
                case 2:
                    CartaElejida=3;
                    op=0;
                    break;
                case 3:
                    CartaElejida=4;
                    op=0;
                    break;
                case 4:
                    CartaElejida=5;
                    op=0;
                    break;
                default:
                    break;

                }

                break;
            default:
                break;
            }

        }
        while(op!=0);

        CartaElejida=CartaElejida-1;

        CartaBloqueadas[1]=CartaElejida;

        rlutil::setColor(rlutil::GREEN);
        break;
    case 6:
        break;
    }
    if (DadoRandom==6)
    {
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
        rlutil::locate(40,31+x);
        rlutil::setColor(rlutil::YELLOW);
        cout << "#"<< x+1 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
    }

}

void FuncionMostrarMano1(string MazoNombres[20],int BarajaJugadores[10])
{

    for (int x=5; x<10; x++)
    {
        rlutil::locate(40,26+x);
        rlutil::setColor(rlutil::YELLOW);
        cout << "#"<< x-4 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
    }

}

void FuncionOpcionesDejuego(char Presionar)
{

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(1,38);
    cout << "       Dado numero <6> puedes seleccionar el juego que quieras o puedes pasar de turno "<<endl;
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(1,38);
    cout << "                  Marque cualquier tecla para ver opciones de juego >"<<endl;
    rlutil:: anykey();
    rlutil::locate(0,39);
    cout << "     _____________________________________________________________________________________"<<endl<<endl;
    rlutil::setColor(rlutil::YELLOW);
    cout <<endl;
    rlutil::locate(1,41);
    cout << "     1>Elegir una carta de tu propio corral y robar una carta del mazo "<<endl;
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(1,42);
    cout << "     2>Elegir una carta del corral contrario y robar una carta del mazo "<<endl;
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(0,43);
    cout << "     3>legir una carta de tu propio corral y robar una del corral contrario "<<endl;
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(0,44);
    cout << "     4>Elegir una carta de tu propio corral e intercambiarla por una de tu mismo corral "<<endl;
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(0,45);
    cout << "     5>Elije una carta de tu propia corral y bloqueala para que tu rival no pueda modificarla "<<endl;
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(0,46);
    cout << "     6> Pasar turno"<<endl;
    rlutil::locate(0,47);
    cout << "     _____________________________________________________________________________________"<<endl<<endl;
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(0,48);
    cout << "                                        Su opcion >";
    rlutil::setColor(rlutil::GREEN);


}

void MostrarLogo()
{

    rlutil::locate(17, 2);
    rlutil::setColor(rlutil::YELLOW);
    cout << "Bienvenidos a:"<<endl;
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(22, 3);
    cout << "              ,,                                 ,,        "<<endl;
    rlutil::locate(22, 4);
    cout << "  .g8```bgd `7MM                mm             `7MM        "<<endl;
    rlutil::locate(22, 5);
    cout << ".dP'     `M   MM                MM               MM        "<<endl;
    rlutil::locate(22, 6);
    cout << "dM'       `   MM  `7MM  `7MM  mmMMmm   ,p6`bo    MMpMMMb.  "<<endl;
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(22, 7);
    cout << "MM            MM    MM    MM    MM    6M'  OO    MM    MM  "<<endl;
    rlutil::locate(22, 8);
    cout << "MM            MM    MM    MM    MM    6M'  OO    MM    MM  "<<endl;
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(22, 9);
    cout << "`Mb.     ,'   MM    MM    MM    MM    YM.    ,   MM    MM  "<<endl;
    rlutil::locate(22, 10);
    cout << "  ``bmmmd'  .JMML.  `Mbod`YML.  `Mbmo  YMbmd'  .JMML  JMML."<<endl;
    rlutil::locate(22, 12);
    rlutil::setColor(rlutil::YELLOW);
    cout << "                                                By Simon Nomis"<<endl;
    rlutil::setColor(rlutil::GREEN);
    cout <<endl<<endl<<endl;

}

void Creditos()
{

    rlutil::locate(14,25);
    rlutil::setColor(rlutil::WHITE);
    cout << "    Grupo 42  -   "<<endl<<endl;
     rlutil::locate(30,25);
    cout << "  Alejo ledesma (legajo 29813) y Jeremias Farias (Legajo 29762)"<<endl<<endl;
    rlutil:: anykey();
    int PartidasGanadas1;
    int PartidasGanadas2;
    int TotalPuntos1=0;
    int TotalPuntos2=0;

    bool PrimerPartida=true;
    string Jugador1,Jugador2;

    FuncionMenu(PrimerPartida,Jugador1,Jugador2,PartidasGanadas1,PartidasGanadas2,TotalPuntos1,TotalPuntos2);

}

void FuncionEstadisticas(int TotalPuntos1,int TotalPuntos2,int PartidasGanadas1,int PartidasGanadas2,string  Jugador1,string  Jugador2,bool PrimerPartida)
{

    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(14,4);
    cout << "Estadisticas del jugador> " << Jugador1<<endl;
    rlutil::locate(14,10);
    cout << "Total puntos acumulados:   " << TotalPuntos1<<endl;
    rlutil::locate(14,13);
    cout << "Partidas ganadas:          " << PartidasGanadas1<<endl;

    cout << endl<<endl;
    rlutil::locate(64,4);
    rlutil::setColor(rlutil::YELLOW);
    cout << "Estadisticas del jugador> " << Jugador2<<endl;
    rlutil::locate(64,10);
    cout << "Total puntos acumulados:   " << TotalPuntos2<<endl;
    rlutil::locate(64,13);
    cout << "Partidas ganadas:          " << PartidasGanadas2<<endl;

    if (TotalPuntos2>TotalPuntos1) {

        rlutil::locate(25,20);
        cout << "El jugador " << Jugador2 << " es el victorioso por mayoria de puntos"<<endl;

    }

     if (TotalPuntos1>TotalPuntos2) {
        rlutil::locate(27,20);
        cout << "El jugador " << Jugador1 << " es el victorioso por mayoria de puntos"<<endl;

    }

    rlutil::setColor(rlutil::GREEN);

    rlutil::locate(10,5);
    cout <<"_____________________________________"<<endl;
    rlutil::locate(60,5);
    cout <<"_____________________________________"<<endl;
    rlutil::locate(10,17);
    cout <<"_____________________________________"<<endl;
    rlutil::locate(60,17);
    cout <<"_____________________________________"<<endl;

    rlutil::locate(9,6);
    cout << "|";
    rlutil::locate(9,7);
    cout << "|";
    rlutil::locate(9,8);
    cout << "|";
    rlutil::locate(9,9);
    cout << "|";
    rlutil::locate(9,10);
    cout << "|";
    rlutil::locate(9,11);
    cout << "|";
    rlutil::locate(9,12);
    cout << "|";
    rlutil::locate(9,13);
    cout << "|";
    rlutil::locate(9,14);
    cout << "|";
    rlutil::locate(9,15);
    cout << "|";
    rlutil::locate(9,16);
    cout << "|";
    rlutil::locate(9,17);
    cout << "|";

    rlutil::locate(47,6);
    cout << "|";
    rlutil::locate(47,7);
    cout << "|";
    rlutil::locate(47,8);
    cout << "|";
    rlutil::locate(47,9);
    cout << "|";
    rlutil::locate(47,10);
    cout << "|";
    rlutil::locate(47,11);
    cout << "|";
    rlutil::locate(47,12);
    cout << "|";
    rlutil::locate(47,13);
    cout << "|";
    rlutil::locate(47,14);
    cout << "|";
    rlutil::locate(47,15);
    cout << "|";
    rlutil::locate(47,16);
    cout << "|";
    rlutil::locate(47,17);
    cout << "|";

     rlutil::locate(59,6);
    cout << "|";
    rlutil::locate(59,7);
    cout << "|";
    rlutil::locate(59,8);
    cout << "|";
    rlutil::locate(59,9);
    cout << "|";
    rlutil::locate(59,10);
    cout << "|";
    rlutil::locate(59,11);
    cout << "|";
    rlutil::locate(59,12);
    cout << "|";
    rlutil::locate(59,13);
    cout << "|";
    rlutil::locate(59,14);
    cout << "|";
    rlutil::locate(59,15);
    cout << "|";
    rlutil::locate(59,16);
    cout << "|";
    rlutil::locate(59,17);
    cout << "|";

    rlutil::locate(97,6);
    cout << "|";
    rlutil::locate(97,7);
    cout << "|";
    rlutil::locate(97,8);
    cout << "|";
    rlutil::locate(97,9);
    cout << "|";
    rlutil::locate(97,10);
    cout << "|";
    rlutil::locate(97,11);
    cout << "|";
    rlutil::locate(97,12);
    cout << "|";
    rlutil::locate(97,13);
    cout << "|";
    rlutil::locate(97,14);
    cout << "|";
    rlutil::locate(97,15);
    cout << "|";
    rlutil::locate(97,16);
    cout << "|";
    rlutil::locate(97,17);
    cout << "|";
    rlutil::hidecursor();
    rlutil::locate(32,25);
    cout << "Ingrese cualquier tecla para volver al menu";
    rlutil::anykey();
    rlutil::CursorHider();



    FuncionMenu(PrimerPartida,Jugador1,Jugador2,PartidasGanadas1,PartidasGanadas2,TotalPuntos1,TotalPuntos2);






}


