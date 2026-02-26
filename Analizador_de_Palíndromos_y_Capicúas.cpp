/* ************IDENTIFICADOR*****************
Nombre del autor: De Loza Esquivias Alejandro
Código: 222946692
Actividad: Actividad de aprendizaje 14
Fecha: 25 de febrero de 2026
Propósito: Desarrollar un programa capaz de analizar cadenas de caracteres e identificar si se trata de un palíndromo o una capicúa.
*************************************** */
#include <iostream>//Biblioteca de entradas y salidas
#include <cstring>//Biblioteca usada para copiar strings
#include <stdlib.h>//Para  limpiar pantalla
using namespace std;
//Declaración de funciones
void prn(int n);
void prn(string text);
void imprimir_inverso_espacios(char letra[],int total);
char* minusculas_sin_espacios(char letra[],int total);
int ident_num_in_string(char letra[], int total);
void ident_palindromo(char letra[],int total);
void ident_capicua(char letra[],int total);
bool terminar_programa();
//Variables globales
bool ciclo=true;
string text;
int main() {
    prn("\n--Identificar si un texto o numero es palindromo o capicua--");
    while (ciclo) {
        prn("Ingrese el texto que desea evaluar:");
        getline(cin >> ws, text);
        char textarr[text.length()+1];//Variable de arreglo
        strcpy(textarr, text.c_str());
        //Imprimir inversos
        imprimir_inverso_espacios(textarr,text.length());
        prn("--En minusculas y sin espacios--");
        imprimir_inverso_espacios(minusculas_sin_espacios(textarr,text.length()),text.length());
        //Nueva longitud
        string newtext = minusculas_sin_espacios(textarr,text.length());

        if (ident_num_in_string(textarr,text.length())==text.length()) {
            ident_capicua(minusculas_sin_espacios(textarr,text.length()), newtext.length());
        }//Condición si todos los caracteres son números determinará si es capicúa o no
        else {
            ident_palindromo(minusculas_sin_espacios(textarr,text.length()), newtext.length());
        }//Si hay al menos un número determinara si es palíndromo o no
        if (terminar_programa()==false) {
            ciclo=false;
        }//Condición para cerrar el programa
    }//Fin del while para repetir programa
    prn("--Gracias por confiarnos sus textos--");
}//Fin del main
//Definición de funciones
void prn(string text){
    cout<<(text)<<endl;
}//Función para imprimir texto
void prn(int n) {
    cout<<n<<endl;
}//Función para imprimir cantidades
void imprimir_inverso_espacios(char letra[],int total){
    prn("Su texto invertido es:");
    cout<<"--";
    for (int i=total;i>=0; i--) {
        cout<<letra[i];
    }//Fin del for para imprimir arreglo
    prn(" --");
}//Función para imprimir el inverso de un arreglo unidimensional contando los espacios
char* minusculas_sin_espacios(char letra[],int total) {
    for (int i=0; i<=total; i++) {
        if (letra[i]==' ') {
            for (int j=i; j<=total-1; j++) {
                letra[j]=letra[j+1];
            }//Fin del for para recorrer el texto
            total--;
        }//Condición si hay un espacio y recorrer el texto
        if (letra[i]>='A' && letra[i]<='Z') {
            letra[i]=letra[i]+32;
        }//Condición si la letra es mayúscula
    }//Fin del for para convertir letra por letra
    return letra;
}//Función para pasar un texto a minúsculas y eliminar sus espacios
int ident_num_in_string(char letra[], int total){
    int num=0;
    for (int i=0; i<=total; i++) {
        if (letra[i]>='0'&&letra[i]<='9') {
            num++;
        }//Condición si el caracter es un número
    }//For para revisar si todos los caracteres son números
    return num;
}//Identifucar si el texto contiene números o no para después revisar si es palíndromo o capícua
void ident_capicua(char letra[],int total) {
    int  cu=0, ci=total-1;
    bool capi;
    while (cu<=total && ci>=0) {
        if (letra[cu]==letra[ci]) {
            cu++;
            ci--;
            capi=true;
        }//Condición si ambos caracteres son iguales
        else {
            capi=false;
            break;
        }//Si no son iguales
    }//While para determinar si el inverso es igual al original
    if (capi==true) {
        prn("Su texto es capicua");
    }//Si es capicúa
    else if (capi==false) {
        prn("Su texto no es capicua");
    }//Si no es capicúa
}//Función para determinar si un número es capicúa
void ident_palindromo(char letra[],int total) {
    int  cu=0, ci=total-1;
    bool pali;
    while (cu<=total && ci>=0) {
        if (letra[cu]==letra[ci]) {
            cu++;
            ci--;
            pali=true;
        }//Condición si ambos caracteres son iguales
        else {
            cu=total;
            ci=-1;
            pali=false;
        }//Si no son iguales
    }//While para determinar si el inverso es igual al original
    if (pali==true) {
        prn("Su texto es palindromo");
    }//Si es palíndromo
    else if (pali==false) {
        prn("Su texto no es palindromo");
    }//Si no es palíndromo
}//Función para determinar si un texto es palíndromo
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