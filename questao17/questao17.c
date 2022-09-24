#include <stdio.h>
#include <stdlib.h>

void pega_elementos(int * elements, int size) {
  printf("\n");
  for (int i = 0; i < size; i++) {
    printf("Digite o valor do %i° elemento: ", i+1); 
    scanf("%d", &elements[i]);
  }
}

void soma(int *v_x, int *v_y, int *v_soma, int size){
  int i;
  for(int i = 0; i<size; i++){
    v_soma[i] = v_x[i] + v_y[i];
    printf("%d + %d = %d\n", v_x[i], v_y[i], v_x[i] + v_y[i]);
  }
}

void exibe_elementos(int *elements, int size){
  printf("[");
  for (int i = 0; i < size; i++) {
    if(i < size-1){
      printf("%d, ", elements[i]);
    }else{
      printf("%d]\n", elements[i]);
    }
  }
}

int main() {
  int *v_x, *v_y, *v_soma;
  int size;
  printf("\nQuantos elementos deseja somar? ");
  scanf("%d", &size);

  v_x = malloc(size * sizeof(int));
  v_y = malloc(size * sizeof(int));
  v_soma = malloc(size * sizeof(int));
  if (v_x == NULL || v_y == NULL || v_soma == NULL) {
    printf("\nErro de alocacao.\n");
    return 1;
  }

  printf("Para o vetor X:\n");
  pega_elementos(v_x, size);
  printf("=> Vetor X: ");
  exibe_elementos(v_x, size);

  printf("\nPara o vetor Y:");
  pega_elementos(v_y, size);
  printf("=> Vetor Y: ");
  exibe_elementos(v_y, size);

  soma(v_x, v_y, v_soma, size);
  printf("\nO vetor resultante: ", size);
  exibe_elementos(v_soma, size);

  free(v_x);
  free(v_y);
  free(v_soma);

  return 0;
}