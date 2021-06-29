#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000


int main(){
  unsigned short *A, *B;
  
  int i, j, k;
  int C[VMAX+1];
  int n;
  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  /* your code */

	for(i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	
	k=A[0];
	
	for(i=1;i<=n;i++){
		if(A[i]>k){
			k=A[i];
		}
	}
	
	for(i=0;i<=k;i++){  //CountingSort start
		C[i]=0;
	}
	
	for(j=1;j<=n;j++){
		C[A[j]]++;
	}
	
	for(i=1;i<=k;i++){
		C[i]=C[i]+C[i-1];
	}
	
	for(j=n;j>=1;j--){
		B[C[A[j]]]=A[j];
		C[A[j]]--;
	}					//CountingSort finish
	
	for(i=1;i<=n;i++){
		printf("%d",B[i]);
		if(i!=n){
			printf(" ");
		}
	}
	
	printf("\n");
	
  return 0;
}


