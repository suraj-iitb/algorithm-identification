//
// Created by Weixu Liu on 2021/1/5.
//
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 200;
int a[maxn];
int SelectionSort(int *A, int N){
    int sum = 0;
    for(int i = 0; i < N; i++){
        int flag = i;
        for(int j = i; j < N; j++){
            if(A[flag] > A[j]) flag = j;
        }
        if(flag != i){
            swap(A[flag], A[i]);
            sum++;
        }
    }
    return sum;
}
int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    int sum = SelectionSort(a, N);
    for(int i = 0; i < N - 1; i++) cout << a[i] << " ";
    cout << a[N-1] << endl << sum << endl;
    return 0;
}

