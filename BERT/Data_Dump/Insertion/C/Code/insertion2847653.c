#include <stdio.h>
int main(void){
    // Your code here!
    int n, k, i, j, v;
    scanf("%d", &n);
    int A[n];
    for(k=0; k<=n-1; k++){
        scanf("%d", &A[k]);
        printf("%d", A[k]);
        if(k!=n-1) printf(" ");
    }
    printf("\n");
    
    for(i=1; i<=n-1; i++){
        v=A[i];
        j=i-1;
        while(j>=0 && A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        for(k=0; k<=n-1; k++){
            printf("%d", A[k]);
            if(k!=n-1)
                printf(" ");
        }
        printf("\n");
    }
}

