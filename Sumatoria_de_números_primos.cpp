/* ************IDENTIFICADOR*****************
Nombre del autor: De Loza Esquivias Alejandro
Código: 222946692
Actividad: Actividad de aprendizaje 11
Fecha: 15 de febrero de 2026
Propósito: Desarrollar un programa que identifique y sume los números primos dentro de un rango definido por el usuario.
*************************************** */
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <math.h>
using namespace std;
//Declarar funciones
bool check(int n);
void prn(string text);
void prn(int n);
void primo(int n);
//Variables globales
int n;
bool ciclo=true;
char rep;
//main
int main() {
    prn("\t--Identificar los numeros primos y su suma hasta el limite deseado--");
    while(ciclo) {
        while (true) {
            cout<<"Ingrese el limite que desea [Mayor a 2]:"<<endl;
            cin>>n;
            if (check(n)==false) {
                break;
            }
        }//fin del while
        primo(n);
        prn("\nDesea ingresar una nuevo valor?\n[Si]Presione cualquier tecla.\n[No]Presione {N/n}");
        cin>>rep;
        system("cls");
        if (rep=='N' || rep=='n')
            break;
    }//Fin del while
    prn("\t--Gracias por confiarnos sus numeros primos--");
}//Fin del main
//Deefinir funciones
void prn(string text){
    cout<<(text)<<endl;
}//Fin del prn
void prn(int n){
    cout<<n<<endl;
}//Fin prn num
bool check(int n) {
    if (cin.fail() || n<2 ) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "**Ese no es un valor aceptado**\n--Intente nuevamente--"<<endl;
        return true;
    }
    if (n>=2)
        return false;
}//Fin check
void primo(int n) {
    int sum=0;
    prn("Los numeros primos que posee su limite son:");
    for (int i=2; i<=n; i++) {
        int n2=0;
        for (int j=2; j<=round(sqrt(i)); j++) {
            if (i%j==0) {
                n2=2;
            }
        }//Fin del for
        if (n2==0) {
            prn(i);
            sum+=i;
        }
    }//Fin del for
    prn("\nLa suma de estos numeros es:");
    prn(sum);
}//Fin primo
