void ImprimirMenu();
void ImprimirMenuAlta();
void HacerArchivo();
void LeerCantidadEstudiantes(Empresa& empresa);
void Estudiantes(vector<Estudiante>& list_u);
void LeerBloque(vector<Bloque>& bloques);
void Comidas(vector<Estudiante>& list_u);
void RegistrarEstudiante(Empresa& empresa, int id);
void Directivos(vector<Directivo>& list_u);
void RegistrarDirector(vector<Directivo>& list_u, int id);
bool BuscarUsuario(Empresa& empresa, string usuario, string contrasena);
void Habilitar(Empresa& empresa, bool encontrado, string username, string password, int tipo);
void Deshabilitar(Empresa& empresa, bool encontrado, string username, string password, int tipo);
void MenuUsuario();
void AcessoEstudiante(Empresa& empresa, int id);
void MenuEstudiante();
void MenuBloque();
void MenuTiempo();
void RegistrarBloqueEstudiantes(Empresa& empresa, int bloque, int tiempo, int id);
void GuardarEstudiante(vector<Estudiante>& estudiante);
void GuardarDirectivo(vector<Directivo>& directivo);
void GuardarComidas(vector<Estudiante>& estudiante);
bool VerificarComidas(Empresa& empresa, int id, string bloque, string comida);
bool MenuBloqueEstudiante(Empresa& empresa, int id);
void AccesoDirectivo(Empresa& empresa, int id);
void MenuDirectivos();
void VerDatosEstudiantes(vector<Estudiante>& estudiantes, string bloque, string comida);
void EditarCantidadEstudiantes(vector<Estudiante>& estudiantes, vector<Bloque>& bloques, string bloque, string comida);
void GuardarBloques(vector<Bloque>& bloques);
void GuardarCantidadestudiantes(Empresa& empresa);

void ImprimirMenu()
{
	cout << "======== MENU ========";
	cout << "\n1) Alta de Usuarios";
	cout << "\n2) Habilitar Usuarios";
	cout << "\n3) Deshabilitar Usuarios";
	cout << "\n4) Acceder al Sistema";
	cout << "\n5) Salir";
	cout << "\nSeleccione una opcion: ";
}

void ImprimirMenuAlta()
{
	cout << "======== MENU ALTA DE USUARIOS ========";
	cout << "\n1) Alta de Estudiantes";
	cout << "\n2) Alta de Directivo";
	cout << "\n3) Salir";
	cout << "\nSeleccione una opcion: ";
}

void HacerArchivo()
{
	string filename = "Estudiantes.csv";
	ifstream ifile;
	ifile.open(filename);
	if (!ifile)
	{
		ifile.close();
		ofstream myFileOutput("Estudiantes.csv", ios_base::app);
		myFileOutput << "id,nombre_estudiante,appelido_pat,apellido_mat,edad,sexo,habilitado,usuario,contrasena\n";
		myFileOutput.close();
	}

	string filename2 = "Directivos.csv";
	ifstream ifile2;
	ifile2.open(filename2);
	if (!ifile2)
	{
		ifile2.close();
		ofstream myFileOutput("Directivos.csv", ios_base::app);
		myFileOutput << "id,nombre_directivo,appelido_pat,apellido_mat,edad,sexo,habilitado,usuario,contrasena\n";
		myFileOutput.close();
	}

	string filename3 = "Comidas.csv";
	ifstream ifile3;
	ifile3.open(filename3);
	if (!ifile3)
	{
		ifile3.close();
		ofstream myFileOutput("Comidas.csv", ios_base::app);
		myFileOutput << "id, nombre_Comida, nombre_bloque\n";
		myFileOutput.close();
	}

	string filename4 = "Bloques.csv";
	ifstream ifile4;
	ifile4.open(filename4);
	if (!ifile4)
	{
		ifile4.close();
		ofstream myFileOutput("Bloques.csv", ios_base::app);
		myFileOutput << "nombre_Comida,nombre_Bloque,cantidad \n";
		myFileOutput << "Desayuno,Bloque A,20\n";
		myFileOutput << "Desayuno,Bloque B,20\n";
		myFileOutput << "Comida,Bloque A,20\n";
		myFileOutput << "Comida,Bloque B,20\n";
		myFileOutput << "Cena,Bloque A,20\n";
		myFileOutput << "Cena,Bloque B,20\n";
		myFileOutput.close();
	}
	string filename5 = "CantidadTotalEstudiantes.csv";
	ifstream ifile5;
	ifile5.open(filename5);
	if (!ifile5)
	{
		ifile5.close();
		ofstream myFileOutput("CantidadTotalEstudiantes.csv", ios_base::app);
		myFileOutput << "Cantidad\n";
		myFileOutput << "30\n";
		myFileOutput.close();
	}


}
void LeerCantidadEstudiantes(Empresa& empresa)
{
	string line, colname;
	vector<string> headers;
	string value;
	ifstream myFileInput("CantidadTotalEstudiantes.csv");
	if (!myFileInput.is_open()) throw runtime_error("Could not open file");
	if (myFileInput.good())
	{
		// Extract the first line in the file
		getline(myFileInput, line);

		// Create a stringstream from line
		stringstream ss(line);

		// Extract each column name
		while (getline(ss, colname, ',')) {
			headers.push_back(colname);
		}
	}
	while (getline(myFileInput, line))
	{
		// Create a stringstream of the current line
		stringstream ss(line);

		int colIdx = 0;
		int _cantidad;
		while (getline(ss, value, ','))
		{
			switch (colIdx)
			{
			case 0:
				_cantidad = stoi(value);
				break;
			default:
				break;
			}

			// Si el siguiente token es una coma, ignoralo y se mueve al siguiente elemento
			if (ss.peek() == ',') ss.ignore();
			colIdx++;
		}
		empresa.cantidadEstudiantes = _cantidad;

	}

	myFileInput.close();
}

