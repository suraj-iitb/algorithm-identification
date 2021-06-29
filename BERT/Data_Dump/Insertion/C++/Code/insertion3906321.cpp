#include <iostream>
#include <string>

#define N 100

using namespace std;

void insertion_sort(int A[], int n) {
  for(int i = 0; i < n-1; i++) cout << A[i] << " ";
  cout << A[n-1] << endl;
    
  for(int i = 1; i< n; i++) {
    int v = A[i];
    int j = i-1;
    
    while(j >= 0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;

    for(int i = 0; i < n-1; i++) cout << A[i] << " ";
    cout << A[n-1] << endl;    
  }

  return;
}

int main(void)
{
  int n, A[N];
  cin >> n;

  for(int i = 0; i < n; i++) cin >> A[i];

  insertion_sort(A, n);

  return 0;
}
