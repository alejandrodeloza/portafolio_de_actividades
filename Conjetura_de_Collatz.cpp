/* ************IDENTIFICADOR*****************
Nombre del autor: De Loza Esquivias Alejandro
Código: 222946692
Actividad: Actividad de aprendizaje 12
Fecha: 18 de febrero de 2026
Propósito: Desarrollar un programa capaz de procesar la conjetura de collatz, medir el tiempo de procesamiento y la cantidad de iteraciones.
*************************************** */
#include <iostream>
#include <limits>//Se usa para que el usuario no ingrese caracteres no numericos
#include <stdlib.h>//Para  limpiar pantalla
#include <chrono>//Para medir el tiempo de ejecución
#include <functional>
using namespace std;
//Declaración de funciones
bool check(long long n);
void prn(long long n);
void prnt(long long n);
void prn(string text);
void conjetura_Collatz(long long n);
void time(function<void(int n)> f);
//Variables globales
long long n;
char rep;
bool ciclo=true;
int main() {
    prn("\t--Procesar conjetura de Collatz--");
    while (ciclo) {
        prn("Ingrese el valor que desea evaluar [No menor a 0 o mayor a 2^63]:");
        while (true) {
            cin>>n;
        if (check(n)==false) {
            break;
            }//Romper ciclo
        }// Fin while para revisar valor ingresado
        time(conjetura_Collatz);
        prn("\nDesea ingresar una nuevo valor?\n[Si]Presione cualquier tecla.\n[No]Presione {N/n}");
        cin>>rep;
        system("cls");
        if (rep=='N' || rep=='n')
            break;
    }//Fin while repetir programa
    prn("\t--Gracias por confiarnos sus conjeturas--");
}//Fin del main
//Definicón de funciones
void prn(string text){
    cout<<(text)<<endl;
}//Función para imprimir texto
void prn(long long n) {
    cout<<n<<endl;
}//Función para imprimir cantidades
void prnt(long long n) {
    cout<<n<<"\t";
}//Función para imprimir cantidades seguidas de un tabulador
bool check(long long n) {
    if (cin.fail() || n<=0 || n>LLONG_MAX) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "**Ese no es un valor aceptado**\n\t--Intente nuevamente--"<<endl;
        return true;
    }
    if (n>0 && n<LLONG_MAX)
        return false;
}//Función para evitar que el usuario ingrese un caracter o valor invalido
void conjetura_Collatz(long long n) {
    int count=0;
    prn("Valores resultantes de la conjetura de Collatz de su numero:");
    while (true) {
        if (n%2==0) {
        n=n/2;
        prnt(n);
    }//Para números pares
        else {
            n=n*3+1;
            prnt(n);
        }//Para números impares
        count+=1;
        if (n==1) {
            prn("\nEl numero de iteraciones que duro la secuencia fue de: ");
            prn(count);
            break;
        }//Romper ciclo
    }//Mantener ciclo de conjetura
}//Imprimir conjetura de Collatz y su contador de ciclos
void time(function<void(int n)> func) {
    auto inicio = chrono::high_resolution_clock::now();
    func(n);
    auto fin = chrono::high_resolution_clock::now();
    auto duracion = chrono::duration_cast<std::chrono::microseconds>(fin - inicio);
    cout << "Tiempo de ejecucion de la conjetura:" << duracion.count() << " microsegundos" << endl;
}//Función para medir el tiempo de ejecución de otra función