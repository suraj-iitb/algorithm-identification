#include <stdio.h>

void dis(int *arr,int n)
{
    for(int i = 0;i<n;i++)
    {
        if(i>0)
            printf(" ");
        printf("%d",arr[i]);
    }
    printf("\n");
}

void InsertionSort(int *arr,int n)
{
    dis(arr,n);
    for(int i = 1;i<n;i++)
    {
        int v = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>v)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = v;

        dis(arr,n);
    }
}



int main(int argc, char *argv[])
{
//    int arr[] = {1,3,5,7,2,4,6,8};
//    int arr[] = {8,7,6,5,4,3,2,2};
//    dis(arr,8);
//    InsertionSort(arr,8);
//    dis(arr,8);
    int N;
    int A[100];

    scanf("%d",&N);
    for(int i = 0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }
    InsertionSort(A,N);
    return 0;
}

