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
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int j = n - 1; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                res++;
                flag = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        i == 0 ? cout << arr[i] : cout << " " << arr[i];
    }
    cout<<endl;
    cout<<res<<endl;

    return 0;
}

