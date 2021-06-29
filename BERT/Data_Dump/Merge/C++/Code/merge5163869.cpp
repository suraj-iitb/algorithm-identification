#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)

long A[500010],INF = 1000000050;
long ans = 0;
long L[250005],R[250005];

void merge(long A[], long left, long mid, long right){
  long n1 = mid - left;
  long n2 = right - mid;
  rep(i,n1){
    L[i] = A[left + i];
  }
  rep(i,n2){
    R[i] = A[mid + i];
  }
  L[n1] = R[n2] = INF;
  long i = 0, j = 0;
  for(int k = left; k < right; k++){
    ans++;
    if(L[i] <= R[j]){
      A[k] = L[i++];
    }else{
      A[k] = R[j++];
    }
  }
}

void mergeSort(long A[], long left, long right){
  if(left + 1 < right){
    long mid = (left + right) / 2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A, left, mid, right);
  }
}

int main(){
  long n,S[500010];
  cin >> n;
  rep(i,n){
    cin >> S[i];
  }

  mergeSort(S,0,n);

  rep(i,n-1){
    cout << S[i] << " ";
  }
  cout << S[n-1] << endl;
  cout << ans << endl;
}
