#include <iostream>
#include <cstdio>

using namespace std;

void print(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i) printf(" %d", a[i]);
        else printf("%d", a[i]);
    }
    printf("\n");
}

void insertion_sort(int a[], int n) {
    for (int i = 1; i < n; ++i) {
        int t = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > t) {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = t;
        print(a, n);
    }
}

int a[100+10];

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];
    print(a, N);
    insertion_sort(a, N);
    
    return 0;
}
