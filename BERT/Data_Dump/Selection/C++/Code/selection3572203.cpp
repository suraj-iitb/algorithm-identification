#include <iostream>
#include <cstdlib>

using namespace std;

void SelectionSort(int A[], int N, int &cnt){
  for(int i = 0; i < N-1; i++){
    int minj = i;
    for(int j = i; j < N; j++){
      if(A[j] < A[minj]){
	      minj = j;
      }
    }
    if(i != minj){
      swap(A[i], A[minj]);
      cnt++;
    }
  }
}

int main(){
  int A[100], N, cnt = 0;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  SelectionSort(A, N, cnt);

  for(int i = 0; i < N; i++){
    if(i > 0) cout << " ";
    cout << A[i];
  }
  cout << endl << cnt << endl;
  
  return 0;
}

