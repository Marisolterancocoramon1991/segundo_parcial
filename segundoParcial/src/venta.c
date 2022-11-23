/*
 * venta.c
 *
 *  Created on: 20 nov 2022
 *      Author: kervi
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "mostrar.h"
#include "venta.h"
#define ERROR -1
#define VERDADERO 1

/// @brief libera la memoria en uno de los venta especificados
///
/// @param this puntero a eestructura

void venta_delete(eVenta *this) {
	if (this != NULL) {
		free(this);

	}

}

/// @brief entrega por puntero el id de venta
///
/// @param this el elemento o estructura
/// @param id la informacion que se busca
/// @return int retorna (-1) en caso de fallar
/// 			retorna (1) en caso de hacer el trabajo

int venta_getId(eVenta *this, int *id) {
	int retorno = ERROR;
	if (this != NULL && id != NULL) {
		*id = this->idVenta;
		retorno = VERDADERO;
	}

	return retorno;
}

/// @brief entrega por puntero el dia de la fecha
///
/// @param this estructura
/// @param dia Puntero a int
/// @return int retorna (-1) en caso de fallar
/// 			retorna (1) en caso de hacer el trabajo
int venta_getDia(eVenta *this, int *dia) {
	int retorno = ERROR;
	if (this != NULL && dia != NULL) {
		*dia = this->fecha.dia;
		retorno = VERDADERO;
	}
	return retorno;
}

/// @brief entrega por puntero el mes de la fecha
///
/// @param this  puntero a estructura
/// @param mes Puntero a int
/// @return int retorna (-1) en caso de fallar
/// 			retorna (1) en caso de hacer el trabajo
int venta_getMes(eVenta *this, int *mes) {
	int retorno = ERROR;
	if (this != NULL && mes != NULL) {
		*mes = this->fecha.mes;
		retorno = VERDADERO;
	}
	return retorno;
}

/// @brief entrega por puntero el mes de la fecha
///
/// @param this  puntero a estructura
/// @param anio Puntero a int
/// @return int retorna (-1) en caso de fallar
/// 			retorna (1) en caso de hacer el trabajo
int venta_getAnio(eVenta *this, int *anio) {
	int retorno = ERROR;
	if (this != NULL && anio != NULL) {
		*anio = this->fecha.anio;
		retorno = VERDADERO;
	}
	return retorno;
}

/// @brief entrega la el modelo del auto  por puntero
///
/// @param this  puntero estuctura
/// @param modeloAuto informacion a extraer
/// @return int 	retorna (-1) en caso de fallar
/// 				retorna (1) en caso de hacer el trabajo
int Venta_getModeloAuto(eVenta *this, char *modeloAuto) {
	int retorno = ERROR;
	if (this != NULL && modeloAuto != NULL) {
		strcpy(modeloAuto, this->modeloAuto);
		retorno = VERDADERO;
	}
	return retorno;
}

/// @brief entrega por puntero la cantidad de productos vendidos
///
/// @param this  puntero a estructura
/// @param Cantidad Puntero a int
/// @return int retorna (-1) en caso de fallar
/// 			retorna (1) en caso de hacer el trabajo
int venta_getCantidad(eVenta *this, int *cantidad) {
	int retorno = ERROR;
	if (this != NULL && cantidad != NULL) {
		*cantidad = this->cantidad;
		retorno = VERDADERO;
	}
	return retorno;
}

/// @brief entrega por puntero el precio unitario del producto
///
/// @param this  puntero a estructura
/// @param Cantidad Puntero a float
/// @return int retorna (-1) en caso de fallar
/// 			retorna (1) en caso de hacer el trabajo
int venta_getPrecioUnitario(eVenta *this, float *precioUnitario) {
	int retorno = ERROR;
	if (this != NULL && precioUnitario != NULL) {
		*precioUnitario = this->precioUnitario;
		retorno = VERDADERO;
	}
	return retorno;
}

/// @brief entrega la el la tarjeta de credito por puntero
///
/// @param this  puntero estuctura
/// @param tarjetaCredito informacion a extraer
/// @return int 	retorna (-1) en caso de fallar
/// 				retorna (1) en caso de hacer el trabajo
int Venta_getTarjetaCredito(eVenta *this, char *tarjetaCredito) {
	int retorno = ERROR;
	if (this != NULL && tarjetaCredito != NULL) {
		strcpy(tarjetaCredito, this->tarjetaCredito);
		retorno = VERDADERO;
	}
	return retorno;
}

/// @brief le da al campo id de la estructura venta el id
///
/// @param this puntero a estructura
/// @param idVenta int entero id de venta
/// @return 	retorna (-1) en caso de fallar
/// 			retorna (1) en caso de hacer el trabajo
int venta_setID(eVenta *this, int idVenta) {
	int retorno = ERROR;
	this->idVenta = idVenta;

	if (this != NULL && idVenta >= 0) {
		retorno = VERDADERO;

	}

	return retorno;
}

/// @brief entrega la estructura en el el campo de fecha y despues del dia un valor
///  y lo valida
/// @param this puntero a estructura
/// @param dia int
/// @return		retorna (-1) en caso de fallar
/// 			retorna (1) en caso de hacer el trabajo
int venta_setDia(eVenta *this, int dia) {
	int retorno = ERROR;

	if (this != NULL && (dia >= 0 || dia <= 31)) {
		this->fecha.dia = dia;
		retorno = VERDADERO;
	}

	return retorno;
}

/// @brief entrega la estructura en el el campo de fecha y despues del mes un valor
///  y lo valida
/// @param this puntero a estructura
/// @param mes int
/// @return		retorna (-1) en caso de fallar
/// 			retorna (1) en caso de hacer el trabajo
int venta_setMes(eVenta *this, int mes) {
	int retorno = ERROR;

	if (this != NULL && (mes >= 0 || mes <= 12)) {

		this->fecha.mes = mes;
		retorno = VERDADERO;
	}

	return retorno;
}

/// @brief entrega la estructura en el el campo de fecha y despues del anio un valor
///  y lo valida
/// @param this puntero a estructura
/// @param anio int
/// @return		retorna (-1) en caso de fallar
/// 			retorna (1) en caso de hacer el trabajo
int venta_setAnio(eVenta *this, int anio) {
	int retorno = ERROR;

	if (this != NULL && (anio >= 0 || anio <= 2050)) {

		this->fecha.anio = anio;
		retorno = VERDADERO;
	}

	return retorno;
}

/// @brief entrega en el campo del modelo de auto la informacion correspondiente
///
/// @param this puntero a estructura
/// @param modeloAuto informacion a entregar en el campo
/// @return int retorna (-1) en caso de fallar
/// 			retorna (1) en caso de hacer el trabajo

int venta_setModeloAuto(eVenta *this, char *modeloAuto) {
	int retorno = ERROR;
	if (this != NULL && modeloAuto != NULL) {
		strcpy(this->modeloAuto, modeloAuto);

		retorno = VERDADERO;
	}

	return retorno;
}

/// @brief entrega la estructura en el el campo de fecha y despues del anio un valor
///  y lo valida
/// @param this puntero a estructura
/// @param cantidad int
/// @return		retorna (-1) en caso de fallar
/// 			retorna (1) en caso de hacer el trabajo
int venta_setCantidad(eVenta *this, int cantidad) {
	int retorno = ERROR;
	if (this != NULL && cantidad >= 0) {
		this->cantidad = cantidad;
		retorno = VERDADERO;
	}

	return retorno;
}

/// @brief entrega a la estructura en el campo de precio Unitario
/// la informacion requerida
/// @param this puntero a estructura
/// @param precioUnitario float
/// @returnr	retorna (-1) en caso de fallar
/// 			retorna (1) en caso de hacer el trabajo
int venta_setPrecioUnitario(eVenta *this, float precioUnitario) {
	int retorno = ERROR;
	if (this != NULL && precioUnitario >= 0) {
		this->precioUnitario = precioUnitario;
		retorno = VERDADERO;
	}

	return retorno;
}

/// @brief agrega un en el campo de tarjeta una nueva tarjeta de credito
///
/// @param this puntero a estructura
/// @param tarjetaCredito puntero a char
/// @return		retorna (-1) en caso de fallar
/// 			retorna (1) en caso de hacer el trabajo

int venta_setTarjetaCredito(eVenta *this, char *tarjetaCredito) {
	int retorno = ERROR;

	if (this != NULL && tarjetaCredito != NULL
	/*&& strlen(tarjetaCredito) == 16*/) {
		strcpy(this->tarjetaCredito, tarjetaCredito);
		retorno = VERDADERO;
	}

	return retorno;
}

