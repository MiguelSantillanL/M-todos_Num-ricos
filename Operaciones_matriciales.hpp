#include "Matriz_P.hpp"
#include "Redondeo.hpp"


void RestaMatricial(double **A, int ARows, int ACols, double **B, int BRows, int BCols, double **Resta);
void SumaMatricial(double **A, int ARows, int ACols, double **B, int BRows, int BCols, double **Suma);
void MultiplicacionMatricial(double **Matrix_1,int NRows_1,int NCols_1,double **Matrix_2,int NRows_2,int NCols_2, double **Matrix_Mult);