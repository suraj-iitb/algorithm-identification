#include <stdio.h>
int a[2005];
int d[105];
int c, n, cnt;

void swap(int b, int c) {
    int temp = a[b];
    a[b] = a[c];
    a[c] = temp;
    return;
}

void dswap(int b, int c) {
    int temp = d[b];
    d[b] = d[c];
    d[c] = temp;
    return;
}

void ins() {
    for(int i=0;i<n;i++) {
        int key = a[i];
        int j=i-1;
        while(j>=0 && a[j] > key) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = key;
        for(int j=0; j<n-1; j++) printf("%d ", a[j]);
        printf("%d\n", a[n-1]);
    }
}

int main() {
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    ins();
}
  

