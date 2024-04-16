#include "enumeraciones y clases.h"
#include "metodos.h"
#include <filesystem>

int main()
{
	Empresa cafeteria;
	Bloque bloque;
	bool CorrerPrograma = true, encontrado = false;
	int id_estudiante = 0;
	int id_director = 0;
	string usuario, contrasena;
	int opcion, opc;
	int opcion_dos, id_buscar, tipo_buscar;
	HacerArchivo();
	Estudiantes(cafeteria.lista_estudiantes);
	Directivos(cafeteria.lista_directores);
	LeerBloque(cafeteria.bloques);
	Comidas(cafeteria.lista_estudiantes);
	LeerCantidadEstudiantes(cafeteria);
	for (int i = 0; i < cafeteria.lista_estudiantes.size(); i++)
	{
		cout << cafeteria.lista_estudiantes[i].id << endl;
		cout << cafeteria.lista_estudiantes[i].nombre_estudiante << endl;
	}
	for (int i = 0; i < cafeteria.lista_directores.size(); i++)
	{
		cout << cafeteria.lista_directores[i].id << endl;
		cout << cafeteria.lista_directores[i].nombre_directivo << endl;
	}
	cout << "Cantidad estudiantes: " << cafeteria.cantidadEstudiantes << endl;
	cout << "ENter" << endl;
	cin.ignore();
	while (CorrerPrograma)
	{
		system("cls");
		ImprimirMenu();
		cin >> opcion;
		cin.ignore();
		system("cls");
		switch (opcion)
		{
		case AltaUsuario:
			system("cls");
			cout << "========= ALTA USUARIO ========";
			cout << "\nIngrese el usuario admin: ";
			cin >> usuario;
			cin.ignore();
			if (usuario == "admin")
			{
				cout << "Ingrese la contrasena de admin: ";
				cin >> contrasena;
				cin.ignore();
				if (contrasena == "admin")
				{
					system("cls");
					ImprimirMenuAlta();
					cin >> opcion_dos;
					cin.ignore();
					switch (opcion_dos)
					{
					case AltaEstudiante:
						system("cls");
						cout << "========= ALTA ESTUDIANTE ========" << endl;;
						RegistrarEstudiante(cafeteria, id_estudiante);
						id_estudiante++;
						cout << "\nPresione enter para continuar...";
						cin.ignore();
						break;
					case AltaDirectivo:
						system("cls");
						cout << "========= ALTA DIRECTIVO ========";
						RegistrarDirector(cafeteria.lista_directores, id_director);
						id_director++;
						cout << "\nPresione enter para continuar..." << endl;;
						cin.ignore();
						break;
					default:
						break;
					}
				}
				else
				{
					cout << "La contrasena es incorrecta..." << endl;
					cout << "Presione enter para continuar..." << endl;
					cin.ignore();
				}
			}
			else
			{
				cout << "El usuario es incorrecto...";
				cout << "\nPresione enter para continuar...";
				cin.get();
			}
			break;
		case HabilitarUsuario:
		{
			system("cls");
			cout << "========HABILITAR USUARIO ========" << endl;
			cout << "Ingrese el nombre de usuario: ";
			getline(cin, usuario);
			cout << "Ingrese la Contraseña de " << usuario << ": ";
			getline(cin, contrasena);
			MenuUsuario();
			cin >> tipo_buscar;
			cin.ignore();
			encontrado = BuscarUsuario(cafeteria, usuario, contrasena);
			Habilitar(cafeteria, encontrado, usuario, contrasena, tipo_buscar);
			if (encontrado = false)
			{
				cout << "Usuario o contraseña incorrectos" << endl;
				cout << "Regresando al menu" << endl;
			}
			cout << "Presione enter para continuar..." << endl;
			cin.ignore();
			break;
		}
		case DeshabilitarUsuario:
		{
			system("cls");
			cout << "========HABILITAR USUARIO ========" << endl;
			cout << "Ingrese el nombre de usuario: ";
			getline(cin, usuario);
			cout << "Ingrese la Contraseña de " << usuario << ": ";
			getline(cin, contrasena);
			MenuUsuario();
			cin >> tipo_buscar;
			cin.ignore();
			encontrado = BuscarUsuario(cafeteria, usuario, contrasena);
			Deshabilitar(cafeteria, encontrado, usuario, contrasena, tipo_buscar);
			if (encontrado = false)
			{
				cout << "Usuario o contraseña incorrectos" << endl;
				cout << "Regresando al menu" << endl;
			}
			cout << "Presione enter para continuar..." << endl;
			cin.ignore();
			break;
		}
		case AccesoSistema:
		{
			system("cls");
			MenuUsuario();
			cout << "Seleccione Estudiantes o Directivos: ";
			cin >> opc;
			cin.ignore();
			cout << "Escriba el nombre del usuario: ";
			getline(cin, usuario);
			cout << "Escriba la contrasenia de " << usuario << ": ";
			getline(cin, contrasena);
			encontrado = BuscarUsuario(cafeteria, usuario, contrasena);
			if (encontrado = true)
			{
				switch (opc)
				{
				case 1:
				{
					for (int i = 0; i < cafeteria.lista_estudiantes.size(); i++)
					{
						if (usuario == cafeteria.lista_estudiantes[i].username && contrasena == cafeteria.lista_estudiantes[i].password)
						{
							if (cafeteria.lista_estudiantes[i].habilitar == "True")
							{
								system("cls");
								cout << "----------------------------------------------" << endl;
								cout << "Acceso concedido al usuario: " << cafeteria.lista_estudiantes[i].username << endl;
								cout << "----------------------------------------------" << endl;
								cout << "Presione enter para continuar..." << endl;
								cin.ignore();
								id_buscar = cafeteria.lista_estudiantes[i].id;
								AcessoEstudiante(cafeteria, id_buscar);
								i = cafeteria.lista_estudiantes.size();
							}
							else
							{
								system("cls");
								cout << "----------------------------------------------" << endl;
								cout << "Acceso negado al usuario: " << cafeteria.lista_estudiantes[i].username << endl;
								cout << "Usuario esta deshabilitado " << endl;
								cout << "----------------------------------------------" << endl;
								cout << "Presione enter para continuar..." << endl;
								cin.ignore();
								i = cafeteria.lista_estudiantes.size();
							}
						}
					}
					break;
				}
				case 2:
				{
					for (int i = 0; i < cafeteria.lista_directores.size(); i++)
					{
						if (usuario == cafeteria.lista_directores[i].username && contrasena == cafeteria.lista_directores[i].password)
						{
							if (cafeteria.lista_directores[i].habilitar == "True")
							{
								system("cls");
								cout << "----------------------------------------------" << endl;
								cout << "Acceso concedido al usuario: " << cafeteria.lista_directores[i].username << endl;
								cout << "----------------------------------------------" << endl;
								cout << "Presione enter para continuar..." << endl;
								cin.ignore();
								id_buscar = cafeteria.lista_directores[i].id;
								AccesoDirectivo(cafeteria, id_buscar);
								i = cafeteria.lista_estudiantes.size();
							}
							else
							{
								system("cls");
								cout << "----------------------------------------------" << endl;
								cout << "Acceso negado al usuario: " << cafeteria.lista_directores[i].username << endl;
								cout << "Usuario esta deshabilitado " << endl;
								cout << "----------------------------------------------" << endl;
								cout << "Presione enter para continuar..." << endl;
								cin.ignore();
								i = cafeteria.lista_directores.size();
							}
						}
					}
					break;
				}
				default:
				{
					cout << "Opcion invalida" << endl;
					cout << "Presione enter para continuar.." << endl;
					cin.ignore();
					break;
				}
				}

			}
			else
			{
				cout << "Usuario no encontrado. " << endl;
				cout << "Presione enter para continuar..." << endl;
				cin.ignore();
			}
			break;
		}

		case SalirMain:
			CorrerPrograma = false;
			cout << endl;
			cout << "Finalizando Codigo" << endl;
			cout << "Hasta Pronto!!" << endl;
			cout << endl;
			cout << endl;
			cout << "Codigo Estudiantes y Directivos hecho por: " << endl;
			cout << "Luis Hernandez Aguayo, 0245564" << endl;
			cout << "Luis Manuel Mendez Oliver, 0232092" << endl;
			cout << "Yael Emiliano Salinas Lozano,  0219039" << endl;
			cout << "Sebastian Vazquez Gomez Ordunia, 0232175" << endl;
			cout << endl;
			break;
		default:
			break;
		}
	}

}