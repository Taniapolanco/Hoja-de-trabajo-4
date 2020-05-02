#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
struct servicios{
	int tipos;//Tipos servicio
	float totalap;//total a pagar
	float totald;//total descuento hectareas
	float totalm;//total descuento monto
	float precio;//precio normal
	float total;//total final
	int cantidadh;//cantidad hectareas
	int suma;
	
};
void serviciosv(); 
void registro();//Archivo
int main (){
	serviciosv();
	registro();
}


void serviciosv(){

	int tipos;
	float totalap;
	float totald;
	float totalm;
	float precio;
	float total;
	int cantidadh;
	string s;
	int i;
	int n=0;
	cout<<"Cuantos servicios adquirio con la compania Xterminio, S.A? \t ";
	cin>>n;
	
	for (i=0;i<n;i++){
	cout<<"\n \n _________Compania Xterminio, S.A._________"<<endl;
	cout<<"Por favor ingrese el tipo de servicio que se realizo: "<<endl;
	cout<<"Exterminio de Mala Hierba -> 1"<<endl;
	cout<<"Exterminio de langostas -> 2"<<endl;
	cout<<"Exterminio de gusanos -> 3"<<endl;
	cout<<"Exterminio de todo lo anterio -> 4"<<endl;
	cin>>tipos;
	cout<<"Indique la cantidad de hectareas para el servicio"<<endl;
	cin>>cantidadh;
	system("CLS");}
	if (tipos==1){
		precio=10;
		total= (precio*cantidadh);
		}
		else if (tipos==2){
			precio=20;
			total= (precio*cantidadh);}
			else if (tipos==3){
				precio=30;
				total= (precio*cantidadh);}
				else if (tipos==4){
					precio=50;
					total= (precio*cantidadh);}
					else cout <<"Opcion incorrecta";
if (cantidadh>500)
totald=(total*0.05);
if (total>1500){
totalm= (total*0.10);}
totalap=total-(totald+totalm);


cout<<"Servicios: "<<tipos<<"\t"<<endl;
cout<<"Cantidad de hectareas: "<<cantidadh<<"\t"<<endl;
cout<<"Total sin descuento: "<<total<<"\t"<<endl;
cout<<"Total con descuento por cantidad de hectares: "<<totald<<"\t"<<endl;
cout<<"Total con descuento por monto mayor: "<<totalm<<"\t"<<endl;
cout<<"Total a pagar: "<<totalap<<"\t"<<endl;

ofstream grabararchivo;
system ("PAUSE");

try {
	grabararchivo.open("plagas.txt", ios::app);
	grabararchivo<<tipos  <<"\t"<<cantidadh  <<"\t"<<total  <<"\t"<<totald  <<"\t"<<totalm  <<"\t"<<totalap  <<endl;
	grabararchivo.close();
}
catch (exception X){
	cout <<"Error al grabar en el archivo";
	system("PAUSE");
}
system ("CLS");
fflush(stdin);
cout<<"Ventas actuales"<<endl;
cout<<"tipo    cantidadh    totalsd    totalcdh    totalcdm    totalap"<<endl;
ifstream leerarchivo;
try{
	leerarchivo.open("plagas.txt", ios::in);
	while (getline(leerarchivo,s))
	cout <<s<<endl;
	leerarchivo.close();
}
catch (exception X){
	cout <<"Error al leer archivo"<<endl;
	
}
}

void registro() {
	ifstream doc; 
	float tp,tap=0; //total descuento, total monto, cantidad hectareas, tipos, precio, total, total a pagar
	float sumatotal=0;
	int tp1=0;
	int tp2=0;
	int tp3=0;
	int tp4=0;
	int tpp=0;
	try{
		
		doc.open("plagas.txt", ios::in);
		while (doc>>tp>>tap){
			sumatotal=tap + sumatotal;
			if (tp==1)
			tp1+=tp;
			else if (tp==2)
			tp2+=tp;
			else if (tp==3)
			tp3+=tp;
			else if (tp==4)
			tp4+=tp;
			
		doc.close();
		
		cout<<setprecision(5)<<"Monto pagado por los clientes:            "<<sumatotal<<endl;
		cout<<"Productos: "<<endl;
		cout<<setprecision(5)<<"Exterminio de mala hierva "<<tp1<<endl;
		cout<<setprecision(5)<<"Exterminio de langostas "<<tp2<<endl;
		cout<<setprecision(5)<<"Exterminio de gusanos "<<tp3<<endl;
		cout<<setprecision(5)<<"Exterminio de todo lo anterior "<<tp4<<endl;}
	}
		catch (exception X){
			cout<<"Error al abrir el archivo"<<endl;
			exit (1);
		}
	
}
