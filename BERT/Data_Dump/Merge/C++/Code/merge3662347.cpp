#include<iostream>
using namespace std;
#define INF 10000000000;

int cnt = 0;

void merge(int A[], int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int l[n1+1], r[n2+1];
  for ( int i = 0; i < n1; i++){ l[i] = A[left + i]; }
  for ( int i = 0; i < n2; i++){ r[i] = A[mid + i]; }
  l[n1] = INF;
  r[n2] = INF;

  int i = 0, j = 0;
  for ( int k = left; k < right; k++){
    if ( l[i] < r[j]){
      A[k] = l[i];
      i ++;
    } else {
      A[k] = r[j];
      j ++;
    }
    cnt ++;
  }
}

void mergeSort(int A[], int left, int right){
  if ( left + 1 < right){
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(){
  int n;
  cin >> n;
  int A[n+1];
  for ( int i = 0; i < n; i++){
   cin >> A[i];
  }

  mergeSort(A, 0, n);

  for ( int i = 0; i < n; i++){
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  
  cout << cnt << endl;

  return 0;
}
