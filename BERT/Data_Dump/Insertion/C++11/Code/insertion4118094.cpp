#include<iostream>
using namespace std;

void print(int *a, int N) {
    //出力
    for(int i = 0; i < N - 1; i++) cout<<a[i]<<' ';
    cout<<a[N - 1]<<endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, key, j;
    cin>>N; // データの数の入力

    int array[N];
    for(int i = 0; i < N; i++) cin>>array[i]; //データの入力

    // insertionSort
    for(int i = 1; i <= N - 1; i++) {
        
        print(array, N); //出力
        key = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }

    print(array, N);  //出力
    return 0;
}

