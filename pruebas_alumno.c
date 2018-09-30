#include "lista.h"
#include "testing.h"
#include "pila.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


void pila_destruir_wrapper(void* elemento) {
	pila_destruir((pila_t*)elemento);
}

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void prueba_lista_vacia() {
	printf("\t\tINICIO DE PRUEBA LISTA VACIA\n");
	/* Declaro las variables a usar*/
	lista_t* lista= lista_crear();
	
	/* Inicio de pruebas*/
	print_test("La lista se creo correctamente", lista != NULL);
	print_test("La lista está vacia", lista_esta_vacia(lista));
	print_test("El primero de la lista es NULL", lista_ver_primero(lista) == NULL);
	print_test("El último de la lista es NULL", lista_ver_ultimo(lista) == NULL);
	print_test("Largo de la lista es 0", lista_largo(lista) == 0);

	/* Destruyo la lista*/
	lista_destruir(lista, NULL);
	print_test("La lista se destruyo correctamente", true);
	printf("\n");
}

void prueba_lista_insertar_NULL() {
	printf("\t\tINICIO DE PRUEBAS INSERTAR NULL\n");
	/*Declaro variables a usar*/
	lista_t* lista= lista_crear();
	
	/*Inicio pruebas*/
	print_test("La lista se creo correctamente", lista != NULL);
	print_test("La lista esta vacia", lista_esta_vacia(lista));
	print_test("Inserto NULL", lista_insertar_primero(lista, NULL));
	print_test("El primero es NULL", lista_ver_primero(lista) == NULL);
	print_test("El ultimo es NULL", lista_ver_ultimo(lista) == NULL);
	print_test("El largo de la lista es 1", lista_largo(lista) == 1);
	print_test("Se borro correctamente", lista_borrar_primero(lista) == NULL);
	
	/* Destruyo la lista*/
	lista_destruir(lista, NULL);
	print_test("La lista se destruyo correctamente", true);
	printf("\n");
}

void prueba_lista_insertar_primero() {
	printf("\t\tINICIO DE PRUEBAS LISTA INSERTAR PRIMERO\n");
	/* Declaro variables a usar*/
	lista_t* lista= lista_crear();
	int numeros[]= {1,2,3,4,5,6,7,8,9,10};
	
	/* Inicio de pruebas*/
	print_test("La lista se creo correctamente", lista != NULL);
	print_test("La lista esta vacia", lista_esta_vacia(lista));
	print_test("Inserto primero 4", lista_insertar_primero(lista, &numeros[3]));
	print_test("El primero es 4", lista_ver_primero(lista) == &numeros[3]);
	print_test("Inserto primero 9", lista_insertar_primero(lista, &numeros[8]));
	print_test("El primero es 9", lista_ver_primero(lista) == &numeros[8]);
	print_test("El ultimo es 4", lista_ver_ultimo(lista) == &numeros[3]);
	print_test("Se borro primero 9", lista_borrar_primero(lista) == &numeros[8]);
	print_test("Inserto primero 2", lista_insertar_primero(lista, &numeros[1]));
	print_test("Inserto primero 7", lista_insertar_primero(lista, &numeros[6]));
	print_test("El largo de la lista es 3", lista_largo(lista) == 3);
	print_test("Se borro primero 7", lista_borrar_primero(lista) == &numeros[6]);
	print_test("Se borro primero 2", lista_borrar_primero(lista) == &numeros[1]);
	print_test("Se borro primero 4", lista_borrar_primero(lista) == &numeros[3]);
	print_test("El largo de la lista es 0", lista_largo(lista) == 0);
	print_test("La lista esta vacia", lista_esta_vacia(lista)); 
	
	/* Destruyo la lista*/
	lista_destruir(lista, NULL);
	print_test("La lista se destruyo correctamente", true);
	printf("\n");
}