/// @brief crea en el espacio de la memoria dinamica una nueva venta
///
/// @return  retorna la estructura cada en cero
eVenta* venta_new() {
	eVenta *nuevaVenta = NULL;
	nuevaVenta = (eVenta*) malloc(sizeof(eVenta));
	if (nuevaVenta != NULL) {

		venta_setID(nuevaVenta, 0);
		venta_setDia(nuevaVenta, 0);
		venta_setMes(nuevaVenta, 0);
		venta_setAnio(nuevaVenta, 0);
		venta_setModeloAuto(nuevaVenta, " ");
		venta_setCantidad(nuevaVenta, 0);
		venta_setPrecioUnitario(nuevaVenta, 0);
		venta_setTarjetaCredito(nuevaVenta, "0000000000000000");
	}

	return nuevaVenta;
}

/// @brief carga la estructura con todos sus campos
///
/// @param id puntero a char
/// @param dia  puntero a char
/// @param mes  puntero a char
/// @param anio  puntero a char
/// @param modeloAuto  puntero a char
/// @param cantidad  puntero a char
/// @param precioUnitario  puntero a char
/// @param tarjetaCredito  puntero a char
/// @return retorna nukl en caso de fallar o la estructura en caso de ser cierto
eVenta* venta_newParamtros(char *id, char *dia, char *mes, char *anio,
		char *modeloAuto, char *cantidad, char *precioUnitario,
		char *tarjetaCredito) {
	eVenta *nuevaVenta = NULL;
	if (id != NULL && dia != NULL && mes != NULL && anio != NULL
			&& modeloAuto != NULL && cantidad != NULL && precioUnitario != NULL
			&& tarjetaCredito != NULL) {
		nuevaVenta = venta_new();
		if (nuevaVenta != NULL && venta_setID(nuevaVenta, atoi(id)) == VERDADERO
				&& venta_setDia(nuevaVenta, atoi(dia)) == VERDADERO
				&& venta_setMes(nuevaVenta, atoi(mes)) == VERDADERO
				&& venta_setAnio(nuevaVenta, atoi(anio)) == VERDADERO
				&& venta_setModeloAuto(nuevaVenta, modeloAuto) == VERDADERO
				&& venta_setCantidad(nuevaVenta, atoi(cantidad)) == VERDADERO
				&& venta_setPrecioUnitario(nuevaVenta,
						atof(precioUnitario)) == VERDADERO
						&& venta_setTarjetaCredito(nuevaVenta, tarjetaCredito)
						== VERDADERO) {

		} else {
			free(nuevaVenta);
			nuevaVenta = NULL;

		}
	}

	return nuevaVenta;
}

