#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
static const int MAX = 100;

int main(){
  int n,R[MAX],minj,v,a;

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> R[i];
  }

  for(int i = 0; i < n; i++){
    minj = i;
    for(int j = i; j < n; j++){
      if(R[j] < R[minj]){
        minj = j;
      }
    }
    if(minj != i){
      swap(R[i], R[minj]);
      a++;
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

