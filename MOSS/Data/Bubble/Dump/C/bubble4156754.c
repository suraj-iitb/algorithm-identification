#include <stdio.h>
int main(){
    int A[100];
    int N;
    int i,x,flag;
    int cnt=0;
    
    scanf("%d",&N);
    for(i=0;i<N;i++) scanf("%d",&A[i]);

    while(flag){
        flag=0;
        for(i=N-1;i>0;i--){
            if(A[i]<A[i-1]){
                x=A[i];
                A[i]=A[i-1];
                A[i-1]=x;
                cnt++;
                flag=1;
                break;
            }
        }
    }
    
    for(i=0;i<N;i++){
        printf("%d",A[i]);
        if(i!=N-1) printf(" ");
    }
    printf("\n%d\n",cnt);
    
    return 0;
}

