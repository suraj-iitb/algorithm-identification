#include <iostream>
using namespace std;

#define MAX 101
int A[MAX];

void print(int A[], int n){
  int i;
  for(i = 0; i < n; i++){
    if (i > 0) cout << " ";
    cout << A[i];
  }
  cout << "\n";
}

void InsertionSort(int A[], int n){
  int i, j, v, x;
  for (i = 1; i < n; i++){
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v){
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
    print(A, n);
  }
}

int main(){
  int i, n;
  cin >> n;
  for (i = 0; i < n; i++){
    cin >> A[i];
  }
  print(A, n);
  InsertionSort(A, n);
  return 0;
}

