// ALDS1_2_A バブルソート

#include <iostream>

using namespace std;

int main()
{
  int N;
  cin >> N;
  int *A = new int[N];
  for (int i = 0; i < N; i++)
    cin >> A[i];

  int flag = 1;
  int xCount = 0;
  while(flag){
    flag = 0;
    for (int j = N - 1; j >= 1; j--){
      if (A[j] < A[j - 1]){
        int tmp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = tmp;
        xCount++;
        flag = 1;
      }
    }
  }

  for (int i = 0; i < N; i++){
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << xCount << endl;

  delete[] A;
  return 0;
}

