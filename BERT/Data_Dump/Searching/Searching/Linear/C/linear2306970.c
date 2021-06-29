#include <stdio.h>

int main(){
    int an,bn,i,j,count=0;
    scanf("%d",&an);
    int A[an+1];
    for(i=0;i<an;i++)
        scanf("%d",&A[i]);
    scanf("%d",&bn);
    int B[bn+1];
    for(i=0;i<bn;i++)
        scanf("%d",&B[i]);
    
    //search
    for(i=0;i<bn;i++){
        j=0;
        A[an]=B[i];
        while(A[j]!=B[i])
            j++;
        if(j!=an)count++;
        //printf("j=%d\n",j);
    }
    printf("%d\n",count);
    
    return 0;
    
        
}
