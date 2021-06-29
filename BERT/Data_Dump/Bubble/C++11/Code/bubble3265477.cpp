#include <iostream>
#include <algorithm>
using namespace std;

void bubblesort(int A[],int N, int& count){
  bool flag = 1;

  while(flag){
    flag = 0;
    for(int j = N-1; j > 0; --j){
      if(A[j] < A[j-1]){
        count++;
        swap(A[j],A[j-1]);
        flag = 1;
      }
    }
  }
}

int main(){
  int A[100], N, count = 0;

  cin >> N;
  for(int i = 0; i < N; ++i) cin >> A[i];

  bubblesort(A, N, count);

  for(int i = 0; i < N; ++i){
    if (i == (N-1))
      cout<< A[i] << endl;
    else
      cout<< A[i] <<" ";
  }

  cout << count << endl;

  return 0;
}

