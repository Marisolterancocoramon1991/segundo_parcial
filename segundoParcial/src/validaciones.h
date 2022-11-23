/*
 * validaciones.h
 *
 *  Created on: 24 oct 2022
 *      Author: kervi
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int esNumero(char *valorReemplazoResultado);
int esNumeroflotante(char *valorReemplazoResultado);
int recogerNumeroflotante(float *resultado);
int recogerNumero(int *resultado);
int get_UTN_ValidacionNumero(int *resultado, char mensaje[],
		char mensajeFalla[], int numeroMinimo, int numeroMaximo,
		int repeticiones);
int get_UTN_ValidacionNumeroflotante(float *resultado, char mensaje[],
		char mensajeFalla[], int numeroMinimo, int numeroMaximo,
		int repeticiones);
int esString(char arraysNombre[]);
int validarString_UTN(char arraysNombre[], int len, char mensaje[],
		char mensajeError[], int repeticiones);
int validarStringNombre_UTN(char arraysNombre[], int len, char mensaje[],
		char mensajeError[], int repeticiones);
int esStringNombre(char arraysNombre[]);
/*
int get_TarjetaCredito(char resultado[], char mensaje[], char mensajeFalla[],
		int repeticiones);
int recogerTarjetaCredito(char *resultado);*/
int utn_getTrjetaCredito(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int getStringg(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);
int isValidTarjeta(char* stringRecibido);
#endif /* VALIDACIONES_H_ */
