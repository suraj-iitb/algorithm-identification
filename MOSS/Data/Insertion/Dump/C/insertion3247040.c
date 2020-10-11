#include <stdio.h>
static const int N = 1000;

void trace(int n, int A[]){
    for(int i = 0; i < n; i++){
            printf("%d", A[i]);
            if(i != n - 1){
                printf(" ");
            }
    }
    printf("\n");
}

void sort(int n, int A[]){

    /* initialization */
    trace(n, A);

    for(int i = 1; i < n; i++){
        int v = A[i];
        int j = i - 1;

        while(j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1]= v;

        trace(n, A);
    }
}

int main(){
    int n, i;
    int A[N+1];

    scanf("%d", &n);
    for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
    sort(n, A);
    return 0;

}