void Estudiantes(vector<Estudiante>& list_u)
{
	string line, colname;
	vector<string> headers;
	string value;
	ifstream myFileInput("Estudiantes.csv");
	if (!myFileInput.is_open()) throw runtime_error("Could not open file");
	if (myFileInput.good())
	{
		// Extract the first line in the file
		getline(myFileInput, line);

		// Create a stringstream from line
		stringstream ss(line);

		// Extract each column name
		while (getline(ss, colname, ',')) {
			headers.push_back(colname);
		}
	}
	while (getline(myFileInput, line))
	{
		// Create a stringstream of the current line
		stringstream ss(line);

		int colIdx = 0;
		int _id, _edad;
		string _nombre, _habilitar, _sexo, _apellido_mat, _apellido_pat, _username, _password;

		while (getline(ss, value, ','))
		{
			switch (colIdx)
			{
			case 0:
				_id = stoi(value);
				break;
			case 1:
				_nombre = value;
				break;
			case 2:
				_apellido_pat = value;
				break;
			case 3:
				_apellido_mat = value;
				break;
			case 4:
				_edad = stoi(value);
				break;
			case 5:
				_sexo = value;
				break;
			case 6:
				_habilitar = value;
				break;
			case 7:
				_username = value;
				break;
			case 8:
				_password = value;
				break;
			default:
				break;
			}

			// Si el siguiente token es una coma, ignoralo y se mueve al siguiente elemento
			if (ss.peek() == ',') ss.ignore();
			colIdx++;
		}
		Estudiante temporal = { _id, _nombre, _apellido_pat, _apellido_mat, _edad, _sexo,_habilitar,_username,_password };
		list_u.push_back(temporal);
	}

	myFileInput.close();
}

void LeerBloque(vector<Bloque>& bloques)
{
	string line, colname;
	vector<string> headers;
	string value;
	ifstream myFileInput("Bloques.csv");
	if (!myFileInput.is_open()) throw runtime_error("Could not open file");
	if (myFileInput.good())
	{
		// Extract the first line in the file
		getline(myFileInput, line);

		// Create a stringstream from line
		stringstream ss(line);

		// Extract each column name
		while (getline(ss, colname, ',')) {
			headers.push_back(colname);
		}
	}
	while (getline(myFileInput, line))
	{
		// Create a stringstream of the current line
		stringstream ss(line);

		int colIdx = 0;
		int _cantidad;
		string _nombre, _bloque;
		while (getline(ss, value, ','))
		{
			switch (colIdx)
			{
			case 0:
				_nombre = value;
				break;
			case 1:
				_bloque = value;
				break;
			case 2:
				_cantidad = stoi(value);
				break;
			default:
				break;
			}

			// Si el siguiente token es una coma, ignoralo y se mueve al siguiente elemento
			if (ss.peek() == ',') ss.ignore();
			colIdx++;
		}
		Bloque temporal = { _nombre,_bloque,_cantidad };
		bloques.push_back(temporal);

	}

	myFileInput.close();
}

void Comidas(vector<Estudiante>& list_u)
{
	string line, colname;
	vector<string> headers;
	string value;
	ifstream myFileInput("Comidas.csv");
	if (!myFileInput.is_open()) throw runtime_error("Could not open file");
	if (myFileInput.good())
	{
		// Extract the first line in the file
		getline(myFileInput, line);

		// Create a stringstream from line
		stringstream ss(line);

		// Extract each column name
		while (getline(ss, colname, ',')) {
			headers.push_back(colname);
		}
	}
	while (getline(myFileInput, line))
	{
		// Create a stringstream of the current line
		stringstream ss(line);

		int colIdx = 0;
		int _id;
		string _nombre;
		string _bloque;
		int encontro;
		while (getline(ss, value, ','))
		{
			switch (colIdx)
			{
			case 0:
				_id = stoi(value);
				break;
			case 1:
				_nombre = value;
				break;
			case 2:
				_bloque = value;
			default:
				break;
			}

			// Si el siguiente token es una coma, ignoralo y se mueve al siguiente elemento
			if (ss.peek() == ',') ss.ignore();
			colIdx++;
		}

		for (int k = 0; k < list_u.size(); k++)
		{
			if (list_u[k].id == _id)
			{
				encontro = k;
				Comida temporal = { _id,_nombre,_bloque };
				list_u[encontro].comidaEstudiante.push_back(temporal);
			}
		}
	}

	myFileInput.close();
}

