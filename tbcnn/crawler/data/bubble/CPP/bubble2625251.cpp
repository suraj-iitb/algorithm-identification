#include <iostream>
using namespace std;

void sort(int* num, int n);
void output(int* num, int n);

int cnt = 0;

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
  int flag = 1;
  while(flag){
    flag = 0;
    for(int j = n - 1; j > 0; j--){
      if(num[j] < num[j - 1]){
        int temp = num[j];
        num[j] = num[j - 1];
        num[j - 1] = temp;
        flag = 1;
        cnt++;
      }
    }
  }
}

void output(int* num, int n){
  for(int i = 0; i < n; i++){
    if(i == n - 1) cout << num[i];
    else cout << num[i] << " ";
  }
  cout << endl;
  cout << cnt << endl;
}
