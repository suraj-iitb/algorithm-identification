#include <iostream>
using namespace std;

void bubblesort(int n, int a[]){
  int count = 0;
  for(int i = 0; i < n; i++){
    for(int j = n-1; j>i; j--){
      if(a[j] < a[j-1]){
        int tmp = a[j];
        a[j] = a[j-1];
        a[j-1] = tmp;
        count++;
      }
    }
  }
  for(int i = 0; i < n-1; i++){
    cout << a[i] << " ";
  }
  cout << a[n-1] << endl;
  cout << count << endl;

  return ;
}

int main(int argc, char const *argv[]) {
  int a[101], n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  bubblesort(n, a);
  return 0;
}
