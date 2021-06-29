#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,count=0;
  cin >> n;
  vector<int> date(n);
  for(int i=0;i<n;i++){
    cin >> date.at(i);
  }
  bool t = true;
  int i=0;
  while(t){
    for(int j=n-1;j>i;j--){
      if(date.at(j)<date.at(j-1)){
        swap(date.at(j),date.at(j-1));
        count++;
      }
    }
    i++;
    if(i==n){
      t =false;
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
