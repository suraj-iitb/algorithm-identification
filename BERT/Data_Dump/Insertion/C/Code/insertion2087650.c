#include <stdio.h>

int main(void){
   int N,n,i,j,k,v;
   int A[100];
   scanf("%d",&N);
	
   for(i=0;i<N;i++){
      scanf("%d",&n);
      A[i] = n;
   }
	//printf("do");
	
	for(k=0;k<N-1;k++){
			printf("%d ",A[k]);
		}
	printf("%d\n",A[k]);
	
	for(i=1;i<N;i++){
		v = A[i];
		j = i-1;
		while(j>=0&&A[j]>v){
			A[j+1] = A[j];
			j--;
			A[j+1] = v;
		}
		for(k=0;k<N-1;k++){
			printf("%d ",A[k]);
		}
		printf("%d\n",A[k]);;
	}	
return 0;
}
