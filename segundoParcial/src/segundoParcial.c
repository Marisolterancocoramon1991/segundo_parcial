/*
 ============================================================================
 Name        : segundoParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "mostrar.h"
#include "validaciones.h"
#include "Controller.h"
#define VERDADERO 1
#define ERROR -1

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int opcionSobreEscribir;
	int idventa;

	int pContadorCantidadUnidad;
	int pContadorMasVentaPrecioMasDiezMIL;
	int pContadorMasVentaPrecioMasVeinteMIL;
	int pAuxcontadorModelo;

	LinkedList *listaVentas = ll_newLinkedList();

	do {
		menuPrincipal();
		if (get_UTN_ValidacionNumero(&opcion, "Elija una opcion del MENU  \n",
				"ERROR, Elija una opcion del MENU DE OPCIONES valida \n", 0, 9,
				10) == VERDADERO) {
			switch (opcion) {
			case 1:
				if (ll_isEmpty(listaVentas) == 0) {
					if (get_UTN_ValidacionNumero(&opcionSobreEscribir,
							" Desea sobre escribir en la lista 1 para seguir y 0 para culminar\n",
							"ERROR, Elija una opcion del MENU DE OPCIONES valida \n",
							0, 1, 10) == VERDADERO
							&& opcionSobreEscribir == 1) {

						ll_clear(listaVentas);

					} else if (opcionSobreEscribir == 0) {
						break;
					}

				}

				if (controller_cargarVentasesDesdeTexto("ventas.csv.TXT",
						listaVentas) == VERDADERO) {
					avisoCargaExitosLista();
				}
//informes

				break;
			case 2:

				if (ll_isEmpty(listaVentas) == 0) {
					if (get_UTN_ValidacionNumero(&opcionSobreEscribir,
							" Desea sobre escribir en la lista 1 para seguir y 0 para culminar\n",
							"ERROR, Elija una opcion del MENU DE OPCIONES valida \n",
							0, 1, 10) == VERDADERO
							&& opcionSobreEscribir == 1) {

						ll_clear(listaVentas);

					} else if (opcionSobreEscribir == 0) {
						break;
					}
				}
				if (controller_CargaFromBinary("data.bin",
						listaVentas)== VERDADERO) {
					avisoCargaExitosLista();
				}

				break;
			case 3:
				if (ll_isEmpty(listaVentas) == 0) {
					if (controller_agregarVenta(listaVentas) == VERDADERO) {
						printf("\t\t\tHas agregado una venta con exito\n"
								"\t\t\t================================\n");

					}

				}
				break;
			case 4:

				if (ll_isEmpty(listaVentas) == 0) {
					if (controller_listarVentas(listaVentas) == VERDADERO) {
						idventa = controller_removerVenta(listaVentas);

						if (idventa != ERROR) {

							printf("\t\t\tExcelente se ha dado de"
									" baja  a la venta exitosamente...\n"
									"\t\t\t============================="
									"================================\n");

						}

					}
				} else {
					printf("\t\t\tNo se han cargado "
							"los archivos en la memoria \n"
							"\t\t\t======================"
							"=====================\n");
				}

				break;
			case 5:
				if (ll_isEmpty(listaVentas) == 0) {
					if (controller_editarVenta(listaVentas) == VERDADERO) {

						printf("\t\t\tExcelente se ha podido"
								" Modificar el jugardor con exito\n");
					}
				}
				break;
			case 6:
				if (ll_isEmpty(listaVentas) == 0) {
					if (informesCalcular(listaVentas, &pContadorCantidadUnidad,
							&pContadorMasVentaPrecioMasDiezMIL,
							&pContadorMasVentaPrecioMasVeinteMIL,
							&pAuxcontadorModelo) == VERDADERO
							&& controller_EscribirInformes("informes.txt",
									pContadorCantidadUnidad,
									pContadorMasVentaPrecioMasDiezMIL,
									pContadorMasVentaPrecioMasVeinteMIL,
									pAuxcontadorModelo) == VERDADERO) {
						printf("pudo cargar el archivo\n");
					}
				}
				break;
			case 7:
				if (ll_isEmpty(listaVentas) == 0) {

					if (controller_guardarVentasModoTexto("ventas.csv.TXT",
							listaVentas) == VERDADERO) {

						printf("Excelente se ha ingresado los elementos a"
								" al archivo de texto...\n");

					} else {
						printf("no se ha podido guardar los "
								"datos en los archivos\n");
					}

				}

				if (ll_isEmpty(listaVentas) == 0) {

				}
				break;
			case 8:
				if (ll_isEmpty(listaVentas) == 0) {
					if (controller_saveAsBinary("data.bin",
							listaVentas)==VERDADERO) {
						printf("Guardado en modo binario con exito!!!\n");

					} else {
						printf(
								"Primero debe cargar algun empleado para poder guardarlo\n");
					}
				}
				break;

			}

		}

	} while (opcion != 9);

	ll_clear(listaVentas);
	ll_deleteLinkedList(listaVentas);
	printf("Usted ha salido del programa... \n");

	return EXIT_SUCCESS;
}

