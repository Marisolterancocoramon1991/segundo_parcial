/*
 * mostrar.c
 *
 *  Created on: 20 nov 2022
 *      Author: kervi
 */
#include <stdio.h>

/// @brief muestra el menu principal
///
void menuPrincipal() {

	printf(
			"\n\n"
					"\t\t\t\t\t\t==================================================================*\n"
					"\t\t\t\t\t\t|\t\t\t   MENU PRINCIPAL                         |\n"
					"\t\t\t\t\t\t==================================================================*\n"
					"\t\t\t\t\t\t|1. Cargar los datos  del archivo data.csv (modo texto)           |\n"
					"\t\t\t\t\t\t|2. Cargar los datos de archivo data.bin (modo binario)           |\n"
					"\t\t\t\t\t\t|3. Alta de Venta                                                 |\n"
					"\t\t\t\t\t\t|4. Baja de Venta                                                 |\n"
					"\t\t\t\t\t\t|5. Modificar venta                                               |\n"
					"\t\t\t\t\t\t|6. informe de Venta y crear archivo (informes.txt)               |\n"
					"\t\t\t\t\t\t|7. Cargar los datos de archivo data.bin (modo binario)           |\n"
					"\t\t\t\t\t\t|8. Guardar los datos  del archivo data.csv (modo texto)          |\n"
					"\t\t\t\t\t\t|9. Salir                                                         |\n"
					"\t\t\t\t\t\t==================================================================*\n");

}

/// @brief avisa que la carga fu exitosa
///

void avisoCargaExitosLista() {

	printf(
			"\t\t\t\t\t\t==================================================================*\n"
					"\t\t\t\t\t\t|\t\t\tSe ha cargado exitosamente                |\n"
					"\t\t\t\t\t\t==================================================================*\n");

}


/// @brief printe al menu de opciones de modelo
///
void opcionesModeloAuto() {
	printf("\t\t\t|============================|\n"
			"\t\t\t|Opciones de Modelo de autos |\n"
			"\t\t\t|============================|\n"
			"\t\t\t|1)Blazer                    |\n"
			"\t\t\t|2)Accord                    |\n"
			"\t\t\t|3)Avalon                    |\n"
			"\t\t\t|4)Odyssey                   |\n"
			"\t\t\t|5)Vanquish                  |\n"
			"\t\t\t|6)Continental GT            |\n"
			"\t\t\t|7)Mulsanne                  |\n"
			"\t\t\t|8)Bentayga                  |\n"
			"\t\t\t|9)Cruze                     |\n"
			"\t\t\t|10)Aveo                     |\n"
			"\t\t\t|11)Trax                     |\n"
			"\t\t\t|12)Orlando                  |\n"
			"\t\t\t|13)Spark                    |\n"
			"\t\t\t|14)Camaro                   |\n"
			"\t\t\t|15)Nemo                     |\n"
			"\t\t\t|16)Berlingo                 |\n"
			"\t\t\t|17)Logan                    |\n"
			"\t\t\t|18)Sandero                  |\n"
			"\t\t\t|19)Duster                   |\n"
			"\t\t\t|20)Dokker                   |\n"
			"\t\t\t|21)California               |\n"
			"\t\t\t|22)Portofino                |\n"
			"\t\t\t|23)Freemont                 |\n"
			"\t\t\t|24)Panda                    |\n"
			"\t\t\t|25)Punto                    |\n"
			"\t\t\t|26)Fiorino                  |\n"
			"\t\t\t|27)EcoSport                 |\n"
			"\t\t\t|28)Mustang                  |\n"
			"\t\t\t|29)Transit Connect          |\n"
			"\t\t\t|30)Edge                     |\n"
			"\t\t\t|============================|\n");
}

/// @brief cabecera para modificar
///

void cabeceraVentaAModificar() {
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
			"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
			"+-+-+-+-++-+-+-+-+-+-+-+-+-+-"
			"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"
			"                     "
			"                 VENTA  A MODIFICAR\n"
			"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"
			"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
			"+-+-+-++-+-+-+-+-+-+-+-+-+-+"
			"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"
			"ID           FECHA            AUTO         "
			"     CANTIDAD              PRECIO UNITARIO        "
			"TARJETA CREDITO\n");

}


/// @brief cabercera para remover
///

void cabeceraVentaARemover() {
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
			"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
			"+-+-+-+-++-+-+-+-+-+-+-+-+-+-"
			"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"
			"                     "
			"                 VENTA  A REMOVER\n"
			"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"
			"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
			"+-+-+-++-+-+-+-+-+-+-+-+-+-+"
			"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"
			"ID           FECHA            AUTO         "
			"     CANTIDAD              PRECIO UNITARIO        "
			"TARJETA CREDITO\n");

}


/// @brief menu de opciones para modificar
///

void menuModificacion() {
	printf("\n\n\n");
	printf("\t\t\t|--------------------------------------------|\n"
			"\t\t\t|          MENU DE MODIFICACIONES            |\n"
			"\t\t\t|--------------------------------------------|\n"
			"\t\t\t|1) Modificar el fecha                       |\n"
			"\t\t\t|2) Modificar la modelo                      |\n"
			"\t\t\t|3) Modificar cantdad                        |\n"
			"\t\t\t|4) Modificar precio unitario                 |\n"
			"\t\t\t=============================================*\n");
}





