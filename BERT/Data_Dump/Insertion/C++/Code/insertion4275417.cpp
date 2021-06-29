#include <bits/stdc++.h>

using namespace std;

int n;
int a[100];

void printarr(int a[], int n) {
    for (int i=0;i<n;i++) {
        printf("%d", a[i]);
        if (i<n-1) printf(" ");
    }
    printf("\n");
}

int sort() {
    int j, i, v;
    for (i=0;i<n;i++) {
        v = a[i];
        j = i - 1;
        while (j >= 0 && v < a[j]) {
            a[j+1] = a[j]; 
            j--;
        }
        a[j+1] = v;
        printarr(a, n);
    }
    return 0;
}

int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort();
    return 0;
}
