#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

void printSort(int a[], int N){
    rep(i, N){
        if(i != 0){
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
}

void insertSort(int a[], int N){
    int v, j;
    for(int i = 1; i < N; i++){
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j]; //a[i]のいちに後ろにずらしていく
            j--;
        }
        a[j+1] = v; //最後はj--してあるから
        printSort(a, N);
    }
}

int main(){
    int N, a[100];
    cin >> N;
    rep(i, N){
        cin >> a[i];
    }
    printSort(a, N);
    insertSort(a, N);
}
