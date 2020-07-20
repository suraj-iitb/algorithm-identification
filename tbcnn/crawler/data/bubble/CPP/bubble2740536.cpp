#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
static const int MAX = 1000;

int main(){
  int n,R[MAX],j,v,a;
  int flag = 1;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> R[i];
  }
  while(flag){
    flag = 0;
    for (int i = n-1; i >= 1; i--){
      if(R[i] < R[i-1]){
        swap(R[i],R[i-1]);
        a++;
        flag = 1;
      }
    }
  }
  for(int i = 0; i < n; i++){
    if(i != n-1){
      cout << R[i] << " ";
    }else{
      cout << R[i] << endl;
    }
  }
  cout << a << endl;
  return 0;
}

