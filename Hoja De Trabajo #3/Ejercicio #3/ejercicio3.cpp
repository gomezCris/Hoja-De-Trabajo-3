/*					EJERCICIO 3
Un empresa que se dedica a la venta de seguros de vehiculos, calcula el importe
seg�n el modelo y color del automovil, asi como la edad del conductor.

Modelo       Color             Precio
A            Blanco            240.50
             Metalizado        330.00
             Otros             270.50
B            Blanco            300.00
             Metalizado        360.50
             Otros             330.00
           
Incremento de precio
Edad            % Incremento
<31                    25%
Entre 31 y 65    0%
>65                   30%

Determine el importe a pagar mostrandolo en pantalla seg�n los datos del veh�culo (modelo y color)
y la edad del conductor.

Grabe los datos a un archivo.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Declaraci�n de estructura de tipo pizza
struct Vehiculos{
	int edad;
	string modelo;
	string color;
	float precio;
	float importe;
};

//Agregar vehiculo a Archivo
void agregarVehiculo(){
	
	/*	Declaraci�n de variables
		stVehiculo es de tipo estructura Vehiculos
	*/
	Vehiculos stVehiculo;
	int tipo;
	int color;
	
	cout << "--------------------------------------REGISTRAR VEHICULO--------------------------------------" << endl;
	
	//Ingresar edad del conductor
	cout << "Ingrese la edad del conductor: "<< endl;
	cin >> stVehiculo.edad;
	
	//Seleccionar el modelo del vehiculo
	cout << "Por favor seleccione el modelo del vehiculo " << "\n" 
	<< "1. A" << "\n"
	<< "2. B" << endl;
	cout << "Seleccione una opcion (1-2)" << endl;
	cin >> tipo;
	
	 
	//Validaciones correspondientes para determinar el descuento y el total a pagar por la pizza
	if (tipo == 1){
		stVehiculo.modelo = "A";
		cout << "Ingrese color:" << "\n"
		<< "1. Blanco-----------Q240.50" << "\n"
		<< "2. Metalizado-------Q330.00" << "\n"
		<< "3. Otros------------Q270.50" << endl;
		cin >> color;
		
		switch (color){
			case 1:
				stVehiculo.color = "Blanco";
				stVehiculo.precio = 240.50;
				break;
			case 2:
				stVehiculo.color = "Metalizado";
				stVehiculo.precio = 330.00;
				break;
			case 3:
				stVehiculo.color = "Otros";
				stVehiculo.precio = 270.50;
				break;
		}
		
	}
	else if (tipo == 2){
		stVehiculo.modelo = "B";
		cout << "Ingrese color:" << "\n"
		<< "1. Blanco-----------Q300.00" << "\n"
		<< "2. Metalizado-------Q360.00" << "\n"
		<< "3. Otros------------Q330.00" << endl;
		cin >> color;
		
		switch (color){
			case 1:
				stVehiculo.color = "Blanco";
				stVehiculo.precio = 300.00;
				break;
			case 2:
				stVehiculo.color = "Metal.";
				stVehiculo.precio = 360.00;
				break;
			case 3:
				stVehiculo.color = "Otros";
				stVehiculo.precio = 330.50;
				break;
		}
	}
	
	if (stVehiculo.edad < 31){
		stVehiculo.importe = stVehiculo.precio + (stVehiculo.precio * 0.25);
	}
	else if(stVehiculo.edad >= 31 and stVehiculo.edad <= 65){
		stVehiculo.importe = stVehiculo.precio + (stVehiculo.precio * 0.00);
	}
	else if(stVehiculo.edad > 65){
		stVehiculo.importe = stVehiculo.precio + (stVehiculo.precio * 0.30);
	}
	
	//Salida en pantalla del registro del veh�culo
	cout << "------------------------------------------------------------------" << endl;
	cout << "El importe a pagar del vehiculo es:  Q" << stVehiculo.importe << endl;
	cout << "------------------------------------------------------------------" << endl;
	
	//Abrir archivo
	ofstream archivoVehiculo("VEHICULOS.txt", std::ios_base::app);
	
	//Ingresar datos del vehiculo al archivo
	archivoVehiculo 
	<< stVehiculo.edad << "\t" << stVehiculo.modelo << "\t" << stVehiculo.color 
	<< "\t" << stVehiculo.precio << "\t" << stVehiculo.importe << endl;
	
	//Cerrar archivo
	archivoVehiculo.close();
	
	return;
	
}

int main(){
			
	//Declaraci�n de variables
	char opcion; //Guarda la opci�n ingresada por el usuario
	string vacio; //Variable encargada de obtener un valor vac�o para selecci�n de opci�n en men�
	bool terminar = false; //Variable bandera para terminar ejecuci�n de programa
	
	//MEN� DE PROGRAMA
	do {
		cin.clear();
		
		cout << "---------------------SEGURO VEHICULAR---------------------" << endl;
		cout << "1. Importe a pagar" << "\n"
		<< "2. Salir" << endl;
		cout << "Elija una opci�n (1-2)" << endl;
		cin >> opcion;
		
		switch(opcion){
			case '1':
				agregarVehiculo();
				break;
			case '2':
				terminar = true;
				break;
			default:
				cout << "Opci�n inv�lida";
				getchar();
				getline(cin, vacio);
				break;
		}
		
	}while(terminar != true);
	
	return 0;
}
