#include <bits/stdc++.h>
using namespace std;

int main(){
//srandom((unsigned long)time(NULL));

int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
cin>>a[i];
}
int cnt=0;
for(int i=1;i<n;i++){
  int v=a[i];
  int j=i-1;
 // if(a[j]>a[i])cnt++;
  while(j>=0 && a[j]>v){
    cnt++;
    a[j+1]=a[j];
    j--;
  }
  a[j+1]=v;
}
for(int i=0;i<n-1;i++){
  cout<<a[i]<<" ";
}
cout<<a[n-1]<<endl;
cout<<cnt<<endl;

return 0;
}


