#include <iostream>
#include <cstdio>

int comp_num = 0;
int A[500000];
int L[500000/2 + 3];
int R[500000/2 + 3];

void DumpArray(int *A, int n)
{
    for (int i = 0; i < n; i++) {
        std::cout << A[i];
        if (i != n - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void Merge(int *A, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;

    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }

    L[n1] = 1000000001;
    R[n2] = 1000000001;

    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        comp_num++;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort(int *A, int left, int right)
{
    if (left + 1 < right) {
        int mid = (left + right) / 2 ;
        MergeSort(A, left, mid);
        MergeSort(A, mid, right);
        Merge(A, left, mid, right);
    }
}

int main(int argc, char *argv[])
{
    int n;
    int A[500000];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    MergeSort(A, 0, n);

    DumpArray(A, n);
    std::cout << comp_num << std::endl;
    return 0;
}
