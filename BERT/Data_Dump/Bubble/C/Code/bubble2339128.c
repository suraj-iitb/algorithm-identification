#include<stdio.h>
 int main(void){
    int i,j,N,mem,min;
    int a[150];
    min =0;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<N-1;i++){
        for(j=0;j<N-1;j++){
            if(a[j]>a[j+1]){
                mem=a[j];
                a[j]=a[j+1];
                a[j+1]=mem;
                min++;
            }
        }
    }
    for(i=0;i<N-1;i++){
        printf("%d ",a[i]);
    }
    printf("%d\n%d\n",a[N-1],min);

    return 0;
 }
