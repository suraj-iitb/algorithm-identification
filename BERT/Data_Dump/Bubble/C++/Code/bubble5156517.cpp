#include <iostream>
using namespace std;
const int N_MAX=100;

int bubbleSort(int A[],int N){
  int sw=0;
  bool flag=1;//もうこれ以上ソートする場所がないかのフラグ
  for(int i=0;flag;i++){
    flag=0;
    for(int j=N-1;j>=i+1;j--){
      if(A[j-1]>A[j]){
        swap(A[j],A[j-1]);
        flag=1;
        sw++;
      }
    }
  }
  return sw;
}


int main(){
  int N,A[N_MAX],sw;

  cin >> N;
  for(int i=0;i<N;i++) cin >> A[i];

  sw=bubbleSort(A,N);
  for(int i=0;i<N;i++){
    if(i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << sw << endl;

  return 0;
}