void RegistrarEstudiante(Empresa& empresa, int id)
{
	// leer todos los estudiantes del archivo csv y guardarlos en un vector
	string line, colname;
	vector<string> headers;
	string value;
	ifstream myFileInput("Estudiantes.csv");
	if (!myFileInput.is_open()) throw runtime_error("Could not open file");
	if (myFileInput.good())
	{
		// Extract the first line in the file
		getline(myFileInput, line);

		// Create a stringstream from line
		stringstream ss(line);

		// Extract each column name
		while (getline(ss, colname, ',')) {
			headers.push_back(colname);
		}
	}
	// save al lines of the file in a vector
	vector<string> lines;
	while (getline(myFileInput, line))
	{
		lines.push_back(line);
	}

	// close the file
	myFileInput.close();
	string nombre, apellido_pat, apellido_mat, sexo, habilitar, username, password;
	int  edad;
	bool confirmacion = false;
	if (empresa.lista_estudiantes.size() < empresa.cantidadEstudiantes)
	{
		cout << "\nIngrese su nombre: ";
		getline(cin, nombre);
		cout << "Ingrese su apellido paterno: ";
		getline(cin, apellido_pat);
		cout << "Ingrese su apellido materno: ";
		getline(cin, apellido_mat);
		cout << "Ingrese su edad: ";
		cin >> edad;
		cin.ignore();
		cout << "Ingrese su sexo (M/F): ";
		cin >> sexo;
		cin.ignore();
		habilitar = "True";
		cout << "Ingrese un nombre de usuario: " << endl;
		getline(cin, username);
		cout << "Ingrese una contrasenia: " << endl;
		getline(cin, password);
		for (int i = 0; i < empresa.lista_estudiantes.size(); i++)
		{
			if (empresa.lista_estudiantes[i].username == username || empresa.lista_estudiantes[i].password == password)
			{
				while (confirmacion != true)
				{
					system("cls");
					cout << "Nombre de usuario o contraseña ya en uso" << endl;
					cout << endl;
					cout << "Ingrese un nuevo nombre de usuario: " << endl;
					getline(cin, username);
					cout << "Ingrese una nueva contraseña: " << endl;
					getline(cin, password);
					if (empresa.lista_estudiantes[i].username != username || empresa.lista_estudiantes[i].password != password)
					{
						confirmacion = true;
						cout << "Nombre de usuario y contraseña registrados" << endl;
						cout << "Presione enter para continuar..." << endl;
						cin.ignore();
					}
				}

			}
		}
		// añadir las lineas guardas en el vector y el nuevo estudiante
		for (int i = 0; i < empresa.lista_estudiantes.size(); i++)
		{
			if (empresa.lista_estudiantes[i].id == id)
			{
				id++;
			}
		}
		lines.push_back(to_string(id) + "," + nombre + "," + apellido_pat + "," + apellido_mat + "," + to_string(edad) + "," + sexo + "," + habilitar + "," + username + "," + password);	// crear un nuevo archivo con el nombre de Estudiantes.csv
		Estudiante temporal = { id, nombre, apellido_pat, apellido_mat, edad, sexo, habilitar,username,password };
		empresa.lista_estudiantes.push_back(temporal);
		ofstream myFileOutput("Estudiantes.csv", ios_base::app);
		myFileOutput << temporal.id << "," << temporal.nombre_estudiante << "," << temporal.apellido_pat << "," << temporal.apellido_mat << "," << temporal.edad << "," << temporal.sexo << "," << temporal.habilitar << "," << temporal.username << "," << temporal.password << endl;
		myFileOutput.close();
		cout << "---Datos importantes del Estudiante---" << endl;
		cout << "Nombre: " << nombre << " " << apellido_pat << " " << apellido_mat << endl;
		cout << "Nombre de Usuario: " << username << endl;
		cout << "ID: " << id << endl;
	}
	else
	{
		cout << "Se ha alcanzado la cantidad máxima de estudiantes en el sistema" << endl;
	}

}

void Directivos(vector<Directivo>& list_u)
{
	string line, colname;
	vector<string> headers;
	string value;
	ifstream myFileInput("Directivos.csv");
	if (!myFileInput.is_open()) throw runtime_error("Could not open file");
	if (myFileInput.good())
	{
		// Extract the first line in the file
		getline(myFileInput, line);

		// Create a stringstream from line
		stringstream ss(line);

		// Extract each column name
		while (getline(ss, colname, ',')) {
			headers.push_back(colname);
		}
	}
	while (getline(myFileInput, line))
	{
		// Create a stringstream of the current line
		stringstream ss(line);

		int colIdx = 0;
		int _id, _edad;
		string _nombre, _habilitar, _sexo, _apellido_mat, _apellido_pat, _username, _password;
		while (getline(ss, value, ','))
		{
			switch (colIdx)
			{
			case 0:
				_id = stoi(value);
				break;
			case 1:
				_nombre = value;
				break;
			case 2:
				_apellido_pat = value;
				break;
			case 3:
				_apellido_mat = value;
				break;
			case 4:
				_edad = stoi(value);
				break;
			case 5:
				_sexo = value;
				break;
			case 6:
				_habilitar = value;
				break;
			case 7:
				_username = value;
				break;
			case 8:
				_password = value;
				break;
			default:
				break;
			}

			// Si el siguiente token es una coma, ignoralo y se mueve al siguiente elemento
			if (ss.peek() == ',') ss.ignore();
			colIdx++;
		}
		Directivo temporal = { _id, _nombre, _apellido_pat, _apellido_mat, _edad, _sexo,_habilitar,_username,_password };
		list_u.push_back(temporal);
	}

	myFileInput.close();
}


