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

void bubbleSort(int *a, int n) {
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int j = n-1; j > 0; j--) {
            if (a[j] < a[j-1]) {
                cnt++;
                int tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                flag = 1;
            }
        }
    }
}

int main() {    
    int a[MAX], n;

    cin >> n;
    
    for (int i = 0; i < n; i++) cin >> a[i];
    
    bubbleSort(a, n);
    trace(a, n);
    cout << cnt << endl;

    return 0;
}

