#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trace(int a[], int n){
    for(int i = 0; i < n; i++){
        if(i > 0){ 
            cout << " ";/* 隣接する要素の間に一つの空白を出力 */
        }
        cout << a[i];
    }
  	cout << "\n";
}

/* 挿入ソート (0オリジン配列) */
int insertionSort(int a[], int n){
  	int j;
    int v;
    for(int i = 1; i < n; i++){
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v){ 
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        trace(a, n);
    }
}

int main(){
    int n;
    int a[100];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    trace(a, n);
    insertionSort(a, n);
}
