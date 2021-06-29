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

void selection_sort(int n, int a[], int& swapCount) {
    for (int i=0; i<n; i++) {
        int mini = i;
        for (int j=i; j<n; ++j) {
            if (a[j] < a[mini]) {
                mini = j;
            }
        }
        int tmp = a[mini];
        a[mini] = a[i];
        a[i] = tmp;
        if (i != mini) {
            swapCount++;
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
    selection_sort(n, a, count);
    dump(n, a);
    cout<<count<<endl;
    return 0;
}

