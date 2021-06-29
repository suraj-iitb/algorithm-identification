#include <stdio.h>
int main(){
    int N,flag=1,A[100],count,t,j,i,a;
    scanf("%d",&N);
    for(t=0;t<N;t++){
        scanf("%d",&A[t]);
        }
        i=0;
    while(flag==1){
        flag=0;
    for(j=N-1;j>i;j--){
            if(A[j]<A[j-1]){
                a=A[j-1];
                A[j-1]=A[j];
                A[j]=a;
                count++;
                flag=1;
            }
        }
        i++;
    }
        for(j=0;j<N;j++){
            printf("%d",A[j]);
            if(j<N-1)
                printf(" ");
        }
        printf("\n");
        printf("%d\n",count);
        return 0;
}
