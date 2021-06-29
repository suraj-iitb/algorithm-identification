#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b) {
    int tmp = b;
    b = a;
    a = tmp;    
}

void print(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1)
            cout << " ";
        else
            cout << endl;
    }
}

void insertionSort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j-1]);
            j--;
        }
    
        print(arr, n);
    }
}


int main() {
    int n;
    int *arr;
    cin >> n;
    arr = new int(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    insertionSort(arr, n);

    return 0;
}
