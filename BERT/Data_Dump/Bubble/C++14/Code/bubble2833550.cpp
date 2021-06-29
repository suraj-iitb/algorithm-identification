#include <cstdio>
#include <algorithm>
using namespace std;

int bubbleSort(int a[], int n) {
    int count = 0;
    bool flag = true;
    for (int i = 0; flag; i++) {
        flag = false;
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                count++;
                flag = true;
            }
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
    
    int count = bubbleSort(a, n);
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n%d\n", count);
    return 0;
}
