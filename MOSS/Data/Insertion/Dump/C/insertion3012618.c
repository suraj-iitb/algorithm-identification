#include <stdio.h>
int main(void){
    int n;
    int i,j,k;
    int v;
    
    scanf("%d",&n);
    int A[n];
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    for(i=1;i<=n-1;i++){
        for(k=0;k<n;k++){
            if(k==0){
                printf("%d",A[k]);
            }else{
                printf(" %d",A[k]);
            }
        }
        printf("\n");
        v = A[i];
        j = i - 1;
        while(A[j]>v && j>=0){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }
    for(k=0;k<n;k++){
        if(k==0){
            printf("%d",A[k]);
        }else{
            printf(" %d",A[k]);
        }
    }
    printf("\n");
    
}
