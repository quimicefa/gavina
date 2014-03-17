#include "CP437.h"

/*
 * Funcion getChar
 * Se usa para leer un caracter y evaluar su condicion
 * Recibe un *File y un contador de bytes por referencia
 * Devuelve el char en unicode
*/


/*int getChar (FILE** fichero,long* tc)
{
	int c=0;
	int k=0;
	long iMark=0;
	
	iMark=fmod((*tc-256),128);
    if(iMark==0)
    {
    	for (k=0;k<7;k++) 
    	{
			getc(*fichero); 
			*tc++;
		}
     
    }
    c=getc(*fichero);
    c=getUnicode(c); // realiza la conversion a Unicode
	*tc++;
	//return (c);

}*/

/*
 * Funcion getUnicode
 * Se usa para codificar a Unicode
 * Recibe un char en formato int
 * Devuelve el char en unicode
*/

int getUnicode( int ic)
{   
 	int iReUTF=ic;
	int i=0;
	for(i=0; cp437[i].ch437<0xff; i++)
    	{
	      if(cp437[i].ch437==ic)
    	  {
           	iReUTF=cp437[i].chUTF;
            break;
    	  }
      }
    return (iReUTF);  
}

/*
 * Funcion getFieldCode
 * Se usa para codificar las etiquetas mq a xml
 * Recibe un array de char
 * Devuelve un entero especificando el numero de etiqueta
*/

int getFieldCode ( char cEtiqueta[SIZE_STRUCT])
{   
	
	int iCodigo=-1;
	int i=0;
             
    for(i=0; lista_de_codigos[i].cFieldCode!=NULL; i++)
    {
		if(strcmp(cEtiqueta, lista_de_codigos[i].cFieldCode)==0)
    	{
           	iCodigo=lista_de_codigos[i].id;
            break;
    	}
    }  
    return (iCodigo);  
}

