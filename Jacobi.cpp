/*
		METODOS NUMERICOS: *- MATRICES -*
		Método de Jacobi
		Archivos necesarios para compilar:
		Redondeo.hpp, Redondeo.cpp, Matriz_P.hpp, Matriz_P.cpp Operaciones_matriciales.hpp Operaciones_matriciales.cpp
*/
#include<iostream>
#include "Redondeo.hpp"
#include "Matriz_P.hpp"
#include "Operaciones_matriciales.hpp"

#define N_DEC 4 //Numero de decimales
using namespace std;

void MetodoJacobi(double **b, int b_Rows, int b_Cols , double **X , int X_Rows, int X_Cols  , double **D, int D_Rows, int D_Cols ,double **Sum_LU, int S_Rows, int S_Cols, double **Jacobi);

int main(){
    double **Matriz,**D,**b,**Sum_LU,**X0,**X;
	//creando punteros dobles
	Matriz=CrearMatriz_double(3,3);
	b=CrearMatriz_double(3,1);
	D=CrearMatriz_double(3,3);
	Sum_LU=CrearMatriz_double(3,3);
	X0=CrearMatriz_double(3,1);
	X=CrearMatriz_double(3,1);

    //pidiendo datos
	cout<<"Ingrese los elementos de la Matriz:\n";
	get_Matrix_double(Matriz,3,3);
	cout<<"Ingrese b:\n";
	get_Matrix_double(b,3,1);
	cout<<"Ingrese la aproximacion inicial:\n";
	get_Matrix_double(X0,3,1);

    //llenando la matriz diagonal
	for(int i=0 ; i< 3 ; i++)
		D[i][i]=Matriz[i][i];
	
	//LLENANDO LA MATRIZ L+U
	for(int i=0 ; i< 3 ; i++){
		for(int j=0 ; j< 3 ; j++){
			if(i!=j)
				Sum_LU[i][j]=Matriz[i][j];
		}
	}

    //Mostrando datos
	cout << "\n\nLa matriz ingresada es:";
	Show_Matrix_Double(Matriz,3,3);
	cout << "\n\n b es:";
	Show_Matrix_Double(b,3,1);
	cout << "\n\n La aproximacion inicial indicada es:";
	Show_Matrix_Double(X0,3,1);
	cout << "\n\n D es:";
	Show_Matrix_Double(D,3,3);
	cout << "\n\nLa matriz L+U:";
	Show_Matrix_Double(Sum_LU,3,3);

    X=X0;
		//jacobi
	cout << "\n\nEl resultado es:" << endl;
	for(int i=0 ; i< 100 ; i++){
		MetodoJacobi(b,3,1,X,3,1,D,3,3,Sum_LU,3,3,X);
		cout << "\nX[" << i+1 << "]";
		cout << endl;
		Show_Matrix_Double(X,3,1);
		cin.ignore(256,'\n');
	}

	LiberarMemoria_double(Matriz,3,3);
	LiberarMemoria_double(b,3,1);
	LiberarMemoria_double(D,3,3);
	LiberarMemoria_double(Sum_LU,3,3);
	LiberarMemoria_double(X0,3,1);
	LiberarMemoria_double(X,3,1);
    
    return 0;
}


void MetodoJacobi(double **b, int b_Rows, int b_Cols , double **X , int X_Rows, int X_Cols  , double **D, int D_Rows, int D_Cols ,double **Sum_LU, int S_Rows, int S_Cols, double **Jacobi){
	double **D_Inverso,**Mult1,**Mult2,**Mult3;
	D_Inverso=CrearMatriz_double(D_Rows,D_Cols);
	Mult1=CrearMatriz_double(D_Rows,b_Cols);
	Mult2=CrearMatriz_double(D_Rows,S_Cols);
	Mult3=CrearMatriz_double(D_Rows,X_Cols);

	for(int i=0 ; i< 3 ; i++)
		D_Inverso[i][i]=(1.0)/D[i][i];
	//X^(k+1)=D^(-1)*b - D^(-1) * (L+U)*X^k
	//D^(-1)*b
	cout << "\nD^(-1)*b";
	MultiplicacionMatricial(D_Inverso,D_Rows,D_Cols,b,b_Rows,b_Cols,Mult1);
	Show_Matrix_Double(Mult1,D_Rows,b_Cols);
	//D^(-1) * (L+U)
	cout << "\nD^(-1) * (L+U)";
	MultiplicacionMatricial(D_Inverso,D_Rows,D_Cols,Sum_LU,S_Rows,S_Cols,Mult2);
	Show_Matrix_Double(Mult2,D_Rows,S_Cols);
	//Mult2*X^k
	cout << "\nMult2*X^k";
	MultiplicacionMatricial(Mult2,D_Rows,S_Cols,X,X_Rows,X_Cols,Mult3);
	Show_Matrix_Double(Mult3,D_Rows,X_Cols);
	RestaMatricial(Mult1,D_Rows,b_Cols,Mult3,D_Rows,X_Cols,Jacobi);
	
	LiberarMemoria_double(D_Inverso,D_Rows,D_Cols);
	LiberarMemoria_double(Mult1,D_Rows,b_Cols);
	LiberarMemoria_double(Mult2,D_Rows,S_Cols);
	LiberarMemoria_double(Mult3,D_Rows,X_Cols);

}
