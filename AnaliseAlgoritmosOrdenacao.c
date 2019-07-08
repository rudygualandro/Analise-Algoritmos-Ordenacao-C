#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercala(int p, int q, int r, int vetor[]){ 
  int i, j, k, *w;
  w = malloc((r-p) * sizeof(int));
  i = p; j = q; k = 0;
  while(i < q && j < r){
    if (vetor[i] <= vetor[j])
      w[k++] = vetor[i++];
    else
      w[k++] = vetor[j++];
  }
  while(i < q) w[k++] = vetor[i++];
  while(j < r) w[k++] = vetor[j++];
  for(i = p; i < r; i++)
    vetor[i] = w[i-p];
  free(w);
}
  
void merge_sort(int p, int r, int vetor[]) { 
  if (p < r - 1){ 
    int q = (p+r)/2; 
    merge_sort(p, q, vetor); 
    merge_sort(q, r, vetor);
    intercala(p, q, r, vetor); 
  }
}
//*************************************************************
void swap(int* a, int* b){
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition(int arr[], int low, int high){ 
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high- 1; j++){
      if (arr[j] <= pivot){ 
        i++;
        swap(&arr[i], &arr[j]); 
      }
  }
  swap(&arr[i + 1], &arr[high]); 
  return (i + 1); 
} 

void quickSort(int arr[], int low, int high){
  if (low < high){ 
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}
//************************************************************
void insertionSort(int arr[], int n){ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 

        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
}

void bubble_sort (int vetor[], int n) {
  int i, j, aux;

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n ; j++) {
      if (vetor[j] > vetor[j + 1]) {
        aux = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = aux;
      }
    }
  } 
}

void selection_sort (int vetor[],int n) {
  int i, j, min, aux;
  
  for (i = 0; i < n - 1; i++) {
    min = i;

    for (j = i + 1; j < n - 1; j++) {
      if (vetor[j] < vetor[min]) {
        min = j;
      }
    }
  
    if (i != min) {
      aux = vetor[i];
      vetor[i] = vetor[min];
      vetor[min] = aux;
    }
  }
}

int main(void) {
  int n = 1000; //Tamanho do vetor
  int vetor1[n], vetor2[n], vetor3[n], vetor4[n], vetor5[n];

  int i;

  // inicializa os vetores aleatorios de tamanho n;
  for(i = 0; i < n; i++) {
    vetor1[i]  = rand() % (n + 1);
  }
  for(i = 0; i < n; i++) {
    vetor2[i]  = vetor1[i];
    vetor3[i]  = vetor1[i];
    vetor4[i]  = vetor1[i];
    vetor5[i]  = vetor1[i];
  }

  printf("\nVetores Aleatorios:");
  // Selection Sort Aleatorio
  clock_t Ticks[2];
  Ticks[0] = clock();

  selection_sort(vetor1, n);

  Ticks[1] = clock();
  double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf("\nTempo gasto para Selection Sort: %gms.", Tempo);

  // Bubble Sort Aleatorio
  Ticks[0] = clock();

  bubble_sort(vetor2, n);

  Ticks[1] = clock();
  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf("\nTempo gasto para Bubble Sort: %gms.", Tempo);

  // Quick Sort Aleatorio
  Ticks[0] = clock();

  quickSort(vetor3, 0, n - 1);

  Ticks[1] = clock();
  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf("\nTempo gasto para Quick Sort: %gms.", Tempo);

  // Merge Sort Aleatorio
  Ticks[0] = clock();

  merge_sort(0, n-1, vetor4);

  Ticks[1] = clock();
  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf("\nTempo gasto para Merge Sort: %gms.", Tempo);

  // Insertion Sort Aleatorio
  Ticks[0] = clock();

  insertionSort(vetor5, n);

  Ticks[1] = clock();
  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf("\nTempo gasto para Insertion Sort: %gms.", Tempo);

  // inicializa os vetores em ordem crescente de tamanho n;
  for(i = 0; i < n; i++) {
    vetor1[i] = i;
  }
  for(i = 0; i < n; i++) {
    vetor2[i] = vetor1[i];
    vetor3[i] = vetor1[i];
    vetor4[i] = vetor1[i];
    vetor5[i] = vetor1[i];
  }

  printf("\n\nVetores Crescentes:");
  // Selection Sort Crescente
  Ticks[0] = clock();

  selection_sort(vetor1, n);

  Ticks[1] = clock();
  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf("\nTempo gasto para Selection Sort: %gms.", Tempo);

  // Bubble Sort Crescente
  Ticks[0] = clock();

  bubble_sort(vetor2, n);

  Ticks[1] = clock();
  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf("\nTempo gasto para Bubble Sort: %gms.", Tempo);

  // Quick Sort Crescente
  Ticks[0] = clock();

  quickSort(vetor3, 0, n - 1);

  Ticks[1] = clock();
  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf("\nTempo gasto para Quick Sort: %gms.", Tempo);

  // Merge Sort Crescente
  Ticks[0] = clock();

  merge_sort(0, n-1, vetor4);

  Ticks[1] = clock();
  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf("\nTempo gasto para Merge Sort: %gms.", Tempo);

  // Insertion Sort Crescente
  Ticks[0] = clock();

  insertionSort(vetor5, n);

  Ticks[1] = clock();
  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf("\nTempo gasto para Insertion Sort: %gms.", Tempo);


  // inicializa os vetores em ordem decrescente de tamanho n;
  for(i = n; i >= 0; i--) {
    vetor1[i]  = i;
  }
  for(i = 0; i < n; i++) {
    vetor2[i] = vetor1[i];
    vetor3[i] = vetor1[i];
    vetor4[i] = vetor1[i];
    vetor5[i] = vetor1[i];
  }

  printf("\n\nVetores decrescentes:");
  // Selection Sort Decrescente
  Ticks[0] = clock();

  selection_sort(vetor1, n);

  Ticks[1] = clock();
  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf("\nTempo gasto para Selection Sort: %gms.", Tempo);

  // Bubble Sort Decrescente
  Ticks[0] = clock();

  bubble_sort(vetor2, n);

  Ticks[1] = clock();
  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf("\nTempo gasto para Bubble Sort: %gms.", Tempo);

  // Quick Sort Decrescente
  Ticks[0] = clock();

  quickSort(vetor3, 0, n - 1);

  Ticks[1] = clock();
  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf("\nTempo gasto para Quick Sort: %gms.", Tempo);

  // Merge Sort Decrescente
  Ticks[0] = clock();

  merge_sort(0, n-1, vetor4);

  Ticks[1] = clock();
  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf("\nTempo gasto para Merge Sort: %gms.", Tempo);

  // Insertion Sort Decrescente
  Ticks[0] = clock();

  insertionSort(vetor5, n);

  Ticks[1] = clock();
  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf("\nTempo gasto para Insertion Sort: %gms.", Tempo);
  getchar();

  return 0;
}

