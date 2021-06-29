#include<stdio.h>
#include<stdlib.h>

int main(){
    int A[1000];
    int i,N;
    int v,s,j;
    scanf("%d",&N);
    if(N > 100){
        printf("error!");
        return 1;
    }
    for(i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
        printf("%d",A[i]);
        if(i!=N-1){
            printf(" ");
            
        }
    }
      printf("\n");
    
    for(s=1;s<N;s++){
        v = A[s];
        j = s - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
        }
        for(i=0;i<N;i++){
            printf("%d",A[i]);
            if(i!=N-1){
                printf(" ");
            }
            
        }
        printf("\n");
}
    return 0;
}

