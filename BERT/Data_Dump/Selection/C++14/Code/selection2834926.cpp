#include<iostream>
#include<utility>

using namespace std;

int main()
{
  int n; cin >> n;
  int A[n] = {0};
  for (int i = 0; i < n; ++i)
    cin >> A[i];

  int swaps{0};
  for (int i = 0; i < n; ++i) {
    int minidx = i;
    for (int j = i; j < n; ++j) {
      if (A[j] < A[minidx]) minidx = j;
    }
    if (minidx != i) ++swaps, swap(A[minidx], A[i]);
  }
  
  for (int i = 0; i < n; ++i) {
    if(i) cout << " ";
    cout << A[i];
  }

  cout << endl << swaps << endl;
}
