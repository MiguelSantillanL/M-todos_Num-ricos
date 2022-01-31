//Codigos que permiten la creacion y liberacion de memoria de punteros dobles (Matriz)
#include<iostream>
#define N_DEC 4 //Numero de decimales 
//Creacion de Matriz
int **CrearMatriz_int(unsigned int N_rows, unsigned int N_Cols);
float **CrearMatriz_float(unsigned int N_rows, unsigned int N_Cols);
double **CrearMatriz_double(unsigned int N_rows, unsigned int N_Cols);

//Mostar Matriz
void Show_Matrix_Int(int **P_Matrix, unsigned int N_rows, unsigned int N_Cols);
void Show_Matrix_Float(float **P_Matrix, unsigned int N_rows, unsigned int N_Cols);
void Show_Matrix_Double(double **P_Matrix, unsigned int N_rows, unsigned int N_Cols);

//Dar Datos de Matriz
void get_Matrix_int(int **P_Matrix,unsigned int N_rows,unsigned int N_Cols);
void get_Matrix_float(float **P_Matrix,unsigned int N_rows,unsigned int N_Cols);
void get_Matrix_double(double **P_Matrix,unsigned int N_rows,unsigned int N_Cols);

//Liberion de memoria
void LiberarMemoria_int(int **P_Matrix,unsigned int N_rows,unsigned int N_Cols);
void LiberarMemoria_float(float **P_Matrix,unsigned int N_rows,unsigned int N_Cols);
void LiberarMemoria_double(double **P_Matrix,unsigned int N_rows,unsigned int N_Cols);

