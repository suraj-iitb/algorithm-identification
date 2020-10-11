#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i=0;
    int flag=1;
    int n;
    int j,h;
    int A[100];
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
        scanf("%d",&A[j]);
    }
    
    while(flag==1){
        flag=0;
        int k;
        for(k=n-1;k>0;k--){
            if(A[k]<A[k-1]){
                int tmp;
                tmp=A[k];
                A[k]=A[k-1];
                A[k-1]=tmp;
                flag=1;
                i++;
            }
            
        }
        
        
    }
    for(h=0;h<n-1;h++){
        printf("%d ",A[h]);
        
}
    printf("%d\n",A[n-1]);
    printf("%d\n",i);
    return 0;
        }
