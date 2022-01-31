/*
		METODOS NUMERICOS: *- CEROS DE UNA FUNCION -*
		Método de Newton-Raphson
		Archivos necesarios para compilar:
		Redondeo.hpp, Redondeo.cpp, Newton-Raphson.cpp
*/


#include <iostream>
#include <cmath>
#include "Redondeo.hpp"

#define N_DEC 4 //Numero de decimales 

//Funcion a evaluar, en cada operacion es preferible usar Analyze_Number() ya que el redondeo es necesario para exactitud 
//Puede opimirse
#define Funcion_NR(x) ( Analyze_Number( (Analyze_Number(cos(x),N_DEC) - 3.0*x), N_DEC) )
#define Derivada_NR(x) ( Analyze_Number( (-Analyze_Number(sin(x),N_DEC) - 3.0 ), N_DEC) )

using namespace std;

int main() {
    double x=0.3;//x0

    for(int i=0 ; i< 50 ; i++){
		cout << "X[" << i << "]= " << x;
		x = x - ( Funcion_NR(x)/Derivada_NR(x) );
        x = Analyze_Number(x,4);
		cin.ignore(256,'\n');//Cada vez que se da enter se muestran nuevos valores (Puede opimirse)
	}

	return 0;
}
