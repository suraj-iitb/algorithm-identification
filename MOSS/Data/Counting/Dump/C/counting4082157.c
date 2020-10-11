#include<stdio.h>
#define N 2000001

int main(){
    int i,j,A[N],n,a,count=0;
    
    scanf("%d",&n);
    for(i=0; i<=n; i++){
        A[i]=0;
    }
    for(i=0; i<n; i++){
        scanf("%d",&a);
        A[a]++;
    }
    for(i=0; i<=10000; i++){
        for(j=0; j<A[i]; j++){
            printf("%d", i);
            if(count<n-1){
                printf(" ");
                count++;
            }
        }
    }
    printf("\n");
    return 0;
}
