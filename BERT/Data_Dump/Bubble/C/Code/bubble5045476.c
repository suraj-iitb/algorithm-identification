#include<stdio.h>

int bubbleSort(int *,int);

int main()
{
    int i,j,N;
    scanf("%d",&N);
    int A[N];
    for(i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }
    int flag = bubbleSort(A,N);
    for(i=0;i<N-1;i++){
        printf("%d ",A[i]);
    }
    printf("%d\n%d\n",A[N-1],flag);
    return 0;
}

int bubbleSort(int data[],int a)
{
    int i,j,n;
    int flag = 0;
    for(i=0;i<a;i++){
        for(j=a-1;i<j;j--){
            if(data[j]<data[j-1]){
                n = data[j];
                data[j] = data[j-1];
                data[j-1] = n;
                flag++;
            }
        }
    }
    return flag;
}
