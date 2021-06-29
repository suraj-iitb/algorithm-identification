#include <iostream>

#define N 100

using namespace std;

void debug_print(int n, int a[]) {
    for (int i=0; i<n; i++) {
        if (i>0) { cout<<" "; }
        cout<<a[i];
    }
    cout<<endl;
}

void insertion_sort(int n, int a[]) {
    for (int i=1; i<n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j>=0 && a[j]>key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        debug_print(n, a);
    }
}

int main() {
    int n;
    int a[N];
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }

    debug_print(n, a);
    insertion_sort(n, a);

    return 0;
}

