#include <cstdio>
#include <algorithm>
using namespace std;

int selectionSort(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[minj]) {
                minj = j;
            }
        }
        if (minj != i) {
            swap(a[i], a[minj]);
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int count = selectionSort(a, n);
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n%d\n", count);
    return 0;
}
