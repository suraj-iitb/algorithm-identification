#include <stdio.h>
int main(){
    int A[100];
    int n;
    int i,j,t;
    int minj,count=0;
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    for(i=0;i<n;i++){
        minj=i;
        for(j=i;j<n;j++){
            if(A[j]<A[minj]){
                minj=j;
                
            }
        }
        if(i!=minj)count++;

        t=A[i];
        A[i]=A[minj];
        A[minj]=t;
    }
    for(j=0;j<n;j++){
        printf("%d",A[j]);
        if(j<n-1)printf(" ");
    }
    printf("\n%d\n",count);
    
    return 0;
}
