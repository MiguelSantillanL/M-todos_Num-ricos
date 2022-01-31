/*
		METODOS NUMERICOS: *- MATRICES -*
		Método de Factorización LU
		Archivos necesarios para compilar:
		Redondeo.hpp, Redondeo.cpp, Matriz_P.hpp, Matriz_P.cpp Facorizacion_LU.cpp
*/
#include<iostream>
#include "Redondeo.hpp"
#include "Matriz_P.hpp"

#define N_DEC 4 //Numero de decimales 
using namespace std;

void FactorizacionLU(double **Matriz,int NRows,int NCols);
void SustitucionXST(double **Matrix_1,int NRows_1,int NCols_1,double **Matrix_2,int NRows_2,int NCols_2, double **XST);
void SustitucionYST(double **Matrix_1,int NRows_1,int NCols_1,double **Matrix_2,int NRows_2,int NCols_2, double **YST);

int main(){
    double **Matriz;
	//creando punteros dobles
	Matriz=CrearMatriz_double(3,3);
	//pidiendo datos
	cout<<"Ingrese los elementos de la Matriz:\n";
	get_Matrix_double(Matriz,3,3);
	//Factorizacion LU
	FactorizacionLU(Matriz,3,3);
	LiberarMemoria_double(Matriz,3,3);
    return 0;
}

void FactorizacionLU(double **Matriz,int NRows,int NCols){
	double **L,**U,**XR,**YS,**XS;
	L=CrearMatriz_double(3,3);
	U=CrearMatriz_double(3,3);
	XR=CrearMatriz_double(3,1);
	YS=CrearMatriz_double(3,1);
	XS=CrearMatriz_double(3,1);
	//pidiendo XR
	cout<<"Ingrese b:\n";
	get_Matrix_double(XR,3,1);
	cout << endl;
	//1
	for(int i=0 ; i<NCols ; i++){
		U[0][i]=Analyze_Number(Matriz[0][i],N_DEC);
		L[i][i]=1.0;
	}
	//2
	L[1][0]=Analyze_Number( ( Analyze_Number(Matriz[1][0],N_DEC ) / Analyze_Number( U[0][0],N_DEC )),N_DEC );
	L[2][0]=Analyze_Number( ( Analyze_Number(Matriz[2][0],N_DEC ) / Analyze_Number( U[0][0],N_DEC )),N_DEC );
	//3
	U[1][1]=Analyze_Number(( Analyze_Number( Matriz[1][1],N_DEC ) - Analyze_Number( (Analyze_Number( L[1][0],N_DEC )*Analyze_Number( U[0][1],N_DEC )),N_DEC )),N_DEC );
	U[1][2]=Analyze_Number( Matriz[1][2],4)-Analyze_Number((Analyze_Number(L[1][0],4)*Analyze_Number(U[0][2],4)),4);
	//4
	L[2][1]=Analyze_Number((Analyze_Number( Matriz[2][1],N_DEC ) - Analyze_Number( ( Analyze_Number(L[2][0],N_DEC )*Analyze_Number( U[0][1],4)),N_DEC) ),N_DEC )/Analyze_Number( U[1][1],N_DEC );
	//5
	U[2][2]=Analyze_Number( Matriz[2][2],N_DEC )-Analyze_Number( (Analyze_Number( L[2][0],N_DEC )*Analyze_Number( U[0][2],N_DEC )),N_DEC )-Analyze_Number( (Analyze_Number( L[2][1],N_DEC )*Analyze_Number( U[1][2],N_DEC )),4);
	cout << "\nMatriz L" << endl;
	Show_Matrix_Double(L,3,3);
	cout << "\nMatriz U" << endl;
	Show_Matrix_Double(U,3,3);
	cout << "\nb" << endl;
	Show_Matrix_Double(XR,3,1);
	
	//MULTIPLICACION DE L*b
	SustitucionYST(L,3,3,XR,3,1,YS);
	cout << "\nYS es" << endl;
	Show_Matrix_Double(YS,3,1);
	cout << endl;
	//MULTIPLICACION DE U*YS
	SustitucionXST(U,3,3,YS,3,1,XS);
	cout << "\nEl resultado es" << endl;
	Show_Matrix_Double(XS,3,1);
	
	LiberarMemoria_double(L,3,3);
	LiberarMemoria_double(U,3,3);
	LiberarMemoria_double(XR,3,3);
	LiberarMemoria_double(YS,3,3);

}

void SustitucionXST(double **Matrix_1,int NRows_1,int NCols_1,double **Matrix_2,int NRows_2,int NCols_2, double **XST){
    // YST Matricial.
	XST[2][0]=Analyze_Number( (Analyze_Number( Matrix_2[2][0],N_DEC )/Analyze_Number( Matrix_1[2][2],N_DEC )), N_DEC );
	XST[1][0]=Analyze_Number( (Analyze_Number( (Analyze_Number( Matrix_2[1][0],N_DEC )-Analyze_Number( (Analyze_Number( XST[2][0],N_DEC )*Analyze_Number( Matrix_1[1][2],N_DEC )),N_DEC )),N_DEC )/Analyze_Number( Matrix_1[1][1],N_DEC )),N_DEC );
	XST[0][0]=Analyze_Number( (Analyze_Number((Analyze_Number( Matrix_2[0][0],N_DEC )-Analyze_Number( (Analyze_Number( XST[2][0],N_DEC )*Analyze_Number( Matrix_1[0][2],N_DEC )),N_DEC )-Analyze_Number( (Analyze_Number( XST[1][0],N_DEC )*Analyze_Number( Matrix_1[0][1],N_DEC )),N_DEC )),N_DEC )/Analyze_Number( Matrix_1[0][0],4)),N_DEC );
}

void SustitucionYST(double **Matrix_1,int NRows_1,int NCols_1,double **Matrix_2,int NRows_2,int NCols_2, double **YST){
    // YST Matricial.
	YST[0][0]=Analyze_Number(Matrix_2[0][0],4);
	YST[1][0]=Analyze_Number( (Analyze_Number( Matrix_2[1][0],N_DEC )-Analyze_Number( (Analyze_Number( YST[0][0],N_DEC )*Analyze_Number( Matrix_1[1][0],N_DEC )),N_DEC )),N_DEC );
	YST[2][0]=Analyze_Number( (Analyze_Number( Matrix_2[2][0],N_DEC )-Analyze_Number( (Analyze_Number( YST[1][0],N_DEC )*Analyze_Number( Matrix_1[2][1],N_DEC )),N_DEC )-Analyze_Number( (Analyze_Number(YST[0][0],N_DEC )*Analyze_Number( Matrix_1[2][0],N_DEC )),N_DEC )),N_DEC );
}