#include <iostream>
using namespace std;

void sort(int* num, int n);
void output(int* num, int n);

int main(){
  int n;
  cin >> n;
  int* num;
  num = new int[n];
  for(int i = 0; i < n; i++) cin >> num[i];
  sort(num, n);
  output(num, n);
  delete[] num;
  return 0;
}

void sort(int* num, int n){
  for(int i = 1; i <= n - 1; i++){
    output(num, n);
    int v = num[i];
    int j = i - 1;
    while(j >= 0 && num[j] > v){
      num[j + 1] = num[j];
      j--;
    }
    num[j + 1] = v;
  }
}

void output(int* num, int n){
  for(int i = 0; i < n; i++){
    if(i == n - 1) cout << num[i];
    else cout << num[i] << " ";
  }
  cout << endl;
}
