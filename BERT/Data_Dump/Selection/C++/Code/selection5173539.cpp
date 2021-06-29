#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
        int min_pos = i;
        for (int j = i; j < n; j++) {
            if (arr[min_pos] > arr[j]) min_pos = j;
        }
        if (min_pos != i) res++;
        swap(arr[min_pos], arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        i == 0 ? cout << arr[i] : cout << " " << arr[i];
    }
    cout << endl;
    cout<<res<<endl;
    return 0;
}

