#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
using namespace std;

int main() {
    int n,cnt=0;
    cin >> n;
    int a[100] = {};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = n - 1;j > i; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                cnt++;
            }
        }
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << cnt << endl;
}

