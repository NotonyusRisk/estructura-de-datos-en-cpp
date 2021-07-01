#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *sub_der;
	Nodo *sub_izq;
	Nodo *padre;
};

Nodo *arbol = NULL;

//prototipos de funcion
void menu();
Nodo *crearNodo(int, Nodo *);
void insertarArbol(Nodo *&, int, Nodo *);
void mostrarArbol(Nodo *, int);
bool busqueda(Nodo *, int);
void preorden(Nodo *);
void inorden(Nodo *);
void postorden(Nodo *);
void eliminar(Nodo *, int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *, Nodo *);
void destruirNodo(Nodo *);

int main(){
	
	menu();
	
	getch();
	return 0;
}

//menu de las opciones
void menu(){
	int op=0, dato, contador=0;
	
	do{
		cout << "__MENU__\n";
		cout << "1. insertar un elemento al arbol." << endl;
		cout << "2. mostrar el arbol." << endl;
		cout << "3. buscar un elemento en el arbol." << endl;
		cout << "4. Recorrido en Preorden." << endl;
		cout << "5. Recorrido en Inorden." << endl;
		cout << "6. Recorrido en Postorden." << endl;
		cout << "7. eliminar un nodo del arbol." << endl;
		cout << "8. salir.\n";
		cout << "Elija una opcion: ";
		cin >> op;
	
		switch(op){
			case 1:
				cout << "Ingrese un numero: ";
				cin >> dato;
				insertarArbol(arbol, dato, NULL);
				cout << "\n";
				system("pause");
				break;
			case 2:
				cout << "\nMostrando el arbol completo\n\n";
				mostrarArbol(arbol, contador);
				cout << "\n";
				system("pause");
				break;
			case 3:
				cout << "Digite el elemento a buscar: ";
				cin >> dato;
				if(busqueda(arbol, dato)){
					cout << "\nEl elemento " << dato << " fue encontrado en el arbol.\n" << endl;
				}else{
					cout << "\nEl elemento no fue encontrado en el arbol." << endl;
				}
				cout << "\n";
				system("pause");
				break;
			case 4:
				cout << "\nRecorrido en Preorden: ";
				preorden(arbol);
				cout << "\n\n";
				system("pause");
				break;
			case 5:
				cout << "\nRecorrido en Inorden: ";
				inorden(arbol);
				cout << "\n\n";
				system("pause");
				break;
			case 6:
				cout << "\nRecorrido en Postorden: ";
				postorden(arbol);
				cout << "\n\n";
				system("pause");
				break;
			case 7:
				cout << "\nDigite el numero a eliminar: ";
				cin >> dato;
				eliminar(arbol, dato);
				cout << "\n\n";
				system("pause");
				break;
		}
		system("cls");
	}while(op != 8);
}

//funcion crear nuevo nodo
Nodo *crearNodo(int n, Nodo *padre){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->sub_der = NULL;
	nuevo_nodo->sub_izq = NULL;
	nuevo_nodo->padre = padre;
	
	return nuevo_nodo;
}

//funcion insertar un nodo en el arbol
void insertarArbol(Nodo *&arbol, int n, Nodo *padre){
	//si el arbol esta vacio crear un nuevo nodo e insertar el dato
	if(arbol == NULL){
		Nodo *nuevo_nodo = crearNodo(n, padre);
		arbol = nuevo_nodo;
	}
	//sino entonces aplicar el concepto de ABB
	else{
		//insertar el dato en base a la insersion de datos en ABB
		int valorRaiz = arbol->dato;
		if(n < valorRaiz){
			insertarArbol(arbol->sub_izq, n, arbol);
		}
		else{
			insertarArbol(arbol->sub_der, n, arbol);
		}
	}
}

//mostrar datos de los arboles
void mostrarArbol(Nodo *arbol, int contador){
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->sub_der, contador+1);
		for(int i=0; i<contador; i++){
			cout << "   ";
		}
		cout << arbol->dato << endl;
		mostrarArbol(arbol->sub_izq, contador+1);
	}
}

//buscar dato en el arbol
bool busqueda(Nodo *arbol, int n){
	if(arbol == NULL){
		return false;
	}
	else if(arbol->dato == n){
		return true;
	}
	else if(n < arbol->dato){
		return busqueda(arbol->sub_izq, n);
	}
	else{
		return busqueda(arbol->sub_der, n);
	}
}

/*
	metodos de recorrido del arbol
*/

//recorrido en preorden
void preorden(Nodo *arbol){
	if(arbol == NULL){
		return;
	} else{
		cout << arbol->dato << " - ";
		preorden(arbol->sub_izq);
		preorden(arbol->sub_der);
	}
}

//recorrido en inorden
void inorden(Nodo *arbol){
	if(arbol ==NULL){
		return;
	}
	else{
		inorden(arbol->sub_izq);
		cout << arbol->dato << " - ";
		inorden(arbol->sub_der);
	}
}

//recorrido en postorden
void postorden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		postorden(arbol->sub_izq);
		postorden(arbol->sub_der);
		cout << arbol->dato << " - ";
	}
}

/*
	metodos de eliminacion de un dato en el arbol
*/

//eliminar un nodo del arbol
void eliminar(Nodo *arbol, int n){
	if(arbol == NULL){
		return;
	}
	else if(n < arbol->dato){
		eliminar(arbol->sub_izq, n);
	}
	else if(n > arbol->dato){
		eliminar(arbol->sub_der, n);
	}
	else{ //si ya el elemento fue encontrado
		eliminarNodo(arbol);
	}
}

//lado mas izquierdo del subarbol derecho
Nodo *minimo(Nodo *arbol){
	if(arbol == NULL){
		return NULL;
	}
	if(arbol->sub_izq){
		return minimo(arbol->sub_izq);
	}
	else{
		return arbol;
	}
}

//reemplazar el nodo a eliminar
void reemplazar(Nodo *arbol, Nodo *reemplazo){
	if(arbol->padre){
		if(arbol->dato == arbol->padre->sub_izq->dato){
			arbol->padre->sub_izq = reemplazo;
		}
		else if(arbol->dato == arbol->padre->sub_der->dato){
			arbol->padre->sub_der = reemplazo;
		}
	}
	if(reemplazo){
		reemplazo->padre = arbol->padre;
	}
}

void destruirNodo(Nodo *nodo){
	nodo->sub_izq = NULL;
	nodo->sub_der = NULL;
	delete nodo;
}

//eliminar el nodo encontrado
void eliminarNodo(Nodo *nodoEliminar){//si tiene dos hijos
	if(nodoEliminar->sub_izq && nodoEliminar->sub_der){
		Nodo *menor = minimo(nodoEliminar->sub_der);
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);
	}
	else if(nodoEliminar->sub_izq){//si tiene un hijo izquierdo
		reemplazar(nodoEliminar, nodoEliminar->sub_izq);
		destruirNodo(nodoEliminar);
	}
	else if(nodoEliminar->sub_der){//si no tiene hijos y es un nodo hoja
		reemplazar(nodoEliminar, nodoEliminar->sub_der);
		destruirNodo(nodoEliminar);
	}
	else{
		reemplazar(nodoEliminar, NULL);
		destruirNodo(nodoEliminar);
	}
}
