#include <iostream>
using namespace std;

int bubbleSort(int *a, int n)
{
    int sw = 0;
    bool flag = true;
    for (int i = 0; flag; i++) {
        flag = false;
        for (int j = n - 1; j >= i + 1; j--) {
            if (a[j-1] > a[j]) {
                swap(a[j-1], a[j]);
                flag = true;
                sw++;
            }
        }
    }
    return sw;
}

int main()
{
    int a[101], n, sw;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sw = bubbleSort(a, n);

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << sw << endl;

    return 0;
}
