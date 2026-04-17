/* ************IDENTIFICADOR*****************
Nombre del autor: De Loza Esquivias Alejandro
Código: 222946692
Actividad: Actividad de aprendizaje 21
Fecha: 16 de abril de 2026
Propósito: Desarrollar un programa ejecutar el juego del ahorcado con una base de palabras internas.
*************************************** */
#include <iostream> //Biblioteca estandar
#include <limits>//Biblioteca de control de ingreso de carácteres
#include <ctime>//Biblioteca para generar números aleatorios
using namespace std;
//Declaración de funciones
void prn(const string &text);
void prn(int n);
bool checkmenu(int &n);
bool check(int &n);
void mostrar_tablero(int fallidos,const string &text, char letra, string &avance);
bool revisar_letra(const string &text, char letra);
bool revisar_avance(const string &text, const string &avance);
bool terminar_programa();

//Variables globales
string base_de_pal[15]={"Libre","Acuarela","Caleidoscopio","Viento","Esmeralda","Mundo","Burbuja",
    "Horizonte","Uniforme","Galaxia","Pollo","Susurro","Laberinto","Antorcha","Tio iron"};
int main() {
    //Variables locales
    int op;
    prn("\t\t---Hangman the game---");
    while (true) {
        char letra=' ';
        srand(time(NULL));
        prn("-Selecione el modo de juego-");
        prn("[1]--Contra la computadora--\n[2]--Contra un segundo jugador--");
        cout<<":";
        while (!checkmenu(op)){}
        switch (op) {
            case 1: {
                int fallidos=6, pal=rand() % 15;
                string palabra=base_de_pal[pal];
                string avance(palabra.length(), '_');
                while (true) {
                    system("cls");
                    mostrar_tablero(fallidos,palabra,letra, avance);
                    cout<<endl<<"Ingrese su letra:";
                    cin>>letra;
                    if (revisar_letra(palabra,letra)==false)fallidos--;
                    if (revisar_avance(palabra,avance)==true){prn("--Felicidades ha ganado--");break;}
                    if (fallidos==0) {
                        prn("Desea reintentar?__Si_Presione cualquier tecla__No_[N] o [n]");
                        if (terminar_programa())fallidos=6;
                        else break;
                    }
                }//Mantener juego
                break;
            }//Jugar con palabras de la base del programa.
            case 2: {
                int fallidos=6;
                string palabra;
                prn("Ingrese su palabra jugador numero 2:");
                cin>>palabra;
                string avance(palabra.length(), '_');
                while (true) {
                    system("cls");
                    mostrar_tablero(fallidos,palabra,letra, avance);
                    cout<<endl<<"Ingrese su letra:";
                    cin>>letra;
                    if (revisar_letra(palabra,letra)==false)fallidos--;
                    if (revisar_avance(palabra,avance)==true){prn("--Felicidades ha ganado");break;}
                    if (fallidos==0) {
                        prn("Desea reintentar?__Si_Presione cualquier tecla__No_[N] o [n]");
                        if (terminar_programa())fallidos=6;
                        else break;
                    }
                }//Mantener juego
                break;
            }//Jugar contra jugador 2.
            default: {prn("**Error inesperado**"); break;}
        }
        prn("\nDesea jugar de nuevo?\n[Si]Presione cualquier tecla.\n[No]Presione {N/n}");
        if (!terminar_programa())break;
    }//Mantener programa
}//Fin del main
//Definición de funciones
void prn(const string &text) {
    cout << text << endl;
}//Función para imprimir cadenas.
void prn(const int n) {
    cout << n << endl;
}//Función para imprimir números.
bool checkmenu(int &n) {
    cin >> n;
    if (cin.fail() || n<1 || n>2 ) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "**Ese no es un valor aceptado**\n--Intente nuevamente--"<<endl;
        return false;
    }
    else
        return true;
}//Función para identificar si la entrada es un carácter en un menú.
bool check(int &n) {
    cin >> n;
    if (cin.fail() || n<3 || n>7) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "**Ese no es un valor aceptado**\n--Intente nuevamente--"<<endl;
        return false;
    }
    else
        return true;
}//Función para identificar si la entrada es un carácter y que se encuentre entre 3 y 7.
void mostrar_tablero(int fallidos,const string &text, char letra, string &avance) {
    prn("\t\t--Hangman--");
    cout<<"-Fallos restantes ["<<fallidos<<"]-"<<endl;
    prn("_________________________________________________");
    prn("=======================");
    cout<<"||\t\t";
    if (fallidos<=5)prn("  |");//Cuerda
    else cout<<endl;
    cout<<"||\t\t";
    if (fallidos<=4)prn("  ()");//Cabeza
    else cout<<endl;
    cout<<"||\t\t";
    if (fallidos<=3)cout<<" /";//Torso
    if (fallidos<=2)prn("|\\");//Brazos
    else cout<<endl;
    cout<<"||\t\t";
    if (fallidos<=1)prn("/\\");//Piernas
    else cout<<endl;
    prn("||");//Poste
    prn("_________________________________________________");
    cout<<"\n\t-Avance de la palabra-\n\t\t";
    avance[0]=text[0];
    for (int i=0; i<text.length(); i++) {
        if (tolower(letra)==tolower(text[i]))avance[i]=letra;
    }//Identificar avance.
    for (int i=0; i<text.length(); i++) {
        cout<<avance[i];
    }//Mostrar el avance.
}//Función para mostrar el juego.
bool revisar_letra(const string &text, char letra) {
    for (int i=0; i<text.length(); i++) {
        if (text[i]==letra){return true;}
        if (tolower(text[i]) == tolower(letra)) return true;
    }//Buscar
    return false;
}//Buscar letra en la palabra.
bool revisar_avance(const string &text, const string &avance) {
    for (int i=0; i<text.length(); i++) {
        if (avance[i] == '_') return false;
    }//Revisar
    return true;
}//Función para saber si se ganó.
bool terminar_programa() {
    char rep;
    cin>>rep;
    cin.ignore(1000,'\n');
    system("cls");
    if (rep=='N' || rep=='n')
        return false;
    else {
        return true;
    }
}//Función para darle al usuario la decisión de salir del programa