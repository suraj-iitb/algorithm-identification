#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#define MAX 2000000
#define CNTMAX 10000

int n, C[CNTMAX + 10];

void countingSort(int A[], int B[], int k){
    for(int i = 0; i < k; i++){
        C[i] = 0;
    }
    //count number of i
    for(int i = 0; i < n; i++){
        C[A[i]]++;
    }
    //count number less than i
    for(int i = 1; i < k; i++){
        C[i]  += C[i-1];
    }
    //sort
    for(int i = n - 1; i >= 0; i--){
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
}

int main(){
    int A[MAX], B[MAX];

    scanf("%d", &n);
    rep(i, n) scanf("%d", &A[i]);

    countingSort(A,B,CNTMAX);

    rep(i,n){
        if(i) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");

    return 0;
}
