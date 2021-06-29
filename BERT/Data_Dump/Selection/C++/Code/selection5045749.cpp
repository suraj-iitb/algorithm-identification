#include<stdio.h>
int main(void){
    int N,i,j,temp,min,A[100],sum=0;
    
    scanf("%d",&N);
    for(i=0;i<N;i++)scanf("%d",&A[i]);
    
    for(i=0;i<N;i++){
        min=i;
        for(j=i;j<N;j++){
            if(A[j]<A[min]){
                min=j;
            }
        }
        if(min!=i){
            temp=A[i];
            A[i]=A[min];
            A[min]=temp;
            sum++;
        }
    }
    
    for(i=0;i<N;i++){
        printf("%d",A[i]);
        if(i!=N-1)printf(" ");
    }
    
    printf("\n%d\n",sum);
}
