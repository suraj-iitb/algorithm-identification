#include <bits/stdc++.h>
using namespace std;

int n, a[2000010], b[2000010];

void csort(int k)
{
    int c[10010];
    for(int i = 0; i < k; i++) c[i] = 0;

    for(int j = 0; j < n; j++) {
        c[a[j]]++;
    }

    for(int i = 1; i < k; i++) {
        c[i] += c[i - 1];
    }

    for(int j = n - 1; j >= 0; j--) {
        b[c[a[j]]] = a[j];
        c[a[j]]--;
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    csort(10010);

    for(int i = 0; i < n; i++) printf("%s%d", (i ? " " : ""), b[i + 1]);
    cout << endl;

    return 0;
}

