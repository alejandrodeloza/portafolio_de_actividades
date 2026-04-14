/* ************IDENTIFICADOR*****************
Nombre del autor: De Loza Esquivias Alejandro
Código: 222946692
Actividad: Actividad de aprendizaje 19
Fecha: 06 de abril de 2026
Propósito: Desarrollar un programa capaz de convertir números entre las bases comunes: binario, octal, decimal y hexadecimal.
*************************************** */
#include <iostream> //Biblioteca estandar
#include <limits>//Biblioteca de control de ingreso de carácteres
#include <cmath>//Biblioteca de funciones matemáticas
using namespace std;
//Declaración de funciones
void prn(const string &text);
void prn(int n);
bool checkmenu(int &n);
bool check(int &n);
void ingreso_de_base(int opibase, int &dec, string &BiOcHe);
void decimal_conversion(int dec,int base, string &conversion,const string &digitos);
void decimal_a_otras_bases(int dec, string &BiOcHe, int destino);
void otras_bases_conversion(int base,const string &BiOcHe, int &dec);
void otras_bases_a_decimal(const string &BiOcHe, int origen, int &dec);
bool terminar_programa();

int main() {
    //Variables del main
    int opibase=0,opsbase=0, dec=0;
    string BiOcHe;

    prn("\t--Conversor de las bases numericas comunes--\n");
    while (true) {
        prn("-Seleccione la base de origen que desea ingresar-");
        prn("[1]Decimal\n[2]Binario\n[3]Octal\n[4]Hexadecimal\n________________________________________________");
        while (checkmenu(opibase)==false){}//While para evitar errores.
        prn("________________________________________________");
        ingreso_de_base(opibase, dec, BiOcHe);
        while (true) {
            prn("\n-Seleccione la base a la que desea convertir su numero-");
            prn("[1]Decimal\n[2]Binario\n[3]Octal\n[4]Hexadecimal\n________________________________________________");
            while (checkmenu(opsbase)==false){}//While para evitar errores.
            prn("________________________________________________");
            //Determinar proceso
            if (opibase==1) {
                decimal_a_otras_bases(dec, BiOcHe, opsbase);
                prn(BiOcHe);
            }//Decimal a otras bases
            else {
                string BiOcHe2;
                dec=0;
                otras_bases_a_decimal(BiOcHe, opibase, dec);
                decimal_a_otras_bases(dec, BiOcHe2, opsbase);
                prn(BiOcHe2);
            }//El resto de las bases
            prn("\nDesea convertir a otra base?\n[Si]Presione cualquier tecla.\n[No]Presione {N/n}");
            if (terminar_programa()==false)break;
        }//Repetir conversiones
        prn("\nDesea continuar usando el programa?\n[Si]Presione cualquier tecla.\n[No]Presione {N/n}");
        if (terminar_programa()==false)break;
    }//Repetir programa
    prn("-Gracias por confiarnos sus conversiones-");
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
    if (cin.fail() || n<0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "**Ese no es un valor aceptado**\n--Intente nuevamente--"<<endl;
        return false;
    }
    else
        return true;
}//Función para identificar si la entrada es un carácter y que sea mayor a -1
void ingreso_de_base(int opibase, int &dec, string &BiOcHe) {
    switch (opibase) {
        case 1: {
            prn("Ingrese un numero en base decimal:");
            while (check(dec)==false) {}
            break;
        }//Decimal
        case 2: {
            prn("Ingrese un numero en base binaria:");
            bool ciclo=true;
            while (ciclo) {
                int cont=0;
                cin >> BiOcHe;
                for (int i=0; i<BiOcHe.length(); i++) {
                    if (BiOcHe[i]==48 || BiOcHe[i]==49) {
                        cont++;
                    }
                }//Recorrer el arreglo.
                if (cont==BiOcHe.length()) {ciclo=false;}
                else {prn("**Ese no es un valor aceptado**\n--Intente nuevamente--");}
            }//Revisar ingreso
            break;
        }//Binario
        case 3: {
            prn("Ingrese un numero en base octal:");
            bool ciclo=true;
            while (ciclo) {
                int cont=0;
                cin >> BiOcHe;
                for (int i=0; i<BiOcHe.length(); i++) {
                    if (BiOcHe[i]>=48 && BiOcHe[i]<=55) {
                        cont++;
                    }
                }//Recorrer el arreglo.
                if (cont==BiOcHe.length()) {ciclo=false;}
                else {prn("**Ese no es un valor aceptado**\n--Intente nuevamente--");}
            }//Revisar ingreso
            break;
        }//Octal
        case 4: {
            prn("Ingrese un numero en base hexadecimal:");
            bool ciclo=true;
            while (ciclo) {
                int cont=0;
                cin >> BiOcHe;
                for (int i=0; i<BiOcHe.length(); i++) {
                    if (BiOcHe[i]>=48 && BiOcHe[i]<=57 || BiOcHe[i]>=65 && BiOcHe[i]<=70) {
                        cont++;
                    }
                }//Recorrer el arreglo.
                if (cont==BiOcHe.length()) {ciclo=false;}
                else {prn("**Ese no es un valor aceptado**\n--Intente nuevamente--");}
            }//Revisar ingreso
            break;}//Hexadecimal
        default: {prn("Error inesperado");break;}//Posible error
    }//Revisar ingresos.
}//Función para ingresar el valor  a convertir y evitar errores
void decimal_conversion(int dec, const int base, string &conversion,const string &digitos) {
    if (dec==0){conversion+="0";}//Condición en case de que se ingrese un cero
    while (dec>0) {
        conversion += digitos[dec%base];
        dec/=base;
    }//Conversión
}//Conversión de decimal a el resto de bases
void decimal_a_otras_bases(int dec, string &BiOcHe, int destino) {
    BiOcHe="";
    //Variables locales
    int base=0;
    string array_inter, digitos;
    switch (destino) {
        case 1: {
            base=10; break;
        }
        case 2: {
            base=2; break;
        }
        case 3: {
            base=8; break;
        }
        case 4: {
            base=16; break;
        }
        default:{prn("Error inesperado");}
    }//Asignación de base
        switch (destino) {
            case 1: {
                digitos="0123456789";
                decimal_conversion(dec, base, array_inter, digitos);
                prn("--Su numero base decimal--");
                break;
            }
            case 2: {
                digitos="01";
                decimal_conversion(dec, base, array_inter, digitos);
                prn("--Su numero base binaria--");
                break;
            }
            case 3: {
                digitos="01234567";
                decimal_conversion(dec, base, array_inter, digitos);
                prn("--Su numero base octal--");
                break;
            }
            case 4: {
                digitos="0123456789ABCDEF";
                decimal_conversion(dec, base, array_inter, digitos);
                prn("--Su numero base hexadecimal--");
                break;
            }
            default:{prn("Error inesperado");}
        }//Ubicar el residuo en el arreglo
        for (int i=array_inter.length()-1;i>=0; i--) {
            BiOcHe+=array_inter[i];
        }//Rehacer el arreglo a la inversa
}//Función para convertir decimales a otras bases
void otras_bases_conversion(int base,const string &BiOcHe, int &dec) {
    int potencia=0;
    for (int i=BiOcHe.length()-1; i>=0; i--) {
        char digito=BiOcHe[i];
        int valor;
        if (digito>='0'&& digito<='9')valor=digito - '0';//Cambiar a int
        else valor=digito -'A'+10;
        dec+=valor * pow(base, potencia);
        potencia++;
    }//Recorrer de derecha a izquierda
}//Conversión de otras bases a decimal
void otras_bases_a_decimal(const string &BiOcHe, int origen, int &dec) {
    switch (origen) {
        case 2: {
            int base=2;
            otras_bases_conversion(base, BiOcHe, dec);
            break;
        }
        case 3: {
            int base=8;
            otras_bases_conversion(base, BiOcHe, dec);
            break;
        }
        case 4: {
            int base=16;
            otras_bases_conversion(base, BiOcHe, dec);
            break;
        }
        default: {prn("Error inesperado");}
    }//Asignar base y regresar el decimal
}//Función para convertir otras bases a decimales
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