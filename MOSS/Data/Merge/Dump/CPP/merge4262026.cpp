#include <bits/stdc++.h>
using namespace std;
int C = 0;
const int INF = 2000000000;
void merge(vector<int> &A, int left, int mid, int right){
  vector<int> L(mid - left + 1);
  for (int i = 0; i < mid - left; i++){
    L[i] = A[left + i];
  }
  L[mid - left] = INF;
  vector<int> R(right - mid + 1);
  for (int i = 0; i < right - mid; i++){
    R[i] = A[mid + i];
  }
  R[right - mid] = INF;
  int i = 0;
  int j = 0;
  for (int k = left; k < right; k++){
    C++;
    if (L[i] <= R[j]){
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}
void merge_sort(vector<int> &A, int left, int right){
  if (left + 1 < right){
    int mid = (left + right) / 2;
    merge_sort(A, left, mid);
    merge_sort(A, mid, right);
    merge(A, left, mid, right);
  }
}
int main(){
  int n;
  cin >> n;
  vector<int> S(n);
  for (int i = 0; i < n; i++){
    cin >> S[i];
  }
  merge_sort(S, 0, n);
  for (int i = 0; i < n; i++){
    cout << S[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
  cout << C << endl;
}
