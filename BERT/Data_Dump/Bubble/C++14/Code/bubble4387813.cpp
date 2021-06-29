#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int bubbleSort(int a[], int N){
    int sw = 0;
    bool flag = 1;
    for(int i = 1; flag; i++){
        flag = 0;
        for(int j = N-1; j >= i; j--){
            if(a[j-1] > a[j]){
                swap(a[j], a[j-1]);
                sw++;
                flag = 1;
            }
        }
    }

    rep(i, N){
        if(i != 0){
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
    return sw;
}

int main(){
    int N, a[100], ans;
    cin >> N;
    rep(i, N){
        cin >> a[i];
    }
    ans = bubbleSort(a, N);
    cout << ans << endl;     
}
