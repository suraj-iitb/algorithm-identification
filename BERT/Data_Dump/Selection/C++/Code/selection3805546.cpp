#include <cstdio>
#include <iostream>
using namespace std;

void selectionSort(int[], int);

int main() {
  int n, a[100];
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  selectionSort(a, n);
  
  printf("\n");
  return 0;
}

void selectionSort(int a[], int n) {
  int minj, count = 0;
  for(int i = 0; i < n; i++) {
    minj = i;
    for(int j = i; j < n; j++) {
      if(a[j] < a[minj]) {
        minj = j;
      }
    }
    if(i != minj) count++;
    swap(a[i], a[minj]);
  }
  printf("%d", a[0]);
  for(int i = 1; i < n; i++) printf(" %d", a[i]);
  printf("\n%d", count);
}
