#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        int minj = i;
        bool flag = false;
        for (int j = i; j < n; ++j) {
            if (a[j] < a[minj]) {
                minj = j;
                flag = true;
            }
        }
        if (flag) {
            int v = a[i];
            a[i] = a[minj];
            a[minj] = v;
            ++count;
        }
    }

    for (int i = 0; i < n; ++i) {
        if(i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << count << endl;
}

