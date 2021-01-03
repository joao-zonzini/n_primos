#include <stdlib.h>
#include <stdio.h>

void encher_matriz(int *matriz); void printar_matriz(int *matriz);

int main(void) {

  int numeros[10][10];

  encher_matriz(numeros);
  printar_matriz(numeros);

  return 0;
}

void encher_matriz(int *matriz) {
  for (int i = 0; i < 100; i++) {
    *(matriz + i) = i+1;
  }
}

void printar_matriz(int *matriz) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      int count = (i * 10) + j;
      printf("%d\t", *(matriz + count));
    }
    puts("");
  }
}
