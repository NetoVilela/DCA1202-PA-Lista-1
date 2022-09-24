#include <stdio.h>
#include <stdlib.h>

void exibe_numeros(float *numeros, int size){ // Função responsável por exibir os números
  printf("[");
  for (int i = 0; i < size; i++) {
    if(i < size-1){
      printf("%f, ", numeros[i]);
    }else{
      printf("%f]\n", numeros[i]);
    }
  }
}
void ordena_numeros(float *numeros, int size){  // Função que ordenas os numeros no array "numeros"
  // Usados dois laços de repeticao para manter um estado e ir atualizando o outro e comparando
  // Algoritmo bubble sort
  float temp;
  for (int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++){
      if(numeros[i] < numeros[j]){
        temp = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = temp;
      }
    }
  }
}

int compara_numeros(const void * a, const void *b){ // função para comparar dois elementos
  return (*(int*)a - *(int*)b);
}

int main() {
  float * numeros;
  int size;
  printf("\nQuantos elementos deseja ordenar? ");
  scanf("%d", &size);

  numeros = malloc(size * sizeof(float));
  if (numeros == NULL) {
    printf("\nErro de alocacao.\n");
    return 1;
  }
  // Loop responsavel por receber todos os valores até size
  for (int i = 0; i < size; i++) {
    printf("Digite o valor do %i° elemento: ", i+1);
    scanf("%f", &numeros[i]);
  }

  qsort(numeros, size, sizeof(float), compara_numeros);
  printf("Elementos ordenados: ");
  exibe_numeros(numeros, size);

  free(numeros);
}