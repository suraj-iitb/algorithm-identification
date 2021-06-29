#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int bubblesort(vector<int> a, int n) {
    int cnt = 0;
    bool flag = 1;
    while(flag) {
        flag = 0;
        for(int i=n-1; i>0; --i) {
            if(a[i] < a[i-1]) {
                swap(a[i], a[i-1]);
                flag = 1;
                cnt++;
            }
        }
    }
    for(int i=0; i<n; i++) {
        cout << a[i];
        if(i != n - 1) cout << " ";
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    bubblesort(a, n);
}