// Resultados:

// Para n = 1000:
// Vetores Aleatorios:
// Tempo gasto para Selection Sort: 1.53ms.
// Tempo gasto para Bubble Sort: 4.286ms.
// Tempo gasto para Quick Sort: 0.146ms.
// Tempo gasto para Merge Sort: 0.216ms.
// Tempo gasto para Insertion Sort: 0.888ms.

// Vetores Crescentes:
// Tempo gasto para Selection Sort: 1.379ms.
// Tempo gasto para Bubble Sort: 3.047ms.
// Tempo gasto para Quick Sort: 3.522ms.
// Tempo gasto para Merge Sort: 0.129ms.
// Tempo gasto para Insertion Sort: 0.013ms.

// Vetores decrescentes:
// Tempo gasto para Selection Sort: 1.286ms.
// Tempo gasto para Bubble Sort: 2.913ms.
// Tempo gasto para Quick Sort: 3.707ms.
// Tempo gasto para Merge Sort: 0.15ms.
// Tempo gasto para Insertion Sort: 0.013ms.


// Para n = 10000:
// Vetores Aleatorios:
// Tempo gasto para Selection Sort: 132.243ms.
// Tempo gasto para Bubble Sort: 496.961ms.
// Tempo gasto para Quick Sort: 1.714ms.
// Tempo gasto para Merge Sort: 2.658ms.
// Tempo gasto para Insertion Sort: 103.236ms.

// Vetores Crescentes:
// Tempo gasto para Selection Sort: 148.945ms.
// Tempo gasto para Bubble Sort: 311.523ms.
// Tempo gasto para Quick Sort: 437.054ms.
// Tempo gasto para Merge Sort: 1.655ms.
// Tempo gasto para Insertion Sort: 0.076ms.

// Vetores decrescentes:
// Tempo gasto para Selection Sort: 160.977ms.
// Tempo gasto para Bubble Sort: 335.351ms.
// Tempo gasto para Quick Sort: 485.491ms.
// Tempo gasto para Merge Sort: 1.565ms.
// Tempo gasto para Insertion Sort: 0.078ms.


// Para n = 100000:
// Tempo gasto para Selection Sort: 13574.6ms.
// Tempo gasto para Bubble Sort: 51928.7ms.
// Tempo gasto para Quick Sort: 20.133ms.
// Tempo gasto para Merge Sort: 24.938ms.
// Tempo gasto para Insertion Sort: 9062.01ms.

// Vetores Crescentes:
// Tempo gasto para Selection Sort: 13804.8ms.
// Tempo gasto para Bubble Sort: 30217.4ms.
// Tempo gasto para Quick Sort: 38816.4ms.
// Tempo gasto para Merge Sort: 14.072ms.
// Tempo gasto para Insertion Sort: 0.604ms.

// Vetores decrescentes:
// Tempo gasto para Selection Sort: 13038ms.
// Tempo gasto para Bubble Sort: 30298.9ms.
// Tempo gasto para Quick Sort: 37237.1ms.
// Tempo gasto para Merge Sort: 14.309ms.
// Tempo gasto para Insertion Sort: 0.651ms.