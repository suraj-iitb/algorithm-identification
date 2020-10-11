#include <stdio.h>

int main(){
    int i,j,n,minj,k,l=0;

    scanf("%d",&n);
    int A[n];
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    for(i=0;i<=n-1;i++){
        minj=i;
        for(j=i+1;j<=n-1;j++){
            if(A[j]<A[minj]){
                minj=j;
            }
        }
        if(minj!=i){
            k=A[i];
            A[i]=A[minj];
            A[minj]=k;
            l++;
        }
    }
    
    for(i=0;i<n;i++){
        if(i==n-1) printf("%d",A[i]);
        else printf("%d ",A[i]);
    }
    printf("\n%d\n",l);
    return 0;
}
