#include <stdio.h>

int main(void)
{
    int tmp,n,x=0;
    
    scanf("%d",&n);
    int *A=malloc(sizeof(int)*n);
    
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    
    int flag=1;
    while(flag){
        flag=0;
        for(int i=n-1;0<=i;i--){
            if(A[i-1]>A[i]){
              tmp    = A[i];
              A[i]   = A[i-1];
              A[i-1] = tmp;
              x++;
              flag=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(n-1!=i) printf("%d ",A[i]);
        else printf("%d\n%d\n",A[i],x);
    }
    
    free(A);
    return 0;
}
