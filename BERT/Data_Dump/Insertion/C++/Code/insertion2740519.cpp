#include<iostream>
#include<algorithm>
using namespace std;
static const int MAX = 1000;
int main(){
  int n,R[MAX],j,v;

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> R[i];
  }
  for(int i = 0; i < n; i++){
    if(i != n-1){
      cout << R[i] << " ";
    }else{
      cout << R[i];
    }
  }
  cout << endl;
  for(int i = 1; i < n; i++){
    v = R[i];
    j = i-1;
    while((j >= 0) && R[j] > v){
      R[j+1] = R[j];
      j--;
    }
    R[j+1] = v;
    for(int i = 0; i < n; i++){
      if(i != n-1){
        cout << R[i] << " ";
      }else{
        cout << R[i];
      }
    }
    cout << endl;
  }
  return 0;
}

