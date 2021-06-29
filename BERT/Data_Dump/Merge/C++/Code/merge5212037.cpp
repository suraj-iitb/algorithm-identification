#include <iostream>
#define MAX 5000000
#define SENTINEL 2000000000
int L[MAX/2+2], R[MAX/2+2];
int cnt;

void merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) L[i] = A[left+i];
    for (int j = 0; j < n2; j++) R[j] = A[mid + j];
    L[n1] = R[n2] = SENTINEL;
    int i = 0, j = 0;
    for (int k = left; k < right; k++)
    {
        cnt++;
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[], int left, int right)
{
    if (left+1 <right)
    {
        int mid = (right - left) / 2 +left;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(void)
{
    int A[MAX], n, i;
    cnt = 0;
    std::cin>> n;
    for (int i = 0; i < n; i++) std::cin >> A[i];
    mergeSort(A, 0, n);
    for (int i = 0; i < n; i++)
    {
        if (i) std::cout<<" ";
        std::cout<<A[i];
    }
    std::cout<<std::endl;
    std::cout<<cnt<<std::endl;
    return 0;
}
