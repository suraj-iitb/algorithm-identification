#include<iostream>
using namespace std;
int main() {
    int n, cnt = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j >= i; j--)
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                cnt++;
            }
    for (int i = 0; i < n - 1; i++) 
        cout << a[i] << ' ';
    cout << a[n - 1] << '\n' << cnt << '\n';
    return 0;
}
