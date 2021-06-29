#include<bits/stdc++.h>//本当は必要なヘッダファイルだけインクルードするべきです
using namespace std;//本当は個別にusingするか変数や関数ごとにstd::をつけるべきです
//本当は関数内に宣言し明示的に初期化するべきです
int N,cnt;
vector<int>A;
void selectionSort(){
  for(int i=0;i<N;i++){
    int min_j=i;
    for(int j=i+1;j<N;j++){
      if(A[j]<A[min_j]){
        min_j=j;
      }
    }
    if(A[i]>A[min_j]){
      swap(A[i],A[min_j]);
      cnt++;
    }
  }
}
int main(void){
  cin>>N;
  A.resize(N);
  for(int i=0;i<N;i++)cin>>A[i];
  selectionSort();
  for(int i=0;i<N;i++)cout<<A[i]<<(i==N-1?'\n':' ');
  cout<<cnt<<endl;
  return 0;
}