void RegistrarDirector(vector<Directivo>& list_u, int id)
{
	// leer todos los directivos del archivo csv y guardarlos en un vector
	string line, colname;
	vector<string> headers;
	string value;
	ifstream myFileInput("Directivos.csv");
	if (!myFileInput.is_open()) throw runtime_error("Could not open file");
	if (myFileInput.good())
	{
		// Extract the first line in the file
		getline(myFileInput, line);

		// Create a stringstream from line
		stringstream ss(line);

		// Extract each column name
		while (getline(ss, colname, ',')) {
			headers.push_back(colname);
		}
	}
	// save al lines of the file in a vector
	vector<string> lines;
	while (getline(myFileInput, line))
	{
		lines.push_back(line);
	}

	// close the file
	myFileInput.close();
	string nombre, apellido_pat, apellido_mat, sexo, habilitar, username, password;
	int  edad;
	bool confirmacion = false;
	cout << "\nIngrese su nombre: ";
	getline(cin, nombre);
	cout << "Ingrese su apellido paterno: ";
	getline(cin, apellido_pat);
	cout << "Ingrese su apellido materno: ";
	getline(cin, apellido_mat);
	cout << "Ingrese su edad: ";
	cin >> edad;
	cin.ignore();
	cout << "Ingrese su sexo (M/F): ";
	cin >> sexo;
	cin.ignore();
	habilitar = "True";
	cout << "Ingrese un nombre de usuario: ";
	getline(cin, username);
	cout << "Ingrese una contrasenia: ";
	getline(cin, password);
	for (int i = 0; i < list_u.size(); i++)
	{
		if (list_u[i].username == username || list_u[i].password == password)
		{
			while (confirmacion != true)
			{
				system("cls");
				cout << "Nombre de usuario o contraseña ya en uso" << endl;
				cout << endl;
				cout << "Ingrese un nuevo nombre de usuario: " << endl;
				getline(cin, username);
				cout << "Ingrese una nueva contraseña: " << endl;
				getline(cin, password);
				if (list_u[i].username != username || list_u[i].password != password)
				{
					confirmacion = true;
					cout << "Nombre de usuario y contraseña registrados" << endl;
					cout << "Presione enter para continuar..." << endl;
					cin.ignore();
				}
			}

		}
	}
	// añadir las lineas guardas en el vector y el nuevo paciente
	lines.push_back(to_string(id) + "," + nombre + "," + apellido_pat + "," + apellido_mat + "," + to_string(edad) + "," + sexo + "," + habilitar);	// crear un nuevo archivo con el nombre de Estudiantes.csv
	for (int i = 0; i < list_u.size(); i++)
	{
		if (list_u[i].id == id)
		{
			id++;
		}
	}
	Directivo temporal = { id, nombre, apellido_pat, apellido_mat, edad, sexo,habilitar,username,password };
	list_u.push_back(temporal);
	ofstream myFileOutput("Directivos.csv", ios_base::app);
	/*myFileOutput << "id,nombre,telefono,correo,edad,sexo,alergias\n";*/
	myFileOutput << temporal.id << "," << temporal.nombre_directivo << "," << temporal.apellido_pat << "," << temporal.apellido_mat << "," << temporal.edad << "," << temporal.sexo << "," << temporal.habilitar << "," << temporal.username << "," << temporal.password << endl;
	myFileOutput.close();

	cout << "---Datos importantes del Directivo---" << endl;
	cout << "Nombre: " << nombre << " " << apellido_pat << " " << apellido_mat << endl;
	cout << "Nombre de Usuario: " << username << endl;
	cout << "ID: " << id << endl;
}

void MenuUsuario()
{
	system("cls");
	cout << "=======MENU USUARIOS=======" << endl;
	cout << "1. Estudiante" << endl;
	cout << "2. Directivo" << endl;
}

bool BuscarUsuario(Empresa& empresa, string usuario, string contrasena)
{
	bool encontro;
	encontro = false;
	int encontrados = 0;
	for (int i = 0; i < empresa.lista_directores.size(); i++)
	{
		if (empresa.lista_directores[i].username == usuario && empresa.lista_directores[i].password == contrasena)
		{
			encontro = true;
			encontrados = 1;
		}
	}
	if (encontrados == 0)
	{
		for (int i = 0; i < empresa.lista_estudiantes.size(); i++)
		{
			if (empresa.lista_estudiantes[i].username == usuario && empresa.lista_estudiantes[i].password == contrasena)
			{
				encontro = true;
				encontrados = 1;
			}
		}
	}
	return encontro;
}

void Habilitar(Empresa& empresa, bool encontrado, string username, string password, int tipo)
{
	system("cls");
	string confirmar;
	int encontro = 0;
	if (encontrado = true)
	{
		switch (tipo)
		{
		case 1:
		{
			for (int i = 0; i < empresa.lista_estudiantes.size(); i++)
			{
				if (username == empresa.lista_estudiantes[i].username && password == empresa.lista_estudiantes[i].password)
				{
					if (empresa.lista_estudiantes[i].habilitar == "True")
					{
						cout << "El usuario ya estaba habilitado" << endl;
						cout << "Regresando al menu" << endl;
					}
					else
					{
						cout << "Seguro que quiere habilitar al usuario " << username << "?" << endl;
						cout << "Escriba (s/n): ";
						getline(cin, confirmar);
						if (confirmar == "s")
						{
							empresa.lista_estudiantes[i].habilitar = "True";
							cout << "Usuario " << empresa.lista_estudiantes[i].username << " fue habilitado exitosamente" << endl;
							GuardarEstudiante(empresa.lista_estudiantes);
						}
						else
							cout << "Habilitacion no confirmada" << endl;

					}
					i = empresa.lista_estudiantes.size();
				}
			}
			break;
		}
		case 2:
		{
			for (int i = 0; i < empresa.lista_directores.size(); i++)
			{
				if (username == empresa.lista_directores[i].username && password == empresa.lista_directores[i].password)
				{
					if (empresa.lista_directores[i].habilitar == "True")
					{
						cout << "El usuario ya estaba habilitado" << endl;
						cout << "Regresando al menu" << endl;
					}
					else
					{
						cout << "Seguro que quiere habilitar al usuario " << username << "?" << endl;
						cout << "Escriba (s/n): ";
						getline(cin, confirmar);
						if (confirmar == "s")
						{
							empresa.lista_directores[i].habilitar = "True";
							cout << "Usuario " << empresa.lista_directores[i].username << " fue habilitado exitosamente" << endl;
							GuardarDirectivo(empresa.lista_directores);
						}
						else
							cout << "Habilitacion no confirmada" << endl;
					}
					i = empresa.lista_directores.size();
				}
			}
			break;
		}
		default:
		{
			cout << "Opcion invalida" << endl;
			cout << "Regresando al Menu" << endl;
		}
		}
	}

}

