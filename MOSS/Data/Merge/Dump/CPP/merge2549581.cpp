#include <bits/stdc++.h>
using namespace std;

int x[500001];
int tmp[500001];
int cnt = 0;

void MergeSort(int left, int right){
  int mid, i, j, k;

  if(left >= right) return;

  mid = (left+right)/2;
  MergeSort(left, mid);
  MergeSort(mid+1, right);
  // x[left]~x[mid]???????\??????????
  for(i = left; i <= mid; i++) tmp[i] = x[i];
  // x[mid+1]~x[right]??????????????????
  for(i = mid+1, j = right; i <= right; i++, j--) tmp[i] = x[j];

  i = left;
  j = right;
  for(k = left; k <= right; k++){
    cnt++;
    if(tmp[i] <= tmp[j]){
      x[k] = tmp[i++];
    }else{
      x[k] = tmp[j--];
    }
  }
}

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> x[i];
  MergeSort(0, n-1);
  for(int i = 0; i < n; i++){
    cout << x[i] << (i != n-1 ? " " : "\n");
  }
  cout << cnt << endl;
  return 0;
}