/// @brief
///
/// @param idAutoIncremental
/// @return
int idAutoIncremental(int *idAutoIncremental) {
	static int auxiliar = 51;
	int retorno = ERROR;
	if (idAutoIncremental != NULL) {

		auxiliar++;
		*idAutoIncremental = auxiliar;
		retorno = VERDADERO;

	}

	return retorno;
}

/// @brief da uuna opcion del menu para que el usuario pueda elegir
/// el auto que desea
/// @param modeloAuto puntero a char
/// @return retorna (-1) en caso de fallar
/// 				(1) en caso de ser cierto
int eleccioModeloAuto(char *modeloAuto) {
	int retorno = ERROR;
	int option;
	if (modeloAuto != NULL) {
		opcionesModeloAuto();

		if (get_UTN_ValidacionNumero(&option,
				"Elija una opcion del MENU DE OPCIONES \n",
				"ERROR, Elija una opcion del MENU DE OPCIONES valida \n", 1, 30,
				10) == VERDADERO) {
			switch (option) {
			case 1:
				strcpy(modeloAuto, "Blazer");
				break;
			case 2:
				strcpy(modeloAuto, "Accord");
				break;
			case 3:
				strcpy(modeloAuto, "Avalon");
				break;
			case 4:
				strcpy(modeloAuto, "Odyssey");
				break;
			case 5:
				strcpy(modeloAuto, "Vanquish");
				break;
			case 6:
				strcpy(modeloAuto, "Continental GT");
				break;
			case 7:
				strcpy(modeloAuto, "Mulsanne");
				break;
			case 8:
				strcpy(modeloAuto, "Bentayga");
				break;
			case 9:
				strcpy(modeloAuto, "Cruze");
				break;
			case 11:
				strcpy(modeloAuto, "Trax");
				break;
			case 10:
				strcpy(modeloAuto, "Aveo");
				break;
			case 13:
				strcpy(modeloAuto, "Trax");
				break;
			case 14:
				strcpy(modeloAuto, "Orlando");
				break;
			case 15:
				strcpy(modeloAuto, "Spark");
				break;
			case 16:
				strcpy(modeloAuto, "Camaro");
				break;

			case 17:
				strcpy(modeloAuto, "Nemo");
				break;
			case 18:
				strcpy(modeloAuto, "Berlingo");
				break;
			case 19:
				strcpy(modeloAuto, "Logan");
				break;

			case 20:
				strcpy(modeloAuto, "Sandero");
				break;
			case 21:
				strcpy(modeloAuto, "Duster");
				break;
			case 22:
				strcpy(modeloAuto, "Dokker");
				break;
			case 23:
				strcpy(modeloAuto, "California");
				break;

			case 24:
				strcpy(modeloAuto, "Portofino");
				break;
			case 25:
				strcpy(modeloAuto, "Freemont");
				break;
			case 26:
				strcpy(modeloAuto, "Panda");
				break;

			case 27:
				strcpy(modeloAuto, "Punto");
				break;
			case 28:
				strcpy(modeloAuto, "Fiorino");
				break;

			case 29:
				strcpy(modeloAuto, "EcoSport");
				break;
			case 30:
				strcpy(modeloAuto, "Mustang");
				break;

			}
			retorno = VERDADERO;
		}

	}

	return retorno;
}

