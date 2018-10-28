#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>


const char * LerVoz()
{
	FILE *f; 
	int erro = 0;
	char text[130], cmp[130];
	static char  trat[8];
		
	f = fopen("/var/log/syslog","r");		//ABRE O SYSLOG
	fseek(f, -130, SEEK_END);				//COLOCA O CURSOR DE LEITURA NO FINAL DO ARQUIVO E VOLTA 130 POSIÇÕES
		
	fgets(text, 130, f);					//COPIA OS 130 ULTIMOS CARACTERES
	
	fclose(f);
	if(strcmp(text,cmp) == 0)				//COMPARA PRA N EXCUTAR ORDENS REPETIDAS
		return "semorde";
		
	strcpy(cmp,text);
	strcpy(trat, &text[122]);				//PEGA SÓ A PARTE DA ORDEM DO STRING
	
	
	if(strcmp(trat,"proximo") == 0)			//RETORNA APENAS A INFORMAÇÃO DESEJADA
		return trat;
	if(strcmp(trat,"voltaaa") == 0)
		return trat;
	if(strcmp(trat,"repetee") == 0)
		return trat;
	if(strcmp(trat,"ler1234") == 0)
		return trat;
	if(strcmp(trat,"para123") == 0)
		return trat;
	else
		return "semorde";					//IGNORA POSSIVEIS MENSAGENS NO SYSLOG

}


int main()
{
	char ordem[8];
	while(1)
	{
		strcpy(ordem,LerVoz());				// GUARDA A ORDEM EM UM VETOR DENOTRO DA MAIN
		printf("%s\n", ordem);
		sleep(5);
	}
	
	return 0;
}
