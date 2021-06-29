#include<stdio.h>

int main(){
    int A[10000];
    int n,i,x,j,cnt=0;
    scanf("%d",&n);
    for(i=0;i<10000;i++){
        A[i]=0;
    }
    for(i=0;i<n;i++){
        scanf("%d",&x);
        A[x]++;
    }
    for(i=0;i<10000;i++){
        for(j=0;j<A[i];j++){
            printf("%d",i);
            if(cnt<n-1){
                printf(" ");
                cnt++;
            }
        }
    }
    printf("\n");
    return 0;
}
