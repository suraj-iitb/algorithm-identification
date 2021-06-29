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
    for (int i = 0; i<n; i++) {
        int m = a[i],k=i;
        for (int j = i + 1;j < n;j++) {
            if (m > a[j]) {
                m = a[j];
                k = j;
            }
        }
        if (i != k) {
            swap(a[i], a[k]);
            cnt++;
        }
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << cnt << endl;
}
