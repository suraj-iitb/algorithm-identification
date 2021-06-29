#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define INFTY 1000000007

int merge(int A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  
  //L[0...n1], R[0...n2] を生成
  int L[n1+1], R[n2+1];
  for(int i = 0; i < n1; i++) L[i] = A[left + i];
  for(int i = 0; i < n2; i++) R[i] = A[mid + i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  
  int i = 0, j = 0;
  for(int k = left; k < right; k++) {
    if(L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    }
    else { 
      A[k] = R[j];
      j++;
    }
  }
  return right-left;
}

int mergeSort(int A[], int left, int right) {
  int ret = 0;
  if(left+1 < right) {
    int mid = (left + right)/2;
    ret += mergeSort(A, left, mid);
    ret += mergeSort(A, mid, right);
    ret += merge(A, left, mid, right);
  }
  return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  int s[n];
  rep(i, 0, n) cin >> s[i];
  
  int ans = mergeSort(s, 0, n);
  
  rep(i, 0, n) 
    cout << (i ?" " :"") << s[i];
  
  cout << "\n" << ans << "\n";
}
