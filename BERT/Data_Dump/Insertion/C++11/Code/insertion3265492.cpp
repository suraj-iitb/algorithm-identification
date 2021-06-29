#include <iostream>
#include <algorithm>
using namespace std;

void output();

int A[100], N;

int main(){
  cin >> N;
  for(int i = 0; i < N; ++i) cin >> A[i];
  output();

  for(int i = 1; i < N; ++i){
    int v = A[i];
    int j = i-1;
    while((j >= 0)&&(A[j] > v)){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    output();
  }
  return 0;
}

void output(){
for(int i = 0; i < N; ++i){
  if(i==(N-1))
    cout << A[i] << endl;
  else
    cout << A[i] << " ";
  }
}

