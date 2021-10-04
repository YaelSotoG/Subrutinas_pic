
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;


void unvar(int cm,double n){
	int tmax, var1,nopsrest;
	tmax=5+(256)*(n+3);//cual es el maximo de tiempo 
	if(tmax>=cm){//sobrepasa ese tiempo?
		var1=(cm-5)/(n+3);//saca la variable 1
		tmax=5+(var1)*(n+3);//cuanto tiempo genera la variable uno
		nopsrest=cm-tmax;//cuantos ciclos faltan
		cout<<"###############################################################################################"<<endl;
		cout<<"******resultado 1 var*********************"<<endl;
		cout<<"var1="<<var1<<endl;//imprime resultados
		cout<<"CM="<<tmax<<endl;
		cout<<"Nops restantes="<<nopsrest<<endl;
		cout<<"se deben agregar "<<nopsrest<<" Nops"<<endl;
	}
	else{//si sobrepasa el tiempo 
		cout<<"###############################################################################################"<<endl;
		cout<<"******resultado 1 var*********************"<<endl;
		cout<<"*******NO SE PUEDE RESOLVER CON ST1V"<<endl;
	}
	return;
}



void dosvar(int cm,double n){
	int tmax,nopsrest,x,y,z,min=1000000;//mil para que el error sea menor 
	tmax=7+(4*256)+((n+3)*(256*256));//cuanto es el maximo que logra la subrutina
	if(tmax>=cm){//sobrepasa ese tiempo?
		for(int var1=0;var1<=255;var1++){//valores en variable 1
				for(int var2=0;var2<=255;var2++){//valores en variable 2
					tmax=7+(4*var2)+((n+3)*(var1*var2));//cuanto tiempo genera var 1 y 2
					nopsrest=cm-tmax;//ciclos que faltan
					if(min>nopsrest&&nopsrest>0){//si el error es menor al anterior
						x=var1;//guarda variables
						y=var2;
						z=tmax;
						min=nopsrest;//guarda el error actual
					}	
				}
		
			}
		cout<<"###############################################################################################"<<endl;
		cout<<"******resultado 2 var*********************"<<endl;
		cout<<"var1="<<x<<endl;//imprime valores
		cout<<"var2="<<y<<endl;
		cout<<"CM="<<z<<endl;
		cout<<"Nops restantes="<<min<<endl;
		cout<<"se deben agregar "<<min<<" Nops"<<endl;
	}
	else{//si sobrepasa el tiempo
		cout<<"###############################################################################################"<<endl;
		cout<<"******resultado 2 var*********************"<<endl;
		cout<<"*******NO SE PUEDE RESOLVER CON ST2V"<<endl;
	}
	return;
}


void tresvar(int cm,double n){
	int tmax,nopsrest,min=1000000,x,y,z,v;//mil para que el error sea menor
	tmax=9+((4*256)*(1+256))+((n+3)*(256*256*256));//cuanto es el maximo que logra la subrutina
	if(tmax>=cm){//sobrepasa ese tiempo?
		for(int var1=0;var1<=255;var1++){//valores en variable 1
			for(int var2=0;var2<=255;var2++){//valores en variable 2
				for(int var3=0;var3<=255;var3++){//valores en variable 3
					tmax=9+((4*var1)*(1+var3))+((n+3)*(var2*var1*var3));//cuanto tiempo genera var 1,2 y3
					nopsrest=cm-tmax;//ciclos que faltan
					if(min>nopsrest&&nopsrest>0){//si el error es menor al anterior
						x=var1;
						y=var2;//guarda valores
						z=var3;
						v=tmax;
						min=nopsrest;//guarda el error mas pequeño y pregunta si hay otro menor
					}	
				}
		
			}
		}
		cout<<"###############################################################################################"<<endl;
		cout<<"******resultado 2 var*********************"<<endl;
		cout<<"var1="<<x<<endl;
		cout<<"var2="<<y<<endl;//imprime valores
		cout<<"var3="<<z<<endl;
		cout<<"CM="<<v<<endl;
		cout<<"Nops restantes="<<min<<endl;
		cout<<"se deben agregar "<<min<<" Nops"<<endl;
		return;
	}
	else{
		cout<<"###############################################################################################"<<endl;
		cout<<"******resultado 3 var*********************"<<endl;
		cout<<"*******NO SE PUEDE RESOLVER CON ST3V"<<endl;
	}
	return;
		
	
}





int main(){
		double f,t,n,tcm;//se declaran variable
		int cm; 
	cout<<"a que frecuencia trabaja? (HZ)"<<endl;///piden los valores
	cin>>f;
	cout<<"Cuantos nops usara? (de preferencia menos de 7)"<<endl;
	cin >>n;
	cout<<"Cuanto tiempo? (en uS)"<<endl;
	cin >>t;
	t=(t*.000001);//convier el tiempo en us
	tcm=4*(1/f);//convierte la frecuencia en segundos
	cm=t/tcm;//cuanto tarda un ejecutarse un ciclo de maquina
	unvar(cm,n);//llama a una variable
	dosvar(cm,n);//lama a 2 variables
	tresvar(cm,n);//llama a 3 variables
	return 0;
}
