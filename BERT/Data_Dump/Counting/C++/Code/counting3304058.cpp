#include "iostream"
#include <algorithm>

using namespace std;

void CountingSort(int A[],int B[],int k){
  int C[2000000];
  for (int i = 0; i < k; i++) {
    C[i] = 0;
    for(int j = 1;j<k;j++){
      C[A[j]]++;
    }
    for(int j = k;j<1;j--){
      B[C[A[j]]] = A[j];
      C[A[j]]--;
    }
  }
}

int main(){
  int A[2000000],B[2000000];
  int n;
  int cnt = 0;
  cin >> n;
  for (int i=0; i < n; i++) {
    cin >> A[i];
  }
    for (int i=0; i < n; i++) {
    B[i] = A[i];
    cnt++;
  }
CountingSort(A,B,n);
sort(B,B+cnt);
cout << B[0];
  for (int i=1; i < n; i++) {
    cout << " ";
cout << B[i];
}
cout << endl;
return 0;
}

