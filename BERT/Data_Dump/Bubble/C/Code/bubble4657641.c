#include<stdio.h>
int bubbleSort(int A[],int N){
    int j,i,x=0;
    unsigned short flag=1;
    // flag=
    while(flag){
        flag=0;
        for(j=N-1;j>0;j--){
            if(A[j]<A[j-1]){
                i=A[j-1];
                A[j-1]=A[j];
                A[j]=i;
                flag=1;
                x++;
            }
        }
    }
    return x;
}
int main(void){
    int i,N,x;
    scanf("%d\n",&N);
    int a[N];
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    x=bubbleSort(a,N);
    for(i=0;i<N;i++){
        printf("%d",a[i]);
        if(i==N-1)break;
        printf(" ");
    }
    printf("\n%d\n",x);
    return 0;
}
