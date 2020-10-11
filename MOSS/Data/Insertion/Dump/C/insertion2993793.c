#include <stdio.h>

int  A[10001];
int N,v,j;

int main(void) {
  scanf("%d",&N);
    for(int i=0;i<N;i++){
      scanf("%d",&A[i]);
  }

  for(int i=0;i<N;i++){
    v = A[i];
    j = i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }

    for(int i=0;i<N;i++){
      printf("%d",A[i]);
      if(i<N-1){
        printf(" ");
    }

    }

  printf("\n");
}


      	return 0;

}

