#include <iostream>

#define MAX 100

using namespace std;

int main()
{
    int n;
    int a[MAX];

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int count = 0;
    bool check = true;
    while (check) {
        check = false;
        for (int i = n-1; i > 0; --i) {
            if (a[i] < a[i-1]) {
                int v = a[i];
                a[i] = a[i-1];
                a[i-1] = v;
                check = true;
                ++count;
            }
        }
    }

    cout << a[0];
    for (int i = 1; i < n; ++i) cout << " " << a[i];
    cout << endl;
    cout << count << endl;
    return 0;
}

