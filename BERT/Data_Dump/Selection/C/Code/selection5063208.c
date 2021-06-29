#include<stdio.h>

void selectionSort(int N,int A[]){
    int i, r=0, f, min, t;
    for(f=0; f<N-1; f++){
        min=f;
        for(i=N-1; i>=f; i--){
            if(A[min]>=A[i]){
                min=i;
            }
        }
        t=A[f];
        A[f]=A[min];
        A[min]=t;
        if(min!=f)r++;
    }
    for(i=0; i<N; i++){
        if(i>0)printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", r);
}

int main(){
    int N,i;
    int A[100];
    scanf("%d", &N);
    for (i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    selectionSort(N,A);
    return 0;
}
