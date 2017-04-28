#include <iostream>
#include <cmath>

using namespace std;

int factorial(int n);
float aproximarExp(int n,float x);
void imprimeCaracteristicasTrapezoide(float[],float[],float[],float[]);
float alturaTriangulo(float, float,float[]);
float areaTrapezoide(float[],float,float[],float);
bool validarPuntos(float[],float[],float[],float[]);

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
			float a[2],b[2],c[2],d[2];
		cout<<"Ingrese los puntos del trapezoide de la forma."<<endl;
			cout<<"D C"<<endl;
			cout<<"A B"<<endl;
			
			cout<<"Ingrese Ax: ";
			cin>>a[0];
			cout<<"Ingrese Ay: ";
			cin>>a[1];
			cout<<"Ingrese Bx: ";
                        cin>>b[0];
			cout<<"Ingrese By: ";
                        cin>>b[1];
			cout<<"Ingrese Cx: ";
                        cin>>c[0];
			cout<<"Ingrese Cy: ";
                        cin>>c[1];
			cout<<"Ingrese Dx: ";
                        cin>>d[0];
			cout<<"Ingrese Dy: ";
                        cin>>d[1];
			if(validarPuntos(a,b,c,d)){
				cout<<"No son puntos válidos"<<endl;
				break;
			}
			imprimeCaracteristicasTrapezoide(a,b,c,d);
			
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

float distancia(float punto1[],float punto2[]){
	float distancia;
	distancia=sqrt(pow(punto2[0]-punto1[0],2)+pow(punto2[1]-punto1[1],2));
	return distancia;
}

void imprimeCaracteristicasTrapezoide(float a[],float b[],float c[],float d[]){
	cout<<endl;
	cout<<"Los puntos son: "<<endl;
	cout<<"("<<a[0]<<","<<a[1]<<")"<<endl;
	cout<<"("<<b[0]<<","<<b[1]<<")"<<endl;
	cout<<"("<<c[0]<<","<<c[1]<<")"<<endl;
	cout<<"("<<d[0]<<","<<d[1]<<")"<<endl;
	
	cout<<endl;
	cout<<"Las distancias de los puntos son: "<<endl;
	cout<<"La distancia AB es: "<<distancia(a,b)<<endl;
	cout<<"La distancia BC es: "<<distancia(b,c)<<endl;
	cout<<"La distancia CD es: "<<distancia(c,d)<<endl;
	cout<<"La distancia DA es: "<<distancia(d,a)<<endl;
	
	float triangulo1[]={distancia(d,a),distancia(a,b),distancia(b,d)};
	float triangulo2[]={distancia(b,c),distancia(c,d),distancia(b,d)};
	cout<<endl;
	cout<<"Los lados del triángulo 1 son"<<endl;
	cout<<triangulo1[0]<<endl;
	cout<<triangulo1[1]<<endl;
	cout<<triangulo1[2]<<endl;

	cout<<endl;
        cout<<"Los lados del triángulo 2 son"<<endl;
        cout<<triangulo2[0]<<endl;
        cout<<triangulo2[1]<<endl;
        cout<<triangulo2[2]<<endl;

	float semiPerimetroT1=(triangulo1[0]+triangulo1[1]+triangulo1[2])/2;
	float semiPerimetroT2=(triangulo2[0]+triangulo2[1]+triangulo2[2])/2;
	cout<<endl;
	cout<<"Semiperimetro triángulo 1: "<<semiPerimetroT1<<endl;
	cout<<"Semiperimetro triángulo 2: "<<semiPerimetroT2<<endl;
	cout<<"Perímetro triángulo 1: "<<semiPerimetroT1*2<<endl;
	cout<<"Perímetro triángulo 2: "<<semiPerimetroT1*2<<endl;
	
	cout<<endl;
	cout<<"Las alturas del triángulo 1 son: "<<endl;
	cout<<"Altura 1: "<<alturaTriangulo(semiPerimetroT1,triangulo1[0],triangulo1)<<endl;
	cout<<"Altura 2: "<<alturaTriangulo(semiPerimetroT1,triangulo1[1],triangulo1)<<endl;
	cout<<"Altura 3: "<<alturaTriangulo(semiPerimetroT1,triangulo1[2],triangulo1)<<endl;
	
	cout<<endl;
	cout<<"Las alturas del triángulo 2 son: "<<endl;
        cout<<"Altura 1: "<<alturaTriangulo(semiPerimetroT2,triangulo2[0],triangulo2)<<endl;
        cout<<"Altura 2: "<<alturaTriangulo(semiPerimetroT2,triangulo2[1],triangulo2)<<endl;
        cout<<"Altura 3: "<<alturaTriangulo(semiPerimetroT2,triangulo2[2],triangulo2)<<endl;	

	cout<<endl<<"El área del trapezoide es: ";
	cout<<areaTrapezoide(triangulo1,semiPerimetroT1,triangulo2,semiPerimetroT2);
	cout<<endl;
}

float alturaTriangulo(float semiperimetro,float lado,float triangulo[]){
	float s=semiperimetro;
	float h;
	h=(2/lado)*sqrt(s*(s-triangulo[0])*(s-triangulo[1])*(s-triangulo[2]));
	return h;
}

float areaTrapezoide(float triangulo1[],float semip1,float triangulo2[],float semip2){
	float Area1=0.5*triangulo1[2]*alturaTriangulo(semip1,triangulo1[2],triangulo1);
	float Area2=0.5*triangulo2[2]*alturaTriangulo(semip2,triangulo2[2],triangulo2);
	return Area1+Area2;
}

bool validarPuntos(float a[],float b[],float c[],float d[]){
	bool esValido=true;
	if(a==b){
		esValido=false;}
	if(a==c){
                esValido=false;}
	if(a==d){
                esValido=false;}
	if(b==c){
                esValido=false;}
	if(b==d){
                esValido=false;}
	if(c==d){
                esValido=false;}
	return !esValido;
}
