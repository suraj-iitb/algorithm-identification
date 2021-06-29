#include <iostream>
#include <vector>
using namespace std;
int N;
int Space(vector<int> a){
  for(int i = 0; i < N; i++){
    if(i > 0){
      cout << " ";
    }
    cout << a[i];
  }
  cout << endl;
  return 1;
}
int inssort(vector<int> a){
  for(int i = 1; i < N; i++){
    int v = a[i];
    int j = i - 1;
    while(j >= 0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    Space(a);
  }
  return 1;
}
int main(){
  //int N;
  cin >> N;
  vector<int> a(N);
  //int a[100];
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }

  Space(a);

  inssort(a);
  return 0;
}
