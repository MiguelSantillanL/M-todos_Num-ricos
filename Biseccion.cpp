/*
		METODOS NUMERICOS: *- CEROS DE UNA FUNCION -*
		Método de Bisección
		Archivos necesarios para compilar:
		Redondeo.hpp, Redondeo.cpp, Biseccion.cpp
*/


#include <iostream>
#include <cmath>
#include "Redondeo.hpp"

#define N_DEC 4 //Numero de decimales 

//Funcion a evaluar, en cada operacion es preferible usar Analyze_Number() ya que el redondeo es necesario para exactitud 
//Pero puede opimirse
#define Funcion_Bis(x) ( Analyze_Number( (Analyze_Number(cos(x),N_DEC) - 3.0*x ), N_DEC ) )


using namespace std;

int main() {
    double xa, xb, m = 0, mx = 0, fx1 = 0, fx2 = 0, mult = 0;
	xa = 0.2;
	xb = 0.4;
    //Los resultados son mostrados en forma de tabla, al dar enter se muestra un nuevo resultado 
    cout << "i               ai               mi             bi              f(ai)           f(mi)           f(bi) " << endl;
	for(int i=0 ; i< 100 ; i++){ 
        xa = Analyze_Number(xa,N_DEC);  xb = Analyze_Number(xb,N_DEC);
        m = Analyze_Number( ((xa+xb)/2.0), N_DEC);  
        cout << i << '\t' << '\t' << xa << '\t' << '\t' << m << '\t' << '\t' << xb ;
        fx1 = Funcion_Bis(xa); //Fxa
		fx2 = Funcion_Bis(xb); //Fxb
        mx = Funcion_Bis(m);  //Fm
        mult = Analyze_Number( (fx1*mx), N_DEC);

        if( mult<0.0 )  xb=m;
		else            xa=m;	

        cout << '\t' << '\t' << fx1 << '\t' << '\t' << mx << '\t' << '\t' << fx2;
        cin.ignore(256,'\n');   //Cada vez que se da enter se muestran nuevos valores (Puede opimirse)
    }
	return 0;
}
