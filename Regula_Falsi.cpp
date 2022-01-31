/*
		METODOS NUMERICOS: *- CEROS DE UNA FUNCION -*
		Método de Regula Falsi
		Archivos necesarios para compilar:
		Redondeo.hpp, Redondeo.cpp, Regula_Falsi.cpp
*/

#include <iostream>
#include <cmath>
#include "Redondeo.hpp"

#define N_DEC 4 //Numero de decimales 

//Funcion a evaluar, en cada operacion es preferible usar Analyze_Number() ya que el redondeo es necesario para exactitud 
//Pero puede opimirse
#define Funcion_RF(x) ( Analyze_Number( (Analyze_Number( pow(x,3),N_DEC ) - Analyze_Number( x,N_DEC ) - 1.0 ), N_DEC)  )

using namespace std;

int main() {
    double xa, xb, m = 0, mx = 0, fax1 = 0, fbx2= 0; //, raiz = 0;
	xa=1.0;
	xb=2.0;
    //Los resultados son mostrados en forma de tabla, al dar enter se muestra un nuevo resultado 
    cout << "i               ai               mi             bi              f(ai)           f(mi)           f(bi) " << endl;
	for( int i=0 ; i< 100 ; i++ ){ 
        xa = Analyze_Number(xa,N_DEC);
		xb = Analyze_Number(xb,N_DEC);
        fax1 = Funcion_RF(xa);
		fbx2 = Funcion_RF(xb);
        //raiz = Analyze_Number(fax1*fbx2 , N_DEC);
        m = Analyze_Number(xa - ( ( Analyze_Number( fax1*(xb-xa),N_DEC ) )/( Analyze_Number( (fbx2-fax1),N_DEC ) ) ) , N_DEC);
        mx = Funcion_RF(m);
        cout << i << '\t' << '\t' << xa << '\t' << '\t' << m << '\t' << '\t' << xb ;

		if(mx<0.0)  xa=m;
		else        xb=m;	

		cout << '\t' << '\t' << fax1 << '\t' << '\t' << mx << '\t' << '\t' << fbx2;
		cin.ignore(256,'\n'); //Cada vez que se da enter se muestran nuevos valores (Puede opimirse)
    }
	return 0;
}
