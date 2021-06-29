#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <string>
using namespace std;
int main(void){
  int n;
  cin>>n;
  int ans=0;
  vector<long long int> hoge(n);
  for(long long int i=0; i<n; i++){
    cin>>hoge.at(i);
  }
  for(int i=0; i<n; i++){
    int minj=i;
    for(int j=i; j<n; j++){
      if(hoge.at(j)<hoge.at(minj)){
        minj=j;
      }
    }
    if(i!=minj){
    int change=hoge.at(i);
    hoge.at(i)=hoge.at(minj);
    hoge.at(minj)=change;
    ans++;
    }
  }
  for(int i=0; i<n; i++){
    cout<<hoge.at(i);
    if(i!=n-1){
      cout<<" ";
    }else{
      cout<<endl;
    }
  }
  cout<<ans<<endl;
}
