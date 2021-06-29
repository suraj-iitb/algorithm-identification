#include<stdio.h>
int main(void){
    int i,j,cnt=0,tmp,N,A[100],min=100,mins=0;
    scanf("%d", &N);
    for(i=0;i<N;i++) scanf("%d",&A[i]);
    for(i=0;i<N-1;i++){
        min=A[i];
        mins=i;
        for(j=i+1;j<N;j++){
            if(A[j]<min){
                mins=j;
                min=A[j];
            }
        }
        if(mins!=i){
            tmp=A[i];
            A[i]=A[mins];
            A[mins]=tmp;
            cnt++;
        }
    }
    printf("%d",A[0]);
    for(i=1;i<N;i++) printf(" %d",A[i]);
    printf("\n");
    printf("%d\n",cnt);
    return 0;
}
