/* ************IDENTIFICADOR*****************
Nombre del autor: De Loza Esquivias Alejandro
Código: 222946692
Actividad: Actividad de aprendizaje 15
Fecha: 02 de marzo de 2026
Propósito: Desarrollar un programa capaz de llenar matrices de manera automatica así como dejar al usuario llenarla de manera manual.
*************************************** */
#include <iostream>
#include <limits>//Biblioteca de control de ingreso de caracteres
#include <ctime>//Biblioteca para generar números aleatorios
#include <cstdlib>//Biblioteca para el uso de srand
using namespace std;

//Declaración de funciones
void prn(string text);
void prn(int n);
bool terminar_programa();
bool check(int n);
bool check2(int n);
int tam_matr();
int random_or_selection();
void llenar_aleatoria(int matr[][10], int tam);
void llenar_manual(int matr[][10], int tam);
void imprimir_matr(int matr[][10], int tam);

//Variables globales
int tam=0;

int main() {
    srand(time(NULL));
    prn("\t--Crear matriz--");
    while (true) {
        tam = tam_matr();

        //Declarar matriz
        int matr[10][10];

        switch (random_or_selection()) {
            case 1: {
                llenar_aleatoria(matr,tam);
                break;
            }//Aleatorio
            default: {
                llenar_manual(matr,tam);
            }//Manual
        }//El usuario decide si llenar de manera manual o aleatoria la matriz
        prn("-Su matriz-");
        imprimir_matr(matr,tam);
        if (terminar_programa()==false)
            break;
    }//While para reiniciar programa
    prn("--Gracias por confiarnos sus arreglos bidimensionales--");
}//Fin del main

//Definición de funciones
void prn(string text){
    cout<<(text)<<endl;
}//Función para imprimir texto
void prn(int n) {
    cout<<n<<endl;
}//Función para imprimir cantidades
bool terminar_programa() {
    char rep;
    prn("\nDesea continuar usando el programa?\n[Si]Presione cualquier tecla.\n[No]Presione {N/n}");
    cin>>rep;
    cin.ignore(1000,'\n');
    system("cls");
    if (rep=='N' || rep=='n')
        return false;
    if (rep!='N' && rep!='n') {
        return true;
    }
}//Función para darle al usuario la desición de salir del programa
bool check(int n) {
    if (cin.fail() || n<2 || n>10 ) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "**Ese no es un valor aceptado**\n--Intente nuevamente--"<<endl;
        return true;
    }
    if (n>=3 && n<=10)
        return false;
}//Función para identificar si la entrada es un caracter
bool check2(int n) {
    if (cin.fail() || n<0 || n>2 ) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "**Ese no es un valor aceptado**\n--Intente nuevamente--"<<endl;
        return true;
    }
    if (n>=1 && n<=2)
        return false;
}//Función para identificar si la entrada es un caracter
int tam_matr() {
    int tam;
    prn("-Ingrese el tamano de la matriz que desea manejar (matriz cuadrada, ejemplo: 3x3)-");
    prn("--Tamano (3-10)--");
    while (true) {
        cin>>tam;
        if (check(tam)==false)
            break;
    }//While para errores
    return tam;
}//Función para ingresar el tamaño de la matriz
int random_or_selection() {
    int selec;
    prn("--Selccione la funcion que desee--");
    prn("-Llenar de manera aleatoria [1]-");
    prn("-Llenar de manera manual [2]-");
    while (true) {
        cin>>selec;;
        if (check2(selec)==false)
            break;
    }//While para errores
    return selec;
}//Función para que el usuario seleccione si quiere rellenar la matriz aleatoriamente o manualmente
void llenar_aleatoria(int matr[][10], int tam) {
    for (int i=0;i<tam; i++) {
        for (int j=0;j<tam;j++) {
            matr[i][j] = (rand() % 201) - 100;
        }//Mover en columnas
    }//Mover por filas
}//Función de llenado aleatorio
void llenar_manual(int matr[][10], int tam) {
    int valor;
    prn("-Si en alguna de las posiciones desea agregar un numero aleatorio use un caracter que no sea numerico-");
    for (int i=0;i<tam; i++) {
        for (int j=0;j<tam;j++) {
            cout<<"["<<i<<"]["<<j<<"]";
            cin>>valor;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                matr[i][j] = (rand() % 201) - 100;
            }
            else {
                matr[i][j] = valor;
            }
        }//Mover en columnas
    }//Mover por filas
}//Función de llenado manual
void imprimir_matr(int matr[][10], int tam) {
    for (int i=0;i<tam;i++) {
        for (int j=0;j<tam;j++) {
            cout<<"[ "<<matr[i][j]<<"]"<<"\t";
        }//Mover por columnas
        prn(" ");
    }//Mover por filas
}//Función imprimir matriz