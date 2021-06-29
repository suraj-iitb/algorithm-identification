#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void print_table(int A[],int n){
  for(int i=0;i<n;i++){
    cout << (i==0 ? "" : " ") << A[i];
  }
  cout << endl;
}

int bubbleSort(int A[],int N){
  int sw = 0;
  bool flag = 1;
  for(int i=0;flag;i++){
    flag = 0;
    for(int j=N-1;j>=i+1;j--){
      if(A[j-1]>A[j]){
        swap(A[j-1],A[j]);
        flag = 1;
        sw++;
      }
    }
  }
  return sw;
}

int main(){
  int N,sw,A[100];
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  sw = bubbleSort(A,N);

  print_table(A,N);
  cout << sw << endl;
  return 0;
}

