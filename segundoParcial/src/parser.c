/*
 * parser.c
 *
 *  Created on: 20 nov 2022
 *      Author: kervi
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "venta.h"
#define VERDADERO 1
#define ERROR -1




/// @brief  Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
///
/// @param pFile puntero archivo
/// @param pArrayListVenta puntero a la lista enlazada
/// @return retorna (-1) error si no lee
/// 				(0) si lo lee bien
int parser_VentaFromText(FILE *pFile, LinkedList *pArrayListVenta) {
	int retorno = ERROR;
	char axuliarId[100];
	char axuliarDia[100];
	char axuliareMes[100];
	char axuliarAnio[100];
	char axuliarModeloAuto[100];
	char axuliarCantidad[100];
	char axuliarPrecioUnitario[100];
	char axuliarTarjetaCredito[100];
	int retornoFscanf;
	eVenta *pNuevaVenta;

	if (pFile != NULL && pArrayListVenta != NULL) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", axuliarId,
				axuliarAnio, axuliarModeloAuto, axuliarCantidad,
				axuliarPrecioUnitario, axuliarTarjetaCredito); //lectura fantasma

		while (feof(pFile) == 0) {

			retornoFscanf = fscanf(pFile,
					"%[^,],%[^/]/%[^/]/%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					axuliarId, axuliarDia, axuliareMes, axuliarAnio,
					axuliarModeloAuto, axuliarCantidad, axuliarPrecioUnitario,
					axuliarTarjetaCredito);

			if (retornoFscanf != 8) {
				retorno = ERROR;
				break;
			} else {

				pNuevaVenta = venta_newParamtros(axuliarId, axuliarDia,
						axuliareMes, axuliarAnio, axuliarModeloAuto,
						axuliarCantidad, axuliarPrecioUnitario,
						axuliarTarjetaCredito);

				{

					if (pNuevaVenta != NULL) {
						ll_add(pArrayListVenta, pNuevaVenta);
						// SE AGREGA A LA LINKEDLIST

						retorno = VERDADERO;
					} else {

					}
				}

			}
		}
	}

	return retorno;
}



/// @brief Parsea los datos de los jugadores desde el archivo binario.
///
/// @param pFile Puntero archivo
/// @param pArrayListVentas puntero a la lista enlazada
/// @return retorna (-1) en caso de poder entrar leer el archivo
/// 				(1) en caso de leer todo el archivo
int parser_VentaFromBinary(FILE *pFile, LinkedList *pArrayListVentas) {
	int retorno = ERROR;
	int auxiliarId;
	int auxiliarDia;
	int axiliarMes;
	int auxiliarAnio;
	char modeloAuto[50];
	int auxiliarCantidad;
	float precioUnitario;
	char tarjetaCredito[50];
	int ventas;
	eVenta *pNuevoVenta;
	if (pFile != NULL && pArrayListVentas != NULL) {
		while (feof(pFile) == 0) //itero hasta que el archivo llegue a su final
		{
			pNuevoVenta = venta_new();
			if (pNuevoVenta != NULL) {

				ventas = fread(pNuevoVenta, sizeof(eVenta), 1, pFile);
				if (ventas < 1) { //verifico q haya cargado al jugador
					retorno = ERROR;
					break;
				} else {
					if (venta_getId(pNuevoVenta, &auxiliarId) == VERDADERO
							&& venta_getDia(pNuevoVenta, &auxiliarDia)
									== VERDADERO
							&& venta_getMes(pNuevoVenta, &axiliarMes)
									== VERDADERO
							&& venta_getAnio(pNuevoVenta, &auxiliarAnio)
									== VERDADERO
							&& Venta_getModeloAuto(pNuevoVenta, modeloAuto)
									== VERDADERO
							&& venta_getCantidad(pNuevoVenta, &auxiliarCantidad)
									== VERDADERO
							&& venta_getPrecioUnitario(pNuevoVenta,
									&precioUnitario) == VERDADERO
							&& Venta_getTarjetaCredito(pNuevoVenta,
									tarjetaCredito)) {

						ll_add(pArrayListVentas, pNuevoVenta);
						retorno = VERDADERO;

					} else {
						venta_delete(pNuevoVenta);
					}

				}

			}
		}

	}
	return retorno;
}

