#include <iostream>
using namespace std;

int main(){
  long long N;
  cin >> N;
  long long A[101];
  for (int i=0;i<N;i++){
    cin >> A[i];
  }
  long long v;
  int j;
  for (int i=0;i<N;i++){
    v = A[i];
    j = i-1;
    while (j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for (int j=0;j<N;j++){
      cout << A[j];
      if (j<N-1){
        cout << " ";
      }else{
        cout << endl;
      }
    }
  }
}
