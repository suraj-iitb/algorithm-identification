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
  for (int i = 0; i < n; ++i)
    for (int j=n-1; j > i; --j)
      if (A[j] < A[j-1])
        swap(A[j], A[j-1]), swaps++;
  
  for (int i = 0; i < n; ++i)
    cout << ((i==0) ? "" : " ") << A[i];
  cout << endl << swaps << endl;
}
