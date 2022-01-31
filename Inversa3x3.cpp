#include "Inversa3x3.hpp"

void Inversa3x3(double **Matriz, double **Inversa){
	double determinante;
	determinante = 0.0;
	
	for(int i = 0; i < 3; i++)
		determinante = Analyze_Number( ( determinante + (Analyze_Number( Matriz[0][i],N_DEC ) * ( Analyze_Number( Matriz[1][(i+1)%3],N_DEC ) * Analyze_Number( Matriz[2][(i+2)%3],N_DEC ) - Analyze_Number( Matriz[1][(i+2)%3],N_DEC ) * Analyze_Number( Matriz[2][(i+1)%3],N_DEC ))) ),N_DEC );

	//std::cout<<"\nEl determinante de la matriz ingresada es: "<<determinante;
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++)
			Inversa[i][j] = Analyze_Number( (((Analyze_Number(Matriz[(j+1)%3][(i+1)%3],4) * Analyze_Number(Matriz[(j+2)%3][(i+2)%3],4)) - (Analyze_Number(Matriz[(j+1)%3][(i+2)%3],4) * Analyze_Number(Matriz[(j+2)%3][(i+1)%3],4)))/ determinante),N_DEC );
	}
}