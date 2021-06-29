#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;


void trace(int A[], int N)
{
  int i;
  for(i = 0; i < N-1; i++) cout << A[i] << " ";
  cout << A[i];
  cout << endl;
}

/*
@param int A : 配列
@param int N : 配列の要素数
*/
void insertionSort(int A[], int N)
{
  //for(int i = 1; i < N-1; i++)
  for(int i = 1; i < N; i++)
  {
    trace(A, N);

    int v = A[i];
    int j = i - 1;
    while( j >= 0 && A[j] > v)
    {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
  }
  trace(A, N);
}


int main(int argc, char const *argv[]) {
  int array[1000];

  int N;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> array[i];
  insertionSort(array, N);


  return 0;
}
