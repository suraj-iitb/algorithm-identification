#include<stdio.h>
#define N 100

int main(){
    int n, i, j, ex, ans = 0, flag = 1, A[N];
    
    scanf("%d",&n);
    for(i=0 ; i<n ; i++){
        scanf("%d",&A[i]);
    }
    
    while(flag){
        flag = 0;
        for(j=n-1 ; j>0 ; j--){
            if(A[j] < A[j-1]){
                ex = A[j];
                A[j] = A[j-1];
                A[j-1] = ex;
                flag = 1;
                ans++;
            }
        }
    }
    for(i=0 ; i<n ;i++){
        if(i != 0)printf(" ");
        printf("%d",A[i]);
    }
    printf("\n%d\n",ans);
    return 0;
}

