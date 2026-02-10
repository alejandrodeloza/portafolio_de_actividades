/* ************IDENTIFICADOR*****************
Nombre del autor: De Loza Esquivias Alejandro
Código: 222946692
Actividad: Actividad de aprendizaje 9
Fecha: 09 de febrero de 2026
Propósito: Imprimir en pantalla la secuencia de numeros que el usuario designe elevando a su cuadrado y sumando.
*************************************** */
#include <iostream>
#include <stdlib.h>
#include <limits>
using namespace std;
int limit, n[2];
char rep;
bool ciclo=true;
int main() {
    cout<<"\t--Secuencia de potencias--"<<endl;
    while (ciclo) {

        cout<<"Ingrese el limite que desea para su secuencia"<<endl;
        while (!(std::cin >> limit)) {
            std::cout << "Error: Solo se permiten numeros. Intente de nuevo: "<<endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        n[2]= 0;
        cout<<"Su secuencia es:"<<endl;
        for(int i=1;i<=limit;i++) {
            n[1]= i*i;
            cout<<i<<"^2="<<n[1]<<"\t";
            n[2]= n[1]+n[2];
        }
        cout<<"\nLa suma total de sus potencias es de: "<<endl;
        cout<<n[2]<<endl;
        cout<<"Desea ingresar una nueva secuencia?\n[Si]Presione cualquier tecla.\n[No]Presione {N/n}"<<endl;
        cin>>rep;
        system("cls");
        if (rep=='N' || rep=='n') {
            ciclo=false;
            cout<<"\t--Gracias por confiarnos sus potencias--"<<endl;
        }
    }//Fin de while
}//Fin de main