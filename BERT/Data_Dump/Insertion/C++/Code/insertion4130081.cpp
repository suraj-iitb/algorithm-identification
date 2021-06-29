#include<iostream>
using namespace std;

#define N 100

void print(int *, int);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, key, j;
    cin>>n; // データの数の入力

    int array[N];
    for(int i = 0; i < n; i++) cin>>array[i]; //データの入力

    // insertionSort
    for(int i = 1; i < n; i++) {
        print(array, n); //出力
        
        key = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }

    print(array, n);  //出力
    return 0;
}

void print(int *a, int n) {
    //出力
    for(int i = 0; i < n - 1; i++) cout<<a[i]<<' ';
    cout<<a[n - 1]<<endl;
}

