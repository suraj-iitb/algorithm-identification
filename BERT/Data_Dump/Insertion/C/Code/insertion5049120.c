#include<stdio.h>
int main(){
    int i, j, N, v, k;
    int A[1000];
    
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    i=0;
    while(1){
        printf("%d", A[i]);
        if(i >= N-1){
            printf("\n");
            break;
        }
        else{
            printf(" ");
            i++;
        }
    }
    
    for(i = 1 ; i<=N-1 ; i++){
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        k=0;
        while(1){
            printf("%d", A[k]);
            if(k >= N-1){
                printf("\n");
                break;
            }
            else{
                printf(" ");
                k++;    
            }
            
        }
    }
    return 0;
}

