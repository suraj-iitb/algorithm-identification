#include <stdio.h>
i,j,t,N,f=1,A[100];
int main(void){
    for(scanf("%d",&N);i<N;scanf("%d",&A[i++]));
    for(i=0;f==1;i++){
        f=0;
        for(j=N-1;j>i;j--){
            if(A[j]<A[j-1])A[j]^=A[j-1]^=A[j]^=A[j-1],t++;
            f=1;
        }
    }
    for(i=0;i<N;printf("%d%s",A[i],i==N-1?"\n":" "),i++);
    printf("%d\n",t);
}
