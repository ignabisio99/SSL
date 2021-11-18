#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	#define Q0 0
	#define Q1 1
	#define Q2 2

	char caracter;
	char matriz[3][2] = {
							{1,2}, //q0
							{1,2}, //q1
							{2,2}, //q2
						};
						
	int estado=Q0;
	int resultado = 0;
    char operador;

	int posCol (char);
	void cargarArchivo(int);
    int noEsOperador(char);
    void operar(char*);

int main()
{

	FILE *f = fopen("calculadora.txt", "r");
	FILE *e = fopen("salida.txt", "w");
	if (f == NULL)
	{
		puts("No se pudo leer el archivo de entrada");
	}

    char* numero_actual = strdup("");
    int flag = 1;
	while (!feof(f))
	{
		do {
			caracter = fgetc(f);
			if (estado != Q2 && !feof(f))
			{
				switch (estado)
				{
					case Q0:
					case Q1:
						estado = matriz[estado][posCol(caracter)];
						break;
					default:
						estado = Q2;
						break;
				}
			}


        if (noEsOperador(caracter))
            strncat(numero_actual,&caracter,strlen(numero_actual)+1);

		} while (noEsOperador(caracter) && !feof(f));
        estado = 0;

        if(flag){
            resultado = atoi(numero_actual);
            operador = caracter;   
            flag = 0;

        } else {
            operar(numero_actual);
            operador = caracter;
        }
        free(numero_actual);
        numero_actual=strdup("");

	}
    printf("%d resultado \n",resultado);
	return 0;
}

int posCol(char numero)
{
	switch (numero)
	{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
        return 0;

		default:
        return 1;

	}
}

void cargarArchivo(int estado)
{
	switch (estado)
	{
		case 1:;
            puts("Decimal");
            break;
		case 2:;
			printf("No reconocida\n");
            break;
	}
}

int noEsOperador(char caracter){
    return (caracter != '+' && caracter != '-' && caracter != '*');
}

void operar(char* numero_actual){
    int operando = atoi(numero_actual);
    switch (operador)
    {
    case '+':;
        resultado += operando;
        break;
    case '-':;
        resultado -= operando;
        break;
    case '*':;
        resultado *= operando;
        break;
    }

}