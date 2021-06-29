#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b[100],c;
  cin>>a;
  for(int i=0;i<a;i++){
    cin>>b[i];
  }
  for(int i=1;i<=a;i++){
    sort(b,b+i);
    for(int j=0;j<a-1;j++){
      cout <<b[j]<<" ";
    }
    cout <<b[a-1]<<endl;
  }
  return 0;
}