void Deshabilitar(Empresa& empresa, bool encontrado, string username, string password, int tipo)
{
	system("cls");
	string confirmar;
	int encontro = 0;
	if (encontrado = true)
	{
		switch (tipo)
		{
		case 1:
		{
			for (int i = 0; i < empresa.lista_estudiantes.size(); i++)
			{
				if (username == empresa.lista_estudiantes[i].username && password == empresa.lista_estudiantes[i].password)
				{
					if (empresa.lista_estudiantes[i].habilitar == "False")
					{
						cout << "El usuario ya estaba deshabilitado" << endl;
						cout << "Regresando al menu" << endl;
					}
					else
					{
						cout << "Seguro que quiere deshabilitar al usuario " << username << "?" << endl;
						cout << "Escriba (s/n): ";
						getline(cin, confirmar);
						if (confirmar == "s")
						{
							empresa.lista_estudiantes[i].habilitar = "False";
							cout << "Usuario " << empresa.lista_estudiantes[i].username << " fue deshabilitado exitosamente" << endl;
							GuardarEstudiante(empresa.lista_estudiantes);
						}
						else
							cout << "Deshabilitacion no confirmada" << endl;
					}
					i = empresa.lista_estudiantes.size();
				}
			}
			break;
		}
		case 2:
		{
			for (int i = 0; i < empresa.lista_directores.size(); i++)
			{
				if (username == empresa.lista_directores[i].username && password == empresa.lista_directores[i].password)
				{
					if (empresa.lista_directores[i].habilitar == "False")
					{
						cout << "El usuario ya estaba deshabilitado" << endl;
						cout << "Regresando al menu" << endl;
					}
					else
					{
						cout << "Seguro que quiere deshabilitar al usuario " << username << "?" << endl;
						cout << "Escriba (s/n): ";
						getline(cin, confirmar);
						if (confirmar == "s")
						{
							empresa.lista_directores[i].habilitar = "False";
							cout << "Usuario " << empresa.lista_directores[i].username << " fue deshabilitado exitosamente" << endl;
							GuardarDirectivo(empresa.lista_directores);
						}
						else
							cout << "Deshabilitacion no confirmada" << endl;
					}
					i = empresa.lista_directores.size();
				}
			}
			break;
		}
		default:
		{
			cout << "Opcion invalida" << endl;
			cout << "Regresando al Menu" << endl;
		}
		}
	}

}

void GuardarEstudiante(vector<Estudiante>& estudiante)
{
	int id, edad;
	string nombre, apellido_pat, apellido_mat, sexo, habilitar, username, password;
	ofstream ofs;
	ofs.open("Estudiantes.csv", ofstream::trunc);
	ofstream myFileOutput("Estudiantes.csv", ios_base::app);
	myFileOutput << "id,nombre_estudiante,appelido_pat,apellido_mat,edad,sexo,habilitado\n";
	myFileOutput.close();
	for (int i = 0; i < estudiante.size(); i++)
	{
		id = estudiante[i].id;
		nombre = estudiante[i].nombre_estudiante;
		apellido_pat = estudiante[i].apellido_pat;
		apellido_mat = estudiante[i].apellido_mat;
		edad = estudiante[i].edad;
		sexo = estudiante[i].sexo;
		habilitar = estudiante[i].habilitar;
		username = estudiante[i].username;
		password = estudiante[i].password;
		Estudiante temporal = { id, nombre, apellido_pat, apellido_mat, edad, sexo, habilitar,username,password };
		ofstream myFileOutput("Estudiantes.csv", ios_base::app);
		myFileOutput << temporal.id << "," << temporal.nombre_estudiante << "," << temporal.apellido_pat << "," << temporal.apellido_mat << "," << temporal.edad << "," << temporal.sexo << "," << temporal.habilitar << "," << temporal.username << "," << temporal.password << endl;
		myFileOutput.close();
	}

}

void GuardarDirectivo(vector<Directivo>& directivo)
{
	int id, edad;
	string nombre, apellido_pat, apellido_mat, sexo, habilitar, username, password;
	ofstream ofs;
	ofs.open("Directivos.csv", ofstream::trunc);
	ofstream myFileOutput("Directivos.csv", ios_base::app);
	myFileOutput << "id,nombre_directivo,appelido_pat,apellido_mat,edad,sexo,habilitado,usuario,contrasena\n";
	myFileOutput.close();
	for (int i = 0; i < directivo.size(); i++)
	{
		id = directivo[i].id;
		nombre = directivo[i].nombre_directivo;
		apellido_pat = directivo[i].apellido_pat;
		apellido_mat = directivo[i].apellido_mat;
		edad = directivo[i].edad;
		sexo = directivo[i].sexo;
		habilitar = directivo[i].habilitar;
		username = directivo[i].username;
		password = directivo[i].password;
		Directivo temporal = { id, nombre, apellido_pat, apellido_mat, edad, sexo, habilitar,username,password };
		ofstream myFileOutput("Directivos.csv", ios_base::app);
		myFileOutput << temporal.id << "," << temporal.nombre_directivo << "," << temporal.apellido_pat << "," << temporal.apellido_mat << "," << temporal.edad << "," << temporal.sexo << "," << temporal.habilitar << "," << temporal.username << "," << temporal.password << endl;
		myFileOutput.close();
	}

}

void GuardarComidas(vector<Estudiante>& estudiante)
{
	int id;
	string nombre_comida, nombre_bloque;
	ofstream ofs;
	ofs.open("Comidas.csv", ofstream::trunc);
	ofstream myFileOutput("Comidas.csv", ios_base::app);
	myFileOutput << "id, nombre_Comida, nombre_bloque;\n";
	myFileOutput.close();
	for (int i = 0; i < estudiante.size(); i++)
	{
		for (int j = 0; j < estudiante[i].comidaEstudiante.size(); j++)
		{
			id = estudiante[i].comidaEstudiante[j].id_estudiante;
			nombre_comida = estudiante[i].comidaEstudiante[j].nombre;
			nombre_bloque = estudiante[i].comidaEstudiante[j].bloque;
			Comida temporal = { id,nombre_comida,nombre_bloque };
			ofstream myFileOutput("Comidas.csv", ios_base::app);
			myFileOutput << temporal.id_estudiante << "," << temporal.nombre << "," << temporal.bloque << endl;
			myFileOutput.close();
		}
	}

}

