using namespace std;
#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(int)(N);i++)


void printAll(vector<int> A){
  rep(i,A.size()-1)cout << A[i] << " ";
  
  cout << A[A.size()-1] << endl;
}

void insertionSort(vector<int> A, int N){ // N個の要素を含む0-オリジンの配列A
  for(int i=1;i<N;i++){
    int v = A[i];
    int j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    printAll(A);
  }
}


int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i,N)cin >> a[i];

  printAll(a);
  insertionSort(a,N);
  
}
