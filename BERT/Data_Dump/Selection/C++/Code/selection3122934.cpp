#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int *read_array(int N)
{
    int *array;
    int i,m;
    array = new int[N];
    for(i=0;i<N;i++){
        scanf("%d",&m);
        array[i] = m;
    }

    return array;
}

void print_array(int *array, int N)
{
    int i;
    for(i=0;i<N;i++){
        if(i!=N-1){
            printf("%d ",array[i]);
        }else{
            printf("%d",array[i]);
        }
    }
    printf("\n");
    return;
}

int selectionSort(int *A, int N)
{
    int i,j,minj,v,num,flag;
    num = 0;
    flag = 0;
    for(i=0;i<N;i++){
        minj = i;
        for(j=i;j<N;j++){
            if(A[j]<A[minj]){
                minj=j;
                flag = 1;
            }
        }
        v = A[minj];
        A[minj] = A[i];
        A[i] = v;
        if(flag){
            num += 1;
            flag = 0;
        }

    }
    return num;
}

int main()
{
    int *A,N,num;
    scanf("%d",&N);
    A = read_array(N);
    num = selectionSort(A,N);
    print_array(A,N);
    printf("%d\n",num);

    return 0;
}
