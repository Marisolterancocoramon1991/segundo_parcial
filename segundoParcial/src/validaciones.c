/*
 * validaciones.c
 *
 *  Created on: 24 oct 2022
 *      Author: kervi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// @brief Compara desde la tabla ascii si lo ingresado por
/// el usuario son letras y sin espacio para determinar que es una palabra sola
/// @param arraysNombre recibe una matriz
/// @return retorna uno en caso de de verdadero y retorna menos uno en caso de falso
int esStringNombre(char arraysNombre[]) {
	int retorno = 0;
	int i;
	if (arraysNombre != NULL) {
		for (i = 0; i < strlen(arraysNombre); i++) {

			if (!(isalpha(arraysNombre[i]) != 0)) {
				retorno = -1;
				break;

			} else {
				retorno = 1;
			}
		}

	}

	return retorno;
}
/// @brief compara desde la tabla ascii si lo ingresado por
/// el usuario son letras y ademas si hay espacio
/// @param arraysNombre
/// @return retorna uno en caso de de verdadero y retorna menos uno en caso de falso
int esString(char arraysNombre[]) {
	int retorno = 0;
	int i;
	if (arraysNombre != NULL) {
		for (i = 0; i < strlen(arraysNombre); i++) {

			if (!(isalpha(arraysNombre[i]) != 0 || isspace(arraysNombre[i]) != 0)) {
				retorno = -1;
				break;

			} else {
				retorno = 1;
			}
		}

	}

	return retorno;
}

/// @brief imprime un mensaje e ingresa los caracteres que el usuario desea
/// convierte lo ingresado en mayuscula
/// @param arraysNombre la matriz trabajar
/// @param len longitud del array.
/// @param mensaje lo que se quiere transmitir al usuario.
/// @param mensajeError lo que se quiere transmitir al usuario en caso de error.
/// @param repeticiones numero de repeticiones permitidas.
/// @return retorna uno en caso de de verdadero y retorna menos uno en caso de falso.
int validarStringNombre_UTN(char arraysNombre[], int len, char mensaje[],
		char mensajeError[], int repeticiones) {
	int retorno = 0;
	int i;

	if (arraysNombre != NULL && mensaje != NULL && len > 0
			&& repeticiones > 0) {
		do {
			printf("%s", mensaje);
			fflush(stdin);
			fgets(arraysNombre, len, stdin);
			arraysNombre[strlen(arraysNombre) - 1] = '\n';
			arraysNombre[strlen(arraysNombre) - 1] = '\0';

			if (esStringNombre(arraysNombre) == 1) {

				for (i = 0; i < len; i++) {
					arraysNombre[i] = toupper(arraysNombre[i]); //ctype.h
					repeticiones = -1;
					retorno = 1;

				}

			} else if (esString(arraysNombre) == -1) {
				repeticiones--;
				printf("%s", mensajeError);
				printf("numero de intentos %d \n", repeticiones);
			}

		} while (repeticiones > 0);
	}
	if (repeticiones == 0) {
		retorno = -1;
	}

	return retorno;
}
/// @brief imprime un mensaje e ingresa los caracteres que el usuario desea
/// convierte lo ingresado en mayuscula
/// @param arraysNombre la matriz trabajar
/// @param len longitud del array.
/// @param mensaje lo que se quiere transmitir al usuario.
/// @param mensajeError lo que se quiere transmitir al usuario en caso de error.
/// @param repeticiones numero de repeticiones permitidas.
/// @return retorna uno en caso de de verdadero y retorna menos uno en caso de falso.
int validarString_UTN(char arraysNombre[], int len, char mensaje[],
		char mensajeError[], int repeticiones) {
	int retorno = 0;
	int i;
	do {
		if (arraysNombre != NULL && mensaje != NULL && len > 0
				&& repeticiones > 0) {
			printf("%s", mensaje);
			fflush(stdin);
			fgets(arraysNombre, len, stdin);
			arraysNombre[strlen(arraysNombre) - 1] = '\n';
			arraysNombre[strlen(arraysNombre) - 1] = '\0';

			if (esString(arraysNombre) == 1) {

				for (i = 0; i < len; i++) {
					arraysNombre[i] = toupper(arraysNombre[i]); //ctype.h

					repeticiones = -1;
				}
				retorno = 1;
			} else if (esString(arraysNombre) == -1) {
				repeticiones--;
				printf("%s", mensajeError);
				printf("numero de intentos %d \n", repeticiones);

			}

		}

	} while (repeticiones > 0);
	if (repeticiones == 0) {
		retorno = -1;
	}
	return retorno;
}

/// @brief busca si lo ingresado es un numero entero
/// @param valorReemplazoResultado es un puntero a char
/// @return retorna uno si para caso de verdadero y ceero en el caso de falso
int esNumero(char *valorReemplazoResultado) {
	int i = 0;
	int retorno = 1;
	if (valorReemplazoResultado != NULL) {
		while (valorReemplazoResultado[i] != '\0') {
			if (valorReemplazoResultado[i] < '0'
					|| valorReemplazoResultado[i] > '9') {

				retorno = 0;
				break;
			}
			i++;
		}

	}

	return retorno;
}

/// @brief busca si lo ingresado es un numero flotante
/// @param valorReemplazoResultado es un puntero a char
/// @return retorna uno si para caso de verdadero y ceero en el caso de falso
int esNumeroflotante(char *valorReemplazoResultado) {
	int i = 0;
	int retorno = 1;
	if (valorReemplazoResultado != NULL) {
		while (valorReemplazoResultado[i] != '\0') {
			if ((valorReemplazoResultado[i] < '0'
					|| valorReemplazoResultado[i] > '9')
					&& (valorReemplazoResultado[i] != '.')) {

				retorno = 0;
				break;

			}
			i++;
		}

	}

	return retorno;
}
/// @brief recoge el numero y en caso de ser cierto lo convierte en flotante
/// @param resultado es un puntero a flotante
/// @return  retorna uno si para caso de verdadero y ceero en el caso de falso
int recogerNumeroflotante(float *resultado) {
	int retorno = 0;
	char valorReemplazo[500];

	fflush(stdin);
	fgets(valorReemplazo, sizeof(valorReemplazo), stdin);
	valorReemplazo[strlen(valorReemplazo) - 1] = '\n';
	valorReemplazo[strlen(valorReemplazo) - 1] = '\0';

	int retornoEsNumero = esNumeroflotante(valorReemplazo);

	if (retornoEsNumero == 1) {
		*resultado = atof(valorReemplazo);
		retorno = 1;
	}
	return retorno;
}

/// @brief recoge el numero y en caso de ser cierto lo convierte en entero
/// @param resultado resultado es un puntero a entero
/// @return retorna uno si para caso de verdadero y cero en el caso de falso

int recogerNumero(int *resultado) {
	int retorno = 0;
	char valorReemplazo[500];
	int retornoEsNumero;

	fflush(stdin);
	fgets(valorReemplazo, sizeof(valorReemplazo), stdin);
	valorReemplazo[strlen(valorReemplazo) - 1] = '\n';
	valorReemplazo[strlen(valorReemplazo) - 1] = '\0';
	retornoEsNumero = esNumero(valorReemplazo);
	if (retornoEsNumero == 1) {
		*resultado = atoi(valorReemplazo);
		retorno = 1;
	}
	return retorno;
}
/// @brief llama a las demas funciones para converitir una
/// cadena de caracteres en numero entero
/// @param resultado es un puntero a entero
/// @param mensaje es una cadena de caracteres
/// @param mensajeFalla cadena de caracter por si tiene algun error
/// @param numeroMinimo se pide en la funcion numero minimo
/// @param numeroMaximo se pide tambien el numero maximo
/// @param repeticiones aqui se pone la cantidad de repetciones que le queda al usuario
/// @return retorna uno si para caso de verdadero y menos uno en el caso de falso
int get_UTN_ValidacionNumero(int *resultado, char mensaje[],
		char mensajeFalla[], int numeroMinimo, int numeroMaximo,
		int repeticiones) {
	int valorReemplazo;
	int retorno = 0;

	if (resultado != NULL && mensaje != NULL && mensajeFalla != NULL
			&& numeroMinimo <= numeroMaximo && repeticiones >= 0) {

		while (repeticiones > 0) {
			printf("%s", mensaje);
			if (recogerNumero(&valorReemplazo) == 1) {

				if (valorReemplazo >= numeroMinimo
						&& valorReemplazo <= numeroMaximo) {

					repeticiones = -1;

				} else {
					printf("%s. numero de intentos %d \n", mensajeFalla,
							repeticiones);
					repeticiones--;
				}

			}

		}
		if (repeticiones == 0) {
			retorno = -1;
		} else {
			retorno = 1;
			*resultado = valorReemplazo;
		}
	}

	return retorno;
}
/// @brief llama a las demas funciones para convertir una
/// cadena de caracteres en numero flotante
/// @param resultado es un puntero a entero
/// @param mensaje es una cadena de caracteres
/// @param mensajeFalla cadena de caracter por si tiene algun error
/// @param numeroMinimo se pide en la funcion numero minimo
/// @param numeroMaximo se pide tambien el numero maximo
/// @param repeticiones aqui se pone la cantidad de repeticiones que le queda al usuario
/// @return retorna uno si para caso de verdadero y menos uno en el caso de falso
int get_UTN_ValidacionNumeroflotante(float *resultado, char mensaje[],
		char mensajeFalla[], int numeroMinimo, int numeroMaximo,
		int repeticiones) {
	float valorReemplazo;
	int retorno = 0;

	if (resultado != NULL && mensaje != NULL && mensajeFalla != NULL
			&& numeroMinimo <= numeroMaximo && repeticiones >= 0) {

		while (repeticiones > 0) {
			printf("%s", mensaje);
			if (recogerNumeroflotante(&valorReemplazo) == 1) {

				if (valorReemplazo >= numeroMinimo
						&& valorReemplazo <= numeroMaximo) {

					repeticiones = -1;

				} else {
					printf("%s. numero de intentos %d \n", mensajeFalla,
							repeticiones);
					repeticiones--;
				}

			}

		}
		if (repeticiones == 0) {
			retorno = -1;
		} else {
			retorno = 1;
			*resultado = valorReemplazo;
		}
	}

	return retorno;
}

/*
int recogerTarjetaCredito(char *resultado) {
	int retorno = 0;
	char valorReemplazo[5000];

	fflush(stdin);
	fgets(valorReemplazo, sizeof(valorReemplazo), stdin);
	valorReemplazo[strlen(valorReemplazo) - 1] = '\n';
	valorReemplazo[strlen(valorReemplazo) - 1] = '\0';

	int retornoEsNumero = esNumero(valorReemplazo);

	if (retornoEsNumero == 1) {
		strcpy(resultado, valorReemplazo);
		retorno = 1;
	}
	return retorno;
}

int get_TarjetaCredito(char *resultado, char mensaje[], char mensajeFalla[],
		int repeticiones) {
	int retorno = -1;
	if (resultado != NULL && mensaje != NULL && mensajeFalla != NULL
			&& repeticiones >= 0) {
		while (repeticiones > 0) {
			printf("%s", mensaje);
			if (recogerTarjetaCredito(resultado) == 1
					 && strlen(resultado) == 16) {
				repeticiones = -1;
				retorno = 1;

			} else {
				repeticiones--;
				printf("\t\t\t%s", mensajeFalla);
				printf("numero de intentos %d \n", repeticiones);

			}
		}
	} else {
		printf("\t\t\t puede que haya cargado mal la tarjeta de credito\n");

	}

	return retorno;
}

*/


int isValidTarjeta(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9'))
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}
int getStringg(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max+10];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",msg);   //no poner salto de linea, se va a pasar en el mensaje por valor
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)    // tamaño (max) =cantidad de elementos (strlen) + 1(\0)
            {
                strncpy(resultado,bufferStr,max);
                retorno=1;
                break;
            }
            printf("%s 1",msgError);
            (*reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return retorno;
}

int utn_getTrjetaCredito(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
//    maxSize=11; //con puntos
//    minSize=8;  // sin puntos
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(getStringg(msg,msgError,minSize,maxSize,&reintentos,bufferStr)==1 && isValidTarjeta(bufferStr)==1) //==0 sin errores !0
            {
                strncpy(input,bufferStr,maxSize);
                retorno=1;
                break;
            }
            else
            {
                printf("%s 2",msgError);
                reintentos--;
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}



















