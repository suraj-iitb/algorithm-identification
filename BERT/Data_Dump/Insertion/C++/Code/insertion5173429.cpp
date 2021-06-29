#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        if (i == 0) cout << arr[i];
        else cout << " " << arr[i];
    }
    cout<<endl;
    for (int i = 1; i < n; ++i) {
        int v=arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > v) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = v;

        for (int k = 0; k < n; ++k) {
            if (k == 0) cout << arr[k];
            else cout << " " << arr[k];
        }
        cout<<endl;
    }
    return 0;
}

