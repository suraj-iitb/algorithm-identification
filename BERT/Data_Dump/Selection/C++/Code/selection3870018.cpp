// ALDS1_2_B 選択ソート

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int N;
  cin >> N;
  int *A = new int[N];
  for (int i = 0; i < N; i++)
    cin >> A[i];

  int xCount = 0;
  for (int i = 0; i < N; i++){
    int minj = i;
    for (int j = i; j < N; j++){
      if (A[j] < A[minj]){
        minj = j;
      }
    }
    if (i != minj){
      swap(A[i], A[minj]);
      xCount++;
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

