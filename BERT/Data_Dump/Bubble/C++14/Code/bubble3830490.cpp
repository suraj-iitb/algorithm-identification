#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> num(N);
  for(int i=0;i<N;i++){
    cin>>num.at(i);
  }
  int count =0;
  bool judge = true;
  while(judge){
    judge = false;
    for (int j=N-1;1<=j;j--){
      if(num[j]<num[j-1]){
        int v=num[j],w=num[j-1];
        num[j]=w;
        num[j-1]=v;
        judge = true;
        count++;
      }
    }
  }
  for(int i=0;i<N;i++){
    if(i==N-1){
      cout<<num[N-1]<<endl;
      break;
    }
    cout<<num[i]<<" ";
  }
  cout<<count<<endl;
}
