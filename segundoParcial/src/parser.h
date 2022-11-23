/*
 * parser.h
 *
 *  Created on: 20 nov 2022
 *      Author: kervi
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_VentaFromText(FILE *pFile, LinkedList *pArrayListJugador);
int parser_VentaFromBinary(FILE *pFile, LinkedList *pArrayListVentas);

#endif /* PARSER_H_ */
