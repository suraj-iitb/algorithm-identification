#include <stdio.h>

int n, T;

int Binary_Search(int a[],int key) {
    int left = 0;
    int right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (a[mid] == key) {
            return 1;
        } else if (key < a[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d",&n);
    int a[n+1];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    scanf("%d",&T);
    int b;
    int ans=0;
    for (int i = 0; i < T; ++i) {
        scanf("%d",&b);
        if (Binary_Search(a,b)) ans++;
    }
    printf("%d\n",ans);
    return 0;
}

