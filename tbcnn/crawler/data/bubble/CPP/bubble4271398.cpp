#include <iostream>

#define N 100

using namespace std;

void dump(int n, int a[]) {
    for (int i=0; i<n; i++) {
        if (i>0) { cout<<" "; }
        cout<<a[i];
    }
    cout<<endl;
}

void bubble_sort(int n, int a[], int& swapCount) {
    for (int i=0; i<n; i++) {
        for (int j=n-1; j>i; --j) {
            if (a[j] < a[j-1]) {
                int tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                swapCount++;
            }
        }
    }
}

int main() {
    int n;
    int a[N];
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    int count = 0;
    bubble_sort(n, a, count);
    dump(n, a);
    cout<<count<<endl;
    return 0;
}

