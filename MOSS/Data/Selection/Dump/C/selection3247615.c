#include <stdio.h>
#define N 100

void trace(int A[], int n){
    for(int i = 0; i < n; i++){
            printf("%d", A[i]);
            if(i != n - 1){
                printf(" ");
            }

    }
    printf("\n");
}

int selectsort(int a[], int n){
    int tmp, minj, cnt, flag;
    cnt = 0;
    for(int i = 0; i < n; i++){
        minj = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[minj]){
                minj = j;
            }

        }
        tmp = a[i];
        a[i] = a[minj];
        a[minj] =tmp;
        if(minj !=i)cnt++;
    }

    trace(a, n);
    return cnt;

}


int main(){
    int n, i;
    int A[N + 1];

    scanf("%d", &n);
    for (i = 0; i < n; i++ ) scanf("%d", &A[i]);


    printf("%d\n", selectsort(A, n));

    return 0;
}
