#include <stdio.h>
#define N 100

int main(){
    int i, j, key, n;
    int A[N];
    
    scanf("%d", &n);
    for(i = 0;i < n;i++)scanf("%d", &A[i]);
    for(i = 0;i < n;i++){
        printf("%d", A[i]);
        if(i != n - 1)
            printf(" ");
    }
    printf("\n");
    
    for(j = 1;j < n;j++){
        key = A[j];
        i = j - 1;
        while(i >= 0 && A[i] > key){
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i+1] = key;
        for(i = 0;i < n;i++){
            printf("%d", A[i]);
            if(i != n - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
