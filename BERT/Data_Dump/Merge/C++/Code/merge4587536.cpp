#include<iostream>
using namespace std;

int cnt;
int L[500000/2+2], R[500000/2+2];

void merge( int A[], int left, int mid, int right ){
  int n1 = mid-left;
  int n2 = right-mid;

  for( int i=0; i<n1; i++ ){
    L[i] = A[left+i];
  }
  for( int i=0; i<n2; i++ ){
    R[i] = A[mid+i];
  }
  L[n1] = 1000000000;
  R[n2] = 1000000000;

  int a=0, b=0;
  for( int j=left; j<right; j++ ){
    cnt++;
    if( L[a] <= R[b] ){
      A[j] = L[a++];
    }else{
      A[j] = R[b++];
    }
  }
}

void mergeSort( int A[], int left, int right ){
  if( left+1 < right ){
    int mid = (left+right)/2;
    mergeSort( A, left, mid );
    mergeSort( A, mid, right );
    merge( A, left, mid, right );
  }
}

int main(){
  int n;
  cin >> n;

  int S[500000];
  for( int i=0; i<n; i++ ){
    cin >> S[i];
  }

  mergeSort( S, 0, n );

  for( int i=0; i<n; i++ ){
     if( i!=n-1 ){
       cout << S[i] << " ";
     }else{
       cout << S[i] << endl;
    }
  }

  cout << cnt << endl;

  return 0;
}
