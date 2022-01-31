#include <cmath>

#define Analyze_Number(Num,N_Decimales) ( (Num < 0) ? (-RedondearDecimales(-Num,N_Decimales)) : RedondearDecimales(Num,N_Decimales) )
#define Ajuste_Red(Num,N_Decimales) ( double((int)(Num * pow(10.0,N_Decimales) )) )

double RedondearDecimales(double Num, double N_Decimales);
