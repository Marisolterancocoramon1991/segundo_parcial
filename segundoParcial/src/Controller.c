/*
 * Controller.c
 *
 *  Created on: 20 nov 2022
 *      Author: kervi
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "venta.h"
#include "mostrar.h"
#include "linkedlist.h"
#include "validaciones.h"
#include "parser.h"

#define VERDADERO 1
#define ERROR -1

/// @brief funcion criterio para contar las cantidades venditas
///
/// @param Elemento puntero a void
/// @return retorna la cantidad de productos vendidos
/// 				(0) en caso de fallar
/// 	(retorna la cantidad) uno en caso de cumplir la conedicion

int contadorUnidadesVendidas(void *Elemento) {
	int retorno = 0;
	eVenta *auxelmento;
	if (Elemento != NULL) {
		auxelmento = (eVenta*) Elemento;
		venta_getCantidad(auxelmento, &retorno);
	}

	return retorno;
}

/// @brief funcion criterio para saber cuales son los montos mayoes a veinte mil
///
/// @param Elemento puntero a void
/// @return retorna
/// 				(0) en caso de no cumplirse la condicion
/// 				(1) uno en caso de cumplir la conedicion

int contadorVentaPrecioMayorVeinteMil(void *Elemento) {
	int retorno = 0;
	float auxiliarPrecio;
	eVenta *auxelmento;
	if (Elemento != NULL) {
		auxelmento = (eVenta*) Elemento;

		venta_getPrecioUnitario(auxelmento, &auxiliarPrecio);
		if (auxiliarPrecio > 20000) {
			retorno++;
		}

	}

	return retorno;

}

/// @brief funcion criterio que compara los nombres de los carros
///
/// @param Elemento puntero a void
/// @return retorna
/// 				(0) en caso de no cumplirse la condicion
/// 				(1) uno en caso de cumplir la conedicion

int contadorModelo(void *Elemento) {
	int retorno = 0;

	char auxiliarmodeloAuto[100];
	eVenta *auxelmento;
	if (Elemento != NULL) {
		auxelmento = (eVenta*) Elemento;

		Venta_getModeloAuto(auxelmento, auxiliarmodeloAuto);
		if (strcmp(auxiliarmodeloAuto, "Cougar") == 0) {
			retorno++;
		}

	}

	return retorno;

}

/// @brief funcion criterio que coompara si el elemento o venta tiene un monto mayor a diez
/// mil
/// @param Elemento puntero a void
/// @return retorna
/// 				(0) en caso de no cumplirse la condicion
/// 				(1) uno en caso de cumplir la conedicion

int contadorVentaPrecioMayorDiezMil(void *Elemento) {

	int retorno = 0;
	float auxiliarPrecio;
	eVenta *auxelmento;
	if (Elemento != NULL) {
		auxelmento = (eVenta*) Elemento;
		venta_getPrecioUnitario(auxelmento, &auxiliarPrecio);
		if (auxiliarPrecio > 10000) {
			retorno++;
		}

	}

	return retorno;

}

/// @brief busca el id de la venta y retorna el indice
///
/// @param BuscarId puntero a int id a buscar
/// @param pArrayListVenta puntero a la lista enlazada
/// @return retorna (-1) en caso de fallar
/// 				(indice) en caso de hallar coincidencia

int buscar_ventaId(int *BuscarId, LinkedList *pArrayListVenta) {
	int retorno = ERROR;
	int i;
	int id;
	eVenta *venta;
	if (BuscarId != NULL && pArrayListVenta != NULL) {
		for (i = 0; i < ll_len(pArrayListVenta); i++) {
			venta = (eVenta*) ll_get(pArrayListVenta, i);

			venta_getId(venta, &id);
			if (*BuscarId == id) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/// @brief abre el archivo en modo lectura para poder cargarlo al sistema
///
/// @param path punttero a char nombre del archivo
/// @param pArrayListVenta puntero a lista enlazada
/// @return retorna (-1) en caso de fallar
/// 				(1) en caso de se cierto

int controller_cargarVentasesDesdeTexto(char *path, LinkedList *pArrayListVenta) {
	int retorno = ERROR;
	FILE *auxiliarPath = NULL;
	if (path != NULL && pArrayListVenta != NULL) {

		auxiliarPath = fopen(path, "r");
		if (auxiliarPath != NULL) {

			if (parser_VentaFromText(auxiliarPath, pArrayListVenta) == VERDADERO) {
				retorno = VERDADERO;
			}
		} else {

			printf("Hubo un error en la carga del Archivo Venta\n");

		}
		fclose(auxiliarPath);
	}

	return retorno;
}

/// @brief agrega una venta al sistema
///
/// @param pArrayListVenta puntero a la lista enlazada
/// @return		(-1) en caso de fallar
/// 			(1) en caso de se cierto

int controller_agregarVenta(LinkedList *pArrayListVenta) {
	int retorno = ERROR;
	int dia;
	int mes;
	int id;
	int anio;
	char modeloAuto[50];
	int cantidad;
	float precioUnitario;
	char tarjeta[17];
	eVenta *nuevaVenta = NULL;

	if (pArrayListVenta != NULL) {
		nuevaVenta = venta_new();
		if (get_UTN_ValidacionNumero(&dia,
				"\t\t\t Cual es el dia de la venta\n",
				"ERROR, Elija una opcion del MENU DE OPCIONES valida \n", 1, 31,
				10) == VERDADERO
				&& get_UTN_ValidacionNumero(&mes,
						"\t\t\t Cual es el mes de la venta\n",
						"ERROR, Elija una opcion del MENU DE OPCIONES valida \n",
						1, 12, 10) == VERDADERO
				&& get_UTN_ValidacionNumero(&anio,
						"\t\t\t Cual es el año de la venta\n",
						"ERROR, Elija una opcion del MENU DE OPCIONES valida \n",
						2000, 2030, 10) == VERDADERO
				&& eleccioModeloAuto(modeloAuto) == VERDADERO
				&& get_UTN_ValidacionNumeroflotante(&precioUnitario,
						"\t\t\t Eleccion de precio unitario debe ser mayor a mil \n",
						"Hubo algun tipo del problema con la car del precio unitario",
						1000, 99999999, 10) == VERDADERO
				&& get_UTN_ValidacionNumero(&cantidad,
						"\t\t\t Cantidad de autos a vender\n",
						"ERROR, Elija una opcion del MENU DE OPCIONES valida \n",
						1, 31, 10) == VERDADERO

				&& utn_getTrjetaCredito("\t\t\t Tarjet de credito", "ERROR", 16,
						17, 3, tarjeta) == VERDADERO

				&& idAutoIncremental(&id) == VERDADERO) {

			if (venta_setDia(nuevaVenta, dia) == VERDADERO
					&& venta_setMes(nuevaVenta, mes) == VERDADERO
					&& venta_setAnio(nuevaVenta, anio) == VERDADERO
					&& venta_setModeloAuto(nuevaVenta, modeloAuto) == VERDADERO
					&& venta_setCantidad(nuevaVenta, cantidad) == VERDADERO
					&& venta_setPrecioUnitario(nuevaVenta,
							precioUnitario) == VERDADERO
							&& venta_setTarjetaCredito(nuevaVenta, tarjeta)
							== VERDADERO && venta_setID(nuevaVenta, id) == VERDADERO) {

				if (nuevaVenta != NULL) {
					ll_add(pArrayListVenta, nuevaVenta);
					retorno = VERDADERO;

				}

			}

		}

	}
	return retorno;
}

/// @brief lista la ventas cargadas
///
/// @param pArrayListVenta puntero a lista enlazada
/// @return (-1) en caso de fallar
/// 		(1) en caso de se cierto
int controller_listarVentas(LinkedList *pArrayListVenta) {
	int retorno = ERROR;
	int i;
	eVenta *venta = NULL;

	if (pArrayListVenta != NULL) {

		for (i = 0; i < ll_len(pArrayListVenta); i++) {

			venta = (eVenta*) ll_get(pArrayListVenta, i);

			if (imprime_UnaVenta(venta) == VERDADERO) {
			} else {
				printf("no se ha podido cargar la"
						" lista de selecciones completa\n");
			}

		}
		retorno = VERDADERO;
	}

	return retorno;
}

/// @brief lea la lista en modo binario
///
/// @param path puntero a char
/// @param pArrayListVentas puntero a lista enlazada
/// @return	(-1) en caso de fallar
/// 				(1) en caso de se cierto

int controller_CargaFromBinary(char *path, LinkedList *pArrayListVentas) {
	int retorno = ERROR;
	FILE *auxP;
	if (path != NULL && pArrayListVentas != NULL) {
		auxP = fopen(path, "rb"); //LO LEO EN MODO BINARIO
		if (auxP != NULL) {

			if (parser_VentaFromBinary(auxP, pArrayListVentas) == VERDADERO) {
				retorno = VERDADERO;
			}

		} else {
			printf("No se pudo leer el archivo\n");
		}

	}
	fclose(auxP);
	return retorno;
}

/// @brief edita algun campo de la estuctura venta
///
/// @param pArrayListVenta puntero a lista enlazada
/// @return retorna (-1) en caso de fallar
/// 				(1) en caso de se cierto

int controller_editarVenta(LinkedList *pArrayListVenta) {
	int retorno = ERROR;
	int idAEditar;
	int indice;
	int dia;
	int mes;
	int anio;
	char modeloAuto[50];
	int cantidad;
	float precioUnitario;
	int opcionesMenu;
	int seguirIterando;
	eVenta *ventaAmodificar;
	if (pArrayListVenta != NULL) {
		do {

			if (controller_listarVentas(pArrayListVenta) == VERDADERO
					&& get_UTN_ValidacionNumero(&idAEditar,
							"Ingrese el id de la  venta que "
									"desea modificar algunos de los campos\n",
							"ERROR,no ha ingresado un numero de "
									"referencia valido \n", 1, 100000000, 10)
							== VERDADERO) {

				indice = buscar_ventaId(&idAEditar, pArrayListVenta);
				if (indice != ERROR) {
					ventaAmodificar = (eVenta*) ll_get(pArrayListVenta, indice);
					cabeceraVentaAModificar();
					imprime_UnaVenta(ventaAmodificar);
					menuModificacion();

					if (get_UTN_ValidacionNumero(&opcionesMenu,
							"INGRESE LAS OPCIONES DEL MENU...\n "
									"================================\n",
							"ERROR,no ha ingresado un numero de "
									"referencia valido \n", 1, 4,
							10) == VERDADERO) {
						switch (opcionesMenu) {
						case 1:
							if (get_UTN_ValidacionNumero(&dia,
									" Elija dia de la venta \n",
									"ERROR, Elija dia de la venta \n", 1, 31,
									10) == VERDADERO) {

							} else {
								printf("\t\t\t no se ha "
										"podido ingresar el dia\n");
								break;
							}

							if (get_UTN_ValidacionNumero(&mes,
									"Elija mes de la venta  \n",
									"ERROR, Elija mes de la venta \n", 1, 31,
									10) == VERDADERO) {

							} else {
								printf("\t\t\t no se ha "
										"podido ingresar el mes\n");
								break;
							}

							if (get_UTN_ValidacionNumero(&anio,
									" Elija anio de la venta \n",
									"ERROR, Elija anio de la venta \n", 1900,
									2050, 10) == VERDADERO) {

							} else {
								printf("\t\t\t no se ha "
										"podido ingresar el anio\n");
								break;
							}
							if (venta_setDia(ventaAmodificar, dia) == VERDADERO
									&& venta_setMes(ventaAmodificar,
											mes) == VERDADERO
											&& venta_setAnio(ventaAmodificar, anio)
											== VERDADERO) {
								printf("\t\t\texcelente se ha modificado"
										" la fecha correctamente\n");
							}

							break;
						case 2:

							if (eleccioModeloAuto(modeloAuto) == VERDADERO
									&& venta_setModeloAuto(ventaAmodificar,
											modeloAuto) == VERDADERO) {
								printf("\t\t\texcelente se ha modificado"
										" el modelo correctamente\n");

							}

							break;
						case 3:

							if (get_UTN_ValidacionNumero(&cantidad,
									" Elija anio de la venta \n",
									"ERROR, Elija anio de la venta \n", 1900,
									2050, 10) == VERDADERO
									&& venta_setCantidad(ventaAmodificar,
											cantidad) == VERDADERO) {
								printf("\t\t\texcelente se ha modificado"
										" el modelo correctamente\n");

							}

							break;
						case 4:

							if (get_UTN_ValidacionNumeroflotante(
									&precioUnitario,
									"\t\t\t Eleccion de precio unitario debe ser mayor a mil \n",
									"Hubo algun tipo del problema con la car del precio unitario",
									1000, 99999999, 10) == VERDADERO) {

							}

							if (venta_setPrecioUnitario(ventaAmodificar,
									precioUnitario)) {
								printf(
										"\t\t\texcelente se ha modificado"
												" el precio de la unidad correctamente\n");
							}

							break;

						}
					}

				} else {
					printf("\t\t\t no se haya a la venta on ese id \n");
				}
			}
			if (get_UTN_ValidacionNumero(&seguirIterando,
					"desea seguir modificando venta 1 para si "
							"y 0 para no \n",
					"ERROR,no ha ingresado un numero de "
							"referencia valido \n", 0, 1, 10) != VERDADERO) {
				printf("hubo un problema al ingresar la eleccion"
						"intentelo mas tarde \n");
				break;
			}
		} while (seguirIterando != 0);
	}

	return retorno;
}

/// @brief remueve alguna venta
///
/// @param pArrayListVenta puntero a lista enlazada
/// @return (-1) en caso de fallar
/// 		(1) en caso de se cierto
int controller_removerVenta(LinkedList *pArrayListVenta) {
	int retorno = ERROR;
	int idRemover;
	int indice;
	int idSeleccion;
	int confirmacion;
	eVenta *VentaRemover = NULL;
	if (pArrayListVenta != NULL) {
		if (get_UTN_ValidacionNumero(&idRemover,
				"Ingrese el numero de id de la venta a eliminar ",
				"ERROR,no ha ingresado un numero de "
						"referencia valido \n", 0, 100000000, 10) == VERDADERO) {

			indice = buscar_ventaId(&idRemover, pArrayListVenta);
			if (indice == ERROR) {
				printf("no se ha encontrado el id de la venta  \n");

			} else {

				VentaRemover = (eVenta*) ll_get(pArrayListVenta, indice);
				cabeceraVentaARemover();
				if (imprime_UnaVenta(VentaRemover) == VERDADERO
						&& get_UTN_ValidacionNumero(&confirmacion,
								"Desea eliminar el venta 1 para si "
										"y 0 para no \n",
								"ERROR,no ha ingresado un numero de "
										"referencia valido \n", 0, 1, 10)
								== VERDADERO && confirmacion == 1) {
					venta_getId(VentaRemover, &idSeleccion);
					retorno = idSeleccion;
					venta_delete(VentaRemover);
					ll_remove(pArrayListVenta, indice);
					printf("se ha eliminado la Venta"
							"exitosamente\n");

				} else {
					printf("no se ha dado de baja ningun elemento\n");
				}
			}
		}
	}

	return retorno;
}

/// @brief guarda la lista en modo texto
///
/// @param path  puntero a archivo
/// @param pArrayListJugador puntero a lista enlazada
/// @return (-1) en caso de fallar
/// 		(1) en caso de se cierto

int controller_guardarVentasModoTexto(char *path, LinkedList *pArrayListJugador) {
	int retorno = ERROR;
	int auxiliarId;
	int auxiliarDia;
	int axiliarMes;
	int auxiliarAnio;
	char modeloAuto[50];
	int auxiliarCantidad;
	float precioUnitario;
	char tarjetaCredito[50];
	eVenta *pauxiliarVenta = NULL;
	FILE *pAuxliarArchivo;
	pAuxliarArchivo = fopen(path, "w");
	if (path != NULL && pArrayListJugador != NULL) {
		fprintf(pAuxliarArchivo, "ID_Venta,Fecha_Venta,Modelo_Auto,Cantidad,"
				"Precio_Unitario,tarjeta_Credito\n"); //printeo Fantasma
		for (int i = 0; i < ll_len(pArrayListJugador); i++) {
			pauxiliarVenta = (eVenta*) ll_get(pArrayListJugador, i);
			if (pauxiliarVenta != NULL) {
				if (venta_getId(pauxiliarVenta, &auxiliarId) == VERDADERO
						&& venta_getDia(pauxiliarVenta, &auxiliarDia)
								== VERDADERO
						&& venta_getMes(pauxiliarVenta, &axiliarMes)
								== VERDADERO
						&& venta_getAnio(pauxiliarVenta, &auxiliarAnio)
								== VERDADERO
						&& Venta_getModeloAuto(pauxiliarVenta, modeloAuto)
								== VERDADERO
						&& venta_getCantidad(pauxiliarVenta, &auxiliarCantidad)
								== VERDADERO
						&& venta_getPrecioUnitario(pauxiliarVenta,
								&precioUnitario) == VERDADERO
						&& Venta_getTarjetaCredito(pauxiliarVenta,
								tarjetaCredito)) {
					fprintf(pAuxliarArchivo, "%d,%d/%d/%d,%s,%d,%f,%s\n",
							auxiliarId, auxiliarDia, axiliarMes, auxiliarAnio,
							modeloAuto, auxiliarCantidad, precioUnitario,
							tarjetaCredito);
				}
			}
			retorno = VERDADERO;
		}
		fclose(pAuxliarArchivo);
	}

	return retorno;
}

/// @brief  Guarda los datos de los empleados en el archivo data.csv (modo binario).
///
/// @param path char*
/// @param pArrayListVenta puntero a lista enlazada
/// @return
int controller_saveAsBinary(char *path, LinkedList *pArrayListVenta) {
	int retorno = ERROR;
	FILE *auxP;
	eVenta *auxVenta;

	if (pArrayListVenta != NULL) {
		auxP = fopen(path, "wb"); //Lo abro para escritura
		if (auxP != NULL) {
			for (int i = 0; i < ll_len(pArrayListVenta); i++) {
				auxVenta = (eVenta*) ll_get(pArrayListVenta, i);
				if (auxVenta != NULL) {
					if (fwrite(auxVenta, sizeof(eVenta), 1, auxP) != 1) {
						retorno = ERROR;
						break;
					}
					retorno = VERDADERO;
				}
			}
		} else {
			printf("No se pudo escribir en el archivo");
		}
		fclose(auxP);
	}

	return retorno;
}

/// @brief  escribe en el archivo informe los resultados obtenidos
///
/// @param path Puntero a char
/// @param pContadorCantidadUnidad  int
/// @param pContadorMasVentaPrecioMasDiezMIL  int
/// @param pContadorMasVentaPrecioMasVeinteMIL  int
/// @param pAuxcontadorModelo int
/// @return retorna (-1) en caso de fallar
/// 				(1) en caso de se cierto
int controller_EscribirInformes(char *path, int pContadorCantidadUnidad,
		int pContadorMasVentaPrecioMasDiezMIL,
		int pContadorMasVentaPrecioMasVeinteMIL, int pAuxcontadorModelo) {
	int retorno = -1;
	if (path != NULL && pContadorCantidadUnidad > 0) {
		FILE *pArchivo;
		pArchivo = fopen(path, "w");
		if (pArchivo != NULL) {

			retorno = 0;

			if (fprintf(pArchivo,
					"\n*****************\nINFORMES DE VENTA\n*****************\n\n-Cantidad de unidades vendidas totales: %d\n-Cantidad de ventas por un monto mayor a $10000: %d\n-Cantidad de ventas por un monto mayor a $20000: %d\n-Cantidad de unidades vendidas para el modelo Cougar: %d\n\n*************",
					pContadorCantidadUnidad, pContadorMasVentaPrecioMasDiezMIL,
					pContadorMasVentaPrecioMasVeinteMIL, pAuxcontadorModelo)
					> 0) {
				retorno = VERDADERO;
			}

		}
		fclose(pArchivo);
	}
	return retorno;
}

/// @brief calcula atraves de la funcion account las cantidades exactas
///
/// @param pArrayListVenta puntero a lista
/// @param pContadorCantidadUnidad puntero a int
/// @param pContadorMasVentaPrecioMasDiezMIL puntero a int
/// @param pContadorMasVentaPrecioMasVeinteMIL puntero a int
/// @param pAuxcontadorModelo puntero a int
/// @return (-1) en caso de fallar
/// 		(1) en caso de se cierto

int informesCalcular(LinkedList *pArrayListVenta, int *pContadorCantidadUnidad,
		int *pContadorMasVentaPrecioMasDiezMIL,
		int *pContadorMasVentaPrecioMasVeinteMIL, int *pAuxcontadorModelo) {
	int retorno = ERROR;
	int contadorCantidadUnidad;
	int contadorMasVentaPrecioMasDiezMIL;
	int contadorMasVentaPrecioMasVeinteMIL;
	int auxcontadorModelo;
	if (pArrayListVenta != NULL) {
		contadorCantidadUnidad = ll_count(pArrayListVenta,
				contadorUnidadesVendidas);
		contadorMasVentaPrecioMasDiezMIL = ll_count(pArrayListVenta,
				contadorVentaPrecioMayorDiezMil);
		contadorMasVentaPrecioMasVeinteMIL = ll_count(pArrayListVenta,
				contadorVentaPrecioMayorVeinteMil);
		auxcontadorModelo = ll_count(pArrayListVenta, contadorModelo);

		*pContadorCantidadUnidad = contadorCantidadUnidad;
		*pContadorMasVentaPrecioMasDiezMIL = contadorMasVentaPrecioMasDiezMIL;
		*pContadorMasVentaPrecioMasVeinteMIL =
				contadorMasVentaPrecioMasVeinteMIL;
		*pAuxcontadorModelo = auxcontadorModelo;
		retorno = VERDADERO;
	}
	return retorno;
}

