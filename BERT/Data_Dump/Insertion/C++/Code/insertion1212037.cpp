#include <iostream>
using namespace std;

static const int MAX_N = 100;

void insertionSort(int A[], int n){
  for(int i = 1; i < n; i++){
    int v = A[i];
    int j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(int j = 0; j < n; j++){
      cout << A[j];
      if(j < n - 1) cout << " ";
    }
    cout << endl;
  }
}

int main(void){ 
  int A[MAX_N], n;

  cin >> n;
  for(int i = 0; i < n; i++) cin >> A[i];

  for(int i = 0; i < n; i++){
    cout << A[i];
    if(i < n - 1) cout << " ";
  }
  cout << endl;
  insertionSort(A, n);

  return 0;
}
