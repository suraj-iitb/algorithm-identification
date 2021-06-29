#include <iostream>

void merge(int A[], int left, int mid, int right, int &times)
{
    int n1 = mid - left;
    int n2 = right - mid;

    int* L = new int[n1+1];
    int* R = new int[n2+1];

    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + i];

    L[n1] = 2e9;
    R[n2] = 2e9;

    int i = 0;
    int j = 0;

    for (int k = left; k < right; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
            times++;
        }
        else
        {
            A[k] = R[j];
            j++;
            times++;
        }
    }
}

void mergeSort(int A[], int left, int right, int &times)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;

        mergeSort(A, left, mid, times);
        mergeSort(A, mid, right, times);
        merge(A, left, mid, right, times);
    }
}

int main()
{
    int n;
    std::cin >> n;

    int *S = new int[n];
    for (int i = 0; i < n; i++) std::cin >> S[i];

    int times = 0;
    mergeSort(S, 0, n, times);

    for (int i = 0; i < n - 1; i++) std::cout << S[i] << " ";
    std::cout << S[n-1] << std::endl;
    std::cout << times << std::endl;
}
