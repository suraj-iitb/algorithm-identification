#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int data[n];
  for(int i=0;i<n;i++){
    cin >> data[i];
    if(i != n-1) cout << data[i] << " ";
    else cout << data[i] << endl;
  }

  for(int i=1;i<n;i++){
    int v = data[i];
    int j=i-1;
    while(j >= 0 && data[j] > v){
      data[j+1]=data[j];
      j--;

    }
    data[j+1] = v;
    for(int i=0;i<n;i++){
      if(i != n-1) cout << data[i] << " ";
      else cout << data[i] << endl;
    }
  }

  return 0;
}
