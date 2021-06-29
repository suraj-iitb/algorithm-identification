//
// Created by Weixu Liu on 2021/1/3.
//
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 200;
int a[maxn];

int bubbleSort(int *A, int N){
    int sum = 0;
    for(int i = 0; i < N; i++){
        for(int j = N - 1; j >= i + 1; j--){
            if(a[j] < a[j-1]){
                swap(a[j], a[j-1]);
                sum++;
            }
        }
    }
    return sum;
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    int sum = bubbleSort(a, N);
    for(int i = 0; i < N - 1; i++) cout << a[i] << " ";
    cout << a[N-1] << endl;
    cout << sum << endl;
    return 0;
}

