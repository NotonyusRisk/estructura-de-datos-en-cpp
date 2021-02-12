#include <iostream>
#include <conio.h>

using namespace std;

int tam;
int pila[100];
int tope=0;
int dato=0;

int pop(){
	return pila[tope];
	tope--;
}

void push(int dato){
	pila[tope] = dato;
	tope++;
}

bool llena(){
	if(tope == tam){
		return true;
	}
	else{
		return false;
	}
}

bool vacia(){
	if(tope == 0){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	
	int opcion=0;
	cout << "Ingrese el tamaño de la pila: ";
	cin >> tam;
	
	pila[tam];
	
	do{
		
		cout << "Ingrese la tarea que quiera realizar: \n";
		cout << "1- insertar datos en la pila.\n";
		cout << "2- eliminar un elemento de la pila.\n";
		cout << "3- mostrar la pila.\n";
		cout << "4- salir.";
		cout << "\nelija: ";
		cin >> opcion;
		
		cout << endl;
		switch(opcion){
			case 1:
				cout << "Valor a insertar: ";
				cin >> dato;
				
				if(!llena){
					push(dato);
				}
				else{
					cout << "La pila ya esta llena.";
				}
				break;
			case 2:
				if(!vacia){
					cout << "El elemento de la cima de la pila era: " << pop() << endl;
				}
				else{
					cout << "La pila esta vacia." << endl;
				}
				break;
			case 3:
				for(int i=0; i <= tope; i++){
					cout << pila[i] << endl;
				}
				break;
			default:
				cout << "Elija una opcion valida por favor." << endl;
				break;
		}
	}while(!llena);
	
	getch();
	return 0;
}
