#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n,i,j;
    int A[100];
    int minj;
    int m=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
        
    }
    for(i=0;i<n;i++){
        minj=i;
        int tmp;
        for(j=i;j<n;j++){
            if(A[j]<A[minj]){
                minj=j;
            }
        }
        
            if(i!=minj){
              
            tmp=A[i];
            A[i]=A[minj];
            A[minj]=tmp;
            m++;
            
                    }
        
    }
    for(i=0;i<n-1;i++){
        printf("%d ",A[i]);
    }
    printf("%d\n",A[n-1]);
    printf("%d\n",m);
    return 0;
}
