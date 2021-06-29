#include<bits/stdc++.h>//本当は必要なヘッダファイルだけインクルードするべきです
using namespace std;//本当は個別にusingするか変数や関数ごとにstd::をつけるべきです
//本当は関数内に宣言し明示的に初期化するべきです
int N,cnt;
vector<int>A;
void bubbleSort(){
  bool flag=true;
  while(flag){
    flag=false;
    for(int i=N-1;i>0;i--){
      if(A[i]<A[i-1]){
        swap(A[i],A[i-1]);
        flag=true;
        cnt++;
      }
    }
  }
}
int main(void){
  cin>>N;
  A.resize(N);
  for(int i=0;i<N;i++)cin>>A[i];
  bubbleSort();
  for(int i=0;i<N;i++)cout<<A[i]<<(i==N-1?'\n':' ');
  cout<<cnt<<endl;
  return 0;
}

