#include <iostream>
using namespace std;

int cnt = 0;

void bubbleSort(int A[], int N)
{
  bool flag = true;
  while (flag)
  {
    flag = false;
    for (int i = N - 1; i > 0; i--)
    {
      if (A[i] < A[i - 1])
      {
        int temp = A[i];
        A[i] = A[i - 1];
        A[i - 1] = temp;
        flag = true;
        cnt++;
      }
    }
  }
}

int main(void)
{
  int N, A[100];
  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> A[i];

  bubbleSort(A, N);

  for (int i = 0; i < N; i++)
  {
    if (i > 0)
      cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << cnt << endl;

  return 0;
}
