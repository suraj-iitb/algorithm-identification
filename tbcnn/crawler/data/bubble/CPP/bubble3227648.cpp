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
void bubbleSort(int A[], int N)
{
  int cnt = 0;
  int flag = 1;
  while(flag)
  {
    flag = 0;
    for(int j = N-1; j > 0; j--)
    {
      if(A[j] < A[j-1])
      {
        swap(A[j], A[j-1]);
        cnt++;
        flag = 1;
      }
    }
  }
  trace(A, N);
  cout << cnt << endl;
}


int main(int argc, char const *argv[]) {
  int array[100];
  int N;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> array[i];

  bubbleSort(array, N);

  return 0;
}
