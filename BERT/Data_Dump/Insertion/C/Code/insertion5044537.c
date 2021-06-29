#include <stdio.h>

void print(int A[], int N);

int main()
{
    int i,j,v,A[100],N;
    
    scanf("%d",&N);
    for(i = 0; i < N; i++) scanf("%d",&A[i]);
    print(A, N);
    
    for(i = 1; i < N; i++){
        j = i - 1;
        v = A[i];
        
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            A[j] = v;
            j--;
        }
        A[j+1] = v;
        print(A, N);
    }
    return 0;
}

void print(int A[], int N)
{
    int i;
    for(i = 0; i < N; i++){
        if(i > 0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
}


