#include <iostream>
#include<cmath>
#include "Redondeo.hpp"
using namespace std;

int main(){
    double numero;
	unsigned int NumDecimales;
	cout << "Ingrese el numero a redondear: "; cin >> numero; cin.ignore(256,'\n');
	cout << "Cuantos decimales desea? " ; cin >> NumDecimales; cin.ignore(256,'\n');
    cout << "Numero redondeado " << RedondearDecimales(numero,NumDecimales) << "\n";

    return 0;
}