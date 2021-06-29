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
  for (int i=0;i<N;i++){
    int minnum=i;
    for(int j=i+1;j<N;j++){
      if(num[minnum]>num[j]){
        minnum=j;
      }
    }
    swap(num[i],num[minnum]);
    if(minnum!=i){
      count++;
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
