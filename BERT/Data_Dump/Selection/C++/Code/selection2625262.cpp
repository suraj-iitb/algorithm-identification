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
  for(int i = 0; i <= n - 1; i++){
    int minj = i;
    for(int j = i; j <= n - 1; j++){
      if(num[j] < num[minj]) minj = j;
    }
    if(i != minj) cnt++;
    int temp = num[i];
    num[i] = num[minj];
    num[minj] = temp;
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
