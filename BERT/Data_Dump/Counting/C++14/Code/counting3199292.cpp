#include <iostream>
#include <vector>
using namespace std;
#define MAX 2000001
#define VMAX 10000

int main() {
    int c[VMAX + 1];
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);

    for (int i = 0; i <= VMAX; i++) c[i] = 0;

    for (int i = 0; i < n; i++) {
        cin >> a.at(i + 1);
        c[a.at(i + 1)]++;
    }

    for (int i = 1; i <= VMAX; i++) c[i] += c[i - 1];

    for (int j = 1; j <= n; j++) {
        b.at(c[a.at(j)]) = a.at(j);
        c[a.at(j)]--;
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << b.at(i);
    }
    cout << endl;
}

