#include <iostream>
#include <algorithm>
using namespace std;
static int const MAX = 100;

void trace(int A[], int N)
{
  for (int i = 0; i < N; i++)
  {
    if (i > 0)
      cout << " ";
    cout << A[i];
  }
  cout << endl;
}

int bubbleSort(int A[], int N)
{
  bool flag = true;
  int i = 0;
  int count = 0;
  while (flag)
  {
    flag = false; // 交換できない時も終わりにするため
    for (int j = N - 1; j > i; j--)
    {
      if (A[j] < A[j - 1])
      {
        int temp = A[j - 1];
        A[j - 1] = A[j];
        A[j] = temp;
        flag = true;
        count++;
      }
    }
    i++;
  }
  return count;
}

int main()
{
  int N;
  int A[MAX];

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }

  int count = bubbleSort(A, N);
  trace(A, N);
  cout << count << endl;

  return 0;
}
