#include<stdio.h>

int main(void){
    
    int N,i,j,minj,tmp,count1=0,count2=0;
    int A[100];
    
    scanf("%d",&N);
    
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    
    for(i=0;i<N;i++){
        minj=i;
        count1=0;
        for(j=i;j<N;j++){
            if(A[j]<A[minj]){
                minj=j;
                count1++;
            }
        }
        if(count1>=1){
                count2++;
        }
        tmp=A[i];
        A[i]=A[minj];
        A[minj]=tmp;
    }
        
    for(i=0;i<N;i++){
        printf("%d",A[i]);
        if(i!=N-1){
    		printf(" ");
    	}
    }
    
    printf("\n");
    
    printf("%d\n",count2);
    
    return 0;
}
