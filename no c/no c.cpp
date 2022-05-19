#include <iostream>
#include <string.h>
#include <string>
#include <fstream>

using namespace std;

struct Cita {
	string hora;
	string nombre;
	string tratamiento;
	string numero_cita;
	Cita* anterior = nullptr;
	Cita* posterior = nullptr;
	float precio_total = 0, precio_unitario = 0;
};

int cita_actual = 1;
Cita* primer_cita = nullptr;
Cita* ultima_cita = nullptr;
Cita* demo_cita = nullptr;

void crear_cita(string nombre) {
	Cita* nueva_cita = new Cita;

	nueva_cita->nombre = nombre;

	nueva_cita->numero_cita = to_string(cita_actual);

	if (cita_actual == 1) {
		primer_cita = nueva_cita;
		ultima_cita = nueva_cita;
	}
	else {
		nueva_cita->anterior = ultima_cita;
		ultima_cita->posterior = nueva_cita;
		ultima_cita = nueva_cita;
	}
	cita_actual++;
}

int i = 0;

int main()
{
	Cita citas[50];

	int cita = 0, opcion = 1;
	bool repetir = true;
	bool existen = false;

	while (opcion != 0) {

		cout << "**Clinica dental Dentalsa**\n\n";

		cout << "Menu principal\n\n";

		cout << "1. Agendar cita\n";
		cout << "2. Modificar cita\n";
		cout << "3. Eliminar cita\n";
		cout << "4. Lista de citas vigentes\n";
		cout << "0. Salir\n";

		cout << "\nDigite una opcion\n\n";
		cin >> opcion;

		system("cls");

		int j = 1;
		switch (opcion) {
		case 1:

			while (j != 0) {
				ofstream archivo;

				archivo.open("citas_registro.txt");


				cout << "Introduzca su nombre completo por favor: \n";
				cin.ignore();
				getline(cin, citas[i].nombre);

				system("cls");

				cout << "Digite la hora en la que gustaria tomar su cita en formato de 24 horas\n (ejemplo; 16:13)?: \n";
				getline(cin, citas[i].hora);

				system("cls");

				cout << "Escriba el tratamiento que desea, junto con su precio: \n\n";
				cout << "1. Empaste $200\n" << "Descripcion: Un sellador de surcos, para devolver la estetica y funcionalidad de un diente\n\n";
				cout << "2. Extarccion $400\n" << "Descripcion: Retiro de una pieza dental\n\n";
				cout << "3. Limpieza $150\n" << "Descripcion: Procedimiento para limpiar la placa y el sarro de sus dientes\n\n";
				getline(cin, citas[i].tratamiento);

				system("cls");

				cout << "¿Desea agendar otra cita?: \n\n";
				cout << "1. Si\n";
				cout << "0. No\n\n";
				i++;
				existen = true;
				cin >> j;

				system("cls");
			}break;

			case 2:
				while (j != 0) {
					if (existen == true) {
						cout << "Digite la cita que desea modificar\n\n";

					}
					else {
						cout << "Todavia no se ha agendado ninguna cita\n";
					}
					cout << "\nDigite 0 para volver al menu principal: \n\n";
					cin >> j;

					system("cls");

				}break;

			case 3:
					while (j != 0) {
						if (existen == true) {
							cout << "Digite la cita que desea eliminar\n\n";
						}
						else {
							cout << "Todavia no se ha agendado ninguna cita\n";
						}
						cout << "\nDigite 0 para volver al menu principal: \n\n";
						cin >> j;

						system("cls");
					}

		case 4:
			while (j != 0) {

				if (existen == true) {
					cout << "Citas vigentes: \n\n";
					for (int i = 0; i < 49; i++) {

						cout << "Cita: " << i + 1 << "\n";

						cout << "Nombre completo del paciente: \n" << citas[i].nombre;
						cout << "\nHora de su cita: \n" << citas[i].hora;
						cout << "\ntratamiento deseado: \n" << citas[i].tratamiento << "\n\n";
					}
				}
				else {
					cout << "Todavia no se ha agendado ninguna cita\n";
				}

				cout << "\nDigite 0 para volver al menu principal: \n\n";
				cin >> j;

				system("cls");

			}break;

		case 0:

			cout << "Gracias por usar esta aplicacion :D\n\n";

			return 0;

		};

	}
}