#include<stdio.h>
void tc(int A[],int N);
int main(void){
    int n;
        scanf("%d",&n);
    int A[n];
    for(int i=0;i<=n-1;i++){
        scanf("%d",&A[i]);
    }
    
 		for(int i=0;i<=n-1;i++){
 			if(i>0){printf(" ");}
        printf("%d",A[i]);
 			
    }
	printf("\n");
    	 tc(A,n);
        return 0;
}
void tc(int A[],int N){
    int i;
    int v,j;
   
    for(i=1;i<N;i++){
        v=A[i];
        for(j=i-1;j>=0&&A[j]>v;j--){
        A[j+1]=A[j];
        
        A[j]=v;
        	
        	}
    	for(int i=0;i<N;i++){
        		if(i>0){printf(" ");}
        		 printf("%d",A[i]);
		}
		printf("\n");
    }

}
