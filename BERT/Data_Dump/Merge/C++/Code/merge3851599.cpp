#include <iostream>
#include <climits>
using namespace std;

int n;
int A[500004];

int Merge(int lft, int mid, int rit){
  int res = 0;
  int n1 = mid - lft;
  int n2 = rit - mid;
  int L[n1 + 1], R[n2 + 1];

  for(int i = 0; i <= n1 - 1; i++){
    L[i] = A[lft + i];
  }
  for(int i = 0; i <= n2 - 1; i++){
    R[i] = A[mid + i];
  }
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;

  int i = 0;
  int j = 0;
  for(int k = lft; k <= rit - 1; k++){
    res++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else{
      A[k] = R[j];
      j = j + 1;
    }
  }

  return res;
}

int MergeSort(int lft, int rit){
  int res = 0;

  if(lft + 1 < rit){
    int mid = (lft + rit) / 2;
    res += MergeSort(lft, mid);
    res += MergeSort(mid, rit);
    res += Merge(lft, mid, rit);
  }

  return res;
}

int main(){
  while(cin >> n){
    for(int i = 0; i < n; i++){
      cin >> A[i];
    }

    int ans = MergeSort(0, n);

    for(int i = 0; i < n; i++){
      if(i != 0) cout << " ";
      cout << A[i];
    }
    cout << endl;
    cout << ans << endl;
  }
}

