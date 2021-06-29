#include <bits/stdc++.h>
using namespace std;

void printvec(vector<int> A)
{
  for(int i = 0; i < A.size() - 1; i++) {
    cout << A[i] << " ";
  }
  cout << A[A.size() - 1] << endl;
}

void BubbleSort(vector<int> A){
  int count = 0;
  int flag = 1;
  while(flag){
    flag = 0;
    for(int j = A.size() - 1; j >= 1; j--){
      if(A[j] < A[j - 1]){count++; swap(A[j], A[j - 1]); flag = 1;}
    }
  }
  printvec(A);
  cout << count << endl;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  BubbleSort(A);
  return 0;
}
