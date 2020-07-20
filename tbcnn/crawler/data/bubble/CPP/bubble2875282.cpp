#include <iostream>
using namespace std;
int a[100], n, res;
int main(void){
    // Your code here!
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                swap(a[i - 1], a[i]);
                flag = 1;
                res++;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) cout << a[i] << ' ';
    cout << a[n - 1] << endl << res << endl;
}

