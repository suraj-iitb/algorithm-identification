#include<stdio.h>

int selectionSort(int *,int);

int main(){
    int i,j,N;
    scanf("%d",&N);
    int A[N];
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    int flag = selectionSort(A,N);
    for(i=0;i<N-1;i++){
        printf("%d ",A[i]);
    }
    printf("%d\n%d\n",A[N-1],flag);
    return 0;
}

int selectionSort(int data[],int a)
{
    int i,j,n,minj;
    int flag=0;
    for(i=0;i<a;i++){
        minj=i;
        for(j=i;j<a;j++){
            if(data[j]<data[minj]){
            minj=j;
            }
        }
    if(minj!=i){
        n = data[i];
        data[i] = data[minj];
        data[minj] = n;
        flag++;
    }
    }
    return flag;
}
