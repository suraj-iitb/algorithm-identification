#include <stdio.h>
int main(){   
  int i,j,v,N,n;
    int A[1000];   
    scanf("%d",&N);  
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(n=0;n<N-1;n++){
        printf("%d ",A[n]);
        
    }
	printf("%d",A[N-1]);
	printf("\n");
    for(i=1;i<=N-1;i++){
        v=A[i];
        j=i-1;
        while(j>=0 && A[j]>v){
            A[j+1]=A[j];
            j--;
            A[j+1]=v;
        }
        for(n=0;n<N-1;n++){
        printf("%d ",A[n]);
        
    }
	printf("%d",A[N-1]);
printf("\n");
    }
}

