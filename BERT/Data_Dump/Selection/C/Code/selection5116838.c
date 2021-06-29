#include<stdio.h>

#define N 100

int selectionSort(int [],int);

int main(){
    int i,n,A[N],sw;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    sw=selectionSort(A,n);

    for(i=0;i<n;i++){
        if(i)printf(" ");
        printf("%d",A[i]);
    }
    printf("\n%d\n",sw);

    return 0;
}

int selectionSort(int A[],int n){
    int i,j,tem,minv,sw=0,flag;
    for(i=0;i<n;i++){
        minv=i;
        flag=0;
        for(j=i;j<n;j++){
            if(A[minv]>A[j]){
                minv=j;
                flag=1;
            }
        }
        tem=A[i];
        A[i]=A[minv];
        A[minv]=tem;
        if(flag)sw++;
    }
    return sw;
}
