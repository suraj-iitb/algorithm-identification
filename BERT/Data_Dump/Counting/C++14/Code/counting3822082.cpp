#include <iostream>
using namespace std;

int n;

void counting_sort(unsigned int A[], unsigned int B[], int k) {
  int *C;
  C = (int*)malloc(k+10);

  for (int i = 0; i <= k; i++) {
    C[i] = 0;
  }

  for (int j = 0; j < n; j++) {
    C[A[j]]++;
  }

  for (int i = 1; i < k; i++) {
    C[i] = C[i] + C[i-1];
  }

  for (int j = n-1; j >= 0; j--) {
    B[C[A[j]]-1] = A[j];
    C[A[j]]--;
  }
}


int main() {
  unsigned int *A, *B;

  scanf("%d", &n);

  A = (unsigned int*)malloc(sizeof(unsigned int) * n);
  B = (unsigned int*)malloc(sizeof(unsigned int) * n);

  for (long int i = 0; i < n; i++) {
    scanf("%u", &A[i]);
  }

  counting_sort(A, B, 10010);

  for (int i = 0; i < n; i++) {
    if(i > 0) cout << " ";
    cout << B[i];
  }

  cout << endl;
}

