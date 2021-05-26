#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void menu();
void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
void buscarElemento(Nodo *, int);
void eliminarNodo(Nodo *&, int);
void eliminarLista(Nodo *&, int &);

Nodo *lista = NULL;

int main(){
	
	menu();
	
	getch();
	return 0;
}

//funcion menu
void menu(){
	int op, dato;
	do{
		cout << "\t:MENU:.\n";
		cout << "1. insertar elementos a la lista.\n";
		cout << "2. mostrar los elementos de la lista.\n";
		cout << "3. Buscar un elemento de la lista.\n";
		cout << "4. Eliminar un elemento de la lista.\n";
		cout << "5. Eliminar la lista completa.\n";
		cout << "6. Salir.\n";
		cout << "Opcion: ";
		cin >> op;
		
		switch(op){
			case 1:
				cout << "Ingrese un numero: ";
				cin >> dato;
				insertarLista(lista, dato);
				cout << "\n";
				system("pause");
				break;
			case 2:
				mostrarLista(lista);
				cout << "\n";
				system("pause");
				break;
			case 3:
				cout << "Que elemento desea buscar?: ";
				cin >> dato;
				buscarElemento(lista, dato);
				cout << "\n";
				system("pause");
				break;
			case 4:
				cout << "Ingrese el elemento que desea eliminar: ";
				cin >> dato;
				eliminarNodo(lista, dato);
				cout << "\n";
				system("pause");
				break;
			case 5:
				while(lista != NULL){//mientras no sea el final de la lista
					eliminarLista(lista, dato);
					cout << dato << " -> ";
				}
				cout << "\n";
				system("pause");
				break;
		}
		system("cls");
	}while(op != 6);
}

//funcion para insertar elementos en la lista
void insertarLista(Nodo *&lista, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	//insertar de forma ordenada los elementos a la lista
	while(aux1 != NULL && aux1->dato < n){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	
	//insertar al principio, al medio o al final
	if(lista == aux1){
		lista = nuevo_nodo;
	}
	else{
		aux2->siguiente = nuevo_nodo;
	}
	
	nuevo_nodo->siguiente = aux1;
	
	cout << "\tElemento " << n << " insertado a lista correctamente\n";
}

//funcion para mostrar lista
void mostrarLista(Nodo *lista){
	Nodo *actual = new Nodo();
	actual = lista;
	
	//bucle para recorrer la lista
	while(actual != NULL){
		cout << actual->dato << " -> ";
		actual = actual->siguiente;
	}
}

//funcion para buscar un elemento en la lista
void buscarElemento(Nodo *lista, int n){
	Nodo *actual = new Nodo();
	actual = lista;
	bool band = false;
	
	while(actual != NULL && actual->dato <= n){
		if(actual->dato == n){
			band = true;
		}
		actual = actual->siguiente;
	}
	
	if(band == true){
		cout << "El elemento " << n << " si esta en la lista." << endl;
	}
	else{
		cout << "El elemento " << n << " no existe en la lista." << endl; 
	}
}

//funcion para eliminar un solo elemento de la lista
void eliminarNodo(Nodo *&lista, int n){
	
	if(lista != NULL){
		Nodo *aux_borrar;
		Nodo *anterior = NULL;
		aux_borrar = lista;
		
		while(aux_borrar != NULL && aux_borrar->dato != n){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		
		//si el elemento no es encontrado
		if(aux_borrar == NULL){
			cout << "Elemento no encontrado.";
		}else if(anterior == NULL){
			lista = lista->siguiente;
			delete aux_borrar;
			cout << "El elemento ha sido eliminado." << endl;
		}
		else{
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
			cout << "El elemento ha sido eliminado." << endl;
		}
	}
	else{
		cout << "La lista esta vacia." << endl;
	}
}

void eliminarLista(Nodo *&lista, int &n){
	Nodo *aux = lista;
	n = aux->dato;
	lista = aux->siguiente;
	delete aux;
}
