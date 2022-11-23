/*
 * Controller.h
 *
 *  Created on: 20 nov 2022
 *      Author: kervi
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_cargarVentasesDesdeTexto(char *path, LinkedList *pArrayListVenta);
int controller_agregarVenta(LinkedList *pArrayListVenta);
int controller_agregarVenta(LinkedList *pArrayListVenta);
int buscar_ventaId(int *BuscarId, LinkedList *pArrayListVenta);
int controller_editarVenta(LinkedList *pArrayListVenta);
int controller_listarVentas(LinkedList *pArrayListVenta);
int controller_CargaFromBinary(char *path, LinkedList *pArrayListVentas);
int controller_guardarVentasModoTexto(char *path, LinkedList *pArrayListJugador);
int controller_removerVenta(LinkedList *pArrayListVenta);
int controller_saveAsBinary(char *path, LinkedList *pArrayListVenta);
int controller_EscribirInformes(char *path, int pContadorCantidadUnidad,
		int pContadorMasVentaPrecioMasDiezMIL,
		int pContadorMasVentaPrecioMasVeinteMIL, int pAuxcontadorModelo);
int contadorUnidadesVendidas(void *Elemento);
int informesCalcular(LinkedList *pArrayListVenta, int *pContadorCantidadUnidad,
		int *pContadorMasVentaPrecioMasDiezMIL,
		int *pContadorMasVentaPrecioMasVeinteMIL, int *pAuxcontadorModelo);
int contadorVentaPrecioMayorVeinteMil(void *Elemento);
int contadorVentaPrecioMayorDiezMil(void *Elemento);

#endif /* CONTROLLER_H_ */
