#include <stdio.h>
#include <string.h>
	typedef enum {
		DECIMAL,
		OCTAL,
		HEXADECIMAL,
		NO_RECO
	} tipos_constantes;

	int constantes[4];
	#define Q0 0
	#define Q1 1
	#define Q2 2
	#define Q3 3
	#define Q4 4
	#define Q5 5
	#define Q6 6
	#define Q7 7
	#define Q8 8
	
	
	char c;
	char matriz[9][7] = {
							{1,3,7,7,8,8,8}, //q0
							{8,8,2,2,8,8,8}, //q1
							{8,2,2,2,8,8,8}, //q2
							{8,5,5,8,4,8,8}, //q3
							{8,6,6,6,8,6,8}, //q4
							{8,5,5,8,8,5,8}, //q5
							{8,6,6,6,8,6,8}, //q6
							{8,8,7,7,8,8,8}, //q7	
							{8,8,8,8,8,8,8}  //q8	
						};
						
	int estado=Q0;
	int contadorDePalabras=0;
	

	int posCol (char);
	void cargarArchivo(int,FILE*);

int main() {
	
	FILE *f = fopen("entrada.txt","r");
	FILE *e = fopen("salida.txt","w");
	puts("Archivo de entrada leido: \n");
	if (f != NULL) {
			while (!feof(f)) {
				do{
					c = fgetc(f);
				if (estado!=Q8 && c!= '&' && !feof(f)) {
					switch (estado){
						
						case Q0:
							estado = matriz[estado][posCol(c)];
							
						break;
						
						case Q1:
							estado = matriz[estado][posCol(c)];
						break;
						
						case Q2:
							estado = matriz[estado][posCol(c)];
						break;
						
						case Q3:
							estado = matriz[estado][posCol(c)];
						break;	
						
						case Q4:
							estado = matriz[estado][posCol(c)];
						break;
						
						case Q5:
							estado = matriz[estado][posCol(c)];
						break;

						case Q6:
							estado = matriz[estado][posCol(c)];
						break;

						case Q7:
							estado = matriz[estado][posCol(c)];
						break;

						default: 
							estado=Q8;
							
						break;
						}
					}
							
					printf("%c",c);
            

				} 	while (c != '&' && !feof(f)) ;
						contadorDePalabras++;
            cargarArchivo(estado,e);
						estado=0;
		}
		puts("\narchivo de salida generado en salida.txt\n");
		printf("_______________________\nSe encontraron %d tokens, %d decimales, %d octales, %d hexadecimales y %d no reconocidas\n",contadorDePalabras,constantes[DECIMAL],constantes[OCTAL],constantes[HEXADECIMAL],constantes[NO_RECO]);

	} else {

		printf("No se pudo leer el archivo de entrada");	
	
	}

	return 0;
}


int posCol (char numero) {
		switch (numero){
			case '+':
			case '-':
			return 0;
			break;

			case '0':
			return 1;
			break;
			
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
				return 2;
			break;
			
			case '8':
			case '9':
				return 3;
			break;
			
			case 'x':
			case 'X':
				return 4;
			break;
			
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
				return 5;
			break;
			
			default:
				return 6;			
		}
	}

  void cargarArchivo(int estado, FILE* archivo) { 
	switch(estado){
		case 1:
			{
      			char str[] = "No reconocida,";
      			fwrite(&str,sizeof(char),sizeof(str),archivo);
				constantes[NO_RECO] ++;  
      		}

		break;
		
		case 2:
			 {
      			char str[] = "Decimal,";
      			fwrite(&str,sizeof(char),sizeof(str),archivo);
				  constantes[DECIMAL] ++;  
      		 }
		break;
		case 3:{
      			char str[] = "Octal,";
      			fwrite(&str,sizeof(char),sizeof(str),archivo);
				  constantes[OCTAL] ++;  
      			}
		break;
	
		case 4:
			    {
      			char str[] = "No reconocida,";
      			fwrite(&str,sizeof(char),sizeof(str),archivo);
				  constantes[NO_RECO] ++;  
				}
      break;
		
		case 5:
      		 	{
      			char str[] = "Octal,";
      			fwrite(&str,sizeof(char),sizeof(str),archivo);
				  constantes[OCTAL] ++;  
      			}
      break;
		
		case 6:                   
		 		{
      			char str[] = "Hexadecimal,";
      			fwrite(&str,sizeof(char),sizeof(str),archivo);
				  constantes[HEXADECIMAL] ++;  
      			}
		break;

		case 7:                   
				{
				char str[] = "Decimal,";
				fwrite(&str,sizeof(char),sizeof(str),archivo);
					constantes[DECIMAL] ++;  
				}
		break;

		case 8:                   
				{
				char str[] = "No reconocido,";
				fwrite(&str,sizeof(char),sizeof(str),archivo);
					constantes[NO_RECO] ++;  
				}
		break;


	}
  }                                       
