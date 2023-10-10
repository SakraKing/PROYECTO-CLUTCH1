#include <iostream>
using namespace std;

#include <string>

#include<cstdlib>
using std::rand;
using std::srand;

#include<ctime>
using std::time;

//Mezclar cartas definicion:
bool Verificar( int CartaRandom,int Mazo[]);



// Funcion de nombre de usarios:

void Nombres(string &Nombre1,string &Nombre2)
{


    char Confirmacion;
    bool Entrada = true;

    do
    {
        if (Entrada==false)
        {
            cout << "Ingrese nuevamente los nombres de usuario:"<<endl<<endl;
        }

        cout << "Ingrese el nombre del primer jugador: >";
        cin >> Nombre1;
        cout << endl;
        cout << "Ingrese el nombre del segundo jugador: >";
        cin >> Nombre2;
        cout << endl;
        cout <<"--------------------------"<<endl;

        cout << "Jugador #1: " << Nombre1 <<endl;
        cout << "Jugador #2: " << Nombre2 <<endl;

        cout<< "--------------------------"<<endl;

        cout << "Desea confirmar los nombres? y/n >";
        cin >> Confirmacion;

        cout <<"--------------------------"<<endl;

        Entrada=false;

    }
    while (Confirmacion!='Y',Confirmacion!='y');
}


int main()
{
    srand(time(NULL));


    const int Cartas=20;
    int Mazo[Cartas];
    int CartaRandom=0;



// MENU DEL JUEGO PRINCIPAL

    int Menu;

    cout << "¡Bienvenidos a Clutch!"<<endl;
    cout << "-------------------------------------------------------------------------"<<endl;
    cout << "1 - JUGAR"<<endl;
    cout << "2 - ESTADISTICAS"<<endl;
    cout << "3 - CREDITOS"<<endl;
    cout << "--------------------------"<<endl;
    cout << "0 - SALIR"<<endl;

    cout << ">";
    cin >> Menu;

    string Usuario1,Usuario2;


    switch(Menu)
    {
    case 1:

// Nombre de usarios:
        Nombres(Usuario1,Usuario2);

//Rellenar y mezclar

        for(int i=0; i<20; i++)
        {
            while(Verificar(CartaRandom,Mazo))
            {

                CartaRandom = rand()% 20;
            }

            Mazo[i]=CartaRandom;
        }

//Comienza el Juego.


int Ronda=1;
string PrimeroJuador,SegundoJugador;

//repartir cartas




cout << "CLUTCH" << endl;
cout << "-------------------------------------------------------------------------"<<endl;
cout << "Ronda: " << Ronda<<endl;
cout << 

        





        break;
    case 2:

        break;
    case 3:
        break;
    case 0:
        return 0;

        break;
    default:

        break;

    }

    return 0;

}

//Mezclar.

bool Verificar( int CartaRandom,int Mazo[20])
{
    for(int i=0; i<20; i++)
    {
        if (CartaRandom==Mazo[i])
        {
            return true;
        }

    }
    return false;
}





