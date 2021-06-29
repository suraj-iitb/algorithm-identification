#include<stdio.h>

int main(){
    int A[10000];
    int n,a,i,j,count=0;
    
    scanf("%d",&n);
    
    for(i=0;i<10000;i++){
        A[i]=0;
    }
    
    for(i=0;i<n;i++){
        scanf("%d",&a);
        A[a]++;
    }
    
    for(i=0;i<10000;i++){
        for(j=0;j<A[i];j++){
            printf("%d",i);
            if(count<n-1){
                printf(" ");
                count++;
            }
        }
    }
    
    printf("\n");
    
    return 0;
    
}

