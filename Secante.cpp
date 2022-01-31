/*
		METODOS NUMERICOS: *- CEROS DE UNA FUNCION -*
		Método de la Secante
		Archivos necesarios para compilar:
		Redondeo.hpp, Redondeo.cpp, Secante.cpp
*/

#include <iostream>
#include <cmath>
#include "Redondeo.hpp"

#define N_DEC 4 //Numero de decimales 

//Funcion a evaluar, en cada operacion es preferible usar Analyze_Number() ya que el redondeo es necesario para exactitud 
//Puede opimirse
#define Funcion_Sec(x) ( Analyze_Number( (Analyze_Number( pow(x,3),N_DEC ) - x - 1.0), N_DEC) )


using namespace std;

int main() {
    double xa,xb,fxm = 0,fax = 0,fbx = 0;
    xa=1.0;
	xb=2.0;

    for(int i=0 ; i< 100 ; i++){ 
        xa = Analyze_Number(xa,N_DEC); 
		xb = Analyze_Number(xb,N_DEC);
		fax = Funcion_Sec(xa);
		fbx = Funcion_Sec(xb);
		fxm = Analyze_Number( ( xb-fbx* ( Analyze_Number((xb-xa),N_DEC) )/( Analyze_Number((fbx-fax),N_DEC) ) ), N_DEC);
        cout << "x[" << i << "]= " << fxm ;
		xa=xb;    xb=fxm; //Nuevos valores de xa y xb
		cin.ignore(256,'\n'); //Cada vez que se da enter se muestran nuevos valores (Puede opimirse)

		if(xa==xb)      return 0;
	}	
	return 0;
}
