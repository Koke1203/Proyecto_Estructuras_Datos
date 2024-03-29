#include "interger.h"

// interger.h
// Autores: Gabriel Barboza Carvajal , Jorge Canales Espinoza , Joan Corea Aguilar - ( implementaci�n ).



interger::interger() {
	lis = new lista_doble_enlazada();
}


interger::interger(int num) {
	lis = new lista_doble_enlazada();
	string valor;
	valor = to_string(num);
	ConvertirObjeto(valor);
}

interger::interger(long num) {
	lis = new lista_doble_enlazada();
	string valor;
	valor = to_string(num);
	ConvertirObjeto(valor);
}

interger::~interger()
{
	lis->~lista_doble_enlazada();
	//delete lis;
}




int interger::obtener_cantidad_nodos()
{
	return lis->get_cantidad_nodos();
}

string interger::operator[](long pos)
{
	this->pos = pos;
	//cout << "pos : " << pos << endl;
	string ss;
	if ((pos / 16) > obtener_cantidad_nodos())// pos/16 -> retorna la cantidad de nodos en la lista
	{
		cout << toString() << endl;
		cout << "pos/16 : " << pos / 16 << " , cantidad : " << obtener_cantidad_nodos() << endl;
		cout << "posicion exede el tamanio del interger" << endl;
		return "-1";
	}
	else
	{
		string s;
		long pos_vector = pos;
		if (pos_vector <= 15) {
			s = lis->obtener_nodo(0)->getPtr()->retornar_numero_0s();
			ss += s[pos_vector];
		}
		else
		{
			if (pos > this->obtener_numero_digitos())
				return "la posicion exede el tamanio del numero\n";
			else
			{
				s = lis->obtener_nodo((pos / 16))->getPtr()->retornar_numero_0s();
				long num_digitos_nodo_anterior = 16 * (pos / 16);
				long pos_vector = (pos - num_digitos_nodo_anterior);
				if (pos_vector < 0)pos_vector = 0;
				ss += s[pos_vector];

			}
		}


		return ss;
	}
}


void interger::mostrarNumero()
{
	nodo* aux = lis->getUltimo();

	while (aux != nullptr) {
		//cout << *aux->getPtr() << endl;

		aux->getPtr()->mostrarAlreves();
		aux = aux->getAnt();
	}
	/*
			while (aux)
			{
				aux->getPtr()->mostrarAlreves();
				aux = aux->getSig();
			}*/
}

void interger::mostrar_resultado_numero_multi()
{
}

void interger::mostrarNumeroRellenandoOs()
{
	nodo* aux = lis->getPrimero();

	while (aux)
	{
		aux->getPtr()->mostrarRellenandoOs();
		aux = aux->getSig();
	}
}

void interger::mostrarNumeroAComoSeAlmacena()
{
	nodo* aux = lis->getPrimero();

	while (aux)
	{
		aux->getPtr()->mostrarNormalCasillas();
		aux = aux->getSig();
	}
}
/*
			_-----------------------------------------------el de arriba es la primera version
		 Metodologia de creacion de la lista :
		 vamos a obtener el numero tal como se pasa por el parametro
		 y iremos guardando 4 digitos en una posicion del arreglo asi :
		 si el numero es 12345
		 guardaremos primero los ultimos cuatro digitos en la ultma posicion de ese arreglo , es decir de derecha a izquierda
		--------------------------------------------------> [0000][0000][0001][2345]
		--------------------------------------------------> [null][null][null][2345] -> asi seria mejor creo por que no se usaria la memoria de los primeros 3.
		clase de vector modificada para que almacene los datos de manera dinamica...
		*/