void prueba_lista_insertar_ultimo() {
	printf("\t\tINICIO DE PRUEBAS LISTA INSERTAR ULTIMO\n");
	/* Declaro variables a usar*/
	lista_t* lista= lista_crear();
	int numeros[]={1,2,3,4,5,6,7,8,9,10};
	
	/* Inicio de pruebas*/
	print_test("La lista se creo correctamente", lista != NULL);
	print_test("La lista esta vacia", lista_esta_vacia(lista));
	print_test("Inserto ultimo 10", lista_insertar_ultimo(lista, &numeros[9]));
	print_test("El primero es 10", lista_ver_primero(lista) == &numeros[9]);
	print_test("Inserto ultimo 3", lista_insertar_ultimo(lista, &numeros[2]));
	print_test("EL ultimo es 3", lista_ver_ultimo(lista) == &numeros[2]);
	print_test("El largo de la lista es 2", lista_largo(lista) == 2);
	print_test("Se borro primero 10", lista_borrar_primero(lista) == &numeros[9]);
	print_test("Inserto ultimo 1", lista_insertar_ultimo(lista, &numeros[0]));
	print_test("EL ultimo es 1", lista_ver_ultimo(lista) == &numeros[0]);
	print_test("Se borro primero 3", lista_borrar_primero(lista) == &numeros[2]);
	print_test("Se borro primero 1", lista_borrar_primero(lista) == &numeros[0]);
	print_test("La lista esta vacia", lista_esta_vacia(lista));
	
	/* Destruyo la lista*/
	lista_destruir(lista, NULL);
	print_test("La lista se destruyo correctamente", true);
	printf("\n");
}

void prueba_lista_insertando_varios_elementos() {
	printf("\t\tINICIO DE PRUEBAS LISTA INSERTANDO VARIOS ELEMENTOS\n");
	/* Declaro variables a usar*/
	lista_t* lista= lista_crear();
	int numeros[]= {1,2,3,4,5,6,7,8,9,10};
	bool ok= true;
	
	/*Inicio de pruebas*/
	print_test("La lista se creo correctamente", lista != NULL);
	print_test("La lista esta vacia", lista_esta_vacia(lista));
	
	for(int i= 0; i < 10; i++) {
		ok &= lista_insertar_ultimo(lista, &numeros[i]);
	}
	
	print_test("Se insertaron los 10 elementos correctamente", ok);
	print_test("La lista no esta vacia", !lista_esta_vacia(lista));
	print_test("El largo de la lista es 10", lista_largo(lista) == 10);
	print_test("Ver primero", lista_ver_primero(lista) == &numeros[0]);
	print_test("Ver ultimo", lista_ver_ultimo(lista) == &numeros[9]);
	
	ok= true;
	for(int i= 0; i < 10; i++) {
		ok &= (lista_borrar_primero(lista) == &numeros[i]);
	}
	
	print_test("Se borraron correctamente", ok);
	print_test("La lista esta vacia", lista_esta_vacia(lista));
	print_test("El largo de la lista es 0", lista_largo(lista) == 0);
	
	
	/* Destruyo la lista*/
	lista_destruir(lista, NULL);
	print_test("La lista se destruyo correctamente", true);
	printf("\n");
}

void prueba_lista_insertando_varios_elementos_2() {
	printf("\t\tINICIO DE PRUEBAS LISTA INSERTANDO VARIOS ELEMENTOS 2\n");
	/* Declaro variables a usar*/
	lista_t* lista= lista_crear();
	char abecedario[]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	bool ok= true;
	
	/*Inicio de pruebas*/
	print_test("La lista se creo correctamente", lista != NULL);
	print_test("La lista esta vacia", lista_esta_vacia(lista));
	
	for(int i= 0; i < 26; i++) {
		ok &= lista_insertar_primero(lista, &abecedario[i]);
	}
	
	print_test("Se insertaron los elementos correctamente", ok);
	print_test("La lista no esta vacia", !lista_esta_vacia(lista));
	print_test("El largo de la lista es 26", lista_largo(lista) == 26);
	print_test("Ver primero", lista_ver_primero(lista) == &abecedario[25]);
	print_test("Ver ultimo", lista_ver_ultimo(lista) == &abecedario[0]);
	
	ok= true;
	for(int i= 25; i >= 0; i--) {
		ok &= (lista_borrar_primero(lista) == &abecedario[i]);
	}
	
	print_test("Se borraron correctamente", ok);
	print_test("La lista esta vacia", lista_esta_vacia(lista));
	print_test("El largo de la lista es 0", lista_largo(lista) == 0);
	
	/* Destruyo la lista*/
	lista_destruir(lista, NULL);
	print_test("La lista se destruyo correctamente", true);
	printf("\n");
}

