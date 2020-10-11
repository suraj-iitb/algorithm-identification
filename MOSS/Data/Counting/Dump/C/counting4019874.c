#include<stdio.h>
#include<string.h>
#define N 2000000

int n, k, A[N], B[N], X[N];

int searchk(int X[], int n){
    int max = X[0], tmp;
    for(int i=1 ; i<n ; i++){
        if(max < X[i]){
            tmp = X[i];
            X[i] = max;
            max = tmp;
        }
    }
    return max;
}

void ContingSort(int A[], int B[], int k){
    int C[k];
    /*initialize 0 to k*/
    for(int i=0 ; i<k+1 ; i++)  C[i] = 0;
    /*A record 1 to n*/
    for(int i=0 ; i<n ; i++)    C[A[i]]++;
    /*under-A record 1 to k*/
    for(int i=1 ; i<k+1 ; i++)  C[i] += C[i-1];

    /*copying to B*/
    for(int i=n-1 ; i>=0 ; i--){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }

}

int main(void){
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++){
        scanf("%d", &A[i]);
        X[i] = A[i];    //useing searchk
    }
    int k = searchk(X, n);
    ContingSort(A, B, k);
    for(int i=1 ; i<n ; i++)
        printf("%d ", B[i]);
    printf("%d\n", B[n]);
    return 0;
    }

