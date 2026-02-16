/* ************IDENTIFICADOR*****************
Nombre del autor: De Loza Esquivias Alejandro
Código: 222946692
Actividad: Actividad de aprendizaje 10
Fecha: 11 de febrero de 2026
Propósito: Desarrollar un programa que identifique y contabilice múltiplos específicos dentro de un rango definido por el usuario.
*************************************** */
#include <iostream>
#include <limits>
#include <stdlib.h>
using namespace std;
//Declaración de funciones
bool check(int n);
void prn(string text);
void prn(int n);
void multi(int n);
//Variables globales
int n;
char rep;
bool ciclo=true;
//main
int main(){
    prn("\t--Identificar cuantos multiplos de 3 y 5 hay en su valor y su suma total--");
    while(ciclo) {
        while (true) {
            cout<<"Ingrese el número en el que desea identificar los multiplos [Limite 0 - 1000]:"<<endl;
            cin>>n;
            if (check(n)==false) {
                break;
            }
        }//fin del while
        multi(n);
        prn("\nDesea ingresar una nuevo valor?\n[Si]Presione cualquier tecla.\n[No]Presione {N/n}");
        cin>>rep;
        system("cls");
        if (rep=='N' || rep=='n')
            break;
    }//Fin del while
    prn("\t--Gracias por confiarnos sus multiplos--");
}//Fin del main
//Definición de funciones
void prn(string text){
    cout<<(text)<<endl;
}//Fin del prn  
void prn(int n){
    cout<<n<<endl;
}//Fin prn num
bool check(int n) {
    if (cin.fail() || n<0 || n>1000) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "**Ese no es un valor aceptado**\n--Intente nuevamente--"<<endl;
        return true;
    }
    if (n>0 && n<1000)
        return false;
}//Fin check
void multi(int n) {
    int m3=0, m5=0, sum=0;
    for (int i=1; i<=n; i++) {
        if (i%3==0 && i%5==0) {
            m3= m3+1;
            m5= m5+1;
            sum= sum+i;
        }
        else if (i%3==0) {
            m3= m3+1;
            sum=sum+i;
        }
        else if (i%5==0) {
            m5=m5+1;
            sum=sum+i;
        }
    }//Fin del for
    cout<<"La cantidad de multipos de 3 son: "<<m3<<"\n"<<"La cantidad de multiplos del 5 son: "<<m5<<endl;
    cout<<"La suma total de los multiplos es: "<<sum<<endl;
}//Fin multi