#include <stdio.h>
#include <limits.h>
#define MAX_LENGTH 500000
int counter=0;
void Merge(int arr[], int left, int middle, int right)
{
    int n1 = middle - left;
    int n2= right - middle;
    int L[n1+1], R[n2+1];
    for(int i=0;i<n1;i++){L[i]=arr[left+i];}
    for(int i=0;i<n2;i++){R[i]=arr[middle+i];}
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i=0;
    int j=0;
    for(int k=left;k<right;k++)
    {
        if(L[i]<=R[j])
        {
            arr[k] = L[i];
            i += 1;
        }
        else{
            arr[k] = R[j];
            j += 1;
        }
        counter++;
    }
}
void MergeSort(int arr[], int left, int right)
{
    if(left+1 < right)
    {
        int middle = (left + right)/2;
        MergeSort(arr, left, middle);
        MergeSort(arr, middle, right);
        Merge(arr, left, middle, right);
    }
}
int main() {
    int num=0;
    int A[MAX_LENGTH]={0};
    scanf("%d", &num);
    for(int i=0;i<num;i++){scanf("%d", &A[i]);}
    MergeSort(A, 0, num);
    for(int i=0;i<num;i++)
    {
        if(i!=num-1){printf("%d ", A[i]);}
        else{printf("%d\n", A[i]);}
    }
    printf("%d\n", counter);
    return 0;
}

