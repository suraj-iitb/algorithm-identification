#include <bits/stdc++.h>
using namespace std;

void input(int A[],int N){
  for(int i=0 ; i<N ; i++){
    cin >> A[i] ;
  }
}

void output_space(int A[],int N){
  for(int i=0 ; i<N ; i++){
    if(i != N-1){
      cout << A[i] << " ";
    }else{
      cout << A[i] ;
    }
  }
  cout <<endl;
}
///////////////////////////////////////////////////////
int times;

void bubble_sort(int A[],int N){
  bool flag = 1;
    for(int i=1;flag;i++){
      flag = 0;
      for(int j=N-1;j>=i;j--){
        if(A[j-1]>A[j]){
          swap(A[j-1],A[j]);
          flag = 1;
          times ++;
        }
      }
    }
  output_space(A,N);
  cout << times << endl;
}

int main(){
  int N;
  cin >> N;
  int A[N];
  input(A,N);
  bubble_sort(A,N);
  return 0;
}

