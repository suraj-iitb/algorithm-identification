#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int bubblesort(vector<int>& a, int N){
    int cnt = 0;
    bool f = 1;
    int k = 0;
    while(f){
        f = 0;
        for(int j = N - 1; j > k; j--){
            if(a[j - 1] > a[j]){
                swap(a[j - 1], a[j]);
                cnt++;
                f = 1;
            }
        }
        k++;
    }
    return cnt;
}


int main(){
    int n;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = bubblesort(a, n);
    bool g = 0;
    for(int i = 0; i < n; i++){
        if(g) cout << ' ';
        cout << a[i];
        g = 1;
    }
    cout << endl << ans << endl;
    return 0;
}

