#include "Redondeo.hpp"

double RedondearDecimales(double Num, double N_Decimales){
    double UltimaCifra, Redondeo, R_0, R_1, R_2, Cifra_Max_Min;
    if(N_Decimales==0)
		Redondeo=Num;
	else{
		R_0 = Ajuste_Red(Num,N_Decimales+1.0);
		R_1 = Ajuste_Red(Num,N_Decimales);

		UltimaCifra=R_0-(R_1*10.0);

		if(UltimaCifra==5.0){
			R_2 = Ajuste_Red(Num,N_Decimales-1);
            Cifra_Max_Min=R_1-(R_2*10.0);
            if(int(Cifra_Max_Min)%2!=0)     R_1+=1.0; //cifra anterior del 5 es impar
		}
		else{
			if(UltimaCifra>5.0)             R_1+=1.0;
		}
		Redondeo=R_1/pow(10.0,N_Decimales);
	}
	return Redondeo;
}
