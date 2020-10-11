
#include<stdio.h>

int main(void) {
    int n, flag = 1, exchange = 0;
    
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 0; flag; i++) {
        flag = 0;
        for(int j = n-1; j>=i+1; j--) {
            if(a[j] < a[j-1]) {
                int tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp; 
                flag = 1;
                exchange++;
            }
        }
    }

    for(int i = 0; i < n-1; i++) printf("%d ", a[i]);
    printf("%d\n%d\n", a[n-1], exchange);

    return 0;
}

