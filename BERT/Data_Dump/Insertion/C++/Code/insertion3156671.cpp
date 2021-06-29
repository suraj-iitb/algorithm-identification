#include <iostream>

using namespace std;


//配列の要素を順番に出力
void trace(int a[], int n){
    for(int i = 0; i<n; i++){
        if(i>0) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
}

//挿入ソート（０オリジン配列）
void insertionSort(int a[], int n){
    int i, j, v;
    for(i = 1; i<n; i++){
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j + 1] = a[j];
            j--;
        }
        a[j+1] =v;
        trace(a, n);
    }
}

int main(){
  int n, i, j;
  int a[100];

  cin >> n;
  for(i = 0; i<n; i++)
      cin >> a[i];

  trace(a, n);
  insertionSort(a, n);

  return 0;
}
