
#include<iostream>
#include<algorithm>
using namespace std;

int bubbleSort(int A[], int N){
  int flag = 1;
  int i = 0;
  int sw=0;
  int tmp;
  while (flag){
    flag = 0;
    for (int j=N-1;j>=i+1;j--){
      if (A[j] < A[j-1]){
        tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
        flag = 1;
        sw++;
      }
    }
    i++;
  }

  return sw;
  
}

int main(){
  int A[100], N, sw;
  cin >> N;

  for (int i=0;i<N;i++)cin >> A[i];

  sw = bubbleSort(A, N);

  for (int i=0;i<N;i++){
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << sw << endl;

  return 0;
}
