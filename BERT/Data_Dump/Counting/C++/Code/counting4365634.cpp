#include <iostream>
#include <climits>

using namespace std;

int *A;
int N;

void CountingSort(int k)
{
  int *C = new int[10000 + 1];
  int *B = new int[N];

  for(int i = 0; i <=k; ++i)
    C[i] = 0;
  for(int i = 0; i < N; ++i)
    C[A[i]]++;

  for(int i = 0; i <= k; ++i)
    C[i] = C[i] + C[i - 1];

  for(int i = N - 1; i >= 0; --i)
  {
    B[C[A[i]]-1] = A[i];
    C[A[i]]--;
  }

  for(int i = 0; i < N; ++i)
    A[i] = B[i];

  delete [] B;
  delete [] C;
}

int main()
{
  cin >> N;

  A = new int[N];
 
  for(int i = 0; i < N; ++i)
    cin >> A[i];

  int k = 0;
  for(int i = 0; i < N; ++i)
    k = k < A[i] ? A[i] : k;

  CountingSort(k);

  cout << A[0];
  for(int i = 1; i < N; ++i)
    cout << " " << A[i];
  cout << endl;
 
  delete [] A;


}
