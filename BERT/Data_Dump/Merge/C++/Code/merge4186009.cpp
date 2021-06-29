#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define REPR(i, m, n) for (int i = (int)(m); i >= (int)(n); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;

#define MAX 500000
#define SENTINEL 2000000000

int n;
int A[MAX];
int L[MAX/2+2], R[MAX/2+2];
int cnt;

void merge(int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  rep(i, n1) L[i] = A[left+i];
  rep(i, n2) R[i] = A[mid+i];
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;
  int i = 0;
  int j = 0;
  REP(k, left, right-1){
    cnt++;
    if(L[i] <= R[j]) A[k] = L[i++];
    else A[k] = R[j++];
  }
}

void mergeSort(int left, int right){
  if(left+1 < right){
    int mid = (left+right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}

int main(){
  cin >> n;
  rep(i, n) cin >> A[i];

  cnt = 0;
  mergeSort(0, n);

  rep(i, n){
    if(i == n-1) cout << A[i] << endl;
    else cout << A[i] << " ";
  }
  cout << cnt << endl;
 
  return 0;
}



