#include<stdio.h>

int linersearch(int A[], int N, int key);

int main(){
    int i,N,M,key;
    int n = 0;
    int k = 0;
    int A[10000];
    
    scanf("%d", &N);
    
    for(i=0;i<N;i++){
        scanf("%d", &A[i]);
    }
    
    scanf("%d",&M);
    
    for(i=0;i<M;i++){
        scanf("%d", &key);
        k = linersearch(A,N,key);
        if(k != N){
            n++;
        }
    }
    
    printf("%d\n", n);
    
    return 0;
}

int linersearch(int A[], int N, int key){
    int i;
    i = 0;
    
    A[N] = key;
    
    while(A[i] != key){
        i++;
    }
    return i;
}


