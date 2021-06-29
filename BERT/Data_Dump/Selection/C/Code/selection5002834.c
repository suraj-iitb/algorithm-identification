#include <stdio.h>
int a[105];
int n, cnt;
void swap(int b, int c) {
    cnt++;
    int temp = a[b];
    a[b] = a[c];
    a[c] = temp;
}

void selection() {
    int min=0;
    for(int h=0;h<n;h++) {
        int min = h;    
        for(int i=h;i<n;i++) if(a[i]<a[min]) min=i;
        if(min!=h) swap(min, h);
    }
    for(int i=0;i<n-1;i++) printf("%d ", a[i]);
    printf("%d\n", a[n-1]);
    printf("%d\n", cnt);
}

int main() {
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    // for(int i=0;i<n;i++) printf("%d ", a[i]);
    selection();
}
  
