#include <iostream>
using namespace std;

int main(){
  int n, i, tmp;
  int count = 0;
  int flag = 1;

  cin>>n;
  int a[n];
  for(i = 0; i < n; i++){
    cin>>a[i];
  }

  while(flag){
    flag = 0;
    for(i = n-1; i > 0; i--){
      if(a[i] < a[i-1]){
        tmp = a[i];
        a[i] = a[i-1];
        a[i-1] = tmp;
        flag = 1;
        count++;
      }
    }
  }

  for(i = 0; i < n-1; i++){
    cout<<a[i]<<" ";
  }
  cout<<a[n-1]<<endl<<count<<endl;

}
