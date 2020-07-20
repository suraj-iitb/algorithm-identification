#include <iostream>
using namespace std;

int main(){
  int N , flag = 1 , counter = 0;
  int A[100];
  cin >> N;
  for(int i=0;i<N;i++){
    int tmp;
    cin >> tmp;
    A[i] = tmp;
  }

  while(flag){
    flag = 0;
    for(int j=0;j<N-1;j++){
      if(A[j] > A[j+1]){
        int tmp;
        tmp = A[j+1];
        A[j+1] = A[j];
        A[j] = tmp;
        flag = 1;
        counter++;
      }
    }
  }

  for(int i=0;i<N-1;i++){
    cout << A[i] << ' ';
  }
  cout << A[N-1] << endl << counter << endl;
  return 0;
}

