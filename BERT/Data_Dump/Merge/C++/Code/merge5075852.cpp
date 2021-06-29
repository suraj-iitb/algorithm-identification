#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define MAX 500000
#define INFTY 1000000001

int cnt = 0;
int L[MAX/2+5], R[MAX/2+5];

void Merge(int *A, int left, int mid, int right) {
  int n1 = mid-left;
  int n2 = right-mid;

  for(int i=0; i<n1; ++i) L[i] = A[left+i];
  for(int i=0; i<n2; ++i) R[i] = A[mid+i];

  L[n1] = R[n2] = INFTY;

  int i=0, j=0;
  for(int k=left; k<right; ++k) {
    ++cnt;
    if(L[i] <= R[j]) A[k] = L[i++];
    else A[k] = R[j++];
  }
}

void MergeSort(int *A, int left, int right) {
  if(left+1 < right) {
    int mid = (left+right)/2;
    MergeSort(A, left, mid);
    MergeSort(A, mid, right);
    Merge(A, left, mid, right);
  }
}

int main() {
  int n; cin >> n;
  int num;
  int S[MAX];

  for(int i=0; i<n; ++i) cin >> S[i];
  MergeSort(S, 0, n);
  for(int i=0; i<n; ++i) {
    if(i) cout << " ";
    cout << S[i];
  }
  cout << endl;
  cout << cnt << endl;
}

