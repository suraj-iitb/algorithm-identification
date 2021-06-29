#include<stdio.h>
#include<iostream>

#define MAX_N 105

using namespace std;

int SelectionSort(int arr[], int N)
{
    int swapNum=0;
    for(int i=0; i<N-1; i++)
    {
        int minIdx=i;
        for(int j=i; j<N; j++)
        {
            if(arr[j]<arr[minIdx])
            {
                minIdx=j;
            }
        }
        if(minIdx!=i)
        {
            swap(arr[i], arr[minIdx]);
            swapNum++;
        }
    }
    return swapNum;
}

int main()
{
    int arr[MAX_N];
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", arr+i);
    int res=SelectionSort(arr, N);
    printf("%d", arr[0]);
    for(int i=1; i<N; i++)
        printf(" %d", arr[i]);
    printf("\n");
    printf("%d\n", res);
    return 0;
}
