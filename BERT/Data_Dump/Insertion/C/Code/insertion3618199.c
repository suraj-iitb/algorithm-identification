#include<stdio.h>

int main(){
    int N;
    int A[2000];
    int i, j, k ,v;

    scanf("%d", &N);

    for(i=0; i<N; i++){
        if(i>0){
            printf(" ");
        }
        scanf("%d", &A[i]);
        printf("%d", A[i]);
    }
    printf("\n");

    for(i=1; i<N; i++){
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j = j - 1;
        }
        A[j+1] = v;
        for(k=0; k<N; k++){
            if(k>0){
                printf(" ");
            }
            printf("%d", A[k]);
        }
        printf("\n");
    }

    return 0;
}
