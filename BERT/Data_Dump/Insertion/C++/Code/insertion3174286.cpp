#include <iostream>

using namespace std;
/*
1 insertionSort(A, N) // N個の要素を含む0-オリジンの配列A
2   for i が 1 から N-1 まで
3     v = A[i]
4     j = i - 1
5     while j >= 0 かつ A[j] > v
6       A[j+1] = A[j]
7       j--
8     A[j+1] = v
*/
void printArray(int n, int a[]){
  for (int i=0; i<n-1; i++) cout << a[i] << " ";
  cout << a[n-1] << endl;
}

int main(void){
  int n;
  int a[100];
  
  cin >> n;
  for (int i=0; i<n; i++) cin >> a[i];
  printArray(n,a);
  for (int i=1; i<n; i++){
    int j,t = a[i];
    for (j=i; j>0 && a[j-1]>t; j--){
      a[j] = a[j-1];
    }
    a[j] = t;
    // test output
    printArray(n,a);
  }
  return 0;
}

