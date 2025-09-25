#include <stdio.h>
#include <stdlib.h>

float media(float *v, int n) {
    float soma = 0;
    float media;

    for (int i = 0; i < n; i++)
        soma += v[i];

    media = soma / n;
    return media;
}

int main(void) {
    float *v;
    float med = 0.0;
    int i, n;

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &n);

    v = (float *) malloc(n * sizeof(float));

    for(i = 0; i < n; i++)
        scanf("%f", &v[i]);

    med = media(v, n);

    printf("media = %f", med);
    free(v);

    return 0;
}