void interger::ConvertirObjeto(string num)//crea la lista enlazada de vectores
{
	cont = num.size();
	vector v;
	vector* aux = new vector();//_Creamos un vector de 4 posiciones que contiene elementos dinamicos...
	bool insercion;
	short numero;
	//cout << "Size : " << num.size() << endl;
	for (short i = num.size(); i >= 0; i -= 4)// recorremos la entrada en numeros de cuatro en cuatro
	{

		//cout << "Size : " << num.size() << endl;
		//system("pause");
		if (num.size() >= 4)
		{
			numero = short(stoi(num.substr(num.size() - 4, num.size())));
			insercion = aux->insertarElementoFinal(numero);
			//cout << "> 4" << endl << numero << endl;

			if (insercion == 0)//llego al final , nuevo vector hay que a�adir
			{
				//lis->insertar_elemento(new vector(*aux));//creamos un vector nuevo con base al que se lleno recientemente 
				lis->insertar_elementoPrimero(new vector(*aux));
				//lis->imprimir_lista();
				aux->borrarElementos();//borramos los datos del aux para empezar a llenarlo denuevo
				//cout << "----------------B O R R A N D O __ V E C T O R ---------------" << endl;
				//aux->mostrarNormalCasillas();
				aux->insertarElementoFinal(numero);
				//aux->mostrarNormalCasillas();
			}
			num.resize(num.size() - 4);
			//cout << "Numero : " << numero << endl;
			//system("pause");

		}
		else//final del nunmero
		{
			//cout << "--------------FINAL DEL NUMERO---------------" << endl;
			numero = 0;
			//cout << "Size : " << num.size() << endl;
			if (num.size() != 0)
				numero = short(stoi(num.substr(0, num.size())));
			//cout << numero << endl;
			insercion = aux->insertarElementoFinal(numero);
			if (insercion == false)//se lleno y quedaron numeros sin almacenarse
			{
				cout << "num . size = " << num.size() << endl;
				if (num.size() == 0)
				{
					lis->insertar_elementoPrimero(new vector(*aux));//guardamos el numero anterior
					break;
				}
				else
				{
					lis->insertar_elementoPrimero(new vector(*aux));//guardamos el numero anterior
					//cout << "quedo el elemento : " << numero << " , sin almacenarse " << endl;
					aux->borrarElementos();
					aux->insertarElementoFinal(numero);
					//aux->mostrarNormalCasillas();
					lis->insertar_elementoPrimero(new vector(*aux));
					//lis->imprimir_lista();
					return; break;
				}
				//aux->borrarElementos();//borramos los datos del aux para empezar a llenarlo denuevo
			}
			else
			{
				//aux->mostrarNormalCasillas();
				//cout << "<4" << endl << numero << endl;

				//lis->insertar_elemento(new vector(*aux));//creamos un vector nuevo con base al que se lleno recientemente 
				lis->insertar_elementoPrimero(new vector(*aux));
				//lis->imprimir_lista();
				aux->borrarElementos();//borramos los datos del aux para empezar a llenarlo denuevo
			}
		}
	}



}

string interger::toString()
{
	nodo* aux = lis->getPrimero();
	stringstream s;
	while (aux)
	{
		s << aux->getPtr()->toString();
		aux = aux->getSig();
	}
	return s.str();
}

void interger::guardar_numero_txt(string nombre)
{
	ofstream salida(nombre);
	salida << this->toString();
	salida.close();
}
//
//void interger::cargar_numero(string nombre)
//{
//	ifstream entrada(nombre);
//	short cont = 1;
//	vector* aux = new vector();
//	bool insercion = true;
//	char digi;
//	string numero_4_digitos = "";
//
//	do {
//		if (!entrada.eof())
//			entrada >> digi;
//		else
//			break;
//		cout << "digi: " << digi << endl;
//		numero_4_digitos += digi;
//		digi = ' ';
//		cout << "numero 4 digi : " << numero_4_digitos << endl;
//		if (cont == 4)//llenamos un numero
//		{
//			cout << "numero captado : " << numero_4_digitos << endl;
//
//			short num = atoi(numero_4_digitos.c_str());
//			cout << " num short = " << num << endl;
//			insercion = aux->insertarElementoPrimero(num);
//			if (insercion == false)//se lleno el vector
//			{
//
//				aux->mostrarNormalCasillas();
//				lis->insertar_elementoPrimero(new vector(*aux, bool()));
//				aux->borrarElementos();
//				aux->insertarElementoPrimero(num);
//				cout << "toString : " << lis->imprimir_lista() << endl;
//				system("pause");
//			}
//			num = 0;
//			numero_4_digitos = "";// se setea el valor del string
//
//			cont = 0;
//		}
//
//		cont++;
//	} while (entrada.good() and !entrada.eof());
//	if (aux->getTam() == 4 and numero_4_digitos != "")//quedaron numeros sin insertarse
//	{
//		cout << "ultimos digitos ojas : " << numero_4_digitos << endl;
//		lis->insertar_elementoPrimero(new vector(*aux, bool()));
//		aux->borrarElementos();
//
//		aux->insertarElementoPrimero(atoi(numero_4_digitos.c_str()));
//		cout << "toString _  : " << aux->toString() << endl;
//
//		lis->insertar_elementoPrimero(new vector(*aux, bool()));
//
//		cout << "toString : " << lis->imprimir_lista() << endl;
//
//	}
//	aux->mostrarNormalCasillas();
//
//	cout << "--------------------------------------------------------------------" << endl;
//	lis->imprimir_lista();
//	cout << "--------------------------------------------------------------------" << endl;
//
//	system("pause");
//}


