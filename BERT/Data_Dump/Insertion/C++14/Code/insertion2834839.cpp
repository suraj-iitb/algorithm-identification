#include<iostream>
#include<vector>

using namespace std;

int main()
{
  int N;
  cin >> N;
  cin.get();  // advance line

//int A[N];
  vector<int> A(N);

  for (int i = 0; i < N; ++i)
    cin >> A[i];

  for (int k = 0; k < N; ++k) {
    if (k > 0) cout << " ";
    cout << A[k];
  }
  cout << endl;

  for (int i = 1; i < N; ++i) {
    int key = A[i];
    int j=i-1;
    for (; j>=0 and A[j]>key; --j)
      A[j+1]=A[j];
    A[j+1]=key;

    for (int k = 0; k < N; ++k) {
      if (k > 0) cout << " ";
      cout << A[k];
    }
    cout << endl;
  }
}