void AcessoEstudiante(Empresa& empresa, int id)
{
	int opc, bloque, tiempo;
	string modificarComidas, modificarBloques;
	system("cls");
	bool correrprograma2 = true;
	while (correrprograma2 == true)
	{
		cout << "==============BIENVENIDO AL MENU DE ESTUDIANTES=================" << endl;
		MenuEstudiante();
		cin >> opc;
		cin.ignore();
		switch (opc)
		{
		case registrarBloque:
		{
			system("cls");
			MenuBloque();
			cin >> bloque;
			cin.ignore();
			MenuTiempo();
			cin >> tiempo;
			cin.ignore();
			RegistrarBloqueEstudiantes(empresa, bloque, tiempo, id);
			break;
		}
		case modificarBloque:
		{
			string nuevacomida, nuevobloque;
			int encontrado = 0;
			bool acceso = false, acceso2 = false, encontro = false;
			while (acceso2 == false)
			{
				encontro = MenuBloqueEstudiante(empresa, id);
				if (encontro == true)
				{
					cout << "Escriba el nombre de la comida que desea modificar: ";
					getline(cin, modificarComidas);
					cout << endl;
					cout << "Escriba el bloque de la comida que desea modificar: ";
					getline(cin, modificarBloques);
					cout << endl;
					for (int i = 0; i < empresa.lista_estudiantes.size(); i++)
					{
						if (empresa.lista_estudiantes[i].id == id)
						{
							for (int j = 0; j < empresa.lista_estudiantes[i].comidaEstudiante.size(); j++)
							{
								if (empresa.lista_estudiantes[i].comidaEstudiante[j].nombre == modificarComidas && empresa.lista_estudiantes[i].comidaEstudiante[j].bloque == modificarBloques)
								{
									while (acceso == false)
									{
										cout << "COMIDAS: Desayuno, Comida, Cena" << endl;
										cout << "Escriba la nueva comida: ";
										getline(cin, nuevacomida);
										cout << endl;
										cout << "BLOQUES: Bloque A, Bloque B" << endl;
										cout << "Escriba el nuevo bloque: ";
										getline(cin, nuevobloque);
										if (nuevobloque == "Bloque A" || nuevobloque == "Bloque B")
										{
											if (nuevacomida == "Desayuno" || nuevacomida == "Comida" || nuevacomida == "Cena")
											{
												empresa.lista_estudiantes[i].comidaEstudiante[j].nombre = nuevacomida;
												empresa.lista_estudiantes[i].comidaEstudiante[j].bloque = nuevobloque;
												j = empresa.lista_estudiantes[i].comidaEstudiante.size();
												cout << "Comida guardada exitosamente" << endl;
												acceso = true;
												acceso2 = true;
												encontrado = 1;
											}
											else
											{
												cout << "Comida no encontrada" << endl;
												cout << endl;
											}
										}
										else
										{
											cout << "Bloque no encontrado" << endl;
										}
									}
									j = empresa.lista_estudiantes[i].comidaEstudiante.size();
								}
							}
							i = empresa.lista_estudiantes.size();
						}
					}
					if (encontrado == 0)
					{
						cout << "El bloque o Comida que se desea buscar no fue encontrado" << endl;
						cout << "Intente nuevamente" << endl;
						cout << "Presione enter para Continuar..." << endl;
						cin.ignore();
					}
					GuardarComidas(empresa.lista_estudiantes);
				}
			}
			cout << "Presione enter para Continuar..." << endl;
			cin.ignore();
			break;
		}
		case SalirSubEstu:
		{
			cout << "Saliendo del menu de estudiantes" << endl;
			cout << "Presione enter para continuar..." << endl;
			cin.ignore();
			correrprograma2 = false;
			break;
		}
		default:
		{
			cout << "Opcion invalida" << endl;
			break;
		}
		}
	}


}

bool MenuBloqueEstudiante(Empresa& empresa, int id)
{
	bool encontro = false;
	system("cls");
	for (int i = 0; i < empresa.lista_estudiantes.size(); i++)
	{
		if (empresa.lista_estudiantes[i].id == id)
		{
			cout << "------MENU DE COMIDAS DE " << empresa.lista_estudiantes[i].nombre_estudiante << "---------" << endl;
			for (int j = 0; j < empresa.lista_estudiantes[i].comidaEstudiante.size(); j++)
			{
				cout << "Comida: " << empresa.lista_estudiantes[i].comidaEstudiante[j].nombre << "  ";
				cout << "Bloque: " << empresa.lista_estudiantes[i].comidaEstudiante[j].bloque << endl;
				encontro = true;
			}
		}
	}
	return encontro;
}

void MenuEstudiante()
{
	system("cls");
	cout << "===================MENU ESTUDIANTES=================" << endl;
	cout << "1. Registrar Bloque " << endl;
	cout << "2. Modificar Bloque" << endl;
	cout << "3. Regresar Menu Principal" << endl;
}

void MenuBloque()
{
	system("cls");
	cout << "=========== MENU BLOQUE ==============" << endl;
	cout << "1. Bloque A" << endl;
	cout << "2. Bloque B" << endl;
	cout << "Eliga una opcion: ";
}

void MenuTiempo()
{
	system("cls");
	cout << "===============TIEMPOS================" << endl;
	cout << "1. Desayuno" << endl;
	cout << "2. Comida" << endl;
	cout << "3. Cena" << endl;
	cout << "Eliga una opcion: ";

}

