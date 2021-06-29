#include <iostream>
#include <string>
#include <climits>
using namespace std;

int cnt = 0;
void merge(int *A, int left, int mid, int right){
    int n1 = mid - left, n2 = right - mid;
    int L[n1+1], R[n2+1];
    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1] = INT_MAX, R[n2] = INT_MAX;

    int curL = 0, curR = 0;
    for (int k = left; k < right; k++){
        if (L[curL] <= R[curR]){
            A[k] = L[curL];
            curL++;
        }else{
            A[k] = R[curR];
            curR++;
        }
        cnt++;
    }
}

void mergeSort(int *A, int left, int right){
    if (left+1 < right){
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    int s[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    mergeSort(s, 0, n);
    for (int i = 0; i < n-1; i++) cout << s[i] << " ";
    cout << s[n-1] << "\n" << cnt << "\n";
    return 0;
}

