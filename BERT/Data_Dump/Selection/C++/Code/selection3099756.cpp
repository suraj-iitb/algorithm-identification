#include <iostream>
using namespace std;
static const int MAX = 100;

static int cnt = 0;

void trace(int *a, int n) {
    for (int i = 0; i < n-1; i++) {
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
}

void selectionSort(int *a, int n) {
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (a[minj] > a[j]) {
                minj = j;
            }
        }
        if (i != minj) {
            cnt++;
            int tmp = a[i];
            a[i] = a[minj];
            a[minj] = tmp;
        }
    }
}

int main() {    
    int a[MAX], n;

    cin >> n;
    
    for (int i = 0; i < n; i++) cin >> a[i];
    
    selectionSort(a, n);
    trace(a, n);
    cout << cnt << endl;

    return 0;
}
