#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
const double PI = acos(-1);  // PI = 3.141593...

void print(int a[], int n) {
    for(int i = 0; i < n; ++i) {
        if(i) cout << " ";
        cout << a[i];
    }
    cout << endl;
}
void insertion_sort(int a[], int n) {
    for(int i = 1; i < n; ++i) {
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = v;
        print(a, n);
    }
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    print(a, n);
    insertion_sort(a, n);
    return 0;
}
