#include<stdio.h>

int main(void){
    int n,x;
    int count=0;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(A[j]<A[j-1]){
                x=A[j];
                A[j]=A[j-1];
                A[j-1]=x;
                count++;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        printf("%d",A[i]);
        if(i<n-1){
            printf(" ");
        }
    }
    printf("\n%d\n",count);
    
    return 0;
}
