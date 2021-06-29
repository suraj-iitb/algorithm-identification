#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T> ostream& operator<<(ostream& os, const vector<T> arr){ for(int i = 0; i < (int)arr.size(); i++)cout << arr[i] << (i == (int)arr.size() -1 ? "" : " "); return os;}

int main()
{
    int n; cin >> n;
    bool res = true; //転倒数が0でない
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    int cnt = 0;

    while(res) {
        res = false;
        for(int j = n - 1; j >= 1; j--) {
            if(a[j - 1] > a[j]){
                swap(a[j], a[j - 1]);
                res = true;
                cnt++;
            }
        }
    }
    cout << a << endl;
    cout << cnt << endl;
}
