#include <cstdio>

void print_array(int* a, int n) {
    printf("%d", a[0]);
    for (int i=1; i<n; i++) { printf(" %d", a[i]); }
    printf("\n");
}

int bubbleSort(int* a, int n) {
    int count = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = n-1; j > 0; j--) {
            if (a[j] < a[j-1]) {
                int tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                flag = true;
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int* a = new int[n];
    scanf("%d", &a[0]);
    for (int i=1; i<n; i++) { scanf(" %d", &a[i]); }

    int count = bubbleSort(a, n);
    print_array(a, n);
    printf("%d\n", count);

    return 0;
}
