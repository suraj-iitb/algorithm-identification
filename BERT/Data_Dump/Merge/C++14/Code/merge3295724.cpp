#include <bits/stdc++.h>
#define lp(n) for(int i = 0; i < n; i++)
#define LP(i, a, n) for(int i = a; i < n; i++)
#define lpp(i, n) for(int i = 0; i < n; i++)
#define INF 1e9+7
using namespace std;
int c;
void merge(int A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1+1], R[n2+1];
  lp(n1)
    L[i] = A[left + i];
  lp(n2)
    R[i] = A[mid + i];
  L[n1] = INF;
  R[n2] = INF;
  int i = 0;
  int j = 0;
  LP(k,left,right){
    c++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else {
      A[k] = R[j];
      j = j + 1;
    }
  }
}
void mergeSort(int A[], int left, int right) {
  if(left+1 < right) {
    int mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
int main(){
  int n, S[500000];
  cin >> n;
  lp(n) cin >> S[i];
  mergeSort(S, 0, n);
  lp(n) cout << S[i] << (n-1 == i ? "\n":" ");
  cout << c << endl;
  return 0;
}


