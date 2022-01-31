/*
		METODOS NUMERICOS: *- CEROS DE UNA FUNCION -*
		Método de Iteración en el Punto Fijo
		Archivos necesarios para compilar:
		Redondeo.hpp, Redondeo.cpp, Punto_fijo.cpp
*/

#include <iostream>
#include <cmath>
#include "Redondeo.hpp"

#define N_DEC 4 //Numero de decimales 

//Funcion a evaluar, en cada operacion es preferible usar Analyze_Number() ya que el redondeo es necesario para exactitud 
//Puede opimirse
#define Funcion(x) (Analyze_Number( (Analyze_Number(cos(x),N_DEC) /3.0) ,N_DEC) )

using namespace std;

int main() {
    double x=0.2;

    for(int i=0 ; i< 50 ; i++){
		cout << "X[" << i << "]= " << x;
		x=Funcion(x);
		cin.ignore(256,'\n');//Cada vez que se da enter se muestran nuevos valores (Puede opimirse)
	}

	return 0;
}
