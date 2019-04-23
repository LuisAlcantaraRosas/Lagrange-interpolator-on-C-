#include <iostream>
#include <stdio.h>
using namespace std;
int PointsQuantity;
double Sum=0, Product=1,x;
int main()
{
	//Pedir cantidad de puntos a interpolar
	cout<<"Ingrese cantidad de puntos a interpolar: ";
	cin>>PointsQuantity;
	//Definir vector de puntos
	float Points[PointsQuantity-1][2];
	//Pedir cada punto individualmente de forma tabular
	for(int i=0; i<=PointsQuantity-1;i++)
	{
		cout<<"Ingrese el punto "<<i<<":"<<endl;
		scanf("%f %f",&Points[i][0],&Points[i][1]);
	}
	//Pedir el valor de x a interpolar.
	cout<<"Ingrese el valor de x que desee interpolar:"<<endl;
	cin>>x;
	//Iniciar algoritmo de interpolación de Lagrange
	for(int k=0; k<=PointsQuantity-1;k++)
	{
		Product=1;
		for(int i=0; i<=PointsQuantity-1;i++)
		{
			if(k!=i)
			{
				Product=((x-Points[i][0])/(Points[k][0]-Points[i][0]))*Product;
			}
		}
		Sum=Sum+Product*Points[k][1];
	}
	//Dar el valor obtenido
	cout<<"El valor x interpolado en x="<<x<<" es f(x)="<<Sum<<endl;
}
