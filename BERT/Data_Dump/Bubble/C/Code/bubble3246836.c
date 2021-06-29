#include <stdio.h>
int main(){
    int A[100];
    int n;
    int j,t;
    int flag=1,count=0;
    
    scanf("%d",&n);
    for(j=0;j<n;j++){
        scanf("%d",&A[j]);
    }

    while(flag){
        flag = 0;
        for (j=n-1;j>0;j--){
            if(A[j]<A[j-1]){
                t=A[j];
                A[j]=A[j-1];
                A[j-1]=t;
                flag=1;
                count++;
            }
        }
    }
    for(j=0;j<n;j++){
        printf("%d",A[j]);
        if(j<n-1)printf(" ");
    }
    printf("\n%d\n",count);
    
    return 0;
}

