#include <stdio.h>
#include <stdlib.h>

unsigned short *A,*B;
int C[10000+1],n;
void CountingSort(unsigned short*,unsigned short*,int);
int main(){
  int i;

  scanf("%d",&n);
 
    A=(short *)malloc(sizeof(short)*n+1);
    B=(short *)malloc(sizeof(short)*n+1);

  for(i=0;i<n;i++) {
   
    scanf("%d",&A[i+1]);

  }

  CountingSort(A,B,10000);
  
  for(i=2;i<=n+1;i++){
    if(i>2) printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
  free(A);
  free(B);
  return 0;
}

void CountingSort(unsigned short *A,unsigned short *B,int k){
  int i,j;

  for(i=0;i<=k;i++){
    C[i]=0;
	   }
    
  for (j=0;j<=n;j++){ 
    C[A[j+1]]++;
	   }
  for (i=1;i<=k;i++){
    C[i] = C[i] + C[i-1];
	  }
  for (j=1;j<=n;j++){
    B[C[A[j]]] = A[j];
	  C[A[j]]--;
	  }
}
