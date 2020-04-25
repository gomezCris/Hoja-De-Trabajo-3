/*								EJERCICIO 1
El presidente de un club de futbol requiere calcular el sueldo de sus jugadores
si se tiene como dato la edad y la nacionalidad del jugador.

Ademas se sabe que el sueldo se calculara de la siguiente manera:
Sueldo fijo $2500.00
Si es extranjero recibe un bono de $500.00

Si la edad esta entre 15 y 20, el salario incrementa en $1400.00
Si la edad esta entre 21 y 25, el salario incrementa en $1500.00
Si la edad esta entre 26 y 30, el salario incrementa en $1200.00
Si la edad es mayor a 30, el salario incrementa en $800.00
Determine el sueldo del jugador si se tiene como datos la edad y nacionalidad.

Mostrar un reporte del total a pagar de planilla, as� como el total de jugadores por
los rangos de edad. Ademas de indicar que rango de edad es el mas remunerado.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Declaraci�n de estructura de tipo Jugador

struct Jugadores{
	string nombre;
	string apellido;
	int edad;
	string esGuatemalteco;
	float sueldo;
};

//Creaci�n de vector de tipo estructura de Jugadores
std::vector<Jugadores> jugador;

//Funci�n encargada de agregar jugadores a archivos
void agregarJugadores(){
	
	/*----DECLARACI�N DE VARIABLES
	_jugador es de tipo estructura de Jugadores
	guatemalteco recibe un valor de tipo string para asignar nacionalidad
	*/
	
	Jugadores _jugador;
	string guatemalteco;
	
	cout << "----------------------------REGISTRO DE JUGADOR----------------------------" << endl;
	
	//Ingreso de nombre
	cout << "Ingrese nombre del jugador: " << "\n";
	cin >> _jugador.nombre;
	
	//Ingreso del apellido
	cout << "Ingrese apellido del jugador: " << "\n";
	cin >> _jugador.apellido;
	
	//Ingreso de edad
	cout << "Ingrese edad del jugador: " << "\n";
	cin >> _jugador.edad;
	
	//Ingreso de nacionalidad
	cout << "�El jugador es de nacionalidad guatemalteca? (Si/No)" << "\n";
	cin >> _jugador.esGuatemalteco;
	
	//Ingreso de Sueldo
	cout << "Ingrese el sueldo del jugador: " << "\n";
	cin >> _jugador.sueldo;
	
	//Validaci�n correspondiente a verificar si el jugador ingresado es guatemalteco, si no lo es se asigna el valor de Extranjero
	if (_jugador.esGuatemalteco == "SI" || _jugador.esGuatemalteco == "si" || _jugador.esGuatemalteco == "S�" || _jugador.esGuatemalteco == "s�"){
		_jugador.esGuatemalteco = "Guatemalteco";
	}else{
		_jugador.esGuatemalteco = "Extranjero";
		_jugador.sueldo = _jugador.sueldo + 500.00;
	}
	
	
	/*
		Validaciones correspondientes a las edades de los jugadores 
		para determinar el aumento en el salario correspondiente.
	*/
	if (_jugador.edad >= 15 and _jugador.edad <= 20){
		_jugador.sueldo = _jugador.sueldo + 1400.00;	
	}
	else if(_jugador.edad >= 21 and _jugador.edad <= 25){
		_jugador.sueldo = _jugador.sueldo + 1500.00;	
	}
	else if(_jugador.edad >= 26 and _jugador.edad <= 30){
		_jugador.sueldo = _jugador.sueldo + 1200.00;	
	}
	else if(_jugador.edad >30){
		_jugador.sueldo = _jugador.sueldo + 800.00;	
	}
	
	//Grabar Jugador en archivo
	ofstream archivoJugador("JUGADORES.txt", std::ios_base::app);
	
	archivoJugador <<
	_jugador.nombre << "\t"<< _jugador.apellido << "\t" << _jugador.edad << "\t" <<
	_jugador.esGuatemalteco << "\t" << _jugador.sueldo
	<< endl;
	
	//Cerrar Archivo
	archivoJugador.close();
}

//Funci�n encargada de calcular el total a pagar de planilla
void totalPlanilla(){
	/*	DECLARACI�N DE VARIABLES
		total variable que almacenar� el total a pagar en planilla
	*/
	float total = 0.00;
	
	/*
		Iteraci�n de todos los sueldos registrados en el vector "jugador"
		para realizar la suma correspondiente al total a pagar en planilla.
	*/
	for (int i = 0; i <= jugador.size(); i++){
		total = total + jugador[i].sueldo;
	}
	
	
	//Muestra el total a pagar
	cout << "-------------------------------------------------------" << "\n";
	cout << "EL TOTAL A PAGAR EN PLANILLA ES DE: $" << total << endl;
	cout << "-------------------------------------------------------" << "\n";
	
	return;
}


