#include<stdio.h>
#include<algorithm>
using namespace std;

static const int MAX = 2000001;
static const int VMAX = 10000;

int main(){
    unsigned short *A, *B;
    int n, C[VMAX + 1];

    scanf("%d", &n);

    A = new unsigned short[n+1]; B = new unsigned short[n+1];

    for(int i=0; i<=VMAX; ++i) C[i] = 0;

    for(int i=0; i<n; ++i){
        scanf("%hu", &A[i+1]);
        ++C[A[i+1]];
    }

    for(int i=1; i<VMAX; ++i) C[i] = C[i] + C[i-1];

    for(int i=1; i<=n; ++i){
        B[C[A[i]]] = A[i];
        --C[A[i]];
    }

    for(int i=1; i<=n; ++i){
        if(i>1) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");
}

