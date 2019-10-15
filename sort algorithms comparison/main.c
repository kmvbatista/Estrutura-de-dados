#include <stdlib.h>
#include <stdio.h>
#include "bublesort.h"
#include "insertsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include <time.h>

void generateVector(int* vector, int tam) {
  for (int i = 0; i < tam; i++)
  {
    vector[i] = rand()%99;
  }
}

static __inline__ unsigned long long rdtsc(void)
{
  unsigned long long x;
  __asm__ __volatile__ ("rdtsc" : "=A"(x));
  return x;
}

long getMergeTime(int range);
long getQuickTime(int range);
long getInsertionTime(int range);

void main() {
  srand((unsigned)time(NULL));
  int range;
  printf("digite o range do vetor\n");
  scanf("%d", &range);
  long mergeTime = getMergeTime(range);
  long insertionTime = getInsertionTime(range);
  long quickTime = getQuickTime(range);
  printf("o tempo do merge é %lu\n o do insertion é %lu\n e o do quick é %lu\n", mergeTime, insertionTime, quickTime);
  
  
}

long getMergeTime(int range) {
  int *vector, *auxiliar; 
  auxiliar = malloc(range * sizeof(int));
  vector= malloc(range * sizeof(int));
  generateVector(vector, range);
  long initialTime = rdtsc();
  mergesort(vector, auxiliar,0, range-1);
  long posTime = rdtsc();
  free(vector);
  free(auxiliar);
  return  posTime-initialTime;
}

long getInsertionTime(int range) {
  int *vector;
  vector= malloc(range * sizeof(int));
  generateVector(vector, range);
  long initialTime = rdtsc();
  insert(vector, range);
  long posTime = rdtsc();
  free(vector);
  return posTime-initialTime;
}

long getQuickTime(int range) {
  int *vector;
  vector = malloc(range * sizeof(int));
  generateVector(vector, range);
  long initialTime = rdtsc();
  quick_sort(vector, 0, range-1);
  long posTime = rdtsc();
  free(vector);
  return posTime-initialTime;
}