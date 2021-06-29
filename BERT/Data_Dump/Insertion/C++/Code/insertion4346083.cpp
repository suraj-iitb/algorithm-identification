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
    int n;
    cin >> n;
    int a[100] = {};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int j = i - 1;
        int v = a[i];
        while (j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            j--;
        }
        a[j + 1] = v;
        for (int k = 0; k < n; k++) {
            if (k) cout << " ";
            cout << a[k];
        }
        cout << endl;
    }
}
