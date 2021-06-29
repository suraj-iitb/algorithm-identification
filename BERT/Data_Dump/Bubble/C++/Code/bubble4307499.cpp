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
  vector<long long int> a(n);
  for(long long int i=0; i<n; i++){
    cin>>a.at(i);
  }
  bool flag=true;
  int ans=0;
  while(flag){
    flag=false;
    for(int j=n-1; j>=1; j--){
      if(a.at(j)<a.at(j-1)){
        int v=a.at(j);
        a.at(j)=a.at(j-1);
        a.at(j-1)=v;
        flag=true;
        ans++;
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout<<a.at(i);
    if(i!=n-1){
      cout<<" ";
    }else{
      cout<<endl;
    }
  }
  cout<<ans<<endl;
  return 0;
  
}
