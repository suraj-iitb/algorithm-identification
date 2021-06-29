#include <iostream>
#include <algorithm>
using namespace std;

static int cnt=0;

void show(int A[], int N){
  for(int i=0; i<N; i++){
    if(i) cout << " ";
    cout << A[i];
  }
  cout << endl;
}

void bubbleSort(int A[], int N){
  int tmp;
  for(int i=0; i<N; i++){
    for(int j=N-1; j>i; j--){
      if(A[j]<A[j-1]){
        tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
        cnt++;
      }
    }
  }
  show(A, N);
}

int main(){
  int N, A[100];
  cin >> N;
  for(int i=0; i<N; i++) cin >> A[i];
  bubbleSort(A, N);
  cout << cnt << endl;
}
