#include <iostream>
using namespace std;
#include <string>
#include<cstdlib>
using std::rand;
using std::srand;
#include<ctime>
using std::time;
using std::time;
// Declaracion de funciones.

int FuncionMenu();

void FuncionJugar();

void FuncionNombres(string&Jugador1,string&Jugador2);

void FuncionMezclarBaraja(int Mazo[20],int CartaRandom,int MazoRestante[10],int BarajaJugadores[10]);

bool Verificar( int CartaRandom,int BarajaJugadores[20])
;

void FuncionRepartirCartas(int BarajaJugadores[10],int Mazo[20],int MazoRestante[10]);

int FuncionJuegoTerminado(int BarajaJugadores[10]);

void FuncionCambiosJugador1(char Presionar,int Mazo[10],int BarajaJugadores[10],string PrimerTurno,string MazoNombres[20],int AuxBaraJugadores[],int MazoRestante[]);

//id FuncionCambiosJugador2(char Presionar,int Mazo[10],int BarajaJugadores[10],string PrimerTurno,string MazoNombres[20],int AuxBaraJugadores[],int MazoRestante[]);
bool FuncionPrimerJugador(int BarajaJugadores[],int Mazo[]);

void FuncionMostrarMano2(string MazoNombres[20],int BarajaJugadores[]);

//void FuncionMazoNombres(string MazoNombres[20]);

//main_______________________________________________________________________________________________________________________
int main ()
{

    switch(FuncionMenu())
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
    return 0;

}
// Funciones__________________________________________________________________________________________________________________

int FuncionMenu() // Funcion Menu de juego.
{

    int Menu;

    cout << "Bienvenidos a Clutch"<<endl;
    cout << "-------------------------------------------------------------------------"<<endl;
    cout << "1 - JUGAR"<<endl;
    cout << "2 - ESTADISTICAS"<<endl;
    cout << "3 - CREDITOS"<<endl;
    cout << "--------------------------"<<endl;
    cout << "0 - SALIR"<<endl;

    cout << ">";
    cin >> Menu;

    string Jugador1,Jugador2;

    switch(Menu)
    {
    case 1:
        system("cls");
        FuncionJugar();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        return 0;
        break;


    }
}

void FuncionJugar() //Funcion para el juego.
{

    string Jugador1,Jugador2;


    FuncionNombres(Jugador1,Jugador2);

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
    int CartaBloqueada1,CartaBloqueada2,CartaBloqueada3,CartaBloqueada4,CartaBloqueada5;

// Mezclo mazo.
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
        cout << MazoNombres[Mazo[i]] << " ";
    }
    cout << endl<<endl;

    FuncionRepartirCartas(BarajaJugadores,Mazo,MazoRestante);

    bool JuegoTerminado=false;

    int Ronda=1;

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