//metodo que obtiene la cantidad de digitos del numero
int interger::digitos_numero() {
	return cont;
}

//devuelvo el vector que contiene la posicion digitada del nodo
vector* interger::obtener_nodo(int pos) {
	return lis->obtener_nodo(pos)->getPtr();
}

int interger::getCarry(int num)
{
	int carry = 0;
	if (num >= 10) {
		while (num != 0) {
			carry = num % 10;
			//cout << "Carry : " << carry << endl;
			num = num / 10;
			//cout << "Num : " << num << endl;
		}
	}

	else {
		carry = 0;
		/*	cout << "Num <= 10" << endl;
			cout << "Carry : " << carry << endl;
			cout << "Num : " << num << endl;*/
	}
	return carry;
}

//para saber si dos intergers son iguales, tengo que pasarlo a la clase interger.cpp, y realizar la sobrecarga del operador
bool interger::operator==(interger& num2) {
	bool es_igual = false;
	if (cont != num2.digitos_numero()) {  //automaticamente se sabe que son diferentes
		return es_igual;
	}
	else if (digitos_numero() == num2.digitos_numero()) { //se sabe que tiene el mismo tamanio
		cout <<"Numero de digitos"<< num2.digitos_numero() << endl;
		if (digitos_numero() <= 9) {    //compara para numeros menores o iguales a nueve digitos.
			string aux, aux2;
			string nodo = lis->getPrimero()->getPtr()->toString();
			cout << nodo << endl;
			//for (size_t i = 0; i < obtener_numero_digitos(); i++) {
			//	//aux += ;
			//}
			//cout << "aux : " << aux << endl;
			for (size_t i = 0; i < num2.obtener_numero_digitos(); i++) {
				aux2 += num2[i];
			}
			if (nodo.compare(aux2) == 0) {
				es_igual = true;
			}
			else {
				es_igual = false;
				return es_igual;
			}
		}
		else if (digitos_numero() > 9) {    //compara para numeros mayores o iguales a 10 digitos.
			vector vector1, vector2;
			for (long i = 0; i < obtener_cantidad_nodos();i++) {
				//obtengo cada contenido de cada nodo de la lista, por medio de la clase vector, luego voy comparando eso.
				vector1 = obtener_nodo(i);
				vector2 = num2.obtener_nodo(i);
				for (short i = 0; i < 4;i++) {
					if (vector1.getNumerosPosicion(i) == vector2.getNumerosPosicion(i)) {
						es_igual = true;
					}
					else {
						es_igual = false;
						return es_igual;
					}
				}
			}
		}
	}
}

//para saber si dos intergers son diferentes, tengo que pasarlo a la clase interger.cpp, y realizar la sobrecarga del operador
bool interger::operator!=(interger& num2) {
	
	bool s = *this == num2;
	if (s)
		return false;
	else
		return true;
	
}

