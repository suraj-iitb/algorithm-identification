#include <cstdio>

void print_array(int* a, int n) {
    printf("%d", a[0]);
    for (int i=1; i<n; i++) { printf(" %d", a[i]); }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    int* a = new int[n];
    scanf("%d", &a[0]);
    for (int i=1; i<n; i++) { scanf(" %d", &a[i]); }

    print_array(a, n);
    for (int i=1; i<n; i++) {
        int v = a[i];
        int j = i-1;
        while (j >= 0 and a[j] > v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        print_array(a, n);
    }

    return 0;
}
