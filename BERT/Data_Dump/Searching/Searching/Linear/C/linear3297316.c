#include <stdio.h>
#define MAXS 10000
#define MAXT 500

int search(int *A, int n, int key);

int main(){

  int i,j,k,n,q;

  int cnt=0;

  scanf("%d",&n);

  int S[n];

  for(i=0;i<n;i++){
    
    scanf("%d", &S[i]);

  }

  scanf("%d", &q);

  int T[q];

  for(i=0;i<q;i++){

    scanf("%d", &T[i]);

  }

  /* 

  printf("%d\n", n);

  for(i=0;i<n;i++){
    
    printf("%d", S[i]);

  }

  
  printf("\n", n);
  
  printf("%d\n", q);

  for(i=0;i<q;i++){
    
    printf("%d",T[i]);

  }

  printf("\n", n);

  */

  for(i=0; i<q; i++){

    if(search(S, n, T[i])){

      cnt++;

    }

  }
			     
  printf("%d\n",cnt);
  
  return 0;
  
}

int search(int *A, int n, int key){

  int i=0;

  A[n]=key;

  while(A[i]!=key){

    i++;

  }

  return i!=n;

}

