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
  for (int i = 1; i < n; i++)
  {
    int v=a.at(i);
    int j=i-1;
      for(int i=0; i<n; i++){
        cout<<a.at(i);
        if(i!=n-1){
          cout<<" ";
        }else{
          cout<<endl;
        }
      }
    while (j>=0&&a.at(j)>v){
      a.at(j+1)=a.at(j);
      j--;
      a.at(j+1)=v;
    }
    
  }
      for(int i=0; i<n; i++){
        cout<<a.at(i);
        if(i!=n-1){
          cout<<" ";
        }else{
          cout<<endl;
        }
      }
  return 0;
}