void RegistrarBloqueEstudiantes(Empresa& empresa, int bloque, int tiempo, int id)
{
	system("cls");
	int encontro = -1, contador = 0;
	string comida, nombreBloque;
	bool acceso, Cantidadbloques = true;
	switch (tiempo)
	{
	case 1:
	{
		comida = "Desayuno";
		break;
	}
	case 2:
	{
		comida = "Comida";
		break;
	}
	case 3:
	{
		comida = "Cena";
		break;
	}
	default:
	{
		comida = "Sin comida asignada";
		break;
	}
	}
	switch (bloque)
	{
	case 1:
	{
		if (comida != "Sin comida asignada")
		{
			nombreBloque = "Bloque A";
		}
		else
		{
			nombreBloque = "Sin Bloque";
		}
		break;
	}
	case 2:
	{
		if (comida != "Sin comida asignada")
		{
			nombreBloque = "Bloque B";
		}
		else
		{
			nombreBloque = "Sin Bloque";
		}
		break;
	}
	default:
	{
		nombreBloque = "Sin Bloque";
		break;
	}
	}
	acceso = VerificarComidas(empresa, id, nombreBloque, comida);
	if (acceso == true)
	{
		for (int i = 0; i < empresa.lista_estudiantes.size(); i++)
		{
			if (id == empresa.lista_estudiantes[i].id)
			{
				encontro = i;
			}
			for (int j = 0; j < empresa.lista_estudiantes[i].comidaEstudiante.size(); j++)
			{
				if (empresa.lista_estudiantes[i].comidaEstudiante[j].nombre == comida && empresa.lista_estudiantes[i].comidaEstudiante[j].bloque == nombreBloque)
				{
					contador++;
				}
			}
		}
		if (encontro != -1)
		{
			for (int l = 0; l < empresa.bloques.size(); l++)
			{
				if (empresa.bloques[l].nombre == comida && empresa.bloques[l].bloque == nombreBloque)
				{
					if (empresa.bloques[l].cantidad <= contador)
					{
						cout << "Se ha alcanzado la cantidad máxima de estudiantes en el " << nombreBloque << " en " << comida << endl;
						Cantidadbloques = false;
					}
				}
			}
			if (Cantidadbloques == true)
			{

				Comida temp;
				temp.id_estudiante = id;
				temp.nombre = comida;
				temp.bloque = nombreBloque;
				empresa.lista_estudiantes[encontro].comidaEstudiante.push_back(temp);
				GuardarComidas(empresa.lista_estudiantes);
				cout << "Comida y Bloque Guardados exitosamente" << endl;
			}
		}
	}
	else
	{
		cout << "Comida no guardada" << endl;
	}
	cout << "Presione enter para continuar..." << endl;
	cin.ignore();
}

bool VerificarComidas(Empresa& empresa, int id, string bloque, string comida)
{
	int contador = 0;
	bool concedido = true;
	for (int i = 0; i < empresa.lista_estudiantes.size(); i++)
	{
		if (id == empresa.lista_estudiantes[i].id)
		{
			if (empresa.lista_estudiantes[i].comidaEstudiante.size() >= 3)
			{
				cout << "El estudiante ya esta inscrito a 3 comidas distintas, es imposible añadir más" << endl;
				concedido = false;
				cout << "Presione enter para continuar..." << endl;
				cin.ignore();
			}
			for (int j = 0; j < empresa.lista_estudiantes[i].comidaEstudiante.size(); j++)
			{
				if (empresa.lista_estudiantes[i].comidaEstudiante[j].nombre == comida && empresa.lista_estudiantes[i].comidaEstudiante[j].bloque == bloque)
				{
					if (concedido == true)
					{
						cout << "Ya estaba registrado al " << bloque << " de " << comida << endl;
						concedido = false;
					}
				}
			}
			i = empresa.lista_estudiantes.size();
		}
	}
	return concedido;
}

void AccesoDirectivo(Empresa& empresa, int id)
{
	int opc;
	system("cls");
	int bloque, comida, cantidad;
	string buscarcomida, buscarBloque;
	bool correrprograma2 = true;
	while (correrprograma2 == true)
	{
		MenuDirectivos();
		cin >> opc;
		cin.ignore();
		switch (opc)
		{
		case editarCapaEstudiantes:
		{
			system("cls");
			cout << "Escriba la capacidad máxima de estudiantes: ";
			cin >> cantidad;
			cin.ignore();
			if (empresa.lista_estudiantes.size() < cantidad)
			{
				cout << "Cantidad maxima de estudiantes establecida exitosamente " << endl;
				empresa.cantidadEstudiantes = cantidad;
				cout << "Presione enter para continuar..." << endl;
				cin.ignore();
				GuardarCantidadestudiantes(empresa);
			}
			else
			{
				cout << "La cantidad maxima ingresada es menor a la cantidad de estudiantes ya registrada, por lo tanto es imposible establecerlo" << endl;
				cout << "Presione enter para continuar..." << endl;
				cin.ignore();

			}
			break;
		}
		case CantidadalumnosXBloque:
		{
			MenuBloque();
			cin >> bloque;
			cin.ignore();
			switch (bloque)
			{
			case 1:
			{
				buscarBloque = "Bloque A";
				break;
			}
			case 2:
			{
				buscarBloque = "Bloque B";
				break;
			}

			default:
				cout << "Opcion invalida";
				break;
			}
			MenuTiempo();
			cin >> comida;
			cin.ignore();
			switch (comida)
			{
			case 1:
			{
				buscarcomida = "Desayuno";
				break;
			}
			case 2:
			{
				buscarcomida = "Comida";
				break;
			}
			case 3:
			{
				buscarcomida = "Cena";
				break;
			}
			default:
				break;
			}
			cout << "Usted eligio la comida: " << buscarcomida << endl;
			cout << "Usted eligio el bloque: " << buscarBloque << endl;
			cout << "Presione enter para iniciar la busqueda..." << endl;
			cin.ignore();
			EditarCantidadEstudiantes(empresa.lista_estudiantes, empresa.bloques, buscarBloque, buscarcomida);
			break;
		}
		case verEstudiantes:
		{
			MenuBloque();
			cin >> bloque;
			cin.ignore();
			switch (bloque)
			{
			case 1:
			{
				buscarBloque = "Bloque A";
				break;
			}
			case 2:
			{
				buscarBloque = "Bloque B";
				break;
			}

			default:
				cout << "Opcion invalida";
				break;
			}
			MenuTiempo();
			cin >> comida;
			cin.ignore();
			switch (comida)
			{
			case 1:
			{
				buscarcomida = "Desayuno";
				break;
			}
			case 2:
			{
				buscarcomida = "Comida";
				break;
			}
			case 3:
			{
				buscarcomida = "Cena";
				break;
			}
			default:
				break;
			}
			cout << "Usted eligio la comida: " << buscarcomida << endl;
			cout << "Usted eligio el bloque: " << buscarBloque << endl;
			cout << "Presione enter para iniciar la busqueda..." << endl;
			cin.ignore();
			VerDatosEstudiantes(empresa.lista_estudiantes, buscarBloque, buscarcomida);
			break;
		}
		case SalirDirectivo:
		{
			cout << "Regresando al menu principal" << endl;
			cout << "Presione enter para continuar..." << endl;
			cin.ignore();
			correrprograma2 = false;
		}
		default:
		{
			break;
		}
		}

	}

}

