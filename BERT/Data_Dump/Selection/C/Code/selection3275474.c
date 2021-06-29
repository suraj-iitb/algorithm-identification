#include<stdio.h>
#define N 100

int main(){
    int n, i, j, f=0, minj, ex, ans=0, A[N];
    scanf("%d",&n);
    
    for(i=0 ; i<n ; i++){
        scanf("%d",&A[i]);
    }
    
    for(i=0 ; i<n ; i++){
        f = 0;
        minj = i;
        
        for(j=i ; j<n ; j++){
            if(A[j] < A[minj]){
                minj = j;
                f = 1;
            } 
        }
        if(f == 1){
            ex = A[i];
            A[i] = A[minj];
            A[minj] = ex;
            ans++;
        }
    }
    for(i=0 ; i<n ; i++){
        if(i != 0) printf(" ");
        printf("%d",A[i]);
    } 
    printf("\n%d\n",ans);
    return 0;
}

