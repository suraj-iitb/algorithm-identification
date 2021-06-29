//参考答案 C++
#include<iostream>
using namespace std;

const int maxn = 101;
int n,a[maxn];
int cnt;

int selectionSort(int a[], int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[minj])
                minj = j;
        }
        swap(a[i], a[minj]);
        if (i != minj)  cnt++;
    }
    return cnt;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cnt = selectionSort(a, n);
    for (int i = 0; i < n; i++) {
        if (i)  cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
