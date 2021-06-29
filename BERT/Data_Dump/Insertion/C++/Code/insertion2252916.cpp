#include <iostream>
using namespace std;

int main(){
  int N;
  int A[100];
  int key,i,j;
  
  cin >> N;

  for (i=0;i<N;i++)
    cin >> A[i];
  for (i=0;i<N;i++){
    cout << A[i];
    if (i<N-1)cout << " ";
  }
  cout << endl;
  for (i=1;i<N;i++){
    key=A[i];
    j=i-1;
    while (j>=0 && A[j]>key){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=key;
    for (j=0;j<N;j++){
      cout << A[j];
      if (j<N-1)cout << " ";
    }
    cout << endl;
  }
}
