#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int cnt = 0;

void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for(int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }
    L[n1] = 1000000000;
    R[n2] = 1000000000;
    int i = 0;
    int j = 0;
    for(int k = left; k < right; k++) {
        cnt++;
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else { 
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[], int left, int right) {
  if(left + 1 < right) {
      int mid;
      mid = (left + right) / 2;
      mergeSort(A, left, mid);
      mergeSort(A, mid, right);
      merge(A, left, mid, right);
  }
  return;
}

int main() {
    int n;
    int S[600000];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> S[i];
    }
    mergeSort(S, 0, n);
    for(int i = 0; i < n; i++) {
        if( i != 0 ) cout << " ";
        cout << S[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
