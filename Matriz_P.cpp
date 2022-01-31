#include "Matriz_P.hpp"

//Valores Int
int **CrearMatriz_int(unsigned int N_rows, unsigned int N_Cols){
	int **P_Matrix=0;
	P_Matrix=new int*[N_rows]; //reservando memoria para las Filas

	for(unsigned int i=0 ; i<N_rows ; i++)
		P_Matrix[i]=new int[N_Cols];//reservar memoria para las Columnas

	return P_Matrix;
}

void Show_Matrix_Int(int **P_Matrix, unsigned int N_rows, unsigned int N_Cols){
	for(unsigned int i = 0; i < N_rows; i++){
		for(unsigned int j = 0; j < N_Cols; j++)
			std::cout<< P_Matrix[i][j] <<"\t";
		std::cout<<"\n";
	}
}

void get_Matrix_int(int **P_Matrix, unsigned int N_rows, unsigned int N_Cols){
	//pidiendo datos
	//std::cout<<"Ingrese los elementos de la Matriz:\n";
	for ( unsigned int i=0 ; i<N_rows ; i++){
		for(unsigned int j = 0; j <N_Cols; j++){
				std::cout << "Valor [" << i << "," << j << "]= ";
				std::cin>>P_Matrix[i][j]; std::cin.ignore(256,'\n');
			}
			std::cout << "\n";
		}
}

void LiberarMemoria_int(int **P_Matrix, unsigned int N_rows, unsigned int N_Cols){
	for(unsigned int i=0 ; i<N_rows ; i++)
		delete[] P_Matrix[i];

	delete P_Matrix;
}


//Valores Float
float **CrearMatriz_float(unsigned int N_rows, unsigned int N_Cols){
	float **P_Matrix=0;
	P_Matrix=new float*[N_rows]; //reservando memoria para las Filas

	for(unsigned int i=0 ; i<N_rows ; i++)
		P_Matrix[i]=new float[N_Cols];//reservar memoria para las Columnas

	return P_Matrix;
}

void Show_Matrix_Float(float **P_Matrix, unsigned int N_rows, unsigned int N_Cols){
	for(unsigned int i = 0; i < N_rows; i++){
		for(unsigned int j = 0; j < N_Cols; j++)
			std::cout<< P_Matrix[i][j] <<"\t";
		std::cout<<"\n";
	}
}

void get_Matrix_float(float **P_Matrix, unsigned int N_rows, unsigned int N_Cols){
	//pidiendo datos
	//std::cout<<"Ingrese los elementos de la Matriz:\n";
	for ( unsigned int i=0 ; i<N_rows ; i++){
		for(unsigned int j = 0; j <N_Cols; j++){
				std::cout << "Valor [" << i << "," << j << "]= ";
				std::cin>>P_Matrix[i][j]; std::cin.ignore(256,'\n');
			}
			std::cout << "\n";
		}
}

void LiberarMemoria_float(float **P_Matrix, unsigned int N_rows, unsigned int N_Cols){

	for(unsigned int i=0 ; i<N_rows ; i++)
		delete[] P_Matrix[i];

	delete P_Matrix;
}


//Valores Double
double **CrearMatriz_double(unsigned int N_rows, unsigned int N_Cols){
	double **P_Matrix=0;
	P_Matrix=new double*[N_rows]; //reservando memoria para las Filas

	for(unsigned int i=0 ; i<N_rows ; i++)
		P_Matrix[i]=new double[N_Cols];//reservar memoria para las Columnas

	return P_Matrix;
}

void Show_Matrix_Double(double **P_Matrix, unsigned int N_rows, unsigned int N_Cols){
	for(unsigned int i = 0; i < N_rows; i++){
		for(unsigned int j = 0; j < N_Cols; j++)
			std::cout<< P_Matrix[i][j] <<"\t";
		std::cout<<"\n";
	}
}


void get_Matrix_double(double **P_Matrix, unsigned int N_rows, unsigned int N_Cols){
	//pidiendo datos
	//std::cout<<"Ingrese los elementos de la Matriz:\n";
	for ( unsigned int i=0 ; i<N_rows ; i++){
		for(unsigned int j = 0; j <N_Cols; j++){
				std::cout << "Valor [" << i << "," << j << "]= ";
				std::cin>>P_Matrix[i][j]; std::cin.ignore(256,'\n');
			}
			std::cout << "\n";
		}
}

void LiberarMemoria_double(double **P_Matrix, unsigned int N_rows, unsigned int N_Cols){
	for(unsigned int i=0 ; i<N_rows ; i++)
		delete[] P_Matrix[i];

	delete P_Matrix;
}
