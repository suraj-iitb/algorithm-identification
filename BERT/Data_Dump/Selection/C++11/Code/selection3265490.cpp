#include <iostream>
#include <algorithm>
using namespace std;

void selectionsort(int A[],int N, int& count){
    for(int i = 0; i < N; ++i){
      int minj = i;
      for(int j = i; j < N; ++j){
        if(A[j] < A[minj]){
          minj = j;
        }
      }
      if(i!=minj) {
        swap(A[i], A[minj]);
        count++;
      }
    }
}

int main(){
  int A[100], N, count = 0;

  cin >> N;
  for(int i = 0; i < N; ++i) cin >> A[i];

  selectionsort(A, N, count);

  for(int i = 0; i < N; ++i){
    if (i == (N-1))
      cout<< A[i] << endl;
    else
      cout<< A[i] <<" ";
  }

  cout << count << endl;

  return 0;
}

