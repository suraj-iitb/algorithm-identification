#include<iostream>
using namespace std;

//配列を表示する関数
void ShowAllay(const int a[], int n){
    for(int i = 0; i < n;i++){
        if(i>0) cout << " ";
        cout << a[i];
    }
    cout << endl;
}

//挿入ソート
void insertionSort(int a[], int n){
    for(int i = 1;i<n;i++){
        int key = a[i];
        //a[0]~a[i-1]のソートされた部分に挿入する。
        int j = i-1;
        while(j >=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        ShowAllay(a,n);
    }
}

int main(void){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ShowAllay(a,n);
    insertionSort(a, n);
    return 0;
}
