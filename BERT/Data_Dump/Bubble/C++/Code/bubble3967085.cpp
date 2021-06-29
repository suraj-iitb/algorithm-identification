#include<bits/stdc++.h>
using namespace std;
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

