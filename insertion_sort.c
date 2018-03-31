#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM_VETOR 99999

void printVector(int *vetor){
  int i;
  for(i = 0 ; i < TAM_VETOR ; i++){
    printf("%d ", vetor[i]);
  }
}

void printEnd(double time, int *vetor){
  char option;
  printf("Imprimir vetor? (y/n)");
  scanf("%c", &option);
  if (option == 'y'){
    printVector(vetor);
    printf("\n");
  }
  printf("Tempo gasto: %lf\n", time);
}

void printBegin(int *vetor){
  char option;
  printf("Imprimir vetor? (y/n)");
  scanf("%c", &option);
  if (option == 'y'){
    printVector(vetor);
    printf("\n\n\n");
  }
}

int main(){
  int vetor[TAM_VETOR];
  int i, j, temp, indexMin;
  for(i = 0 ; i < TAM_VETOR ; i++){
    vetor[i] = rand() % 1000;
  }

  printBegin(vetor);
  getchar();
  printf("Aperte Enter");
  getchar();

//comeca a contar tempo
  clock_t begin = clock();

//algoritmo
  for(i = 1 ; i < TAM_VETOR ; i++){
    j = i;
    while((j != 0) && (vetor[j] < vetor[j-1])){
      temp = vetor[j];
      vetor[j] = vetor[j-1];
      vetor[j-1] = temp;
      j--;
    }
  }
//fim algoritmo

  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//fim contar tempo

  printEnd(time_spent, vetor);
  return 0;
}
