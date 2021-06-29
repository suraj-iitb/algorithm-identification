#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> num(N);
  for(int i=0;i<N;i++){
    cin>>num.at(i);
  }
  for (int i=1;i<=N;i++){
     for (int x=0;x<N;x++){
      if(x==N-1){
        cout<<num[N-1]<<endl;
        break;
      }
      cout<<num[x]<<" ";
    }
    int v =num[i];
    int j= i-1;
    while(j>=0 && num[j]>v){
      num[j+1] = num[j];
      j--;
    }
    num[j+1]=v;
  }
}
