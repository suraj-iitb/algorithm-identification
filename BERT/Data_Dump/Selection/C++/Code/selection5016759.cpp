#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,count=0,minv,exminv;
  cin >>n;
  vector<int> date(n);
  vector<int> sorr(n);
  for(int k=0;k<n;k++){
    cin >> date.at(k);
  }
  
  /*此処からソート開始*/
  bool judge = true;
  int j=0,m;
  while(judge){
    minv=date.at(j);
    exminv=minv;
    for(int i=j;i<n;i++){
      if(exminv>date.at(i)){
        exminv=date.at(i);
        m=i;
      }
    }
    if(exminv!=minv){
      count++;
      swap(date.at(j),date.at(m));
    }
    j++;
    if(j==n){
      judge = false;
    }
  }
  
  for(int i=0;i<n;i++){
    cout <<date.at(i);
    if(i!=n-1){
      cout <<" ";
    }
    else{
      cout <<endl;
    }
  }
  cout <<count<<endl;
}
