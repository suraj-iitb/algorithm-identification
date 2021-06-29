#include <iostream>
#include <vector>
using namespace std;

void trace(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i < a.size() - 1) cout << ' ';
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    trace(a);
    for (int i = 1; i < n; i++) {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        trace(a);
    }
}
