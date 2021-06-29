#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main() {
  unsigned short *A, *B; // �T�C�Y�̏����ȕ����Ȃ��̐����^
  int C[VMAX+1];
  int n, i, j;

  scanf( "%d" , &n );
  A = malloc((n+1) * sizeof(short));
  B = malloc((n+1) * sizeof(short));
  for ( i=1; i<=n; i++ ) scanf( "%d" , &A[i] );

  // �\�[�g�J�n
  for ( i=0; i<VMAX+1; i++ ) C[i] = 0;
  for ( j=1; j<=n; j++ ) C[A[j]]++; // C[i] �� i �̏o�������L�^����
  for ( i=1; i<VMAX+1; i++ )
    C[i] = C[i] + C[i-1]; // C[i] �� i �ȉ��̐��̏o�������L�^����
  for ( j=n; j>0; j-- ) {
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for ( i=1; i<=(n-1); i++ ) printf( "%d " , B[i] );
  printf( "%d\n" , B[n] );
  
  return 0;
}

