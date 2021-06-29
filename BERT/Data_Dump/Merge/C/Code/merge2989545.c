#include <stdio.h>
#include <stdlib.h>
int Merge(int *A, int left,int mid,int right);
int Sort(int *A, int left, int right);
int main(int argc, char** argv) {
 
    int size;
    scanf("%d",&size);
    int right = size;
    int left = 0;
    int array[size];
    for(int i= 0; i<size; i++)
    {
        scanf("%d", &array[i]);
    }

    int count;
    count = Sort(array, left, right);
    for(int i=0; i<size;i++)
    {
        if(i!=size-1)
        printf("%d ",array[i]);
        if(i==size-1)
        printf("%d\n",array[i]);
    }
    printf("%d\n", count);
    
    return (EXIT_SUCCESS);
}
int Merge(int *A, int left,int mid,int right)
{
    int count = 0;
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1], R[n2];
    for(int i = 0; i<n1;i++)
    { 
        L[i] = A[left + i];
    }
    for( int i= 0 ;i< n2;i++)
    {
        R[i] = A[mid + i];
    }
    int i = 0;
    int j = 0;
    for(int k=left; k<right;k++)
    {
        if(j>=n2||i<n1 && L[i] <= R[j])
        {
            A[k] = L[i];
            i = i + 1;
        }
        else
        {
            A[k] = R[j];
            j = j + 1;
        }
        count++;
    }
    return count;
}
int Sort(int *A, int left, int right)
{   
    int count = 0;
    int mid=(left + right)/2;
    if(left+1 < right)
    {
        count = count + Sort(A, left, mid);
        count = count + Sort(A, mid, right);
        count = count + Merge(A, left, mid, right);
 
    }
    return count;
}

