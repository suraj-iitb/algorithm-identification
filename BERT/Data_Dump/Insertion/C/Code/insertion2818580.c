#include<stdio.h>

void insertionSort(int A[],int N){
    int i,j,k,v;
    
    for(i=1;i<N;i++){
        v=A[i];
        j=i-1;
        while(j>=0&&A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        for(k=0;k<N;k++){
            printf("%d",A[k]);
            if(k!=N-1) printf(" ");
            else putchar('\n');
        }
    }
}

int main(void){
    int i,N;
    scanf("%d",&N);
    
    int A[N];
    for(i=0;i<N;i++) scanf("%d",&A[i]);
    for(i=0;i<N;i++){
        printf("%d",A[i]);
        if(i!=N-1) printf(" ");
        else putchar('\n');
    }
    insertionSort(A,N);
    
    return(0);
}