/// @brief imprime una venta
///
/// @param this puntero a la estructura
/// @return (-1) en caso de fallar
/// 				(1) en caso de ser cierto
int imprime_UnaVenta(eVenta *this) {

	int retorno = ERROR;
	int auxiliarId;
	int auxiliarDia;
	int axiliarMes;
	int auxiliarAnio;
	char modeloAuto[50];
	int auxiliarCantidad;
	float precioUnitario;
	char tarjetaCredito[50];

	if (this != NULL) {

		if (venta_getId(this, &auxiliarId) == VERDADERO
				&& venta_getDia(this, &auxiliarDia) == VERDADERO
				&& venta_getMes(this, &axiliarMes) == VERDADERO
				&& venta_getAnio(this, &auxiliarAnio) == VERDADERO
				&& Venta_getModeloAuto(this, modeloAuto) == VERDADERO
				&& venta_getCantidad(this, &auxiliarCantidad) == VERDADERO
				&& venta_getPrecioUnitario(this, &precioUnitario) == VERDADERO
				&& Venta_getTarjetaCredito(this, tarjetaCredito)) {

			printf("%-5d     %2d/%2d/%-4d      "
					"  %-20s    %-5d                  %-10.2f     "
					"   %-24s\n", auxiliarId, auxiliarDia, axiliarMes,
					auxiliarAnio, modeloAuto, auxiliarCantidad, precioUnitario,
					tarjetaCredito);
		}

		retorno = VERDADERO;
	}
	return retorno;
}

