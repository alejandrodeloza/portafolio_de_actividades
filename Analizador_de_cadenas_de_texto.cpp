/* ************IDENTIFICADOR*****************
Nombre del autor: De Loza Esquivias Alejandro
Código: 222946692
Actividad: Actividad de aprendizaje 13
Fecha: 19 de febrero de 2026
Propósito: Desarrollar un programa capaz de analizar cadenas de caracteres y contar los diferentes caracteres que contiene.
*************************************** */
#include <iostream>
#include <cstring>//Biblioteca usada para copiar strings
#include <stdlib.h>//Para  limpiar pantalla
using namespace std;
//Declaración de funciones
void prn(int n);
void prn(string text);
int calc_total_de_char(string text);
void ident_caract(char textarr[], int total);
//Variables globales
string text;
bool ciclo=true;
char rep;
int main() {
    prn("\t--Identificar los caracteres con los que cuenta su texto--");
    while (ciclo) {
        prn("Ingrese el texto que desea evaluar:");
        getline(cin >> ws, text);
        prn("\n--Este es el total de caracteres que contiene su texto--");
        prn(calc_total_de_char(text));
        char textarr[text.length()+1];//Variable de arreglo
        strcpy(textarr, text.c_str());
        ident_caract(textarr,calc_total_de_char(text));
        prn("\nDesea ingresar una nuevo texto?\n[Si]Presione cualquier tecla.\n[No]Presione {N/n}");
        cin>>rep;
        cin.ignore(1000,'\n');
        system("cls");
        if (rep=='N' || rep=='n')
            ciclo=false;
        else
            ciclo=true;
    }//Fin del while para reiniciar el programa
    prn("--Gracias por confiarnos sus textos--");
}//Fin del main
//Definición de funciones
void prn(string text){
    cout<<(text)<<endl;
}//Función para imprimir texto
void prn(int n) {
    cout<<n<<endl;
}//Función para imprimir cantidades
int calc_total_de_char(string text) {
    int total;
    total=text.length();
    return total;
}//Función para calcular el total de caracteres en un string o texto
void ident_caract(char textarr[], int total) {
    int consM=0, consm=0, vocM=0, vocm=0, num=0, pal=0;
    for (int i=0;i<=total;i++) {
        if (textarr[i]>=65 && textarr[i]<=90) {
            if (textarr[i]==65 || textarr[i]==69 || textarr[i]==73 || textarr[i]==79 || textarr[i]==85) {
                vocM++;
            }//Condición para vocales mayúsculas
            else {
                consM++;
            }//Condición para consonantes mayúsculas
        }//Condición para mayúsculas
        else if (textarr[i]>=97 && textarr[i]<=122) {
            if (textarr[i]==97 || textarr[i]==101 || textarr[i]==105 || textarr[i]==111 || textarr[i]==117) {
                vocm++;
            }//Condición para vocales minúsculas
            else {
                consm++;
            }//Condición para consonantes minúsculas
        }//Condición para minúsculas
        else if (textarr[i]==' ') {
            pal++;
        }//Condición para palabras
        else if (textarr[i]>=48 && textarr[i]<=57) {
            num++;
        }//Condición para números
    }//Final del for para ciclar entre los caracteres del texto
    //Zona para imprimir todos los resultados en pantalla
    prn("--La cantidad de palabras que contiene su texto es de:--");
    prn(pal+1);
    prn("--La cantidad de numeros que contiene su texto es de:--");
    prn(num);
    prn("--La cantidad de consonantes que contiene su texto es de:--");
    prn("Mayusculas:");
    prn(consM);
    prn("Minusculas:");
    prn(consm);
    prn("--La cantidad de vocales que contiene su texto es de:--");
    prn("Mayusculas:");
    prn(vocM);
    prn("Minusculas:");
    prn(vocm);

}//Función para determinar el tipo de caracteres con el que cuenta un string