bool  interger::operator >(interger& num2) {
	bool mayor = true;
	if (digitos_numero() > num2.digitos_numero()) {  //automaticamente se sabe que son diferentes
		return mayor;
	}
	else if (digitos_numero() < num2.digitos_numero()) {
		mayor = false;
		return mayor;
	}
	else if (digitos_numero() == num2.digitos_numero()) { //se sabe que tiene el mismo tamanio
		if (digitos_numero() <= 9) {    //compara para numeros menores o iguales a nueve digitos.
			string aux2;
			string aux = lis->getPrimero()->getPtr()->toString();
			for (int i = 0; i < num2.obtener_numero_digitos(); i++) {
				aux2 += num2[i];
			}
			int n1 = utiles::convertir_int(aux);
			int n2 = utiles::convertir_int(aux2);
			if (n1>n2)
			{
				return mayor;
			}
			else
			{
				mayor = false;
				return mayor;
			}
				
		}
		else if (digitos_numero() > 9) {
			vector vector1, vector2;
			for (short i = 0; i < obtener_cantidad_nodos(); i++) {
				//obtengo cada contenido de cada nodo de la lista, por medio de la clase vector, luego voy comparando eso.
				vector1 = obtener_nodo(0);
				vector2 = num2.obtener_nodo(0);
				for (short i = 0; i < 4; i++) {
					if (vector1.getNumerosPosicion(i) > vector2.getNumerosPosicion(i)) {
						mayor = true;
					}
					else {
						mayor = false;
						return mayor;
					}
				}
			}
		}
	}
}

bool interger::operator<(interger& num2) {
	bool menor = true;
	if (digitos_numero() < num2.digitos_numero()) {  //automaticamente se sabe que son diferentes
		return menor;
	}
	else if (digitos_numero() > num2.digitos_numero()) {
		menor = false;
		return menor;
	}
	else if (digitos_numero() == num2.digitos_numero()) { //se sabe que tiene el mismo tamanio
		if (digitos_numero() <= 9) {    //compara para numeros menores o iguales a nueve digitos.
			string aux2;
			string aux = lis->getPrimero()->getPtr()->toString();
			for (int i = 0; i < num2.obtener_numero_digitos(); i++) {
				aux2 += num2[i];
			}
			int n1 = utiles::convertir_int(aux);
			int n2 = utiles::convertir_int(aux2);
			if (n1 < n2)
			{
				return menor;
			}
			else
			{
				menor = false;
				return menor;
			}
		}
		else if (digitos_numero() > 9) {
			vector vector1, vector2;
			for (short i = 0; i < obtener_cantidad_nodos(); i++) {
				//obtengo cada contenido de cada nodo de la lista, por medio de la clase vector, luego voy comparando eso.
				vector1 = obtener_nodo(0);
				vector2 = num2.obtener_nodo(0);
				for (short i = 0; i < 4; i++) {
					if (vector1.getNumerosPosicion(i) < vector2.getNumerosPosicion(i)) {
						menor = true;
					}
					else {
						menor = false;
						return menor;
					}
				}
			}
		}
	}
}

bool interger::operator>=(interger& num2) {
	bool mayor = true;
	if (digitos_numero() > num2.digitos_numero()) {
		return mayor;
	}
	else if (digitos_numero() == num2.digitos_numero()) {
		if (digitos_numero() <= 9) {    //compara para numeros menores o iguales a nueve digitos.
			string aux2;
			string aux = lis->getPrimero()->getPtr()->toString();
			for (int i = 0; i < num2.obtener_numero_digitos(); i++) {
				aux2 += num2[i];
			}
			int n1 = utiles::convertir_int(aux);
			int n2 = utiles::convertir_int(aux2);
			if (n1 > n2)
			{
				return mayor;
			}
			else if (n1 == n2)
			{
				mayor = false;
				return mayor;
			}
		}
		else if (digitos_numero() > 9) {
			vector vector1, vector2;
			for (short i = 0; i < obtener_cantidad_nodos(); i++) {
				vector1 = obtener_nodo(i);
				vector2 = num2.obtener_nodo(i);
				for (short i = 0; i < 4; i++) {
					if (vector1.getNumerosPosicion(i) == vector2.getNumerosPosicion(i)) {
						mayor = false;
						return mayor;
					}
					else if (vector1.getNumerosPosicion(i) > vector2.getNumerosPosicion(i))
					{
						return mayor;
					}
				}
			}
		}
	}
}

