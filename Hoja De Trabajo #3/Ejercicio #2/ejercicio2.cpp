/*									EJERCICIO 2
En la Pizzeria "Gran sabor" se tienen las siguientes ofertas:
Por la compra de una pizza grande (Q80.00), recibe un descuento de 10%
Por la compra de una pizza familiar (Q115.00), recibe un descuento de 15%
Por la compra de una pizza fiesta(Q100.00), recibe un descuento de 20%

Solicitar el tipo de pizza, el precio unitario y hallar el precio a pagar.

Grabar los datos a un archivo y mostrar el total global de la venta del dia y
determinar el total de lo vendido por producto, mostrando tambien el porcentaje
con relacion al total.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Declaraci�n de estructura de tipo pizza
struct Pizzas{
	string tipoPizza;
	float precioUnitario;
	float descuento;
	float precioPagar;
};

//Declaraci�n de Vector de tipo estructura de pizzas
std::vector<Pizzas> vectorPizza;


//Agregar Pizza a Archivo
void agregarPizza(){
	
	/*	Declaraci�n de variables
		stPizza es de tipo estructura Pizzas
	*/
	Pizzas stPizza;
	int tipo;
	
	cout << "--------------------------------------COMPRAR PIZZA--------------------------------------" << endl;
	
	//Seleccionar el tipo de pizza
	cout << "Por favor seleccione el tipo de pizza que desea comprar: " << "\n" 
	<< "1. Pizza Grande ------------------- Q80.00" << "\n"
	<< "2. Pizza Familiar ----------------- Q115.00" << "\n" 
	<< "3. Pizza Fiesta ------------------- Q100.00" << endl;
	cout << "Seleccione una opcion (1-3)" << endl;
	cin >> tipo;
	
	
	//Validaciones correspondientes para determinar el descuento y el total a pagar por la pizza
	if (tipo == 1){
		stPizza.tipoPizza = "Grande";
		stPizza.precioUnitario = 80.00;
		stPizza.descuento = stPizza.precioUnitario * 0.1;
		stPizza.precioPagar = stPizza.precioUnitario - stPizza.descuento;
	}
	else if (tipo == 2){
		stPizza.tipoPizza = "Familiar";
		stPizza.precioUnitario = 115.00;
		stPizza.descuento = stPizza.precioUnitario * 0.15;
		stPizza.precioPagar = stPizza.precioUnitario - stPizza.descuento;
	}
	else if (tipo == 3){
		stPizza.tipoPizza = "Fiesta";
		stPizza.precioUnitario = 80.00;
		stPizza.descuento = stPizza.precioUnitario * 0.2;
		stPizza.precioPagar = stPizza.precioUnitario - stPizza.descuento;
	}
	
	//Salida en pantalla de la compra de pizza
	cout << "------------------------------------------------------------------" << endl;
	cout << "Compra realizada por una piza " << stPizza.tipoPizza << " con un total a pagar de Q" << stPizza.precioPagar << endl;
	cout << "------------------------------------------------------------------" << endl;
	
	//Abrir archivo
	ofstream archivoPizzas("PIZZAS.txt", std::ios_base::app);
	
	//Ingresar datos de pizza a archivo
	archivoPizzas << stPizza.tipoPizza << "\t" << stPizza.precioUnitario << "\t" << stPizza.precioPagar << "\t" << stPizza.descuento << endl;
	
	//Cerrar archivo
	archivoPizzas.close();
	
	return;
	
}

//Funci�n encargada de extraer datos de archivo
void leerArchivo(){
	//Declaraci�n de variable de tipo archivo
	ifstream archivoPizzas;
	
	//Declaraci�n de variable de tipo estructura de Pizzas
	Pizzas stPizza;
	
	//Abrir archivo
	archivoPizzas.open("PIZZAS.txt", ios::in);
	
	//obtener datos desde el archivo
	while (archivoPizzas >> stPizza.tipoPizza >> stPizza.precioUnitario >>  stPizza.precioPagar >> stPizza.descuento){
		//Guardar los datos obtenidos en un vector
		vectorPizza.push_back(stPizza);
	}
	
	//Cerrar archivo
	archivoPizzas.close();
	
	return;
	
}