void MenuDirectivos()
{
	system("cls");
	cout << "=============MENU DIRECTIVOS===========" << endl;
	cout << "1. Editar Capacidad de Estudiantes" << endl;
	cout << "2. Editar Capacidad de Estudiantes por bloques y comidas" << endl;
	cout << "3. Ver estudiantes por bloques y comidas" << endl;
	cout << "4. Salir al menu principal" << endl;
	cout << "Seleccione una opcion: ";
}

void VerDatosEstudiantes(vector<Estudiante>& estudiantes, string bloque, string comida)
{
	int encontro = 0, contador = 0;
	system("cls");
	cout << "====LISTA ESTUDIANTES EN EL " << bloque << "" << comida << "====" << endl;
	for (int i = 0; i < estudiantes.size(); i++)
	{
		for (int j = 0; j < estudiantes[i].comidaEstudiante.size(); j++)
		{
			if (estudiantes[i].comidaEstudiante[j].bloque == bloque && estudiantes[i].comidaEstudiante[j].nombre == comida)
			{
				cout << endl;
				cout << "Nombre del Estudiante: " << estudiantes[i].nombre_estudiante << endl;;
				cout << "ID de " << estudiantes[i].nombre_estudiante << ": " << estudiantes[i].id << endl;
				cout << endl;
				encontro = 1;
				contador++;
			}
		}
	}
	if (encontro == 0)
	{
		cout << endl;
		cout << "No habia ningun estudiante en esa comida ni bloque" << endl;
	}
	cout << endl;
	cout << "Total de estudiantes en el " << bloque << " y " << comida << ": " << contador << endl;
	cout << endl;
	cout << "Presione enter para continuar..." << endl;
	cin.ignore();
}

void EditarCantidadEstudiantes(vector<Estudiante>& estudiantes, vector<Bloque>& bloques, string bloque, string comida)
{
	int encontro = 0, cantidad, contador = 0, cantidadinscritos = 0;
	system("cls");
	cout << "====LISTA DE ESTUDIANTES INSCRITOS EN EL BLOQUE: " << bloque << " Y EN LA COMIDA " << comida << "====" << endl;
	for (int i = 0; i < estudiantes.size(); i++)
	{
		for (int j = 0; j < estudiantes[i].comidaEstudiante.size(); j++)
		{
			if (estudiantes[i].comidaEstudiante[j].bloque == bloque && estudiantes[i].comidaEstudiante[j].nombre == comida)
			{
				contador++;
				cantidadinscritos++;
			}
		}
	}
	cout << endl;
	cout << "Estudiantes inscritos en el " << bloque << " en  " << comida << ": " << contador << endl;;
	cout << "Escriba una cantidad máxima de alumnos para  " << comida << " en el  " << bloque << endl;
	cin >> cantidad;
	cin.ignore();
	if (cantidad < contador)
	{
		cout << "No se puede cambiar la cantidad de alumnos YA inscritos en la comida y el bloque" << endl;
		cout << "Presione enter para continuar..." << endl;
		cin.ignore();
	}
	else
	{
		cout << "Cantidad maxima de alumnos asignada correctamente" << endl;
		for (int i = 0; i < bloques.size(); i++)
		{
			if (bloques[i].nombre == comida && bloques[i].bloque == bloque)
			{
				bloques[i].nombre = comida;
				bloques[i].bloque = bloque;
				bloques[i].cantidad = cantidad;
			}
		}
		cout << "Presione enter para continuar..." << endl;
		cin.ignore();
		GuardarBloques(bloques);

	}
}

void GuardarBloques(vector<Bloque>& bloques)
{
	string nombre_comida, nombre_bloque;
	int cant;
	ofstream ofs;
	ofs.open("Bloques.csv", ofstream::trunc);
	ofstream myFileOutput("Bloques.csv", ios_base::app);
	myFileOutput << "nombre_Comida, nombre_bloque,cantidad\n";
	myFileOutput.close();
	for (int i = 0; i < bloques.size(); i++)
	{
		nombre_comida = bloques[i].nombre;
		nombre_bloque = bloques[i].bloque;
		cant = bloques[i].cantidad;
		Bloque temporal = { nombre_comida,nombre_bloque,cant };
		ofstream myFileOutput("Bloques.csv", ios_base::app);
		myFileOutput << temporal.nombre << "," << temporal.bloque << "," << temporal.cantidad << endl;
		myFileOutput.close();
	}
}

void GuardarCantidadestudiantes(Empresa& empresa)
{
	ofstream ofs;
	ofs.open("CantidadTotalEstudiantes.csv", ofstream::trunc);
	ofstream myFileOutput("CantidadTotalEstudiantes.csv", ios_base::app);
	myFileOutput << "cantidad\n";
	myFileOutput << empresa.cantidadEstudiantes << endl;
	myFileOutput.close();
}