#include<iostream>
using namespace std;
int main() {
    int n, data[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    for (int i = 1; i < n; i++) {
        for (int k = 0; k < n - 1; k++) {
            cout << data[k] << " ";
        }
        cout << data[n - 1] << endl;
        for (int j = i-1; j >= 0; j--) {
            if (data[j+1] > data[j]) {
                break;
            }
            int work = data[j+1];
            data[j + 1] = data[j];
            data[j] = work;
        }
    }
    for (int i = 0; i < n-1; i++) {
        cout << data[i] << " ";
    }
    cout <<data[n-1]<< endl;
    return 0;
}
