#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int tmp;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j > i; j--) {
            if(a[j] < a[j-1]){
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                cnt++;
            }
        }
    }

    for (int i = 0; i < n-1; i++) {
        cout << a[i] << " ";
    }

    cout << a[n-1] << endl;
    cout << cnt << endl;


    return 0;
}