bool interger::operator<=(interger& num2) {
	bool menor = true;
	if (digitos_numero() < num2.digitos_numero()) {
		return menor;
	}
	else if (digitos_numero() == num2.digitos_numero()) {
		if (digitos_numero() <= 9) {    //compara para numeros menores o iguales a nueve digitos.
			string aux2;
			string aux = lis->getPrimero()->getPtr()->toString();
			for (int i = 0; i < num2.obtener_numero_digitos(); i++) {
				aux2 += num2[i];
			}
			int n1 = utiles::convertir_int(aux);
			int n2 = utiles::convertir_int(aux2);
			if (n1 < n2)
			{
				return menor;
			}
			else if (n1 == n2)
			{
				menor = false;
				return menor;
			}
		}
		else if (digitos_numero() > 9) {
			vector vector1, vector2;
			for (short i = 0; i < obtener_cantidad_nodos(); i++) {
				vector1 = obtener_nodo(i);
				vector2 = num2.obtener_nodo(i);
				for (short i = 0; i < 4; i++) {
					if (vector1.getNumerosPosicion(i) == vector2.getNumerosPosicion(i)) {
						menor = false;
						return menor;
					}
					else if (vector1.getNumerosPosicion(i) < vector2.getNumerosPosicion(i))
					{
						return menor;
					}
				}
			}
		}
	}
}



interger* interger::multiply(interger num1, interger num2)
{
	int len1 = num1.obtener_numero_digitos();
	int len2 = num2.obtener_numero_digitos();
	try
	{
		if (utiles::convertir_int(num2.toString()) == CERO or utiles::convertir_int(toString()) == CERO
			or utiles::convertir_int(num2.toString()) < CERO or utiles::convertir_int(toString()) < CERO)
			throw "multiplicacion por 0 , Resultado = 0\n";
	}
	catch (const char* da)
	{
		cout << da << endl;
		interger *in=new interger();
		in->ConvertirObjeto("1");
		return in;
	}

	short* result = new short[len1 + len2];
	for (size_t i = 0; i < len1 + len2; i++)
	{
		result[i] = 0;
	}
	int i_n1 = 0;
	int i_n2 = 0;
	for (int i = len1 - 1; i >= 0; i--)
	{
		int carry = 0;
		int n1 = num(num1[i]);
		i_n2 = 0;

		for (int j = len2 - 1; j >= 0; j--)
		{
			int n2 = num(num2[j]);
			int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

			carry = sum / 10;

			result[i_n1 + i_n2] = sum % 10;
			i_n2++;
		}

		if (carry > 0)
			result[i_n1 + i_n2] += carry;

		i_n1++;
	}

	int i = (len1 + len2) - 1;
	while (i >= 0 && result[i] == 0)
		i--;

	string s = "";
	//guardamos el resultado en un txt


	cadena* resu = new cadena(0);

	i = (len1 + len2) - 1;
	//cout << " i : " << i << endl;
	while (i >= 0)
	{
		string ss = std::to_string(result[i--]);
		//cout << "ss : " << ss << endl;
		resu->Insertar(ss.at(0));
		ss = "";
	}
	resu->guardar_resultado_alreves("../resultado_alreves.txt");
	interger* res = new interger();
	res->cargar_numero_alreves("../resultado_alreves.txt");
	return res;

}


