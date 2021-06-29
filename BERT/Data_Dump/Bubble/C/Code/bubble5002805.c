#include <stdio.h>
int a[105];
int n;
void swap(int b, int c) {
    int temp = a[b];
    a[b] = a[c];
    a[c] = temp;
}

void bubble() {
    int cnt=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(a[j+1] < a[j]) {
                swap(j, j+1);
                cnt++;
                
            }
        }
    }
    for(int i=0;i<n-1;i++) printf("%d ", a[i]);
    printf("%d\n", a[n-1]);
    printf("%d\n", cnt);
}

int main() {
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    // for(int i=0;i<n;i++) printf("%d ", a[i]);
    bubble();
}
  
