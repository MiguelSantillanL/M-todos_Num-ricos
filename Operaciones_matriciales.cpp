#include "Operaciones_matriciales.hpp"

void RestaMatricial(double **A, int ARows, int ACols, double **B, int BRows, int BCols, double **Resta){		
		for (int i = 0; i < ARows; i++){ 
            for (int j = 0 ; j < BCols; j++)
				Resta[i][j]= A[i][j] - B[i][j];
            }
}

void SumaMatricial(double **A, int ARows, int ACols, double **B, int BRows, int BCols, double **Suma){		
		for (int i = 0; i < ARows; i++){ 
            for (int j = 0 ; j < BCols; j++)
				Suma[i][j]= A[i][j] + B[i][j];
            }
}

void MultiplicacionMatricial(double **Matrix_1,int NRows_1,int NCols_1,double **Matrix_2,int NRows_2,int NCols_2, double **Matrix_Mult){
	 // Multiplicacion Matricial.
    for(int i=0; i<NRows_1; ++i){ // NRows_1
        for(int j=0; j<NCols_2; ++j){ // NCols_2
            for(int z=0; z<NCols_1; ++z){ //puede ser  NCols_1 o  NRows_1 ya que en teoria son el mismo numero
               // C[i][j] += A[i][z] * B[z][j];
				Matrix_Mult[i][j] += Analyze_Number( Matrix_1[i][z],N_DEC ) * Analyze_Number( Matrix_2[z][j] ,N_DEC);
				Matrix_Mult[i][j] = Analyze_Number(Matrix_Mult[i][j], N_DEC);
			}
		}
	}
}
