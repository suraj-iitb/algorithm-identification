#include <bits/stdc++.h>
using namespace std;

int bubble(vector<int>&);

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = bubble(a);

    for (int i = 0; i < n - 1; i++) {
        cout << a[i] << " ";
    }
    cout << a[n - 1] << endl << cnt << endl;

    return 0;
}

int bubble(vector<int>& a) {
    int cnt = 0;
    bool flag = true;
    while(flag == true) {
        flag = false;
        for (int i = a.size() - 1; i > 0; i--) {
            if (a[i] < a[i - 1]) { 
                int temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
                flag = true;
                cnt++;
            }
        }
    }
    return cnt;
}

