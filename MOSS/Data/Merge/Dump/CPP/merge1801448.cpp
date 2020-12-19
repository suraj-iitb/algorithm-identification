#include <iostream>
using namespace std;

int L[250002],R[250002],cnt;//分割したものをL,Rとする

//統治
void merge( int A[], int left, int mid, int right, int n ) {
  int n1 = mid - left;
  int n2 = right - mid;
  for ( int i = 0; i < n1; i++ ) L[i] = A[left + i];
  for ( int i = 0; i < n2; i++ ) R[i] = A[mid + i];  
  L[n1] = R[n2] = 2000000000;//番兵
  int i = 0, j = 0;
  for ( int k = left; k < right; k++ ) {
    cnt++; //比較回数をカウント
    if ( L[i] <= R[j] ) {
      A[k] = L[i];
      i = i + 1;
    } else {
      A[k] = R[j];
      j = j + 1;
    }
  }
}

//分割
void mergeSort( int A[], int left, int right, int n ) {
  if ( left+1 < right ) {
    int mid = ( left + right ) / 2;
    mergeSort( A, left, mid, n );
    mergeSort( A, mid, right, n );
    merge( A, left, mid, right, n );
  }
}

int main() {
  int A[600000],n;
  cin >> n;
  for ( int i = 0; i < n; i++ ) cin >> A[i];

  mergeSort( A, 0, n, n);
  
  for ( int i = 0; i < n-1; i++ ) cout << A[i] << " ";
  cout << A[n-1] << endl;
  cout << cnt << endl;//比較回数を出力 
  return 0;
}
