#include <stdio.h>
#include <iostream>
using namespace std;


#define abs(N) ((N>0)?N:-1*N)
//#define min(A,B) ((A>B)?B:A)
//#define max(A,B) ((A<B)?B:A)
#define print(S) (cout << S)
#define println(S) (cout << S << endl)

static const int N = 1000;

void trace(int A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main(){
  int n, i, j;
  int A[N];
  scanf("%d", &n);

  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);

  trace(A, n);
  int key;
  for (int i = 1; i < n; ++i) {
	  key = A[i];
//	  println(key);
	  j = i-1;
	  while(j>=0 && A[j] > key){
//		  print("A[j+1] : ");
//		  println(A[j+1]);
//		  print("A[j] : ");
//		  println(A[j]);
		  A[j+1]=A[j];
		  j--;
	  }
	  A[j+1] = key;
	  trace(A,n);
  }

  return 0;
}

