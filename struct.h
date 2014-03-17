#include "constantes.h"

// Enumeracion de Tipos de Campo

enum idField
{
	fDAS, //Timestamp del Microquestel	
    fNU, // Numero identificacion 	text 	obl
    fCR, // Clase de Recurso		text 	obl
    fTI, // Titulo en catalan		text 	obl
    fTO, // Titulo original			text 
    fAU, // Autor					descrp 
    fAF, // Afiliacion				text
    fED, // Editor					descrp
    fTR, // Titulo Revista			descrip
    fDA, // Fecha					descrip
    fLL, // Lenguaje				descrip
    fNS, // Nivel Superior			text
    fNI, // Nivel Inferior 			text
    fCA, // Caracteristicas			text
    fLO, // Localizacion			descrip
    fIA, // Id Administrativa		text
    fDI, // Disponibilitat			text
    fDE, // Descriptores Enfoque	descrip
    fDT, // Descriptores Tematicos	descrip	obl
    fDN, // Desc. Audiencia-Nivel   descrip
    fDC, // Desc. Cronologicos		descrip
    fID, // Identificadores			descrip
    fRE, // Resum					text	obl
    fDD, // Dades Enregistrament	text 	obl
    fNULL,
};

static struct
{
    char   		*cFieldCode;
    enum 		idField id;
    char 		*XMLStart;
    char 		*XMLEnd;
}

lista_de_codigos[]=
{
	{"#/#",      fDAS , "<MRK>", "</MRK>"}, 
    {"#NU",      fNU , "<NU>", "</NU>"}, 
    {"#CR",      fCR , "<CR>"	,	"</CR>"},
    {"#TI",      fTI, "<TI>"	,	"</TI>"},
    {"#TO",      fTO, "<TO>"	,	"</TO>"},
    {"#AU",      fAU, "<AU>"	,	"</AU>"},
    {"#AF",      fAF, "<AF>"	,	"</AF>"},
    {"#ED",      fED, "<ED>"	,	"</ED>"},
    {"#TR",      fTR, "<TR>"	,	"</TR>"},
    {"#DA",      fDA, "<DA>"	,	"</DA>"},
    {"#LL",      fLL, "<LL>"	,	"</LL>"},
    {"#NS",      fNS, "<NS>"	,	"</NS>"},
    {"#NI",      fNI, "<NI>"	,	"</NI>"},
    {"#CA" ,      fCA, "<CA>"	,	"</CA>"},
    {"#LO",      fLO, "<LO>"	,	"</LO>"},
    {"#IA",      fIA, "<IA>"	,	"</IA>"},
    {"#DI",      fDI, "<DI>"	,	"</DI>"},
    {"#DE",      fDE, "<DE>"	,	"</DE>"},
    {"#DT",      fDT, "<DT>"	,	"</DT>"},
    {"#DN",      fDN, "<DN>"	,	"</DN>"},
    {"#DC",      fDC, "<DC>"	,	"</DC>"},
    {"#ID",      fID, "<ID>"	,	"</ID>"},
    {"#RE",      fRE, "<RE>"	,	"</RE>"},
    {"#DD",      fDD , "<DD>", "</DD>"}, 
    {NULL,      fNULL, " ", " "}
};
