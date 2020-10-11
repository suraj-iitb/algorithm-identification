#include<stdio.h>

int A[100];

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int selection(int *A, int N){
    int i, j, minj;
    int ans = 0;
    
    for(i = 0; i < N; i++){
        minj = i;
        for(j=i+1; j < N; j++){
            minj = A[j] < A[minj]?j:minj;
        }
        if(i != minj){
            swap(&A[i], &A[minj]);
            ans++;
        }
    }
    return ans;
}

int main(void){
    int i, ans, n;
    
    scanf("%d", &n);
    
    for(i=0; i<n;i++){
        scanf("%d", &A[i]);
    }
    
    ans = selection(A, n);
    
    for(i=0; i<n;i++){
        if(i == n-1) printf("%d\n", A[i]);
        else printf("%d ", A[i]);
    }
    printf("%d\n", ans);

    return 0;    
}