interger& interger::operator*(interger& num2)
{

	interger num1(*this);
	unsigned int len1 = num1.obtener_numero_digitos();// num1.obtener_numero_digitos();
	unsigned int len2 = num2.obtener_numero_digitos();
	try
	{
		if (utiles::convertir_int(num2.toString()) == CERO or utiles::convertir_int(toString()) == CERO
			or utiles::convertir_int(num2.toString()) < CERO or utiles::convertir_int(toString()) < CERO)
			throw "multiplicacion por 0 , Resultado = 0\n";
	}
	catch (const char* da)
	{
		cout << da << endl;
		interger in;
		in.ConvertirObjeto("1");
		return in;
	}
	//vector para almacenar el resultado de las multiplicaciones
	short* result = new short[len1 + len2];
	for (size_t i = 0; i < len1 + len2; i++)
	{
		result[i] = 0;
	}
	//indices para los numeros 1 y 2
	int i_n1 = 0;
	int i_n2 = 0;
	//recorremos el primer numero de derecha a izquierda como se hace a pie , cada digito multiplicados por los demas
	for (int i = len1 - 1; i >= 0; i--)
	{
		//cout << "i :" << i << endl;
		int carry = 0;
		int n1 = num(num1[i]);
		i_n2 = 0;

		//recorremos el segundo numero de derecha a izquierda...          
		for (int j = len2 - 1; j >= 0; j--)
		{
			
			int n2 = num(num2[j]);

			int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

			carry = sum / 10;

			result[i_n1 + i_n2] = sum % 10;
			i_n2++;
		}

		if (carry > 0)
			result[i_n1 + i_n2] += carry;

		i_n1++;
	}

	// ignore '0's from the right 
	int i = (len1 + len2) - 1;
	//cout << " i : " << i << endl;
	while (i >= 0 && result[i] == 0)
		i--;


	//// generate the result string 
	string s = "";
	//guardamos el resultado en un txt

	cadena* resu = new cadena(0);

	i = (len1 + len2) - 1;
	//cout << " i : " << i << endl;
	while (i >= 0)
	{
		string ss = std::to_string(result[i--]);
		//cout << "ss : " << ss << endl;
		resu->Insertar(ss.at(0));
		ss = "";
	}

	resu->guardar_resultado_alreves("../resultado_alreves.txt");
	interger* res = new interger();
	res->cargar_numero_alreves("../resultado_alreves.txt");
	return *res;
}

interger& interger::operator*=(interger& num2)
{
	interger num1(*this);
	int len1 = num1.obtener_numero_digitos();// num1.obtener_numero_digitos();
	int len2 = num2.obtener_numero_digitos();
	
	try
	{
		if (utiles::convertir_int(num2.toString()) == CERO or utiles::convertir_int(toString()) == CERO
			or utiles::convertir_int(num2.toString())< CERO or utiles::convertir_int(toString())< CERO)
			throw "multiplicacion por 0 , Resultado = 0\n";
	}
	catch (const char * da)
	{
		cout << da << endl;
		interger in;
		in.ConvertirObjeto("1");
		return in;
	}

	short* result = new short[len1 + len2];
	for (size_t i = 0; i < len1 + len2; i++)
	{
		result[i] = 0;
	}

	int i_n1 = 0;
	int i_n2 = 0;
	
	for (int i = len1 - 1; i >= 0; i--)
	{
		int carry = 0;
		int n1 = num(num1[i]);
		i_n2 = 0;

		for (int j = len2 - 1; j >= 0; j--)
		{
			int n2 = num(num2[j]);
		
			int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

			carry = sum / 10;
			
			result[i_n1 + i_n2] = sum % 10;
			i_n2++;
		}

		if (carry > 0)
			result[i_n1 + i_n2] += carry;

		i_n1++;
	}

	int i = (len1 + len2) - 1;
	//cout << " i : " << i << endl;
	while (i >= 0 && result[i] == 0)
		i--;

	//// generate the result string 
	string s = "";
	//guardamos el resultado en un txt

	cadena* resu = new cadena(0);

	i = (len1 + len2) - 1;
	//cout << " i : " << i << endl;
	while (i >= 0)
	{
		string ss = std::to_string(result[i--]);
		//cout << "ss : " << ss << endl;
		resu->Insertar(ss.at(0));
		ss = "";
	}

	resu->guardar_resultado_alreves("../resultado_alreves.txt");
	interger* res = new interger();
	res->cargar_numero_alreves("../resultado_alreves.txt");
	*this = *res;
	return *this;
}

