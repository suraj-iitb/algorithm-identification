#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int selectionSort(int a[], int N){
    int minj;
    int sw = 0;
    for(int i = 0; i < N-1; i++){
        minj = i;
        for(int j = i + 1; j < N; j++){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        if(i != minj){
            swap(a[i], a[minj]);
            sw++;
        }
    }
    return sw;
}

int main(){
    int N, ans, a[100];
    cin >> N;
    rep(i, N){
        cin >> a[i];
    }

    ans = selectionSort(a, N);

    rep(i, N){
        if(i){
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
    cout << ans << endl;
}