/*
	Funci�n encargada de mostrar el rango de edad m�s remunerado 
	y el total de jugadores por edad.
*/
void edadMasRemunerada(){
	//DECLARACI�N DE VARIABLES
	
	
	string rangoEdad; //Almacena el rango de edad m�s remunerado
	float suma1520 = 0.00; //Suma de salarios de las edades entre 15 y 20 a�os
	float suma2125 = 0.00; //Suma de salarios de las edades entre 21 y 25 a�os
	float suma2630 = 0.00; //Suma de salarios de las edades entre 26 y 30 a�os
	float sumaMayor30 = 0.00; //Suma de salarios de jugadores mayores a 30 a�os
	int total1520 = 0; //Contador de jugadores de entre 15 y 20 a�os
	int total2125 = 0; //Contador de jugadores de entre 21 y 25 a�os
	int total2630 = 0; //Contador de jugadores de entre 26 y 30 a�os
	int totalMayor30 = 0; //Contador de jugadores mayores a 30 a�os
	float remuneracion = 0.00; //Variable encargada de almacenar el total de remuneraci�n m�s alta.
	
	/*
		Iteraci�n correspondiente al vector "jugador" para determinar 
		el total de jugadores y el total de salarios por rango de edad
	*/
	for (int i = 0; i <= jugador.size(); i ++){
		if(jugador[i].edad >= 15 and jugador[i].edad <= 20){
			suma1520 = suma1520 + jugador[i].sueldo;
			total1520 = total1520 +1;
		}
		else if(jugador[i].edad >= 21 and jugador[i].edad <= 25){
			suma2125 = suma2125 + jugador[i].sueldo;
			total2125 = total2125 + 1;
		}
		else if(jugador[i].edad >= 26 and jugador[i].edad <= 30){
			suma2630 = suma2630 + jugador[i].sueldo;
			total2630 = total2630 + 1;
		}
		else if(jugador[i].edad > 30){
			sumaMayor30 = sumaMayor30 + jugador[i].sueldo;
			totalMayor30 = totalMayor30 +1;
		}
	}
	
	//Arreglo encargado de almacenar los totales de salarios seg�n rango de edad.
	float arregloTotales[4] = { suma1520, suma2125, suma2630, sumaMayor30 };
	
	/*
		Iteraci�n del arreglo para determinar cu�l es la mayor
		remuneraci�n de salario y determinar en qu� rango de edades.
	*/
	for (int i = 0; i <= 3; i++){
		if (arregloTotales[i] > remuneracion){
			remuneracion = arregloTotales[i];
			if (i = 0){
				rangoEdad = "15 - 20 A�OS";
			}
			else if (i = 1){
				rangoEdad = "21 - 25 A�OS";
			}
			else if (i = 2){
				rangoEdad = "26 - 30 A�OS";
			}
			else if (i = 3){
				rangoEdad = "MAYOR A30 A�OS";
			}
		}
	}
	
	//Salida en consola de la funci�n
	cout << "-------------------------------------------------------" << "\n";
	cout << "EL TOTAL DE JUGADORES DE ENTRE 15 A 20 A�OS ES " << total1520 << endl;
	cout << "EL TOTAL DE JUGADORES DE ENTRE 21 A 25 A�OS ES " << total2125 << endl;
	cout << "EL TOTAL DE JUGADORES DE ENTRE 26 A 30 A�OS ES " << total2630 << endl;
	cout << "EL TOTAL DE JUGADORES MAYORES A 30 A�OS ES " << totalMayor30 << endl;
	cout << "-------------------------------------------------------" << "\n";
	cout << "-------------------------------------------------------" << "\n";
	cout << "EL RANGO DE EDAD M�S REMUNERADO ES " << rangoEdad << " CON UN TOTAL DE $" << remuneracion <<  endl;
	cout << "-------------------------------------------------------" << "\n";
	
	return;
}

//Funci�n encargada de extraer datos de archivo
void leerArchivo(){
	//Declaraci�n de variable de tipo archivo.
	ifstream archivoJugadores;
	
	//Declaraci�n de variable de tipo estructura de Jugadores
	Jugadores stJugadores;

	
	//Abrir archivo Jugadores
	archivoJugadores.open("JUGADORES.txt", ios::in);
	
	//Obtener los datos desde el archivo.
	while(archivoJugadores >> stJugadores.nombre >> stJugadores.apellido >> stJugadores.edad >> stJugadores.esGuatemalteco >> stJugadores.sueldo){
		//Guardar los datos obtenidos en un vector
		jugador.push_back(stJugadores);
	}
	
	//Cerrar archivo
	archivoJugadores.close();
	
	return;
}

//Funci�n principal
int main(){
	
	//Declaraci�n de variables
	char opcion; //Guarda la opci�n ingresada por el usuario
	string vacio; //Variable encargada de obtener un valor vac�o para selecci�n de opci�n en men�
	bool terminar = false; //Variable bandera para terminar ejecuci�n de programa
	
	//MEN� DE PROGRAMA
	do {
		cin.clear();
		
		cout << "---------------------JUGADORES---------------------" << endl;
		cout << "1. Agregar jugadores" << "\n"
		<< "2. Mostrar total a pagar en planilla" << "\n"
		<< "3. Rango de edad m�s remunerado y total de jugadores por edad" << "\n"
		<< "4. Salir" << endl;
		cout << "Elija una opci�n (1-4)" << endl;
		cin >> opcion;
		
		switch(opcion){
			case '1':
				agregarJugadores();
				break;
			case '2':
				leerArchivo();
				totalPlanilla();
				break;
			case '3':
				leerArchivo();
				edadMasRemunerada();
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
