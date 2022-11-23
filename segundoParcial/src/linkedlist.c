/*
 * linkedlist.c
 *
 *  Created on: 20 nov 2022
 *      Author: kervi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

/// @brief Crea una nueva linkedList en la memoria dinamica
///
/// @return En el caso de no conseguir espacio en la memoria dinamica retorna NULL
/// de lo contrario retorna la nueva linkedlist
LinkedList* ll_newLinkedList(void) {
	LinkedList *this;

	this = (LinkedList*) malloc(sizeof(LinkedList));
	if (this != NULL) {
		this->size = 0;
		this->pFirstNode = NULL;
	}

	return this;
}

/// @brief Retorna la cantidad de elementos de la lista
///
/// @param this puntero a la lista
/// @return (-1) si da error y si no da la cantiida de elementos de la lista
int ll_len(LinkedList *this) {
	int returnAux = -1;
	if (this != NULL) {
		returnAux = this->size;
	}

	return returnAux;
}

/// @brief obtine los nodos de la lista
///
/// @param this linkedlist Puntero a la lista
/// @param nodeIndex int Indice del nodo a obtener
/// @return ode* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
///(pElement) Si funciono correctamente
///
static Node* getNode(LinkedList *this, int nodeIndex) {
	Node *pNode = NULL;

	if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)) {
		pNode = this->pFirstNode; // primer vagon
		for (int i = 0; i < nodeIndex; i++) {
			pNode = pNode->pNextNode; // estructura anidada, hacia donde apunta

		}

	}

	return pNode;
}

/// @brief  agrega y enlaza un nuevo nodo a la lista
///
/// @param this Linkedlist Es un puntero a la Lista
/// @param nodeIndex Ubicacion donde se agrega el nuevo nodo
/// @param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
/// @return (-1) si hubo error
/// 		(0) si pudo agregar un nuevo nodo a la lista
static int addNode(LinkedList *this, int nodeIndex, void *pElement) {
	int retorno = -1;
	Node *prev = NULL;
	Node *nuevoNodo = NULL;

	// el nodeIndex tenia que ser <=len porque sin el "=" no entra en el caso del ultimo elemento
	// el espacio se crea una vez ingresado al if
	if (this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) {
		// Creo espacio en memoria para nuevo nodo
		nuevoNodo = (Node*) malloc(sizeof(Node));

		//el elmento que se desea agregar se agrega en el campo pElement
		nuevoNodo->pElement = pElement;

		// si el indice es = 0
		if (nodeIndex == 0) {
			// cargamos en el campo nextNode la ubicacion del campo de la lista pFristNode
			nuevoNodo->pNextNode = this->pFirstNode;
			// despues cargamos en pfirstNode la ubicacion del nuevo nodo
			this->pFirstNode = nuevoNodo;
			// sumamos un nuevo elemento a la lista
			this->size++;
			// retorno verdadero
			retorno = 0;

		} else {
			// si el indice es distinto de cero
			// obtenemos el nodo anterior del indice
			prev = getNode(this, nodeIndex - 1);
			if (prev != NULL) {
				// si es distinto de null
				//nuevo nodo que fue creado en memoria dinamica en el campo pnextnode
				// carga la ubicacicion del node prev en el campo pnextNODE
				nuevoNodo->pNextNode = prev->pNextNode;
				//prev en el campo prnextNode a punto a la ubicacion del nodo creado en momoria
				// dinamica
				prev->pNextNode = nuevoNodo;
				// se aumenta el size
				this->size++;
				retorno = 0;
			}

		}
	}
	return retorno;
}

/// @brief AGREGA UN elemento a la lista
///
/// @param this Puntero a la lista
/// @param pElement puntero al elemento a ser agregado
/// @return (-1) en caso de error
/// 		(0) en caso de ser verdadero
int ll_add(LinkedList *this, void *pElement) {
	int returnAux = -1;

	if (this != NULL && pElement != NULL) {
		// si se hizo bien, devuelve el 0 para el retorno
		if (addNode(this, ll_len(this), pElement) == 0) {
			returnAux = 0;
		}
	}

	return returnAux;
}

/// @brief Permite obtene la ubicaccion del elemento a obtener
///
/// @param this puntero a la lista
/// @param index indice al que se accede
/// @return retorna la uicacion del elemento si es cierto y null si es falso
void* ll_get(LinkedList *this, int index) {
	void *returnAux = NULL;
	Node *pNode;

	if (this != NULL && index < ll_len(this)) {

		pNode = getNode(this, index);

		if (pNode != NULL) {
			returnAux = pNode->pElement;
		}

	}

	return returnAux;
}

/// @brief modifica un elemento de la lista
///
/// @param this puntero a la lista
/// @param index int Ubicacion del elemento a modificar
/// @param pElement  Puntero al nuevo elemento
/// @return (-1) ERROR si no pudo modificar el elemento de la lista
/// 		(0) verdadero si pudo modificar el elemento de la lista
int ll_set(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;
	Node *actual = NULL;
	int len;

	len = ll_len(this);

	if (this != NULL && index >= 0 && index < len) {
		// traigo nodo
		actual = getNode(this, index);
		// guardo modoficacion
		if (actual != NULL) {
			actual->pElement = pElement;
			returnAux = 0;

		}

	}

	return returnAux;
}

/// @brief elimina un elemento de la lista
///
/// @param this linkedList Puntero a la lista
/// @param index int ubicacion del elemento a elminnar
/// @return (-1) si hubo algun tipo de fallo
/// 		(0) retorna 1 si es verdadero
int ll_remove(LinkedList *this, int index) {
	int returnAux = -1;
	Node *actual;
	Node *prev;
	int len;

	len = ll_len(this);

	if (this != NULL && index >= 0 && index < len) {
		actual = getNode(this, index); // actual con getNode
		if (actual != NULL) {
			if (index == 0) {
				this->pFirstNode = actual->pNextNode; // establezco el siguiente nodo como primero para no romper cadena
				this->size--;

			} else {
				// traigo previo node
				prev = getNode(this, index - 1);
				if (prev != NULL) {
					// paso el proximo nodo del actual al previo para no romper cadena
					prev->pNextNode = actual->pNextNode;
					this->size--;
				}

			}
		}
		// libero la memeoria
		free(actual);
		returnAux = 0;
	}

	return returnAux;
}

/// @brief Elimina todos los elementos de la lista
///
/// @param this linkedlist puntero a la lista
/// @return (-1)  Error: si el puntero a la lista es NULL
/// 		(0)   Si funciona correctamente
int ll_clear(LinkedList *this) {
	int returnAux = -1;
	int i;
	int len;

	if (this != NULL) {
		len = ll_len(this);
		for (i = 0; i < len; i++) {
			ll_remove(this, 0);
		}
		returnAux = 0;
	}

	return returnAux;
}

/// @brief Elimina todos los elementos de la lista y la lista
///
/// @param this LinkeList Puntero a la lista
/// @return(-1)  Error: si el puntero a la lista es NULL
/// 		(0)   Si funciona correctamente
int ll_deleteLinkedList(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {
		// elimino elementos
		// si ES VERDADERO SE ELIMINA LA LISTA
		if (ll_clear(this) == 0) {
			free(this);
			returnAux = 0;
		}
	}

	return returnAux;
}

/// @brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
///
/// @param this LinkedList Puntero a la lista
/// @param pElement Puntero al elemento
/// @return (-1) en caso de error
/// 		(indice) en caso de obtener la ocurrencia

int ll_indexOf(LinkedList *this, void *pElement) {
	int returnAux = -1;

	Node *nodo;
	int len;
	if (this != NULL && pElement != NULL) {
		if (this != NULL) {
			len = ll_len(this);
			if (len > 0) {
				for (int i = 0; i < len; i++) {
					nodo = getNode(this, i);
					if (nodo != NULL) {
						// si pElement coincide con puntero, guardo index
						if (pElement == nodo->pElement) {
							returnAux = i;
							break;
						}
					}
				}
			}
		}
	}
	return returnAux;
}

/// @brief  Indica si la lista esta o no vacia
///
/// @param this Linkedlist puntero a linkedlist
/// @return (-1) en caso de error
/// 		(0) retorna uno si hay algun elemento
/// 		(1) retorna 0 si esta vacia
int ll_isEmpty(LinkedList *this) {
	int returnAux = -1; //NULL
	if (this != NULL) {
		if (ll_len(this) > 0) {
			returnAux = 0; // SI HAY ELEMENTO
		} else {
			returnAux = 1; // VACIA
		}
	}
	return returnAux;
}

/// @brief Inserta un nuevo elemento en la lista en la posicion indicada
///
/// @param this Puntero a la lista
/// @param index ubicacion donde se va agregar el elemento
/// @param pElement Puntero al nuevo elemento
/// @return (-1) error si el punteero a la lista es null
/// 		(0) si funciona correctamente
int ll_push(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;
	int len;

	len = ll_len(this);
	if (this != NULL && index >= 0 && index <= len) {
		if (addNode(this, index, pElement) == 0) {
			returnAux = 0;
		}
	}

	return returnAux;
}

/// @brief  Elimina el elemento de la posicion indicada y retorna su puntero
///
/// @param this Punttero a la lista
/// @param index int Ubicacion del elemento eliminar
/// @return retorna (null) en caso de error
/// 				(puntero) y retorna el elemento a eliminar
void* ll_pop(LinkedList *this, int index) {
	void *returnAux = NULL;
	Node *nodo;

	int retornoRemove = -1;

	if (this != NULL && index >= 0 && index < ll_len(this)) {
		// traigo nodo

		nodo = getNode(this, index);
		if (nodo != NULL) {
			// guardo pElement en return aux
			returnAux = nodo->pElement;
			// elimino
			retornoRemove = ll_remove(this, index);
			// si no elimino, cambio return aux a null
			if (retornoRemove != 0) {
				returnAux = NULL;
			}

		}

	}

	return returnAux;
}

/// @brief Determina si la lista contiene o no el elemento pasado como parametro
///
/// @param this Puntero a la lista
/// @param pElement Puntero al elemmento
/// @return (-1) en caso d fallar
/// 		(0) si no contiene elementos
/// 		(1) si contiene elementos
int ll_contains(LinkedList *this, void *pElement) {
	int returnAux = -1;
	if (this != NULL && pElement != NULL) {

		if (ll_indexOf(this, pElement) != -1) {

			returnAux = 1;
		} else {
			returnAux = 0;

		}
	}
	return returnAux;
}

/// @briefDetermina si todos los elementos de la lista (this2)
///estan contenidos en la lista (this)
/// @param this Puntero a la lista
/// @param this2 Puntero a la lista dos
/// @return (-1) en caso de error
/// 		(0) en caso de no contener un elemento
/// 		(1) en caso de contenerlos todos
int ll_containsAll(LinkedList *this, LinkedList *this2) {
	int returnAux = -1;
	int i;
	int len;

	if (this != NULL && this2 != NULL) {
		len = ll_len(this2);
		if (len == 0) {
			returnAux = 0;
		} else {
			returnAux = 1;
			for (i = 0; i < len; i++) {
				// traigo nodo y si contains devuelve 0 rompo iteracion

				if (ll_contains(this, ll_get(this2, i)) == 0) {
					returnAux = 0; // hay un elemento que no contiene
					break;
				} else {
					returnAux = 1; //elemento que contiene
				}

			}
		}
	}

	return returnAux;
}

/// @brief Crea y retorna una nueva lista con los elementos indicados
///
/// @param this Puntero a la lista
/// @param from  int Indice desde el cual se copian los elementos en la nueva lista
/// @param to  int hasta cual se debe copiar
/// @return retorna (null) en caso de error
/// 		retorna (lista) en caso de se haya creado la lista
LinkedList* ll_subList(LinkedList *this, int from, int to) {
	LinkedList *cloneArray = NULL;
	int i;
	void *pElement;
	int len;

	len = ll_len(this);

	if (this != NULL && from >= 0 && from < len && to > from && to <= len) {
		// creo lista
		cloneArray = ll_newLinkedList();
		if (cloneArray != NULL) {
			for (i = from; i < to; i++) {
				// traigo contenido
				pElement = ll_get(this, i);
				if (pElement != NULL) {
					// agrego nodos a la sublista
					ll_add(cloneArray, pElement);
				}
			}
		}
	}

	return cloneArray;
}

/// @brief Crea y retorna una nueva lista con los elementos de la lista
///
/// @param this Puntero a la lista
/// @return Retorna  (NULL) Error: si el puntero a la listas es NULL
/// 		Retorna  (lista) retorna nueva lista
LinkedList* ll_clone(LinkedList *this) {
	LinkedList *cloneArray = NULL;

	if (this != NULL) {
		cloneArray = ll_subList(this, 0, ll_len(this));
	}

	return cloneArray;
}

/// @brief  Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
///
/// @param this  Puntero a la lista
/// @param pFunc Puntero a la funcion criterio
/// @param order int (1) ascendente
/// 			int (0) descendente
/// @return Retorna (-1) en caso de error
/// 		Retorna (0) en caso de cumplir el trabajo
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order) {
	int returnAux = -1;
	void *pAux;
	void *pAuxDos;
	int i;
	int estaOrdenado;
	int retornoFuncionOrdenamiento;
	int len;

	if (this != NULL && pFunc != NULL && (order == 0 || order == 1)) {
		len = ll_len(this);

		do {
			estaOrdenado = 1;
			len--;
			for (i = 0; i < len; i++) {
				pAux = ll_get(this, i);
				pAuxDos = ll_get(this, i + 1);
				estaOrdenado = 0;
				retornoFuncionOrdenamiento = pFunc(pAux, pAuxDos);
				if ((retornoFuncionOrdenamiento > 0 && order == 1)
						|| (retornoFuncionOrdenamiento < 0 && order == 0)) {
					ll_set(this, i, pAuxDos);
					ll_set(this, i + 1, pAux);
					estaOrdenado = 0;
				}

			}

		} while (estaOrdenado == 0);

		returnAux = 0;
	}

	return returnAux;
}

/// @brief se debe iterar hasta que todos los elementos de la lista sean mdificados por la
/// funcion criterio
/// @param this Puntero a la lista
/// @param pFunc Punero a la funcion
/// @return

int ll_map(LinkedList *this, int (*pFunc)(void*)) {
	void *pElement;
	int i;
	int len;
	int returnValue = -1;

	if (this != NULL && pFunc != NULL) {
		len = ll_len(this);

		for (i = 0; i < len; i++) {
			pElement = ll_get(this, i);
			if (pFunc(pElement) == 0) {
				returnValue = 0;
			}
		}

	}

	return returnValue;
}

/// @brief evalua a traves de la funcion criterio si hay un elemento que se encuentre
///
/// @param this Puntero a lista
/// @param fn Puntero a funcion Criterio
/// @return
int ll_count(LinkedList *this, int (*fn)(void*)) {
	void *pElement;
	int i;
	int len;
	int acumulador = 0;

	if (this != NULL && fn != NULL) {
		len = ll_len(this);
		for (i = 0; i < len; i++) {
			pElement = ll_get(this, i);
			acumulador += (fn(pElement));
		}
	}
	return acumulador;
}

/// @brief
///
/// @param this
/// @param fn
/// @return

LinkedList* ll_filter(LinkedList *this, int (*fn)(void*)) {
	int i;
	int longitud;
	void *pElement;
	LinkedList *auxLista;

	if (this != NULL && fn != NULL) {
		auxLista = ll_newLinkedList();
		longitud = ll_len(this);
		// traigo mejor promedio
		if (auxLista != NULL && longitud > 0) {
			for (i = 0; i < longitud; i++) {
				pElement = ll_get(this, i);
				if (pElement != NULL && fn(pElement) == 1) {
					ll_add(auxLista, pElement);
				}

			}

		}
	}
	return auxLista;

}

