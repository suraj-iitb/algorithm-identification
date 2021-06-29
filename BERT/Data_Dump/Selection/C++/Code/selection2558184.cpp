#include<iostream>
using namespace std;

static int cnt=0;

void show(int A[], int N){
  for(int i=0; i<N; i++){
    if(i) cout << " ";
    cout << A[i];
  }
  cout << endl;
}

void selectionSort(int A[], int N){
  int min=101, tmp, minarg;
  for(int j=0; j<N; j++){
    for(int i=j; i<N; i++){
      if(min>A[i]) {min = A[i]; minarg = i;}
    }
    tmp = A[j];
    A[j] = A[minarg];
    A[minarg] = tmp;
    if(j!=minarg) cnt++;
    min = 101;
  }
  show(A, N);
}

int main(){
  int N, A[100];
  cin >> N;
  for(int i=0; i<N; i++) cin >> A[i];
  selectionSort(A, N);
  cout << cnt << endl;
}
