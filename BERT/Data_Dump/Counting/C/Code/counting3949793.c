#include<stdio.h>
#define NMAX 2*1000*1000
#define AMAX 10000

void CountingSort(int A[], int n){
    int i;
    int B[NMAX], Count[AMAX];
    
    //count配列の初期化
    for(i=0; i<=AMAX; i++){
        Count[i]=0;
    }
    //数える
    for(i=0; i<n; i++){
        Count[A[i]]++;
    }
    //累積の配列にする
    for(i=0; i<AMAX; i++){
        Count[i+1]+=Count[i];
    }
    //コピーする。後ろから見ていくので注意。
    for(i=n-1; i>=0; i--){
        B[Count[A[i]]-1]=A[i];
        --Count[A[i]];
    }
    //元の配列にソートした配列を代入する
    for(i=0; i<n; i++){
        A[i]=B[i];
    }
}

int main(){
    
    int i,n;
    
    scanf("%d", &n);
    int A[NMAX];
    
    for(i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    
    CountingSort(A, n);
    
    for(i=0; i<n; i++){
        if(i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    
    return 0;
}

