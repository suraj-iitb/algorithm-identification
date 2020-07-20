#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int A[100];
  for (int i=0;i<N;i++){
    cin >> A[i];
  }
  int tmp1;
  int tmp2;
  int s = 0;
  for (int i=0;i<N;i++){
    for (int j=N-1;j>i;j--){
      if (A[j] < A[j-1]){
        tmp1 = A[j];
        tmp2 = A[j-1];
        A[j] = tmp2;
        A[j-1] = tmp1;
        s += 1;
      }
    }
  }
  for (int i=0;i<N;i++){
    cout << A[i];
    if (i<N-1){
      cout << " ";
    }else{
      cout << endl;
    }
  }
  cout << s << endl;
}

