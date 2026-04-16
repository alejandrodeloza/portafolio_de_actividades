/* ************IDENTIFICADOR*****************
Nombre del autor: De Loza Esquivias Alejandro
Código: 222946692
Actividad: Actividad de aprendizaje 20
Fecha: 15 de abril de 2026
Propósito: Desarrollar un programa capaz de resolver y ejecutar el juego de las torres de hanoi.
*************************************** */
#include <iostream> //Biblioteca estandar
#include <limits>//Biblioteca de control de ingreso de carácteres
using namespace std;
//Declaración de funciones
void prn(const string &text);
void prn(int n);
bool checkmenu(int &n);
bool check(int &n);
void mostrarTorres();
void Iniciar_torres(int n);
bool mover_disc(int org, int dest);
bool revisar_tercera_torre(int n);
bool terminar_programa();
//Variables globales
int torres[3][9];

int main() {
    //Variables del main
    int discos, org, dest;
    prn("\t\t----Torres de hanoi---");
    while (true) {
        int movi=0;
        prn("-Ingrese el numero de discos con el que desea jugar-");
        while (!check(discos)){}//Evitar ingresos incorrectos
        Iniciar_torres(discos);
        while (true) {
            cout<<"Movimentos hasta ahora:"<<movi<<endl;
            mostrarTorres();
            prn("-Seleccione mover desde la torre(A=0__B=1__C=2-");
            cin >> org;
            prn("-A la torre (A=0__B=1__C=2-");
            cin >> dest;
            system("cls");
            if (mover_disc(org, dest))movi++;
            if (revisar_tercera_torre(discos)) {
                system("cls");
                prn("\t\t--Felicidades lo ha conseguido--");
                mostrarTorres();
                cout<<"Movimientos totales:"<<movi<<endl;
                break;
            }//Si coloca todos los discos en la torre C
        }//Ciclo de juego
        prn("\nDesea jugar de nuevo?\n[Si]Presione cualquier tecla.\n[No]Presione {N/n}");
        if (!terminar_programa())break;
    }

}//Fin del main
//Definición de funciones
void prn(const string &text) {
    cout << text << endl;
}//Función para imprimir cadenas
void prn(const int n) {
    cout << n << endl;
}//Función para imprimir números
bool checkmenu(int &n) {
    cin >> n;
    if (cin.fail() || n<1 || n>4 ) {
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
}//Función para identificar si la entrada es un carácter y que se encuentre entre 3 y 7
void mostrarTorres() {
    prn("========================================================");
    prn("\t\t---Torres de hanoi---");
     for (int posi = 8; posi >= 0; posi--){
         for (int torre=0; torre<3; torre++){
            if (torres[torre][posi] == 0)cout<<"\t ||";//Estructura de la torre
            else cout << "\t[ " << torres[torre][posi] << " ]";
             cout<<"\t";
        }//Mover entre las torres
         cout<<endl;
    }//Mover en la torre
    prn("========================================================");
    prn("     --TORRE-A--     --TORRE-B--     --TORRE-C--");
}//Función para mostrar el estado de las torres en cada movimiento
void Iniciar_torres(int n) {
    for (int posi = 8; posi >= 0; posi--) {
        for (int torre=0; torre<3; torre++) {
            if (torre!=0 || posi >n)torres[torre][posi] = 0;
            else torres[torre][posi]=n-posi;
        }
    }
}//Inicializar torres
bool mover_disc(int org, int dest) {
    int posorg=-1, posdest=-1;
    if (org<0||org>2||dest<0||dest>2){prn("**Torre inexistente**");  return false;}//Evitar errores
    for (int i=8; i>=0; i--) {
        if (torres[org][i]!=0) {
            posorg=i; break;
        }//Tomar el disco
    }//Encontrar el disco de hasta arriba
    if (posorg==-1){prn("**Error la torre se encuentra vacia**"); return false;}
    for (int i=0; i<9; i++) {
        if (torres[dest][i]==0){posdest=i; break;}//Ubicar
    }//Encontar espacio en el destino
    if (posdest>0 && torres[org][posorg]>torres[dest][posdest-1]) {
        prn("**No puedes colocar un disco sobre uno mas pequeño**"); return false;
    }//Evitar movimientos invalidos
    //Mover disco
    torres[dest][posdest]=torres[org][posorg];
    torres[org][posorg]=0;
    return true;
}//Mover discos de manera manual entre las torres
bool revisar_tercera_torre(int n) {
    int count=0;
    for (int pos=0;pos<9;pos++) {
        if (torres[2][pos]!=0){count++;}
    }//Mover por la torre
    if (count==n){return true;}//Ganador
    else return false;
}//Función para verificar si el jugador ha ganado
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