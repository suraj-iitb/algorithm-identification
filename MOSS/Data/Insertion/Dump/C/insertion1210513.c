#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define D(fmt,...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define D(fmt,...) 
#define P(fmt,...) fprintf(stdout, fmt, ##__VA_ARGS__)
#define MAX 100
#define BFSZ 5
void print(int array[], size_t size) {
    int z;
    for (z = 0; z < size-1; z++) {
      P("%d ", array[z]);
    }
    P("%d\n", array[z]);
}
void insertionSort (int array[], size_t size)
{
  int i = 0;
  for (i = 1; i < size; i++) {
    int v = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > v) {
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = v;
    print(array, size);
  }
}


int main (int ac, char **av)
{
  while (1) {
    int size = 0;
    fscanf(stdin, "%d\n", &size);
    int array[MAX] = {0};
    char buf[MAX * 5] = {0};
    char *eof = fgets(buf, MAX*5, stdin);
    if (eof == NULL) {
      break;
    }
    int i = 0;
    
    char numBuf[BFSZ] = {0};
    int array_idx = 0;
    int buf_idx = 0;
    for (i = 0; i < size*BFSZ; i++) {
      if (buf[i] == '\0') {
	continue;
      } else if (buf[i] == ' ') {
	array[array_idx++] = atoi(numBuf);
	buf_idx=0;
	memset(numBuf, 0, BFSZ);
      } else if (buf[i] == '\n') {
	array[array_idx++] = atoi(numBuf);
	memset(numBuf, 0, BFSZ);
	break;
      } else {
	memcpy(numBuf+buf_idx++, buf+i, 1);
      }
    }
    int j = 0;
    print(array, size);
    insertionSort(array, size);
  }
  return 0;
}
