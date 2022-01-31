/*
		METODOS NUMERICOS: *- MATRICES -*
		Método de Eliminación Gaussiana
		Archivos necesarios para compilar:
		Redondeo.hpp, Redondeo.cpp, Matriz_P.hpp, Matriz_P.cpp Inversa.hpp, Inversa.cpp, Inversa3x3.hpp, Inversa3x3.cpp
		Operaciones_matriciales.hpp, Operaciones_matriciales.hpp, Metodo_de_la_Inversa.cpp 
*/


#include<iostream>
#include "Redondeo.hpp"
#include "Matriz_P.hpp"
#include "Inversa3x3.hpp"
#include "Operaciones_matriciales.hpp"

#define N_DEC 4 //Numero de decimales 
using namespace std;

int main(){
    double **Matriz,**Inversa,**XR,**Resultado;
    //creando punteros dobles
	Matriz=CrearMatriz_double(3,3);
	Inversa=CrearMatriz_double(3,3);
	XR=CrearMatriz_double(3,1);
	Resultado=CrearMatriz_double(3,1); //Multiplicacion=CrearMatriz(NRows_1,NCols_2);

    //pidiendo datos
	cout<<"Ingrese los elementos de la Matriz:\n"; 
	get_Matrix_double(Matriz,3,3);//Primer mienmbro de cada ecuacion
	cout<<"\n\nIngrese los segundos miembros de cada ecuacion:\n";
	get_Matrix_double(XR,3,1);//Prisegundos mienmbros de cada ecuacion
	Inversa3x3(Matriz,Inversa);//Calculando inversa
	MultiplicacionMatricial(Inversa,3,3,XR,3,1,Resultado);//Calculando resultados de X,Y,Z

	//Mostrando datos
	cout << "\n\nLa matriz ingresada es:\n";
	Show_Matrix_Double(Matriz,3,3);
    cout << "\n\nCon los resultados ingresados de x,y,z respectivamente:\n";
	Show_Matrix_Double(XR,3,1);
	cout << "\n\nLa inversa es: " << endl;
	Show_Matrix_Double(Inversa,3,3);
	cout << "\n\nLos resultados de la matriz x,y,z respectivamente son:\n";
	Show_Matrix_Double(Resultado,3,1);
    
    LiberarMemoria_double(Matriz,3,3);
	LiberarMemoria_double(Inversa,3,3);
	LiberarMemoria_double(XR,3,3);
	LiberarMemoria_double(Resultado,3,1);

    return 0;
}