//Funci�n encargada de mostrar el total de la venta del d�a
void ventaTotalDia(){
	/*	Declaraci�n de variables
		total: variable que almacenar� el total de la venta del d�a
	*/
	float total = 0.00;
	
	//Invocaci�n de la funci�n para extraer los datos del archivo
	leerArchivo();
	
	/*
		Iteraci�n de todos las ventas registradas en el vector "vectorPizza"
		para realizar la suma correspondiente al total de venta del d�a
	*/
	
	for (int i = 0; i <= vectorPizza.size(); i ++){
		total = total + vectorPizza[i].precioPagar;
	}
	
	//Muestra el total de la venta del d�a
	cout << "-------------------------------------------" << endl;
	cout <<"El total de la venta del dia es: Q" << total << endl;
	cout << "-------------------------------------------" << endl;
	
}

void totalPorProducto(){
	//Declaraci�n de variables
	float totalGrande = 0.00;
	float descuentoGrande = 0.00;
	
	float totalFamiliar = 0.00;
	float descuentoFamiliar = 0.00;
	
	float totalFiesta = 0.00;
	float descuentoFiesta = 0.00;
	
	//Invocaci�n de funci�n para extraer datos de archivo
	leerArchivo();
	
	//Iteraci�n del vector pizza para determinar el total pagado por pizza y su descuento
	for (int i = 0; i < vectorPizza.size(); i ++){
		
		if(vectorPizza[i].tipoPizza == "Grande"){
			totalGrande = totalGrande + vectorPizza[i].precioPagar;
			descuentoGrande = descuentoGrande + vectorPizza[i].descuento;
		}
		else if(vectorPizza[i].tipoPizza == "Familiar"){
			totalFamiliar = totalFamiliar + vectorPizza[i].precioPagar;
			descuentoFamiliar = descuentoFamiliar + vectorPizza[i].descuento;
		}
		else if(vectorPizza[i].tipoPizza == "Fiesta"){
			totalFiesta = totalFiesta + vectorPizza[i].precioPagar;
			descuentoFiesta = descuentoFiesta + vectorPizza[i].descuento;
		}
	}
	
	//Salida
	cout << "-------------------------------------------------" << endl;
	cout << "PIZZA" << "\t" << "PAGADO" << "\t" << "DESCUENTO" << endl;
	cout << "GRANDE" << "\t" << totalGrande << "\t" << descuentoGrande << endl;
	cout << "FAM." << "\t" << totalFamiliar << "\t" << descuentoFamiliar << endl;
	cout << "FIESTA" << "\t" << totalFiesta << "\t" << descuentoFiesta << endl;
	cout << "-------------------------------------------------" << endl;
	
}

//Funci�n principal del programa
int main(){
		
	//Declaraci�n de variables
	char opcion; //Guarda la opci�n ingresada por el usuario
	string vacio; //Variable encargada de obtener un valor vac�o para selecci�n de opci�n en men�
	bool terminar = false; //Variable bandera para terminar ejecuci�n de programa
	
	//MEN� DE PROGRAMA
	do {
		cin.clear();
		
		cout << "---------------------PIZZER�A EL GRAN SABOR---------------------" << endl;
		cout << "1. Comprar" << "\n"
		<< "2. Mostrar total de venta del d�a" << "\n"
		<< "3. Total vendido por producto" << "\n"
		<< "4. Salir" << endl;
		cout << "Elija una opci�n (1-4)" << endl;
		cin >> opcion;
		
		switch(opcion){
			case '1':
				agregarPizza();
				break;
			case '2':
				ventaTotalDia();
				break;
			case '3':
				totalPorProducto();
				break;
			case '4':
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

