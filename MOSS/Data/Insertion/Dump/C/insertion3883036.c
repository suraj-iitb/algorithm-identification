#include<stdio.h>

int main(void)
{
    
    int N,i,v,m,j;
    
    scanf("%d",&N);
    
    int A[N];
    for(i=0;i<=N-1;i++){
    scanf("%d",&A[i]);
    }
	
	 for(i=0;i<=N-1;i++){
    printf("%d",A[i]);
	 		if(i!=N-1){printf(" ");}
    }
	printf("\n");
	
    
       for(i=1;i<=N-1;i++){
            j = i - 1;
       	    v = A[i];
            while(j >= 0 && A[j] > v){
                A[j+1] = A[j];
                j--;  
            }
       	A[j+1] = v;	
       	
       	
       	for(m=0;m<N;m++){
       	printf("%d",A[m]);
       	if(m!=N-1){printf(" ");}
       	}
       	printf("\n");
       }
	
	
   }
   
   
