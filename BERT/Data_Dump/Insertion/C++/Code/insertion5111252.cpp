#include <iostream>

#define MAX 1000

using namespace std;

int main()
{
    int r[MAX];
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    for (int i = 0; i < n; i++) {
        int v = r[i];
        for (int j = i-1; j >= 0 && v < r[j]; j--) {
            r[j+1] = r[j];
            r[j] = v;
        }
        cout << r[0];
        for (int j = 1; j < n; j++) {
            cout << " " << r[j];
        }
        cout << endl;
    }

    return 0;
}

