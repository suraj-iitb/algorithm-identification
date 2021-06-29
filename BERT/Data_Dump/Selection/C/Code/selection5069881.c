#include<stdio.h>

int A[100];
int N,x;
int selectionesort(int A[], int N);

int main(){
  
    int i;
    
    scanf("%d",&N);
    /*if(N<1 || N>100){
        exit(1);
    }*/
    
    for(i=0;i<N;i++){
        scanf("%d", &A[i]);
        /*if(A[i]<1 || A[i]>100){
            exit(1);
        }*/
        
    }
    x = selectionesort(A, N);
    
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
int selectionesort(int A[], int N){
    int f = 0;
    int n,i,j,m;
        
        for(i=0;i<N;i++){
            m = i;
            for(j=i;j<N;j++){
                if(A[j]<A[m]) m = j;
            }
                n = A[i];
                A[i] = A[m];
                A[m] = n;
             
            if(i != m) f++;
    }
    return f;
}
