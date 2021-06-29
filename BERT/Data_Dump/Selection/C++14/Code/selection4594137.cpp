#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T> ostream& operator<<(ostream& os, const vector<T> arr){ for(int i = 0; i < (int)arr.size(); i++)cout << arr[i] << (i == (int)arr.size() -1 ? "" : " "); return os;}

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    int cnt = 0;

    for(int i = 0; i < n - 1; i++) {
        int minj = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[minj])minj = j;
        }
        if(i != minj)cnt++;
        swap(a[i], a[minj]);
    }
    cout << a << endl;
    cout << cnt << endl;
}
