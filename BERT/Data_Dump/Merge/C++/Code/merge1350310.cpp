#include <iostream>
#include <climits>
#define rep(i,a) for(i = 0; i < a; i++)
using namespace std;

int count = 0;
void marge(int *, int,int,int);
void margeSort(int *, int,int);

int main(void) {
  int i,n,l,r;
  cin >> n;
  int S[n];
  rep(i,n) {
    cin >> S[i];
  }
  l = 0;
  r = n;
  margeSort(S,l,r);
  rep(i,n){
    cout << S[i];
    if(i < n-1) cout << " ";
  }
  cout << endl;
  cout << count << endl;
  return 0;
}

void marge(int *A, int l, int m, int r) {
  int n1,n2,i,j,k;
  n1 = m - l;
  n2 = r - m;
  int L[n1+1], R[n2+1];
  rep(i,n1) {
    L[i] = A[l + i];
  }
  rep(i,n2) {
    R[i] = A[m + i];
  }
  L[n1] = INT_MAX/2;
  R[n2] = INT_MAX/2;
  i = 0;
  j = 0;
  for(k = l; k < r; k++) {
    if(L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    count++;
  }
}

void margeSort(int *A, int l, int r) {
  if(l+1 < r) {
    int m = (l + r) / 2;
    margeSort(A,l,m);
    margeSort(A,m,r);
    marge(A,l,m,r);
  }
}
