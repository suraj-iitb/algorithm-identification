#include <stdio.h>
void print(int *, int);
int main(){
    int A[101], i, j, n, v;
    scanf("%d", &n);
    for(i =0; i < n; i++){
        scanf("%d", &A[i]);
    }

    for(i = 1; i < n; i++){
        print(A, n);
        printf("\n");
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            j--; 
        }
        A[j + 1] = v;
        
    }
    print(A,n);
    printf("\n");

}
void print(int *A, int n){
    int i;
    for(i = 0; i < n-1; i++){
        printf("%d ",A[i]);
    }
    printf("%d", A[n-1]);
}