// Muestro barajas comienzo de juego.

        cout << "CLUTCH" << endl;
        cout << "-------------------------------------------------------------------------"<<endl;
        cout << "Ronda: ";
        cout << Ronda<<endl;
        cout << "Cartas del jugador #1 "<< Jugador1 <<endl<<endl;

        for (int x=0; x<5; x++)
        {
            BarajaJugadores[x];
            cout << "#" << x+1 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
        cout <<endl;
        cout << "Cartas del jugador #2 "<< Jugador2 <<endl<<endl;

        for (int x=5; x<10; x++)
        {
            BarajaJugadores[x];
            cout << "#" << x-4 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
        cout << endl;

        // Muestro Mazo restante

        cout << "Mazo es: "<<endl<<endl;
        for(int i=0; i<10; i++)
        {
            cout <<  MazoNombres[MazoRestante[i]] << " ";
        }


        char Presionar;
        cout << endl<<endl;
        cout << "-------------------------------------------------------------------------"<<endl;
        cout << "Turno del jugador: ";

        if (PrimerTurno==Jugador1)
        {
            cout << Jugador1<<endl;
            FuncionCambiosJugador1(Presionar,Mazo,BarajaJugadores,PrimerTurno,MazoNombres,AuxBaraJugadores,MazoRestante);
        }
        if (PrimerTurno==Jugador2)
        {
            cout << Jugador2<<endl;

            cout << "Lanzador: " << PrimerTurno << " "<<endl;
            cout << "Preciona cualquier tecla para lanzar el dado >";
            cin >> Presionar;
            cout << endl;

            
            int DadoRandom = 4;
            int CartaElejida;
            int CartaElejidaContraria;
            int Pick;



            switch(DadoRandom)
            {
                cout << "eeeeees " << DadoRandom;
            case 1:
                cout << "Dado numero: "<< DadoRandom <<endl;
                cout << "***Elegir una carta de tu propio corral y robar una carta del mazo (1-5)***"<<endl<<endl;
                cout << "------------------------------------------------------------------------"<<endl;
                cout<< "Tus cartas: "<<endl;

                for (int x=5; x<10; x++)
                {
                    cout << "#"<< x-4<<" " << MazoNombres[BarajaJugadores[x]]<<endl;
                }
                cout << endl;
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
                cout << "Dado numero: "<< DadoRandom <<endl;
                cout << "***Elegir una carta del corral contrario y robar una carta del mazo (1-5)***"<<endl<<endl;
                cout << "------------------------------------------------------------------------"<<endl;
                cout<< "Cartas Contrarias: "<<endl;

                FuncionMostrarMano2(MazoNombres,BarajaJugadores);

                cout << endl;
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
            case 3:
            cout << "Dado numero: "<< DadoRandom <<endl;
        cout << "***Elegir una carta de tu propio corral y robar una del corral contrario (1-5)***"<<endl<<endl;
        cout << "------------------------------------------------------------------------"<<endl;
        cout<< "Tus cartas: "<<endl;

        for (int x=5; x<10; x++)
        {
            cout << "#"<< x-4<<" " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
        cout<< "Cartas contrarias: "<<endl;

        for (int x=0; x<5; x++)
        {
            cout << "#"<< x+1 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
        cout << endl;

        cout << "Carta propia elejida >";
        cin >> CartaElejida;
        while(CartaElejida<1||CartaElejida>5)
        {
            cout << "Ingrese un numero correcto >";
            cin >> CartaElejida;

        }

        cout << "Carta propia elejida >";
        cin >> CartaElejidaContraria;
        while(CartaElejida<1||CartaElejida>5)
        {
            cout << "Ingrese un numero correcto >";
            cin >> CartaElejidaContraria;

        }
        CartaElejida=CartaElejida+4;
        CartaElejidaContraria=CartaElejidaContraria-1;
        
        AuxBaraJugadores[CartaElejida]=BarajaJugadores[CartaElejida];
        BarajaJugadores[CartaElejida]=BarajaJugadores[CartaElejidaContraria];
        BarajaJugadores[CartaElejidaContraria]=AuxBaraJugadores[CartaElejida];


        
        
                break;
            case 4:
            cout << "Dado numero: "<< DadoRandom <<endl;
        cout << "***Elegir una carta de tu propio corral e intercambiarla por una de tu mismo corral  (1-5)***"<<endl<<endl;
        cout << "------------------------------------------------------------------------"<<endl;
        cout<< "Tus cartas: "<<endl;

         for (int x=5; x<10; x++)
        {
            cout << "#"<< x+1 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
         cout << endl;

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
            cout << "Dado numero: "<< DadoRandom <<endl;
        cout << "***Elije una carta de tu propia corral y bloqueala para que tu rival no pueda modificarla  (1-5)***"<<endl<<endl;
        cout << "------------------------------------------------------------------------"<<endl;
        cout<< "Tus cartas: "<<endl;

        for (int x=5; x<10; x++)
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
        CartaElejida=CartaElejida+4;

        CartaBloqueada1=CartaElejida;



                break;
            case 6:
                break;
            }


            //FuncionCambiosJugador2(Presionar,Mazo,BarajaJugadores,PrimerTurno,MazoNombres,AuxBaraJugadores,MazoRestante);


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
        /*switch (FuncionJuegoTerminado(BarajaJugadores)) {
        case 1:
            cout << "Gandor player 1"<<endl;

            break;
        case 2:
             cout << "Gandor player 2"<<endl;
            break;
        }*/

        cin >> JuegoTerminado;

        system("cls");
    }
    FuncionMenu();

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
    do
    {
        if (Entrada==false)
        {
            cout << "Ingrese nuevamente los nombres de usuario:"<<endl<<endl;
        }

        cout << "Ingrese el nombre del primer jugador: >";
        cin >> Jugador1;
        cout << endl;
        cout << "Ingrese el nombre del segundo jugador: >";
        cin >> Jugador2;
        cout << endl;
        cout <<"--------------------------"<<endl;

        system("cls");

        cout << "Jugador #1: " << Jugador1 <<endl;
        cout << "Jugador #2: " << Jugador2 <<endl;

        cout<< "--------------------------"<<endl;

        cout << "Desea confirmar los nombres? y/n >";
        cin >> Confirmacion;

        cout <<"--------------------------"<<endl;

        Entrada=false;
    }
    while (Confirmacion!='Y'&&Confirmacion!='y');

    system("cls");


}

int FuncionJuegoTerminado(int BarajaJugadores[10])
{

    if (BarajaJugadores[0]<4&&BarajaJugadores[1]>=4&&BarajaJugadores[1]<=7&&BarajaJugadores[2]>=8&&BarajaJugadores[2]<=11&&BarajaJugadores[3]>=15&&BarajaJugadores[3]<=12&&BarajaJugadores[4]>=16&&BarajaJugadores[4]<20)
    {
        return 1;
        cout << "Ganador Jugador Numero 1"<<endl;
    }

    if (BarajaJugadores[4]<4&&BarajaJugadores[5]>=4&&BarajaJugadores[5]<=7&&BarajaJugadores[6]>=8&&BarajaJugadores[6]<=11&&BarajaJugadores[7]>=15&&BarajaJugadores[7]<=12&&BarajaJugadores[8]>=16&&BarajaJugadores[8]<20)
    {
        return 2;
        cout << "Ganador Jugador Numero 2"<<endl;
    }

}

void FuncionCambiosJugador1(char Presionar,int Mazo[10],int BarajaJugadores[10],string PrimerTurno,string MazoNombres[20],int AuxBaraJugadores[],int MazoRestante[])
{

    cout << "Lanzador: " << PrimerTurno << " "<<endl;
    cout << "Preciona cualquier tecla para lanzar el dado >";
    cin >> Presionar;
    cout << endl;

    int Pick;
    int DadoRandom = 4;
    int CartaElejida;
    int CartaElejidaContraria;

    switch(DadoRandom)
    {
    case 1:
        cout << "Dado numero: "<< DadoRandom <<endl;
        cout << "***Elegir una carta de tu propio corral y robar una carta del mazo (1-5)***"<<endl<<endl;
        cout << "------------------------------------------------------------------------"<<endl;
        cout<< "Tus cartas: "<<endl;

        for (int x=0; x<5; x++)
        {
            cout << "#"<< x+1 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
        cout << endl;
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

        cout << "Dado numero: "<< DadoRandom <<endl;
        cout << "***Elegir una carta del corral contrario y robar una carta del mazo (1-5)***"<<endl<<endl;
        cout << "------------------------------------------------------------------------"<<endl;
        cout<< "Cartas contrarias: "<<endl;

        for (int x=5; x<10; x++)
        {
            cout << "#"<< x-4<<" " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
        cout << endl;
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
    case 3:
    cout << "Dado numero: "<< DadoRandom <<endl;
        cout << "***Elegir una carta de tu propio corral y robar una del corral contrario (1-5)***"<<endl<<endl;
        cout << "------------------------------------------------------------------------"<<endl;
        cout<< "Tus cartas: "<<endl;

         for (int x=0; x<5; x++)
        {
            cout << "#"<< x+1 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
         cout << endl;
        cout<< "Cartas contrarias: "<<endl;

       
        for (int x=5; x<10; x++)
        {
            cout << "#"<< x-4<<" " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
        cout << endl;

        cout << "Carta propia elejida >";
        cin >> CartaElejida;
        while(CartaElejida<1||CartaElejida>5)
        {
            cout << "Ingrese un numero correcto >";
            cin >> CartaElejida;

        }

        cout << "Carta propia elejida >";
        cin >> CartaElejidaContraria;
        while(CartaElejida<1||CartaElejida>5)
        {
            cout << "Ingrese un numero correcto >";
            cin >> CartaElejidaContraria;

        }
        CartaElejida=CartaElejida-1;
        CartaElejidaContraria=CartaElejidaContraria+4;
        
        AuxBaraJugadores[CartaElejida]=BarajaJugadores[CartaElejida];
        BarajaJugadores[CartaElejida]=BarajaJugadores[CartaElejidaContraria];
        BarajaJugadores[CartaElejidaContraria]=AuxBaraJugadores[CartaElejida];
    
        break;
    case 4:
    cout << "Dado numero: "<< DadoRandom <<endl;
        cout << "***Elegir una carta de tu propio corral e intercambiarla por una de tu mismo corral (1-5)***"<<endl<<endl;
        cout << "------------------------------------------------------------------------"<<endl;
        cout<< "Tus cartas: "<<endl;

         for (int x=0; x<5; x++)
        {
            cout << "#"<< x+1 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
         cout << endl;

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
        break;
    case 6:
        break;
    }

}

/*id FuncionCambiosJugador2(char Presionar,int Mazo[10],int BarajaJugadores[10],string PrimerTurno,string MazoNombres[20],int AuxBaraJugadores[],int MazoRestante[])
{


    cout << "Lanzador: " << PrimerTurno << " "<<endl;
    cout << "Preciona cualquier tecla para lanzar el dado >";
    cin >> Presionar;
    cout << endl;


    int DadoRandom = 1;
    int CartaElejida;

    switch(DadoRandom)
    {
    case 1:
        /out << "Dado numero: "<< DadoRandom <<endl;
        cout << "***Elegir una carta de tu propio corral y robar una carta del mazo (1-5)***"<<endl<<endl;
        cout << "------------------------------------------------------------------------"<<endl;
        cout<< "Tus cartas: ";

        for (int x=0; x<5; x++)
        {
            cout << "#"<< x+1 << " " << MazoNombres[BarajaJugadores[x]]<<endl;
        }
        cout << endl;
        cout << "Carta elejida >";
        cin >> CartaElejida;
        while(CartaElejida<1||CartaElejida>5)
        {
            cout << "Ingrese un numero correcto >";
            cin >> CartaElejida;
        }
        AuxBaraJugadores[CartaElejida-1]=BarajaJugadores[CartaElejida-1];
        BarajaJugadores[CartaElejida-1]=MazoRestante[CartaElejida-1];
        MazoRestante[CartaElejida-1]=AuxBaraJugadores[CartaElejida-1];

        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    }

}*/

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






