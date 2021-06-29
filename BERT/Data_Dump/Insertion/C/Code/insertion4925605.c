#include <stdio.h>

#define MAX (100)
int main(int argc, const char * argv[]) {
    // insert code here...
    int a[MAX]={0}, n, i, j;
    int tmp;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for (i=0; i<n; i++) {
        for (j=0; j<=i; j++) {
            if (a[i]<a[j]) {
                tmp=a[j];
                a[j]=a[i];
                a[i]=tmp;
            }
        }
        for (int x=0; x<n; x++) {
            printf("%d", a[x]);
            if (x!=n-1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

