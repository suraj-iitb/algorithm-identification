#include <iostream>

using namespace std;

#define MAX 500000
#define INFTY 20000000000

long long L[MAX/2+2],R[MAX/2+2];
int cnt=0;

void merge(int A[],int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  for(int i=0; i < n1; ++i)   L[i] = A[left + i];
  for(int i=0; i < n2; ++i)   R[i] = A[mid + i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  int i = 0, j = 0;
  for(int k = left; k < right; ++k){
    ++cnt;
    if( L[i] <= R[j] ){
      A[k] = L[i++];
    }
    else{ 
      A[k] = R[j++];
    }
  }
}

void mergeSort(int A[],int left, int right){
  if( left+1 < right ){
    int mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
  
}

int main(){
  int n,A[MAX];
  cin >> n;
  for(int i=0; i<n; ++i)  cin >> A[i];

  mergeSort(A,0,n);

  for(int i=0; i<n; ++i){
    cout << A[i];
    if(i < n-1)
      cout << " ";
  }
  cout << endl << cnt << endl;


  return 0;
}

