#include<stdio.h>
int main(){
    int A[100];
    int N;
    int i,j,n,m;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(n=0;n<N;n++){
        printf("%d",A[n]);
        if(n<N-1){
            printf(" ");
        }
    }
    printf("\n");

    for(i=1;i<N;i++){
        m = A[i];
        j = i-1;
        while(j >= 0 && A[j] > m){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = m;
        for(n=0;n<N;n++){
            printf("%d",A[n]);
            if(n<N-1){
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

