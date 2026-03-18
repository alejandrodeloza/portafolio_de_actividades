/* ************IDENTIFICADOR*****************
Nombre del autor: De Loza Esquivias Alejandro
Código: 222946692
Actividad: Actividad de aprendizaje 17
Fecha: 12 de marzo de 2026
Propósito: Desarrollar un programa capaz de llenar matrices con valores boleanos (0 y 1) y analizar la caracteristica de la relacion
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
int analizar_reflex(int matr[][10], int tam);
int analizar_simetr(int matr[][10], int tam);
int analizar_transi(int matr[][10], int tam);

//variables globales
int main() {
    //Variables del main
    int tam=0, matr[10][10];
    bool ciclo=true;
    srand(time(NULL));
    prn("\t--Analisis de matrices cuadradas--");
    while (ciclo) {
        tam = tam_matr();
        if (random_or_selection()==1){llenar_aleatoria(matr,tam);}//Llenado aleatorio
        else {llenar_manual(matr, tam);}//Llenado manual
        prn("-Esta es su matriz-");
        imprimir_matr(matr, tam);
        prn("--Posee las siguientes caracteristicas--");
        //Reflexividad
        if (analizar_reflex(matr, tam)==1)prn("-Su matriz es relfexiva-");
        if (analizar_reflex(matr, tam)==2)prn("-Su matriz es irreflexiva");
        if (analizar_reflex(matr, tam)==3) prn("-Su matriz no es reflexiva-");
        //Simetria
        if (analizar_simetr(matr, tam)==1)prn("-Su matriz es simetrica-");
        else prn("*Su matriz no es simetrica*");
        if (analizar_simetr(matr, tam)==2)prn("-Su matriz es asimetrica-");
        else prn("*Su matriz no es asimetrica*");
        if (analizar_simetr(matr, tam)==3)prn("-Su matriz es antisimetrica-");
        else prn("*Su matriz no es antisimetrica*");
        if (analizar_simetr(matr, tam)==4)prn("-No posee ninguna caracteristica de simetria-");
        //Transitividad
        if (analizar_transi(matr, tam)==1)prn("-Su matriz es transitiva-");
        else prn("*Su matriz no es transitiva-");
        if (analizar_reflex(matr, tam)==1 && analizar_simetr(matr, tam)==1 && analizar_transi(matr, tam)==1) {
            prn("--Su relacion es de equivalencia--");
        }
        else if (analizar_reflex(matr, tam)==1 && analizar_simetr(matr, tam)==3 && analizar_transi(matr, tam)==1) {
            prn("--Su relacion es de orden parcial--");
        }
        else if (analizar_reflex(matr, tam)==1 && analizar_simetr(matr, tam)==4 && analizar_transi(matr, tam)==1) {
            prn("--Su relacion es de casi orden--");
        }
        else if (analizar_reflex(matr, tam)==3 && analizar_simetr(matr, tam)==4 && analizar_transi(matr, tam)==1) {
            prn("--Su relacion es de pre-orden--");
        }
        else if (analizar_reflex(matr, tam)==2 && analizar_simetr(matr, tam)==4 && analizar_transi(matr, tam)==1) {
            prn("--Su relacion es de orden estricto--");
        }
        else prn("--Su relacion no tiene tipado--");
        if (terminar_programa()==false)break;
    }//Mantener el programa
    prn("\t--Gracias por confiarnos sus matrices--");
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
    else {
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
    prn("-Ingrese el tamano de la matriz que desea analizar (sera una matriz cuadrada, ejemplo: 3x3)-");
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
            matr[i][j] = (rand() % 2) - 0;
        }//Mover en columnas
    }//Mover por filas
}//Función de llenado aleatorio
void llenar_manual(int matr[][10], int tam) {
    int valor;
    prn("-Si en alguna de las posiciones desea agregar un numero aleatorio use un caracter que no sea numerico o un valor no boleano-");
    for (int i=0;i<tam; i++) {
        for (int j=0;j<tam;j++) {
            cout<<"Elemento en: "<<"["<<i+1<<"]["<<j+1<<"]";
            cin>>valor;
            if (cin.fail() || valor>1 || valor<0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                matr[i][j] = (rand() % 2) - 0;
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
            cout<<"["<<matr[i][j]<<"]"<<"\t";
        }//Mover por columnas
        prn(" ");
    }//Mover por filas
}//Función imprimir matriz

//Nuevas funciones
int analizar_reflex(int matr[][10], int tam) {
    int count=0;
    for (int i=0; i<tam; i++) {
        for (int j=0; j<tam; j++) {
            if (i==j) {
                if (matr[i][j]==1) {
                    count++;
                }//Definir reflexividad
            }//Ubicar diagonal principal
        }//Mover por columnas
    }//Mover por filas
    if (count==tam)return 1; //Reflexiva
    else if (count==0)return 2; //Irreflexiva
    else return 3;//No es reflexiva
}//Función para analizar la reflexividad de una matriz
int analizar_simetr(int matr[][10], int tam) {
    int count_s=0;
    bool antisimetria=true, asimetria=true;
    for (int i=0; i<tam; i++) {
        for (int j=0; j<tam; j++) {
            if (matr[i][j]==matr[j][i]){count_s++;}//Identificar simetría
            if (matr[i][j]==1 && matr[j][i]==1) {asimetria=false;}//Identificar asimetría
            if (i!=j && matr[i][j]==1 && matr[j][i]==1){antisimetria=false;}//Identificar antisimetría
        }//Mover por columnas
    }//Mover por filas
    if (count_s==tam*tam){return 1;}//Simétrica
    if (asimetria==true){return 2;}//Asimétrica
    if (antisimetria==true){return 3;}//Antisimétrica
    else return 4;//No posee ninguna caracteristica de simetria
}//Función para analizar la simetría de una matriz
int analizar_transi(int matr[][10], int tam) {
    bool transit=true;
    for (int i=0; i<tam; i++) {
        for (int j=0; j<tam; j++) {
            if (matr[i][j]==1) {
                for (int y=0; y<tam; y++) {
                    if (matr[j][y]==1) {
                        if (matr[i][y]!=1) {transit=false;}//Transitiva
                        if (transit==false)break;
                    }//Segunda arista de la transitividad
                }//Mover en columnas de la segunda arista de la transitividad
            }//Primera arista de la transitividad
            if (transit==false)break;
        }//Mover en columnas
        if (transit==false)break;
    }//Mover en filas
    if (transit==true){return 1;}//Matriz transitiva
    else {return 2;}//Matriz no transitiva
}//Función para analizar la transitividad