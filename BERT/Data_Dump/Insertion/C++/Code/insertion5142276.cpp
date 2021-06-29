
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)


 void insertionSort(int A[], int N){ // N個の要素を含む0-オリジンの配列A
  rep(i,N){
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
    for(int i = 0; i < N - 1; i++){
      cout << A[i] << " ";
    }
    cout << A[N - 1] << endl;
  }
}


int main(){
  //入力
  int N;
  int A[1010];
  cin >> N;
  rep(i,N){
    cin >> A[i];
  }

  insertionSort(A,N);

  return 0;
}

