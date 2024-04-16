#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include<sstream>
#include <utility>

enum menu_principal;
enum menu_alta;
enum menu_estudiante;
enum menu_directivo;
class Comida;
class Estudiante;
class Directivo;
class Bloque;
struct Empresa;

using namespace std;

enum menu_principal
{
	AltaUsuario = 1,
	HabilitarUsuario,
	DeshabilitarUsuario,
	AccesoSistema,
	SalirMain,
};

enum menu_alta
{
	AltaEstudiante = 1,
	AltaDirectivo,
	SalirMenuAlta,
};
enum menu_estudiante
{
	registrarBloque = 1,
	modificarBloque,
	SalirSubEstu

};

enum menu_directivo
{
	editarCapaEstudiantes = 1,
	CantidadalumnosXBloque,
	verEstudiantes,
	SalirDirectivo
};

class Comida
{
public:
	int id_estudiante;
	string nombre;
	string bloque;
};

class Bloque
{
public:
	string nombre;
	string bloque;
	int cantidad;
};

class Estudiante
{
public:
	int id;
	string nombre_estudiante;
	string apellido_pat;
	string apellido_mat;
	int edad;
	string sexo;
	string habilitar = "True";
	string username;
	string password;
	vector<Comida> comidaEstudiante;
};

class Directivo
{
public:
	int id;
	string nombre_directivo;
	string apellido_pat;
	string apellido_mat;
	int edad;
	string sexo;
	string habilitar = "True";
	string username;
	string password;
};



struct Empresa
{
	vector<Estudiante> lista_estudiantes;
	vector<Directivo> lista_directores;
	vector<Bloque> bloques;
	int cantidadEstudiantes;
};
