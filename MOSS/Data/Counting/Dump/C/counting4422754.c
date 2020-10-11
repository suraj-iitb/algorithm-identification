#include <stdio.h>
#include <stdlib.h>

#define VMAX (10000)

int main(void){
    int A[VMAX+1],t;
    int n,i,cnt;
    scanf("%d",&n);
    cnt=0;
    for(i=0;i<=VMAX;i++)A[i]=0;
    
    for(i=0;i<n;i++){
        scanf("%d",&t);
        A[t]++;
    }
    for(i=0;i<=VMAX;i++){
        while(A[i]>0){
            printf("%d",i);
            A[i]--;
            cnt++;
            if(cnt<n)printf(" ");
        }
    }
    printf("\n");
    return 0;
}
