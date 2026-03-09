/* ************IDENTIFICADOR*****************
Nombre del autor: De Loza Esquivias Alejandro
Código: 222946692
Actividad: Actividad de aprendizaje 16
Fecha: 08 de marzo de 2026
Propósito: Desarrollar un programa capaz de llenar matrices, permitir al usuario llenarlas y realizar operaciones aritmeticas con estas.
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

//Nuevas funciones
int A_or_B();
int menu_operaciones();
bool check3(int n);
void suma(int matr[][10], int matrb[][10], int matrc[][10], int tam);
void resta(int matr[][10], int matrb[][10], int matrc[][10], int tam);
void multiplica(int matr[][10], int matrb[][10], int matrc[][10], int tam);
void division(int matr[][10], int matrb[][10], float matrc[][10], int tam);
void imprimir_matrf(float matr[][10], int tam);

//Variables globales
int tam=0, count=0;
int matra[10][10], matrb[10][10], matrc[10][10];
float matrcf[10][10];
int main() {
    srand(time(NULL));
    prn("\t--Operaciones aritmeticas con matrices--");
    while (true) {
        bool op1=false, op2=false, cicloop = true;
        tam = tam_matr();
        while (op1==false || op2==false) {
            prn("--Selccione la matriz que desea llenar--");
            switch (A_or_B()) {
                case 1: {
                    prn("-Matriz A-");
                    switch (random_or_selection()) {
                        case 1: {
                            llenar_aleatoria(matra,tam);
                            break;
                        }//Aleatorio
                        default: {
                            llenar_manual(matra,tam);
                        }//Manual
                    }//El usuario decide si llenar de manera manual o aleatoria la matriz
                    op1 = true;
                    break;
                }//Llenar matriz A
                case 2: {
                    prn("-Matriz B-");
                    switch (random_or_selection()) {
                        case 1: {
                            llenar_aleatoria(matrb,tam);
                            break;
                        }//Aleatorio
                        default: {
                            llenar_manual(matrb,tam);
                        }//Manual
                    }//El usuario decide si llenar de manera manual o aleatoria la matriz
                    op2 = true;
                    break;
                }//Llenar matriz B
            }//Seleccionar matriz
        }//Llenar matrices

        prn("-Matriz A-");
        imprimir_matr(matra,tam);

        prn("-Matriz B-");
        imprimir_matr(matrb,tam);

        while (cicloop) {
            switch (menu_operaciones()) {
                case 1: {
                    suma(matra,matrb,matrc,tam);
                    prn("\t--Sumatoria de matrices--");
                    prn("-Su matriz resultante-");
                    imprimir_matr(matrc, tam);
                    break;
                }//Sumas
                case 2: {
                    resta(matra,matrb,matrc,tam);
                    prn("\t--Resta de matrices--");
                    prn("-Su matriz resultante-");
                    imprimir_matr(matrc, tam);
                    break;
                }//Restas
                case 3: {
                    multiplica(matra,matrb,matrc,tam);
                    prn("\t--Multiplicacion de matrices--");
                    prn("-Su matriz resultante-");
                    imprimir_matr(matrc, tam);
                    break;
                }//Multiplicacion
                case 4: {
                    division(matra,matrb,matrcf,tam);
                    prn("\t--Divisio escalar de matrices--");
                    prn("-Su matriz resultante-");
                    imprimir_matrf(matrcf, tam);
                     break;
                }//Division
                default: {
                    cicloop = false;
                    break;
                }
            }//Elegir operacion
        }//Realizar operaciones
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
    if (cin.fail() || n<3 || n>10 ) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "**Ese no es un valor aceptado**\n--Intente nuevamente--"<<endl;
        return true;
    }
    if (n>=3 && n<=10)
        return false;
}//Función para identificar si la entrada es un caracter
bool check2(int n) {
    if (cin.fail() || n<1 || n>2 ) {
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
    prn("--Este programa realiza operaciones de matrices, pero estas deben tener las mismas dimensiones--");
    prn("-Ingrese el tamano de las matices que desea manejar (matriz cuadrada, ejemplo: 3x3)-");
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

//Nuevas funciones
int A_or_B() {
    int selec;
    prn("-Matriz A [1]-");
    prn("-Matriz B [2]-");
    while (true) {
        cin>>selec;;
        if (check2(selec)==false)
            break;
    }//While para errores
    return selec;
}//Función para que el usuario seleccione la matriz que desea llenar
int menu_operaciones() {
    int selec;
    prn("--Selccione la operacion que desea realizar--");
    prn("-Suma [1]-");
    prn("-Resta [2]-");
    prn("-Multiplicacion [3]-");
    prn("-Division escalar[4]-");
    prn("Salir del menu de operaciones[5]");
    while (true) {
        cin>>selec;;
        if (check3(selec)==false)
            break;
    }//While para errores
    return selec;
}//Función para que el usuario seleccione la operacion que desea
bool check3(int n) {
    if (cin.fail() || n<1 || n>5 ) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "**Ese no es un valor aceptado**\n--Intente nuevamente--"<<endl;
        return true;
    }
    if (n>=1 && n<=5)
        return false;
}//Función para identificar si la entrada es un caracter
void suma(int matr[][10], int matrb[][10], int matrc[][10], int tam) {
    for (int i=0;i<tam;i++) {
        for (int j=0;j<tam;j++) {
            matrc[i][j] = matr[i][j]+matrb[i][j];
        }//Mover por columnas
    }//Mover por filas
}//Función para sumar matrices
void resta(int matr[][10], int matrb[][10], int matrc[][10], int tam) {
    prn("-La resta no es conmutativa, selecione la que desee");
    prn("-Matriz A - Matriz B [1]");
    prn("-Matriz B - Matriz A [2]");
    int selec;
    while (true) {
        cin>>selec;;
        if (check2(selec)==false)
            break;
    }//While para errores
    switch (selec) {
        case 1: {
            for (int i=0;i<tam;i++) {
                for (int j=0;j<tam;j++) {
                    matrc[i][j] = matr[i][j]-matrb[i][j];
                }//Mover por columnas
            }//Mover por filas
            break;
        }// A - B
        case 2: {
            for (int i=0;i<tam;i++) {
                for (int j=0;j<tam;j++) {
                    matrc[i][j] = matrb[i][j]-matr[i][j];
                }//Mover por columnas
            }//Mover por filas
            break;
        }//B - A
    }//Elegir resta
}//Función para restar matrices
void multiplica(int matr[][10], int matrb[][10], int matrc[][10], int tam) {
    prn("-La multiplicacion no es conmutativa, selecione la que desee");
    prn("-Matriz A x Matriz B [1]");
    prn("-Matriz B x Matriz A [2]");
    int selec, fa=0, fbca=0, cb=0;
    while (true) {
        cin>>selec;;
        if (check2(selec)==false)
            break;
    }//While para errores
    switch (selec) {
        case 1: {
            for (fa=0;fa<tam;fa++) {
                for (cb=0;cb<tam;cb++) {
                    matrc[fa][cb] = 0;
                    for (fbca=0;fbca<tam;fbca++) {
                        matrc[fa][cb] += matr[fa][fbca]*matrb[fbca][cb];
                    }//Mover en filas y columnas de ambos
                }//Mover por columnas de b
            }//Mover por filas de a
            break;
        }//A x B
        case 2: {
            for (fa=0;fa<tam;fa++) {
                for (cb=0;cb<tam;cb++) {
                    matrc[fa][cb] = 0;
                    for (fbca=0;fbca<tam;fbca++) {
                        matrc[fa][cb] += matrb[fa][fbca]*matr[fbca][cb];
                    }//Mover en filas y columnas de ambos
                }//Mover por columnas de b
            }//Mover por filas de a
            break;
        }//B x A
    }//Elegir multipicación
}//Función para multiplicar matrices
void division(int matr[][10], int matrb[][10], float matrc[][10], int tam) {
    int div=0;
    prn("-Solo podemos dividir una matriz entre un numero-");
    prn("-Ingrese el numero por cual desea dividir-");
    while (true) {
        cin>>div;
        if (cin.fail() || div<1 ) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "**Ese no es un valor aceptado**\n--Intente nuevamente--"<<endl;
        }
        if (div>=1)
            break;
    }//While para errores
    prn("--Selccione la matriz que desea dividir--");
    switch (A_or_B()) {
        case 1: {
            for (int i=0;i<tam;i++) {
                for (int j=0;j<tam;j++) {
                    matrc[i][j] = (matr[i][j]*1.0)/div;
                }//Mover por columnas
            }//Mover por filas
            break;
        }//Matriz A
        case 2: {
            for (int i=0;i<tam;i++) {
                for (int j=0;j<tam;j++) {
                    matrc[i][j] = (matrb[i][j]*1.0)/div;
                }//Mover por columnas
            }//Mover por filas
            break;
        }//Matriz B
    }//Elegir matriz
}//Función para dividir matrices entre un número
void imprimir_matrf(float matr[][10], int tam) {
    for (int i=0;i<tam;i++) {
        for (int j=0;j<tam;j++) {
            cout<<"[ "<<matr[i][j]<<"]"<<"\t";
        }//Mover por columnas
        prn(" ");
    }//Mover por filas
}//Función imprimir matriz de flotantes