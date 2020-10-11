#include <stdio.h>


int main(){
    int N,i,j,num[1001],v,x;
    
    scanf("%d",&N);
    for (i=0; i<N; i++) {
        scanf("%d",&num[i]);
    }
    for (x=0; x<N;x++) {
        if (x==N-1) printf("%d",num[x]);
        else printf("%d ",num[x]);
    }
    printf("\n");

    
    for (i=1; i<N; i++) {
        v=num[i];
        j=i-1;
        while (j>=0 && num[j]>v) {
            num[j+1]=num[j];
            j--;
        }
        
        num[j+1]=v;
        for (x=0; x<N;x++) {
            if (x==N-1) printf("%d",num[x]);
            else printf("%d ",num[x]);
        }
        if (i != N) printf("\n");

    }
    
    return(0);
}