void prueba_lista_insertando_punteros() {
	printf("\t\tINICIO DE PRUEBAS LISTA INSERTANDO PUNTEROS\n");
	/* Declaro variables a usar*/
	lista_t* lista= lista_crear();
	int* numeros= malloc(sizeof(int));
	char* letra= malloc(sizeof(char));
	double* temperatura= malloc(sizeof(double));
	double* numero_euler= malloc(sizeof(double));
	
	*numeros= 130;
	*letra= 'a';
	*temperatura= 15.8;
	*numero_euler= 2.718281;
	
	/* Inicio de pruebas*/
	print_test("La lista se creo correctamente", lista != NULL);
	print_test("La lista esta vacia", lista_esta_vacia(lista));
	print_test("Se inserto puntero 1 correctamente", lista_insertar_primero(lista, numeros));
	print_test("Se inserto puntero 2 correctamente", lista_insertar_primero(lista, letra));
	print_test("Se inserto puntero 3 correctamente", lista_insertar_primero(lista, temperatura));
	print_test("Se inserto puntero 4 correctamente", lista_insertar_primero(lista, numero_euler));
	print_test("El largo de la lista es 4", lista_largo(lista) == 4);
	print_test("La lista no esta vacia", !lista_esta_vacia(lista));
	print_test("Ver primero", lista_ver_primero(lista) == numero_euler);
	print_test("Ver ultimo", lista_ver_ultimo(lista) == numeros);
	
	/* Destruyo la lista*/
	lista_destruir(lista, free);
	print_test("La lista se detruyo correctamente", true);
	printf("\n");
}

void prueba_lista_volumen(int largo) {
	printf("\t\tINICIO DE PRUEBAS LISTA VOLUMEN\n");
	/* Declaro variables a usar*/
	lista_t* lista= lista_crear();
	int* vector= malloc(sizeof(int)*largo);
	bool ok= true;
	
	/* Inicio pruebas*/
	print_test("La lista se creo correctamente", lista != NULL);
	print_test("La lista esta vacia", lista_esta_vacia(lista));
	
	for(int i= 0; i < largo; i++) {
		vector[i]= i;
		ok &= lista_insertar_ultimo(lista, &vector[i]);
	}
	
	print_test("Se insertaron correctamente", ok);
	print_test("La lista no esta vacia", !lista_esta_vacia(lista));
	print_test("El largo de la lista es 10000", lista_largo(lista) == largo);
	print_test("Ver primero", lista_ver_primero(lista) == &vector[0]);
	print_test("Ver ultimo", lista_ver_ultimo(lista) == &vector[9999]);
	
	ok= true;
	for(int i= 0; i < largo; i++) {
		ok &= (lista_borrar_primero(lista) == &vector[i]);
	}
	
	print_test("Se borraron correctamente", ok);
	print_test("La lista esta vacia", lista_esta_vacia(lista));
	print_test("El largo de la lista es 0", lista_largo(lista) == 0);
	
	/* Destruyo la lista*/
	free(vector);
	lista_destruir(lista, NULL);
	print_test("La lista se destruyo correctamente", true);
	printf("\n");
}

void prueba_lista_estructura_con_funcion_detruir() {
	printf("\t\tINICIO DE PRUEBAS LISTA ESTRUCTURA CON FUNCION DESTRUIR\n");
	/* Declaro variable a usar*/
	lista_t* lista= lista_crear();
	pila_t* pila= pila_crear();
	
	/* Inicio de pruebas*/
	print_test("La lista se creo correctamente", lista != NULL);
	print_test("La lista esta vacia", lista_esta_vacia(lista));
	print_test("Se inserto la estructura correctamente", lista_insertar_ultimo(lista, pila));
	print_test("La lista no esta vacia", !lista_esta_vacia(lista));
	print_test("El largo de la lista es 1", lista_largo(lista) == 1);
	print_test("Ver primero", lista_ver_primero(lista) == pila);
	print_test("Ver ultimo", lista_ver_ultimo(lista) == pila);
	
	/* Destruyo la lista*/
	lista_destruir(lista, pila_destruir_wrapper);
	print_test("La lista se destruyo correctamente", true);
	printf("\n");
}

void pruebas_lista_alumno(void) {
	prueba_lista_vacia();
	prueba_lista_insertar_NULL();
	prueba_lista_insertar_primero();
	prueba_lista_insertar_ultimo();
	prueba_lista_insertando_varios_elementos();
	prueba_lista_insertando_varios_elementos_2();
	prueba_lista_insertando_punteros();
	prueba_lista_volumen(10000);
	prueba_lista_estructura_con_funcion_detruir();
}
