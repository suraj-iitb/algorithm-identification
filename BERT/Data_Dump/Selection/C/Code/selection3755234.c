#include<stdio.h>

//选择排序法（0起点）
int selectSort(int A[],int N)
{
    int i,j,minj,temp,sw=0;
    for(i=0;i<N-1;i++)
    {
        minj=i;
        for(j=i+1;j<N;j++)
        {
            if(A[j]<A[minj])
                minj=j;
        }
        if(minj!=i)
        {
            sw++;
            temp=A[i];
            A[i]=A[minj];
            A[minj]=temp;
        }
    }
    return sw;
}

int main()
{

    int A[100],N,i,sw;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&A[i]);

    sw = selectSort(A,N);

    for(i=0;i<N;i++)
    {
        if(i) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
    printf("%d\n",sw);
    return 0;
}

