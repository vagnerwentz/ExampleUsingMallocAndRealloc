#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()  {
    setlocale(LC_ALL, "Portuguese");

    int *p;
    int i, k, n;
    printf("\nDigite a quantidade de números que serão digitados ->");
    scanf("%d", &i);

    /*
       A função malloc() reserva espaço suficiente para um vetor de inteiros.
       Caso sejam digitados 5 elementos, serão reservados 20 bytes, pois cada
       inteiro ocupa 4 bytes na memória.
    */

    p = (int *)malloc(i * sizeof(int));
    if(p == NULL) {
        printf("\nErro de alocação");
        exit(1);
    }

    for(k = 0; k < i; k++) {
        printf("Digite o número para o índice %d ->", k);
        scanf("%d", &p[k]);
    }

    for(k = 0; k < i; k++) {
        printf("O número do índice [%d] = %d\n", k, p[k]);
    }

    printf("Digite quantos elementos quer adicionar ao vetor ->");
    scanf("%d", &n);

    /*
       A função realloc aumenta ou diminui o tamanho do vetor dinamicamente. Ela recebe o
       ponteiro para o vetor anterior e retorna o novo espaço alocado.
    */
    p = (int *)realloc(p,(i+n) * sizeof(int));

    if(p == NULL) {
        printf("\nErro de realocação");
        exit(1);
    }

    for(k = 0; k < (n+i); k++) {
        printf("Digite o número para o índice %d ->", k);
        scanf("%d", &p[k]);
    }

    for(k = 0; k < (n+i); k++) {
        printf("O número do índice [%d] = %d\n", k, p[k]);
    }

    free(p);
    return 0;
}

/*int *aVetor; // = aVetor[x]
    // x seria o valor que quero alocar
    aVetor[x] == aVetor = (int *)malloc(x * sizeof(int));



    int **bMatriz // = bMatriz[x][y]

    bMatriz = (int **)malloc(2 * sizeof(int)); // x LINHAS
    for(i = 0; i < x; i++) {
        bMatriz = (int **)malloc(y * sizeof(int)); // 3 COLUNAS
    }
    */
