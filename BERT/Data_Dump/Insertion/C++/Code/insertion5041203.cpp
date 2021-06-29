#include<stdio.h>

int main(void){
    int i,j,l,v,N;
    int A[100];
    
    scanf("%d",&N);
    for(i=0;i<=N-1;i++){
        scanf("%d",&A[i]);
    }
    
    for(i=1;i<=N-1;i++){
        for(l=0;l<=N-1;l++){
            printf("%d",A[l]);
            if(l!=N-1){
                printf(" ");    
            }
        }
        printf("\n");
        v=A[i];
        j=i-1;
        while(j>=0 && A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
    }
    
    for(l=0;l<=N-1;l++){
        printf("%d",A[l]);
        if(l!=N-1){
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
