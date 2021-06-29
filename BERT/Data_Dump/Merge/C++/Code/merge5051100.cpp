#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define INT_MAX 0x7fffffff
static int compareCnt = 0;

void merge(std::vector<int>& A, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;

    std::vector<int> L(n1+1);
    std::vector<int> R(n2+1);

    for (int i = 0; i < n1; i++){
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int lCnt = 0;
    int rCnt = 0;

    for (int k = left; k < right; k++) {
        if (L[lCnt] <= R[rCnt]) {
            A[k] = L[lCnt];
            lCnt++;
        } else {
            A[k] = R[rCnt];
            rCnt++;
        }
        compareCnt++;
    }
}

void mergeSort(std::vector<int>& A, int left, int right)
{
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }

    return;
}

int main(void)
{
    // マージソート

    int n = 0;
    std::cin >> n;

    std::vector<int> A(n);
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    mergeSort(A, 0, n);

    if (n > 0) {
        printf("%d", A[0]);
        for (int i = 1; i < A.size(); i++) {
            printf(" %d", A[i]);
        }
        printf("\n");
    }
    printf("%d\n", compareCnt);

    return 0;
}


