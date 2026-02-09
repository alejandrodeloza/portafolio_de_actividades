/* ************IDENTIFICADOR*****************
Nombre del autor: De Loza Esquivias Alejandro
Código: 222946692
Actividad: Actividad de aprendizaje 8
Fecha: 08 de febrero de 2026
Propósito: Imprimir sucesión de fibonacci
*************************************** */
#include <iostream>
using namespace std;
int n[2], menu, limit;
bool whi=true;
int main() {
    cout<<"\t--Imprimir sucesión de Fibonacci--"<< endl;
    cout<<" --For = 1-- \n --While = 2-- \n --Do while = 3--"<<endl;
    cout<<"Selecione el ciclo que desea emplear:"<<endl;
    cin>>menu;
    n[0]=0,n[01]=1;
    switch (menu) {
        case 1: {
            cout<<"Establezca el limite de la sucesión de Fibonacci:"<<endl;
            cin>>limit;
            cout<<n[0]<<"--"<<n[1]<<"--";
            for(int i=0;i<limit;i++) {
                n[0]=n[0]+n[1];
                if(n[0]> limit || n[1]>limit) {
                    break;
                }
                cout<<n[0]<<"--";
                n[1]=n[1]+n[0];
                if(n[0]> limit || n[1]>limit) {
                    break;
                }
                cout<<n[1]<<"--";
            }
            break;
        }
        case 2: {
            cout<<"Establezca el limite de la sucesión de Fibonacci:"<<endl;
            cin>>limit;
            cout<<n[0]<<"--"<<n[1]<<"--";
            while (whi) {
                n[0]=n[0]+n[1];
                if(n[0]> limit || n[1]>limit) {
                    break;
                }
                cout<<n[0]<<"--";
                n[1]=n[1]+n[0];
                if(n[0]> limit || n[1]>limit) {
                    break;
                }
                cout<<n[1]<<"--";
            }
            break;
        }
        case 3: {
            cout<<"Establezca el limite de la sucesión de Fibonacci:"<<endl;
            cin>>limit;
            cout<<n[0]<<"--"<<n[1]<<"--";
            do {
                n[0]=n[0]+n[1];
                if(n[0]> limit || n[1]>limit) {
                    break;
                }
                cout<<n[0]<<"--";
                n[1]=n[1]+n[0];
                if(n[0]> limit || n[1]>limit) {
                    break;
                }
                cout<<n[1]<<"--";
            } while (whi);
            break;
        }
            default: {
            cout<<"Ciclo no encontrado :("<<endl;
            break;
        }
    }//fin de switch

}//Fin main