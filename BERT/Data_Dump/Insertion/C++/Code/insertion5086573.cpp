// 挿入ソート用のC ++プログラム
#include <iostream> 
using namespace std; 

// サイズnの配列を出力するユーティリティ関数 
void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++) { 
      if( i > 0) cout << " ";
      cout << arr[i];  
    }
    cout << endl; 
}  
  
//挿入ソートを使用して配列をソートする関数
void insertionSort(int arr[], int n)  
{  
  int i, key, j;  
  for (i = 1; i < n; i++) {  
    key = arr[i];  
    j = i - 1;  
    //キーより大きいarr [0..i-1]の要素を、現在の位置より1つ前の位置に移動します。
    while (j >= 0 && arr[j] > key) {  
      arr[j + 1] = arr[j];  
      j--;  
    }  
    arr[j + 1] = key;
    printArray(arr, n);
  }  
}  

  
//ドライバーコード
int main()  
{  
    int arr[100];
    int N,i;
    
    cin >> N;
    // int n = N;  

    for ( i = 0; i < N; i++) cin >> arr[i];

    printArray(arr, N);  
    insertionSort(arr, N);  
  
    return 0;  
}  
  
// これはrathbhupendraによって提供されたコードです