void interger::cargar_numero_alreves(string nombre)
{
	short cont = 0;
	vector* aux = new vector();
	bool insercion = true;
	char digi;
	string numero_4_digitos = "";

	//-------verificar si es un numero menor a 16 digitos , para recuperarlo de otra manera
	ifstream entrada2(nombre);
	string auxstr;
	string num_peque�o; int cont2 = 0;
	while (entrada2.good() and cont <= 17)
	{
		entrada2 >> auxstr;
		num_peque�o += auxstr;
		cont++;

	}
	entrada2.close();
	if (num_peque�o.size() <= 17)
	{
		reverse(num_peque�o.begin(), num_peque�o.end());
		this->ConvertirObjeto(num_peque�o);
	}
	else//es un numero grande
	{
		ifstream entrada(nombre);
		do {
			//cout << ".";
			if (!entrada.eof())
				entrada >> digi;
			else
				break;
			//cout << "digi: " << digi << endl;
			numero_4_digitos += digi;
			digi = ' ';
			if (cont == 4)//llenamos un numero
			{
				//cout << "numero captado : " << numero_4_digitos << endl;
				reverse(numero_4_digitos.begin(), numero_4_digitos.end());
				//cout << "numero 4 digi : " << numero_4_digitos << endl;
				short num = atoi(numero_4_digitos.c_str());
				//cout << " num short = " << num << endl;
				//insercion = aux->insertarElementoPrimero(num);
				insercion = aux->insertarElementoFinal(num);
				if (insercion == false)//se lleno el vector
				{

					//aux->mostrarNormalCasillas();
					lis->insertar_elementoPrimero(new vector(*aux, bool()));// cambiar para insertar de ultimo a ver que tal
					//lis->insertar_elemento(new vector(*aux, bool()));
					aux->borrarElementos();
					//insercion = aux->insertarElementoPrimero(num);//vamos a ponerlo para insercion al final
					insercion = aux->insertarElementoFinal(num);
					//cout << "toString : " << lis->imprimir_lista() << endl;
					//system("pause");
				}
				num = 0;
				numero_4_digitos = "";// se setea el valor del string

				cont = 0;
			}

			cont++;
		} while (entrada.good() and !entrada.eof());

		//cout << "cont : " << cont << endl;
		//cout << "cantidad vector: " << aux->getCant() << endl;
		//cout << "ultimos digitos ojas : " << numero_4_digitos << endl;
		if (!numero_4_digitos.empty())//quedaron numeros sin insertarse
		{
			//cout << "ultimos digitos ojas : " << numero_4_digitos << endl;
			/*lis->insertar_elementoPrimero(new vector(*aux, bool()));*/// cambiar para insertar de ultimo a ver que tal
			if (aux->getCant() < aux->getTam())//aun queda un espacio disponible
			{
				//aux->insertarElementoPrimero(atoi(numero_4_digitos.c_str()));
				aux->insertarElementoFinal(atoi(numero_4_digitos.c_str()));
				//lis->insertar_elemento(new vector(*aux, bool()));
				lis->insertar_elementoPrimero(new vector(*aux, bool()));
			}
			else if (aux->getCant() == aux->getTam())//esta lleno el vector
			{

				//cout << "numero : " << num_int << endl;
				//lis->insertar_elemento(new vector(*aux, bool()));
				//aux->mostrarRellenandoOs();
				lis->insertar_elementoPrimero(new vector(*aux, bool()));
				aux->borrarElementos();
				//cout << "numero _int: " << num_int << endl;
				//aux->insertarElementoPrimero(atoi(numero_4_digitos.c_str()));

				//aux->insertarElementoFinal(atoi(numero_4_digitos.c_str()));

				//cout << "toString _  : " << aux->toString() << endl;

				//lis->insertar_elementoPrimero(new vector(*aux, bool()));
				//lis->insertar_elemento(new vector(*aux, bool()));

			}
			//cout << "toString : " << lis->imprimir_lista() << endl;

		}
		//aux->mostrarNormalCasillas();

		/*cout << "--------------------------------------------------------------------" << endl;
		lis->imprimir_lista();
		cout << "--------------------------------------------------------------------" << endl;
		cout << "cant _ " << lis->get_cantidad_nodos() << endl;
		*/
		//	verificamos que no haya un nodo con 0�s al inicio y lo borramos de ser asi
		string ulti = lis->getPrimero()->getPtr()->toString();
		//cout << "ojas-> " << ulti << endl; 
		bool borrar = true;
		for (size_t i = 0; i < ulti.size(); i++)
		{
			if (ulti[i] != '0')
			{
				borrar = false; break;
			}
		}
		//cout << "borrar : " << borrar << endl;
		if (borrar == true)
			lis->borrar_inicio();

	}
	//system("pause");
	//system("cls");
}

int interger::num(char a)
{
	return int(a) - 48;
}

int interger::num(string a)
{
	return atoi(a.c_str());
}

ostream& operator<<(ostream& o,  interger& in)
{
	o << in.toString() << endl;
	return o;
}
