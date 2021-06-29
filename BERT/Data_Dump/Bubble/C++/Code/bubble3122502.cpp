#include <iostream>
#include <stdlib.h>
#include <stdio.h>

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

int bubbleSort(int *A, int N)
{
    int flag,j,v,num;
    flag = 1;
    num = 0;
    while(flag){
        flag = 0;
        for(j=N-1;j>0;j--){
            if(A[j]<A[j-1]){
                v = A[j];
                A[j] = A[j-1];
                A[j-1] = v;
                flag = 1;
                num += 1;
            }
        }
    }
    return num;
}

int main()
{
    int *A;
    int N,num;
    scanf("%d",&N);
    A = read_array(N);
    num = bubbleSort(A,N);
    print_array(A,N);
    printf("%d\n",num);

    delete [] A;
    return 0;
}
