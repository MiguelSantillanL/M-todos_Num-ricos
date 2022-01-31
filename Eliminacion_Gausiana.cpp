/*
		METODOS NUMERICOS: *- MATRICES -*
		Método de Eliminación Gaussiana
		Archivos necesarios para compilar:
		Redondeo.hpp, Redondeo.cpp, Matriz_P.hpp, Matriz_P.cpp Eliminacion_Gausiana.cpp
*/

#include<iostream>
#include "Redondeo.hpp"
#include "Matriz_P.hpp"
#define N_DEC 4 //Numero de decimales 

void EliminacionGausiana(double **Matriz,int N_Rows,int N_Cols);
void get_Matrix_Gauss(double **Matriz,int n);
void MostrarMatriz(double **Matriz,int n);
void get_Matrix(double **P_Matrix, unsigned int N_rows, unsigned int N_Cols);

using namespace std;

int main(){
    double **Matriz;
	int  n;
	cout << "Numero de ecuacuaciones? " ; cin >> n; cin.ignore(256,'\n');
	
	//creando punteros dobles
	//La matriz es cuadrada
	Matriz=CrearMatriz_double( n, (n+1) );
	get_Matrix_Gauss(Matriz,n);

	//Mostrando datos
	cout << "\n\nLa matriz ingresada es:" << endl;
	MostrarMatriz(Matriz,n);
	EliminacionGausiana(Matriz,n,n);
	LiberarMemoria_double(Matriz,n,n);

    return 0;
}

void EliminacionGausiana(double **Matriz,int N_Rows,int N_Cols){
	double x[N_Rows],t = 0;

	//Eliminamos (x=0) valores por debajo a la diagonal para tratar de dejarlo en forma de gauss
	for (int i=0 ; i<(N_Rows-1) ; i++){            
        for (int k=(i+1) ; k<N_Cols ; k++){
                t=Analyze_Number( ( Analyze_Number( Matriz[k][i],N_DEC )/Analyze_Number( Matriz[i][i],N_DEC ) ), N_DEC );
                for (int j=0;j<=N_Rows;j++)
                    Matriz[k][j]=Analyze_Number( (Analyze_Number( Matriz[k][j],N_DEC )-Analyze_Number((t*Analyze_Number( Matriz[i][j],N_DEC )),N_DEC)), N_DEC );
					//cout << endl;
					//MostrarMatriz_double(Matriz,N_Rows,N_Cols);
			}
	}	
	
	for (int i=(N_Rows-1) ; i>=0 ; i--){                       
        x[i]=Analyze_Number(Matriz[i][N_Cols],N_DEC);  //obtenemos el valor de la ultima incognita dejando la ultima ecuacion como ( 0 0 1 = X )          
        for (int j=i+1;j<N_Cols;j++){ //Recorre la comlna y compara para multiplicar y restar dependiendo el valor de x[]
            if (j!=i)    
                x[i] = Analyze_Number( (x[i]-Analyze_Number( (Matriz[i][j]*x[j]),N_DEC )), N_DEC );
		}
        x[i]=Analyze_Number((x[i]/Matriz[i][i]),4);  //Guardamos resultados de X,Y,J, etc en x[]
    }
	//Mostramos valores resultados
	cout << "\n\nLos resultados de la matriz x,y,z respectivamente son:" << endl;	
	for (int i=0;i<N_Rows;i++)
        cout<< "x[" << i << "]= " << x[i]<<endl;   
}

//-----------------------------------------------------------------------------------------------------------
//Las siguientes funciones son una modificacion de Matriz_P.cpp pero ya que en la eliminacion gausiana el formato
//es un poco diferente entonces solo se cambiaron un poco

void get_Matrix_Gauss(double **Matriz,int n){
	//pidiendo datos 
	cout<<"Ingrese los elementos de la Matriz:\n";
	for ( int i=0 ; i<n ; i++){
		cout << "\nIngrese la ecuacion No." << i+1 << endl;
		for(int j = 0; j <= n; j++){
			if(j==(n)){
				cout << "----------------" << endl;
				cout << "Valor [" << i << "," << j << "]= ";
				cin>>Matriz[i][j]; cin.ignore(256,'\n');
				Matriz[i][j]  = Analyze_Number( Matriz[i][j],N_DEC);
			}
			else{ 
				cout << "Valor [" << i << "," << j << "]= ";
				cin>>Matriz[i][j]; cin.ignore(256,'\n');
				Matriz[i][j] = Analyze_Number( Matriz[i][j],N_DEC );
			}
		}
	}
}

void MostrarMatriz(double **Matriz,int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= n; j++){
			if(j==(n))		cout << "|" << Matriz[i][j];
			else 				cout<< Matriz[i][j] <<"\t";	
		}
		cout<<"\n";
	}	

}

