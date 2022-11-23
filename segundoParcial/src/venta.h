/*
 * venta.h
 *
 *  Created on: 20 nov 2022
 *      Author: kervi
 */

#ifndef VENTA_H_
#define VENTA_H_

typedef struct {
	int dia;
	int mes;
	int anio;
} eFecha;

typedef struct {
	int idVenta;
	 eFecha fecha;
	char modeloAuto[50];
	int cantidad;
	float precioUnitario;
	char tarjetaCredito[17];
} eVenta;



int venta_getId(eVenta *this, int *id);
int venta_getDia(eVenta *this, int *dia);
int venta_getMes(eVenta *this, int *mes);
int venta_getAnio(eVenta *this, int *anio);
int Venta_getModeloAuto(eVenta *this, char *modeloAuto);
int venta_getCantidad(eVenta *this, int *cantidad);
int venta_getPrecioUnitario(eVenta *this, float *precioUnitario);
int Venta_getTarjetaCredito(eVenta *this, char *tarjetaCredito);
int venta_setID(eVenta *this, int idVenta);
int venta_setDia(eVenta *this, int dia);
int venta_setMes(eVenta *this, int mes);
int venta_setAnio(eVenta *this, int anio);
int venta_setModeloAuto(eVenta *this, char *modeloAuto);
int venta_setCantidad(eVenta *this, int cantidad);
int venta_setPrecioUnitario(eVenta *this, float precioUnitario);
int venta_setTarjetaCredito(eVenta *this, char *tarjetaCredito);
eVenta* venta_new();
eVenta* venta_newParamtros(char *id, char *dia, char *mes, char *anio,
		char *modeloAuto, char *cantidad, char *precioUnitario,
		char *tarjetaCredito);
int eleccioModeloAuto(char *modeloAuto);
int idAutoIncremental(int *idAutoIncremental);
int imprime_UnaVenta(eVenta *this);
void venta_delete(eVenta *this);

#endif /* VENTA_H_ */
