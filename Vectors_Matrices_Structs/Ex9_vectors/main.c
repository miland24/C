#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 50

void concatenarFrase(); //Fun��o para retirar os espa�os das frases.

void concatenarFrase(char v1[]) {

    for (int i = 0, controle = 0; i < TAM; i++, controle++) {
        if (v1[controle] == 32)
            controle++;

        v1[i] = v1[controle];
    }
}

int main()
{
    setlocale(LC_ALL, "");
    char frase[TAM] = "Esse boneco � retardado";

   printf("Palavra original: %s\n", frase);
   concatenarFrase(frase);
   printf("\nPalavra sem os espa�os em branco: %s\n", frase);
}




