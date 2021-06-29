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

int selectionSort(int A[], int N)
{
  int count = 0;
  int minIndex = 0;
  for (int i = 0; i < N; i++)
  {
    minIndex = i;
    for (int j = i; j < N; j++)
    {
      if (A[j] < A[minIndex])
      {
        minIndex = j;
      }
    }
    swap(A[i], A[minIndex]);
    if (i != minIndex)
    {
      count++;
    }
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

  int count = selectionSort(A, N);
  trace(A, N);
  cout << count << endl;

  return 0;
}
