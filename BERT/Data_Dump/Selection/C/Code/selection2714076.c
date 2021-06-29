#include<stdio.h>

int main(void){
    int n,x,minj;
    int count=0;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<n;i++){
        minj=i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[minj]){
                minj=j;
            }
        }
        if(!(A[minj]==A[i])){
            count++;
            x=A[minj];
            A[minj]=A[i];
            A[i]=x;
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
