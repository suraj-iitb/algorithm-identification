#include<stdio.h>
#include<stdlib.h>

int A[100];
int N,x;
int bobblesort(int A[], int N);

int main(){
  
    int i;
    
    scanf("%d",&N);
    /*if(N<1 || N>100){
        exit(1);
    }*/
    
    for(i=0;i<N;i++){
        scanf("%d", &A[i]);
       /* if(A[i]<1 || A[i]>100){
            exit(1);
        }*/
        
    }
    x = bobblesort(A, N);
    
    for(i=0;i<N;i++){
        if(i>0){
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", x);
    
    
    return 0;
}
int bobblesort(int A[], int N){
    int f = 1;
    int n,i;
    int c = 0;
    
    while(f){
        
        f = 0;
        
        for(i=N-1;i>=1;i--){
            if(A[i]<A[i-1]){
                n = A[i];
                A[i] = A[i-1];
                A[i-1] = n;
                
                f=1;
                c++;
            }
        }
    }
    return c;
}

