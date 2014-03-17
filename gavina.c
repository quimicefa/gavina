
/* 
 * 
 * Il Club del Azufre, 03 
 * Gavina de Sinera, V.02
 * Nombre Clave : Il Zombie de Sinera 
 * 
 * Descreditos : xxxxxxxxxxxxxxxxxxxxxx
 * 
 */

#include <stdio.h>
#include <string.h>
//#include <math.h>
#include "struct.h"
#include "funciones.h"
#include "constantes.h"



//nombre de los ficheros de entrada y salida

char fnEntrada[255];
char fnSalida[255];

int    c;

int doProcesarIO() 
{
    // Contadores
    int     i=0;
    int 	iEtiqueta=0;
    FILE 	*fiEntrada;
    FILE	*fiSalida;

    char        etiqueta[100];

    enum idField     codigo;


// Abrir ficheros de Entrada y de Salida
// * hay que preparalo para leer los nombres de la consola *

    printf ("Abriendo Archivos...\n");
    fiEntrada = fopen(fnEntrada, "r+b"); 
	if ( fiEntrada == NULL ) {
		printf(ERROR_ENTRADA);
		exit(EXIT_FAILURE);
		}
	else {
		printf(SUCCESS_ENTRADA);
		}

    fiSalida  = fopen(fnSalida, "w+b");
	if ( fiSalida == NULL ) {
		printf(ERROR_SALIDA);
		exit(EXIT_FAILURE);
		}
	else {
		printf(SUCCESS_SALIDA);
		}

// Escribir cabecera XML
	
	fprintf(fiSalida, "<?xml version='1.0' encoding='UTF-16' ?>  \n");

// Procesar archivo mientras haya cosas por leer
    
long j=0;
long iNumFicha=0;
long contador_de_vueltas=0;
int esvalido=0;
int esvalido2=fNULL;
char registro[SIZE_STRUCT];
char registro_anterior[SIZE_STRUCT];
long k;

//char basura[100];
long iMark=0;   
 while(c!=EOF)
        {
        	
        //c=getChar(&fiEntrada,&j);	
		
			iMark=(j-256) % 128;
    if(iMark==0)
    {
    	for (k=0;k<7;k++) 
    	{
			getc(fiEntrada); 
			j++;
		}
     
    }
    c=getc(fiEntrada);
//    c=getUnicode(c); // realiza la conversion a Unicode
	j++;
			
		if (c=='#') 
			{
//			c=getUnicode(c);
			registro[0]=c;
			for (k=1;k<SIZE_STRUCT;k++) {
				
			iMark= (j-256) % 128;
        	if (iMark==0){
        		for (k=0;k<7;k++) {
					getc(fiEntrada); 
					j++;
					}
        		//fprintf (fiSalida,"< MARK >");
        	}

				c=getc(fiEntrada);
				j++;
				
				registro[k]=c;
			
				}
			
			// amigo lector: en este punto del bucle
			// tenemos el posible campo en "registro"
			esvalido=getFieldCode(registro);
			
			// si es valido ...
			
	
			if (esvalido != CAMPO_INVALIDO ) {	
				
				if (esvalido2!=fNULL){
				
					fprintf(fiSalida, "%s \n",lista_de_codigos[esvalido2].XMLEnd);
									
				}
				
				esvalido2=esvalido;
							
				switch (esvalido)
                {
                    case fDAS:

						// Escribir el Tag de Ficha
                    	
    					if (iNumFicha!=0){
    					fprintf(fiSalida,"</Ficha%d>\n",iNumFicha);
    					}
    					iNumFicha++;
    					
    					fprintf(fiSalida,"\t<Ficha%d>\n",iNumFicha);
    
    					fprintf(fiSalida, "\t\t%s", lista_de_codigos[esvalido].XMLStart);
    
                    	for (k=0;k<26;k++) {
							c=getc(fiEntrada); 
							j++;
//c=getUnicode(c); 
// realiza la conversion a Unicode
							putc(c,fiSalida);
						}
                	
   						break;	
   					
   						             
                	default :
                	
	                	fprintf(fiSalida, "\t\t%s", lista_de_codigos[esvalido].XMLStart);	
                }
		
			}
		
	// si es invalido
			}else {
		// SUSTITUCION de <> por []
		if (c=='<') { 
			putc('[',fiSalida);
			}
		else if (c=='>') {
			putc(']',fiSalida);
			}
		else {
			// Asi saltamos la cabecera fea
			if (iNumFicha!=0){
			putc(c,fiSalida);
			}
		}
	}  
	
	//contador_de_vueltas++;
        }  
	printf("%d bytes leidos\n",j);
	printf("%d registros leidos\n",iNumFicha);
    
// Cerrar Archivos one time ready
    
    fclose(fiSalida);
    printf("Archivo de Salida cerrado correctamente\n");
    fclose(fiEntrada);
    printf("Archivo de Entrada cerrado correctamente\n");
    
    return EXIT_SUCCESS;
}



void uso() {
	printf("-------------------------------\n");
	printf("Version: %s\n",VERSION);
	printf("Autores: %s\n",AUTOR);
	printf("Uso:\n");
	printf(" gavina entrada.rnd salida.xml\n");
	printf("-------------------------------\n");
	}


int main(int argc, char *argv[]) {

// cuenta el numero de parametros

if (argc!=3) {
	// si no son 2, SI, he dicho 2 , sacara la "ayuda"
	uso();
	}
else {
	// si son 2, se los copia a una var global ... y las pasa 
	// a las demas funciones.
	strcpy(fnEntrada,argv[1]);
	strcpy(fnSalida,argv[2]);
	doProcesarIO(); //<--esta funcion ... cuidao!
	}
}
