#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<int> arr;

void insertion_sort(int start, int end) {
    int j, flag = false;        
    for (int i = start; i <= end; i++) {
        if (flag) cout << endl;
        flag = true;
        int current_element = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > current_element) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = current_element; 
        for (int i = start; i <= end - 1; i++)
            cout << arr[i] << " ";
        cout << arr[end];
    }
}

int main(void) {
    int n; cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)    
        cin >> arr[i];
    insertion_sort(0, n - 1);
    cout << endl;
    return 0;
}
