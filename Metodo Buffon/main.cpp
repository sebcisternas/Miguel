#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<cmath>
#include<ctime>

using namespace std;
#define pi 3.1415926536
#define randomize() srand((unsigned)time(NULL))

double distancia;
int pantalla;

class Aguja{
public:
    double longitud;
    double angulo;
    double x;
    bool verificar();
    bool agujavar();
};

bool Aguja::agujavar(){
    if(longitud<=distancia) return true;
    else return false;
}

bool Aguja::verificar(){
    double b=longitud*sin(angulo);
    if(agujavar()){
        if(x+b>=distancia) return true;
        else return false;
    }
    else{
        if(b>=distancia) return true;
        else{
            if(x+b>=distancia) return true;
            else return false;
        }
    }
}

void getpantalla(){
    int sc;
    cin.clear();
    sc=_getch();
    switch(sc){
    case 's':
        pantalla=1;
        break;
    case 'p':
        pantalla=2;
        break;
    case 'a':
        pantalla=3;
        break;
    default:
        getpantalla();
        break;
    }
}

struct prob{
    unsigned int tot;
    unsigned int num;
};

int main(){
    unsigned int n;
    unsigned int i;
    Aguja L;
    register bool* ifNeedle;
    prob p;
    double res;
    double piCal;
    int ch;

    for(;;){

        randomize();
        cin.clear();
        cout<<"Distancia entre Lineas"<<endl;
        cin>>distancia;

        cin.clear();
        cout<<"Largo de la Aguja"<<endl;
        cin>>L.longitud;

        cin.clear();
        cout<<"Iteraciones de la aguja"<<endl;
        cin>>n;
        ifNeedle=(bool *)malloc(n*sizeof(bool));

        cin.clear();
        cout<<endl<<"s: ver todos los pasos, p: paso a paso, a: solo ver el resultado total"<<endl<<endl;
        getpantalla();

        cout<<""<<endl<<endl;


        if(L.agujavar()){
            p.tot=1;
            p.num=1, ifNeedle[0]=true;
            for(i=1;i<n;i++){
                p.tot++;

                L.angulo=(rand()%30000)/29999.0*pi;
                L.x=(rand()%30000)/29999.0*distancia;

                if(L.verificar()){
                    p.num++;
                    ifNeedle[i]=true;
                }
                else ifNeedle[i]=false;
            }
        }

        else{
            p.tot=1;
            p.num=0, ifNeedle[0]=false;
            for(i=1;i<n;i++){
                p.tot++;

                L.angulo=(rand()%30000)/29999.0*pi;
                L.x=(rand()%30000)/29999.0*distancia;

                if(L.verificar()){
                    p.num++;
                    ifNeedle[i]=true;
                    ifNeedle[i]=false;
                }
            }
        }


        switch(pantalla){
        case 1:
            for(i=0;i<n;i++){
                cout<<i;
                if(ifNeedle[i]) cout<<" : "<<"Correcto"<<endl;
                else cout<<" : "<<"Incorrecto"<<endl;
            }
            cout<<endl<<endl;
            break;
        case 2:
            for(i=0;i<n;i++){
                _getch();
                cout<<i;
                if(ifNeedle[i]) cout<<" : "<<"Correcto"<<endl;
                else cout<<" : "<<"Incorrecto"<<endl;
            }
            cout<<endl<<endl;
            break;
        default:
            break;
        }


        res=p.num/(p.tot*1.0);
        if(L.longitud<=distancia) piCal=2*L.longitud/(distancia*res);
        else piCal=(1/(res-1))*((2*L.longitud/distancia)-(2/distancia)*(sqrt(L.longitud*L.longitud-distancia*distancia)+distancia*asin(distancia/L.longitud)));

        cout<<"Número total de intentos : ";
        cout<<p.tot<<endl<<endl;
        cout<<"Numero de Exitos : ";
        cout<<p.num<<endl<<endl;
        cout<<"Probabilidad : ";
        cout<<res<<endl<<endl<<endl;
        cout<<"Calculo de pi ";
        cout<<piCal<<endl<<endl;
        cout<<"Presione Q para salir, de lo contrario presione otra tecla para reiniciar"<<endl;
        cin.clear();
        ch=_getch();
        switch(ch){
        case 'q':
            exit(0);
            break;
        default:
            system("cls");
            break;
        }

        free(ifNeedle);
    }

    return 0;
}







