#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;
struct personas{
	int edad;
	int categoria;
	int totalpersonas;
	int in,jv,ad,adm;

	
};
void edades(); 
void reporte();//Archivo
int main (){
	edades();
	reporte();
}
void edades(){
	int edad;
	int totalpersonas;
	int categoria;
	int in,jv,ad,adm;

		
	string s;
	int i;
	int n=0;
	cout<<"Cuantas personas desea agregar? ";
	cin>>n;
	system("CLS");
	
	for (i=0;i<n;i++){
	cout<<"Ingrese edad de la persona "<<endl;
	cin>>edad;
	system("CLS");}
	if (edad>=0 && edad<=12){
		categoria+=in;}
		else if (edad>=13 && edad<=29){
		categoria+=jv;}
			else if (edad>=30 && edad<=59){
		categoria+=ad;}
				else if (edad>=60 && edad<=130){
		categoria+=adm;}
					else cout <<"Dato incorrecto";

ofstream grabararchivo;
system ("PAUSE");

try {
	grabararchivo.open("muestreo.txt", ios::app);
	grabararchivo<<edad<<"\t"<<categoria<<"\t"<<in<<"\t"<<jv<<"\t"<<ad<<"\t"<<adm<<endl;
	grabararchivo.close();
}
catch (exception X){
	cout <<"Error al grabar en el archivo";
	system("PAUSE");
}
system ("CLS");
cout<<"Personas del muestreo"<<endl;
cout<<"Edad    Categoria"<<endl;
ifstream leerarchivo;
try{
	leerarchivo.open("muestreo.txt", ios::in);
	while (getline(leerarchivo,s))
	cout <<s<<endl;
	leerarchivo.close();
}
catch (exception X){
	cout <<"Error al leer archivo"<<endl;	
}
}


void reporte() {
	ifstream doc; 
	int ed;
	int ct,in,jv,ad,adm,tp;
	int n;
	
	
	try{
		
		doc.open("muestreo.txt", ios::in);
		while (doc>>ed>>ct>>tp){
			if (ct==in)
			in+=ct;
			else if (tp==jv)
			jv+=ct;
			else if (tp==ad)
			ad+=ct;
			else if (tp==adm)
			adm+=ct;
}
		doc.close();
		cout<<"Rangos de edades:  "<<endl;
		cout<<setprecision(5)<<" Infante   "<<in<<" - % sobre el total: "<<setprecision(3)<<in*100/n<<endl;
		cout<<setprecision(5)<<" Joven "<<jv<<" - % sobre el total: "<<setprecision(3)<<jv*100/n<<endl;
		cout<<setprecision(5)<<" Adulto  "<<ad<<" - % sobre el total: "<<setprecision(3)<<ad*100/n<<endl;
        cout<<setprecision(5)<<" Adulto Mayor  "<<ad<<" - % sobre el total: "<<setprecision(3)<<adm*100/n<<endl;
}
	
		catch (exception X){
			cout<<"Error al abrir el archivo"<<endl;
			exit (1);
		}
	
}
