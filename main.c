#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAMANHO 20

void name_arq_saida (char arq1[], char arq_saida[])
{
    char str[] = {".merge"};
    int i;
    for ( i = 0; i < TAMANHO; i++ ) {       
        if (arq1[i] == '.') {
            arq_saida[i] = '\0';
            break;
        }
        else{ arq_saida[i] = arq1[i]; }       
    }
    strcat (arq_saida, str);
}

int main( int argc, char*arg[] ){

    char name_a1[TAMANHO], name_a2[TAMANHO], name_saida[TAMANHO];
    long long int b1, b2;
    long long int *binario1 = &b1;
    long long int *binario2 = &b2;
    int l1 = 1, l2 = 1, x = 0, y = 0;
    char *palavra1, *palavra2;

    scanf("%s \n%s", name_a1, name_a2);
    name_arq_saida(name_a1, name_saida);
    FILE *arq1 = fopen(name_a1, "rb");
    FILE *arq2 = fopen(name_a2, "rb");
    FILE *arq_saida = fopen(name_saida, "wb");

    do{
        if(l1 == 1 && x == 0){
            l1 = fread(binario1, sizeof(long long int), 1, arq1);
            if(l1 == 1){
                palavra1 = malloc( (sizeof(char) * (*binario1)) +1);
                fread(palavra1, sizeof(char), *binario1, arq1);
                palavra1[(*binario1)] = '\0';
                x = 1;
            }
        }
        if(l2 == 1 && y == 0){
            l2 = fread(binario2, sizeof(long long int), 1, arq2);
            if(l2 == 1){
                palavra2 = malloc( (sizeof(char) * (*binario2)) +1);
                fread(palavra2, sizeof(char), *binario2, arq2);
                palavra2[(*binario2)] = '\0';
                y = 1;
            }
        }

        if(x == 1 && y == 0){
            fwrite(binario1, sizeof(long long int), 1, arq_saida);
            fwrite(palavra1, sizeof(char), (*binario1), arq_saida);
            free(palavra1);
            x = 0;
        }else
        if(x == 0 && y == 1){
            fwrite(binario2, sizeof(long long int), 1, arq_saida);
            fwrite(palavra2, sizeof(char), (*binario2), arq_saida);
            free(palavra2);
            y = 0;
        }else
        if(x == 1 && y == 1){
            if( strcmp(palavra1,palavra2) < 0 ){
                fwrite(binario1, sizeof(long long int), 1, arq_saida);
                fwrite(palavra1, sizeof(char), *binario1, arq_saida);
                free(palavra1);
                x = 0;
            }
            else{
                fwrite(binario2, sizeof(long long int), 1, arq_saida);
                fwrite(palavra2, sizeof(char), *binario2, arq_saida);
                free(palavra2);
                y = 0;
            }
        }
    }while(l1 != 0 || l2 != 0);

    fclose(arq1);
    fclose(arq2);
    fclose(arq_saida);

    int condicao;
    long long int bn, *binario = &bn;
    char *palavra;
    FILE *arquivo = fopen(name_saida, "rb");
    do{
        condicao = fread(binario, sizeof(long long int), 1, arquivo);
        if(condicao != 0){
            palavra = malloc( (sizeof(char) * (*binario)) +1);
            fread(palavra, sizeof(char), *binario, arquivo);
            palavra[(*binario)] = '\0';
            printf("%s\n", palavra);
            free(palavra);
        }
    } while( condicao != 0);
    fclose(arquivo);

    return 0;
}