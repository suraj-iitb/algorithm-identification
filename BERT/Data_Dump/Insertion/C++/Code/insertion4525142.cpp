#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

void printSequence(int A[], int N)
{
  rep(i, N)
  {
    cout << A[i];
    if (i == N - 1)
    {
      cout << endl;
    } else {
      cout << " ";
    }
  }
}

void insertionSort(int A[], int N)
{
  for (int i = 1; i < N; i++)
  {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v)
    {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
    printSequence(A, N);
  }
}

int main()
{
  int N;
  cin >> N;

  int A[N];
  rep(i, N) cin >> A[i];

  printSequence(A, N);
  insertionSort(A, N);

  return 0;
}
