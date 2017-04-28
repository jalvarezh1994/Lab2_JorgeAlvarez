#include <iostream>
#include <cmath>

using namespace std;

int factorial(int n);
float aproximarExp(int n,float x);

int main(){
	int opcion;
	cout<<"Menú"<<endl;
	cout<<"1. Ejercicio 1"<<endl;
	cout<<"2. Ejercicio 2"<<endl;
	cout<<"3. Salir"<<endl;
	cout<<"Ingrese una opción: ";
	cin>>opcion;
	switch(opcion){
		case 1:{
			float x;
			int n;
			cout<<"Ingrese el exponente: ";
			cin>>x;
			cout<<"Ingrese la cantidad de términos para la aproximación: ";
			cin>>n;
			cout<<"La aproximación queda: "<<aproximarExp(n,x)<<endl;
		}
		case 2:{
		}
		case 3:{
		}
	}
	return 0;
}

float aproximarExp(int n,float x){
	float sumatoria=0;
	for(int i=0;i<=n;i++){
		sumatoria+=(pow(x,i))/(factorial(i));
	}
	return sumatoria;
}

int factorial(int n){
	if(n==0){
		return 1;
        }
	int resultado=1;
	for(int i=1;i	<=n;i++){
		resultado=i*resultado;	
	}
	return resultado;
}
