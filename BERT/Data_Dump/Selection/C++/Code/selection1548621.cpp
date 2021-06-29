#include <iostream>
using namespace std;

int main(){
  int n, i, j, minj, tmp;
  int count = 0;

  cin>>n;
  int a[n];
  for(i =0; i < n; i++){
    cin>>a[i];
  }

  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(a[j] < a[minj]){
        minj = j;
      }
    }
    if(i != minj){
      tmp = a[i];
      a[i] = a[minj];
      a[minj] = tmp;
      count++;
    }
  }

  for(i = 0; i < n-1; i++){
    cout<<a[i]<<" ";
  }
  cout<<a[n-1]<<endl<<count<<endl;
}
