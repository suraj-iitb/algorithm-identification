#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin >> n;
  vector<int> date(n);
  for(int i=0;i<n;i++){
    cin >> date.at(i);
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
  
  /*ここからソート*/
  for(int i=1;i<n;i++){
    m=date.at(i);
    for(int j=0;j<i;j++){
      if(m<=date.at(j)){
        for(int k=i;k>j;k--){
          date.at(k)=date.at(k-1);
        }
        date.at(j)=m;
        break;
      }
    }
    for(int l=0;l<n;l++){
      cout <<date.at(l);
      if(l!=n-1){
        cout <<" ";
      }
      else{
        cout << endl;
      }
    }
  }
}
