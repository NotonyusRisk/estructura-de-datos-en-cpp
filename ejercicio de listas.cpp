#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void llenarLista(Nodo *&, int);
void mostrarLista(Nodo *&);
void calcularMayorMenor(Nodo *);

int main(){
	
	Nodo *lista = NULL;
	int dato;
	char respuesta;
	
	do{
		cout << "Ingrese un numero: ";
		cin >> dato;
		llenarLista(lista, dato);
		
		cout << "\nDesea agregar otro Nodo (s/n): ";
		cin >> respuesta;
	}while(respuesta == 's' || respuesta == 'S');
	
	cout << "\nLos elementos de la lista son:\n";
	mostrarLista(lista);
	
	calcularMayorMenor(lista);
	
	getch();
	return 0;
}

//agregar elementos al final de la lista
void llenarLista(Nodo *&lista, int n){
	Nodo *nuevo_nodo = new Nodo();
	Nodo *aux;
	
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if(lista == NULL){
		lista = nuevo_nodo;
	}
	else{
		aux = lista;
		while(aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo_nodo;
	}
	
	cout << "\nElemento " << n << " insertado a lista";
}

//mostrar elementos de la lista
void mostrarLista(Nodo *&lista){
	while(lista != NULL){
		cout << lista->dato << " -> ";
		lista = lista->siguiente;
	}
}

//calcular el mayor y menor elemento de la lista
void calcularMayorMenor(Nodo *lista){
	int mayor = 0, menor = 999999;
	
	while(lista != NULL){
		if((lista->dato) > mayor){
			mayor = lista->dato;
		}
		if((lista->dato) < menor){
			menor = lista->dato;
		}
		lista = lista->siguiente;
	}
	
	cout << "\nEl mayor elemento es " << mayor << endl;
	cout << "EL menor elemento es " << menor << endl;
}
