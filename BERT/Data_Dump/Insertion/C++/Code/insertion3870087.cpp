#include<bits/stdc++.h>
using namespace std;
void insertionSort(int *a, int N);

int main(){
    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    insertionSort(a,N);
}
void insertionSort(int *a, int N){
    //大きさNの配列aを挿入ソートし各ステップを出力していく関数
    for(int i = 1; i < N; i++){
        for(int k = 0; k < N; k++){
            cout << a[k];
            if(k != N-1) cout << " ";
            else cout << endl;
        }
        int work = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > work){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = work;
    }
    for(int k = 0; k < N; k++){
            cout << a[k];
            if(k != N-1) cout << " ";
            else cout << endl;
        }
}
