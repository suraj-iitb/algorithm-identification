#include <iostream>
#include <cstdio>
#include <cmath>
// #include <stack>
// #include <vector>
#include <cstring>
// #include <algorithm>
using namespace std;

const int SENTINEL = 1000000001;
int N, A[500000];
int count = 0;

void merge(int left, int mid, int right) {
    int leftA[250001];
    for (int i = left; i < mid; i++) {
        leftA[i - left] = A[i];
    }
    leftA[mid - left] = SENTINEL;
    int leftCur = 0;
    
    int rightA[250001];
    for (int j = mid; j < right; j++) {
        rightA[j - mid] = A[j];
    }
    rightA[right - mid] = SENTINEL;
    int rightCur = 0;
    
    for (int i = left; i < right; i++) {
        // printf("%d:%d - %d:%d\n", leftCur, leftA[leftCur], rightCur, rightA[rightCur]);
        // cout << endl;
        if (leftA[leftCur] <= rightA[rightCur]) {
            A[i] = leftA[leftCur];
            leftCur++;
        } else {
            A[i] = rightA[rightCur];
            rightCur++;
        }
        
        count++;        
    }
}

void mergeSort(int left, int right) {
    // printf("%d,%d --- mergeS \n", left, right);
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        // cout << mid;
        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    mergeSort(0, N);

    for (int i = 0; i < N; i++) {
        if (i != 0) {
            cout << " ";
        }
        printf("%d", A[i]);
    }
    
    cout << endl;
    
    printf("%d\n", count);
    
    return 0;
}
