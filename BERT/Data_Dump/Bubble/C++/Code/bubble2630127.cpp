#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>

typedef long long ll;

using namespace std;

void printArray(int *x, int n){
    for(int i = 0; i < n; i++){
        cout << x[i];
        if(i < n-1){
            cout << " ";
        }
    }
    cout << endl;
}

int bubbleSort(int *a, int n){
    int count = 0;
    bool flag = true;
    while(flag){
        flag = 0;
        for(int j = n-1; j > 0; j--){
            if(a[j] < a[j-1]){
                swap(a[j], a[j-1]);
                count++;
                flag = true;
            }
        }
    }
    printArray(a, n);
    return count;
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << bubbleSort(a, n) << endl;
}

int main() {
    solve();
    return 0;
}
