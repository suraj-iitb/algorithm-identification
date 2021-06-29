#include<stdio.h>

int main(void){
    
    int N,i,j,tmp,flag,count=0;
    int A[100];
    
    scanf("%d",&N);
    
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    
    i=0;
    flag=1;
    
    while(flag){
        flag=0;
        for(j=N-1;j>=i+1;j--){
            if(A[j]<A[j-1]){
                tmp=A[j];
                A[j]=A[j-1];
                A[j-1]=tmp;
                flag=1;
                count++;
            }
        }
        i++;
    }
    for(i=0;i<N;i++){
        printf("%d",A[i]);
        if(i!=N-1){
    		printf(" ");
    	}
    }
    printf("\n");
    
    printf("%d\n",count);
    
    return 0;
}
