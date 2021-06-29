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

int SelectionSort(int A[],int N){
  int minj,sw;
  sw = 0;
  for(int i=0;i<N;i++){
    minj = i;
    for(int j=i;j<N;j++){
      if(A[minj]>A[j]){
        minj = j;
      }
    }
    swap(A[minj],A[i]);
    if(i != minj){
      sw++;
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
  sw = SelectionSort(A,N);

  print_table(A,N);
  cout << sw << endl;
  return 0;
}
